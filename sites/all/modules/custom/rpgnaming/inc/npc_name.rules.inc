<?php

function generate_npc_name ($form, &$form_state) {
  dpm('begin generate_npc_name()');
  //dpm($form['#validate'], '#validate');
  //dpm($form_state['values'], 'values in ()');
  
  if (
      $form_state['values']['title'] == 'Choose a random name for me'
      ||
      !isset($form_state['values']['title'])
     ) {

    dpm('pick a random name');
    $race = $form_state['values']['field_npc_race']['und'][0]['value'];
    $gender = $form_state['values']['field_gender']['und'][0]['value'];
    $npc_name = _generate_random_name($race, $gender);
    

  }else {
    $npc_name = $form_state['values']['title'];
  }
  form_set_value($form['title'], $npc_name, $form_state);

}

function _generate_random_name($race, $gender) {
  dpm($race, '$race in _generate_random_name()');
  dpm($gender, '$gender in _generate_random_name()');
  
  $query = "SELECT givenname FROM name_npc_given ORDER BY RAND() LIMIT 1";
  $given_name = db_query($query)->fetchField();

  $query = "SELECT creature FROM creatures ORDER BY RAND() LIMIT 1";
  $creature = db_query($query)->fetchField();

  $name = ucfirst($given_name) . ' ' . ucfirst($creature) . 'bane';

  dpm($given_name);
  dpm($creature);

  return $name;
}

