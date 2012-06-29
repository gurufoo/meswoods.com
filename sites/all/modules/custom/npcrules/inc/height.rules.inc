<?php
// The criteria and setup for determining the height
function generate_npc_height ($form, &$form_state) {
  dpm($form_state['values'], 'values in ()');
  $height = $form_state['values']['field_height']['und'][0]['value'];
  if ($height == '' || !isset($height)) {
    $race = $form_state['values']['field_npc_race']['und'][0]['value'];
    $df = $form_state['values']['field_distinguishing_features']['und'][0]['value'];
    $npc_height = _generate_random_height($race, $df);
  }else {
    $npc_height = $height;
  }
  dpm($npc_height, '$npc_height');
  _npc_setopt('field_height', $npc_height, $form, $form_state);
}

// Generate the random height
// @param $df Distinguishing Feature
function _generate_random_height($race, $df) {
dpm($df, '$df');
  //dpm($race, '$race in _generate_random_name()');
  //dpm($gender, '$gender in _generate_random_name()');
  //$filename = $GLOBALS['_SERVER']['DOCUMENT_ROOT'] . drupal_get_path('module', 'npcrules') . '/inc/names.csv';
  $docroot = $GLOBALS['_SERVER']['DOCUMENT_ROOT'];
  $module_path = drupal_get_path('module', 'npcrules');
  $filename = $docroot . '/' . $module_path . '/inc/heights.csv';
  $file_handle = fopen($filename, "r");
  $height_range = array();
  while (!feof($file_handle)) {
    $line = fgets($file_handle);
    //dpm($line, '$line');
    if (trim($line) != '') {
      $heightarr = explode(',', trim($line));
      //dpm($heightarr, '$heightarr');
      if ($heightarr[0] == $race) {
        $height_range['race']       = $heightarr[0];
        $height_range['min_normal'] = $heightarr[1];
        $height_range['max_normal'] = $heightarr[2];
        $height_range['min_short']  = $heightarr[3];
        $height_range['max_tall']   = $heightarr[4];
      }
    }
  }

  fclose($file_handle);
  dpm($height_range, '$height_range');
  $min = $height_range['min_normal'];
  $max = $height_range['max_normal'];
  if ($df == 'exceptionally_short') {
    $min = $height_range['min_short'];
    $max = $height_range['min_normal'] - 1;
  }else if ($df == 'exceptionally_tall') {
    $min = $height_range['max_normal'] + 1;
    $max = $height_range['max_tall'];
  }
  dpm($min, '$min');
  dpm($max, '$max');
  $option = rand($min, $max);
  return $option;
}

