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
    $max--; // The tallest an exceptionally short person can be is 1 inche shorter than the racial minimum
    $min = floor($min * 0.85); // The shortest an exceptionally short person can be is 3/4 the racial minimum
  }else if ($df == 74) { // Exceptionally Tall
    $min = $max + 1;
    $max = ceil($max * 1.15);
  }
  //dpm($min, '$min');
  //dpm($max, '$max');
  $option = rand($min, $max);
  return $option;
}

function _get_racial_measurements ($race, $type) {
  // If we're missing parameters
  if (!isset($race) || !isset($type)) {
    drupal_set_message('Warning: $race or $type not sent to _get_racial_measurements(). Generating bogus range.');
    return array('min' => 46, 'max' => 74);
  }
  $range = array();
  $range['dwarf']['height']['min'] = 51;
  $range['dwarf']['height']['max'] = 57;

  $range['elf']['height']['min'] = 64;
  $range['elf']['height']['max'] = 72;

  $range['halfling']['height']['min'] = 46;
  $range['halfling']['height']['max'] = 50;

  //$range['']['height']['min'] = ;
  //$range['']['height']['max'] = ;


  return $range[$race][$type];

}

function _get_racial_measurement_descriptor ($race, $type) {

}

