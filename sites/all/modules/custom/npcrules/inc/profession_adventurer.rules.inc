<?php

function profession_adventurer_unlikely ($form, &$form_state) {
  // Get the list of professions
  $profession_options = $form_state['values']['field_profession'];
  dpm($profession_options, '$profession_options');
  foreach ($profession_options['und'] as $option) {
    dpm($option['value'], '$option');
  }
  $options = array();
  $adventurer_professions = array(
      399 => 399, 
      398 => 398,
      395 => 395, 
      397 => 397, 
      396 => 396);
  $mundane_professions = $profession_options;
  foreach ($adventurer_professions as $key => $profession) {
    unset($mundane_professions[$key]);
  }

  if (_rollpercentile(15)) { // 15% chance that an npc has an adventuring profession
    dpm($adventurer_professions, 'We will be an adventurer');
    $profession = array_rand($adventurer_professions);
  }	else { // Nope, not the adventuring sort, just a mundane profession
    dpm($mundane_professions, 'Not an adventurer');
    $profession = array_rand($mundane_professions);
  }
  dpm($profession, '$profession');
  _setopt('field_profession', $profession, $form, $form_state);
}
