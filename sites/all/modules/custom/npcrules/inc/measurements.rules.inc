<?php


/**
* Validate function.  It pretty much just calls the worker function.
*/
function validate_npc_measurements ($form, &$form_state) {
 $race = $form_state['values']['field_npc_race']['und'][0]['value'];
 $df = $form_state['values']['field_distinguishing_features']['und'][0]['value'];

  $measurements = generate_npc_measurements($race, $df);
  dpm($measurements, '$measurements in validate_npc_measurements()');
  foreach ($measurements as $field => $measurement) {
  _setopt($field, $measurement, $form, $form_state);
  }
}

/**
* Returns the machine names for number based measurements.
*/
function _get_measurement_fields () {
  return array(
      'field_height', 
      'field_weight',
      'field_npc_age',
      );
}

/**
* Generates and returns measurements (e.g. age, weight, height, etc...)
* @param $race string The db-stored value of the race
* @param $gender string The db-stored value of the gender
* @param $df int The Distinquishing Feature of the NPC. This param
*   determins if the resulting measurement should be outside the
*   normal range.
* @return array with the value of the measurement, keyed by the field
*   which stores the value.
*/

function generate_npc_measurements ($race, $df = NULL) {
  // Get the fields that are "measurement fields". These are fields that
  // are stored numerically but have textual descriptors as well.
  $fields = _get_measurement_fields();
  // Get the value for each measurement field.
  $measurements = array(); 
  foreach ($fields as $field) {
    $measurements[$field] = _generate_random_measurement_value($race, $df, $field);
  }
    return $measurements;
}

// Generate the random height
// @param $df Distinguishing Feature
function _generate_random_measurement_value($race, $df, $field) {
  //dpm($df, '$df');
  //dpm($race, '$race passed into _generate_random_measurement_value()');
  //dpm($field, '$field passed into _generate_random_measurement_value()');

  $range = _get_racial_measurements ($race, $field);
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

/**
* $field is the machine_name of the filed to get the measurements for.
*/
function _get_racial_measurements ($race, $field) {
  // If we're missing parameters
  //dpm($race, '$race in _get_racial_measurements()');
  //dpm($field, '$field passed in _get_racial_measurements()');
  if (!isset($race) || !isset($field)) {
    drupal_set_message('Warning: $race or $type not sent to _get_racial_measurements(). Generating bogus range.');
    return array('min' => 46, 'max' => 74);
  }

  // Mapping field names to database names
  //dpm($field, '$field being sent to _get_mapped_db_name()');
  $db_field_type =  _get_mapped_db_name($field);

  $range = array();
  $sql = "SELECT min,max FROM {npc_measurements} WHERE race = :race AND type = :type";
  $range = db_query($sql, array(':type' => $db_field_type, ':race' => $race))->fetchAssoc();
  //dpm($range, '$range');


  return $range;

}

/**
* Returns the db field name from the measurements table that matches the field machine name.
*/
function _get_mapped_db_name ($field) {
  //dpm($field, '$field passed into _get_mapped_db_name()');
  switch ($field) {
    case 'field_height':
      //dpm('in the case');
      $dbfieldname = 'height';
      break;
    case 'field_weight':
      $dbfieldname = 'weight';
      break;
    case 'field_npc_age':
      $dbfieldname = 'age';
      break;
  }
  //dpm($dbfieldname, '$dbfieldname');
  return $dbfieldname;
}

/**
* Gets an array of the strings that describe the various heights.
*/
function _get_descriptor_values ($field) {
  //dpm($field, '$field passed into _get_descriptor_values()');
  switch ($field) {
    case 'field_height':
      return array('diminutive', 'short', 'average', 'tall', 'towering');
      break;
    case 'field_weight':
      return array('cadaverous', 'gaunt', 'slight', 'medium', 'toned', 'husky', 'fat', 'corpulant');
      break;
    case 'field_npc_age':
      return array('young', 'adolescent', 'middle aged', 'elderly', 'geriatric');
      break;
  }
}

/**
* Gets the string value that describes the measurement of the npc.
* $field is the machine name for the field, it will be translated into the db field from the measurements table
*/ 
function _get_racial_measurement_descriptor ($race, $field, $value) {
  //dpm($race, '$race passed in to _get_racial_measurement_descriptor()');
  //dpm($field, '$field passed into _get_racial_measurement_descriptor()');
  //dpm($value, '$value passed in to _get_racial_measurement_descriptor()');
  // Get the range of the measurement for the race
  $range = _get_racial_measurements($race, $field);
  // Get the difference between the min and max
  $diff_range = $range['max']- $range['min'] + 1;
  $diff_min = $value - $range['min'];
  //dpm($range, '$range');
  //dpm($diff_range, '$diff_range');
  //dpm($diff_min, '$diff_min');
  // Get all the descriptors for the type of measurement
  $descriptors = _get_descriptor_values ($field);
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
  //dpm($descriptors[$descriptor_index], 'descriptor for ' . $field);
  return $descriptors[$descriptor_index];
}

