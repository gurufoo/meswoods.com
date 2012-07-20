<?php
// The criteria and setup for determining the height
function generate_npc_height ($form, &$form_state) {
  //dpm($form_state['values'], 'values in ()');
  // Use the height the user entered, or if not specified generate a height.
  $height = $form_state['values']['field_height']['und'][0]['value'];
  if ($height == '' || !isset($height)) {
    $race = $form_state['values']['field_npc_race']['und'][0]['value'];
    $df = $form_state['values']['field_distinguishing_features']['und'][0]['value'];
    $npc_height = _generate_random_height($race, $df);
  }else {
    $npc_height = $height;
  }
  //dpm($npc_height, '$npc_height');
  _setopt('field_height', $npc_height, $form, $form_state);
}

// Generate the random height
// @param $df Distinguishing Feature
function _generate_random_height($race, $df) {
  //dpm($df, '$df');
  //dpm($race, '$race in _generate_random_name()');

  $range = _get_racial_measurements ($race, 'height');
  //dpm($range, '$range');

  $min = $range['min'];
  $max = $range['max'];
  //dpm($min,'$min');
  //dpm($max, '$max');
  if ($df == 73) { // Exceptionally Short
    $max = $min - 1; // The tallest an exceptionally short person can be is 1 inche shorter than the racial minimum
    $min = floor($min * 0.85); // The shortest an exceptionally short person can be is 3/4 the racial minimum
  }else if ($df == 74) { // Exceptionally Tall
    $min = $max + 1;
    $max = ceil($max * 1.15);
  }
  //dpm($min, '$min');
  //dpm($max, '$max');
  $option = rand($min, $max);
  //dpm($option, '$option');
  return $option;
}

function _get_racial_measurements ($race, $type) {
  // If we're missing parameters
  //dpm($race, '$race in _get_racial_measurements()');
  //dpm($type, '$type in _get_racial_measurements()');
  if (!isset($race) || !isset($type)) {
    drupal_set_message('Warning: $race or $type not sent to _get_racial_measurements(). Generating bogus range.');
    return array('min' => 46, 'max' => 74);
  }
  $range = array();
  $sql = "SELECT min,max FROM {npc_measurements} WHERE race = :race AND type = :type";
  $range = db_query($sql, array(':type' => $type, ':race' => $race))->fetchAssoc();
  //dpm($range, '$range');
  

  return $range;

}

/**
* Gets an array of the strings that describe the various heights.
*/
function _get_descriptor_values ($type) {
  switch ($type) {
  case 'height':
    return array('diminutive', 'short', 'average', 'tall', 'towering');
  break;
  case 'weight':
    return array('cadaverous', 'gaunt', 'slight', 'medium', 'toned', 'husky', 'fat', 'corpulant');
  break;
  }
}

/**
* Gets the string value that describes the measurement of the npc.
*/ 
function _get_racial_measurement_descriptor ($race, $type, $value) {
  //dpm($value, '$value passed in to _get_racial_measurement_descriptor()');
  //dpm($race, '$race passed in to _get_racial_measurement_descriptor()');
  // Get the range of the measurement for the race
  $range = _get_racial_measurements($race, $type);
  // Get the difference between the min and max
  $diff_range = $range['max']- $range['min'] + 1;
  $diff_min = $value - $range['min'];
  //dpm($range, '$range');
  //dpm($diff_range, '$diff_range');
  //dpm($diff_min, '$diff_min');
  // Get all the descriptors for the type of measurement
  $descriptors = _get_descriptor_values ($type);
  //dpm($descriptors, '$descriptors');


  // Determine the units of measurement per descriptor
  // Get the number of descriptors
  $num_descriptors = count($descriptors);
  //dpm($num_descriptors, '$num_descriptors');


    // If the measurment value passed in is outside of the range, then
  // the NPC is either the bottom or top of the array.
  // If this is the case, stop processing and return the first or last element.
  // The values in the array are listed from least to greatest 
  if ($value > $range['max']) {
    return $descriptors[$num_descriptors - 1]; // The last element in the array
  } else if ($value < $range['min']) {
    return $descriptors[0]; // The first element in the array
  } else {
    unset($descriptors[0]);
    unset($descriptors[$num_descriptors - 1]);
  }
  //dpm($descriptors, '$descriptors');
  // Get the number of descriptors
  $num_descriptors = count($descriptors);
  //dpm($num_descriptors, '$num_descriptors');

$units_per_descriptor = $diff_range / $num_descriptors;
  //dpm($units_per_descriptor, '$units_per_descriptor');

$descriptor_index = ceil($diff_min / $units_per_descriptor);
//dpm($descriptor_index, '$descriptor_index');
// If the value is equal to the minimum option, then we're going to automatically set the index to 1
// which is the lowest available, since we've stripped the extremes up above.
  if ($descriptor_index == 0) {
    $descriptor_index = $descriptor_index + 1;
  }
  return $descriptors[$descriptor_index];
}

