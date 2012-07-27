<?php

/**
 * Females don't have facial  hair
 */
function validate_female_facial_hair ($form, &$form_state) {
  $gender = $form_state['values']['field_gender']['und'][0]['value'];
  $facial_hair = female_no_facial_hair($gender);
  if ($facial_hair) {
    _setopt('field_facial_hair_style', $facial_hair, $form, $form_state);
  }
}
/**
* Helper function.  This is so simple as to be overkill, but the point
* is that valication logic must be performed in helper fucntions because
* the logic could need to operate from a core node submit, or from a
* programatically generated node, in which case there is no $form_state
* to simply modify.
*/
function female_no_facial_hair ($gender) {
  if ($gender == 'female') {
    return '_none';
  } else {
    return FALSE;
  }
}



/**
 *Male Dwarves have are likely to have facial hair
 */
function validate_maile_dwarf_facial_hair_likely ($form, &$form_state) {
  $gender = $form_state['values']['field_gender']['und'][0]['value'];
  $race = $form_state['values']['field_npc_race']['und'][0]['value'];
  $facial_hair = $form_state['values']['field_facial_hair_style']['und'][0]['value'];
  $option = male_dwarf_facial_hair_likely ($gender, $race, $facial_hair);
  _setopt('field_facial_hair_style', $option, $form, $form_state);
}

/**
* Helper function to determine the likelyhood of a dwarf having facial hair.
*/
function male_dwarf_facial_hair_likely ($gender, $race, $facial_hair) {
  
  // What?! A dwarf without facial hair?  Not likely.  Literally ;^)
  if ($gender = 'male' && $race == 'dwarf' && $facial_hair == '_none') {
    if (_rollpercentile(85)) { // 85% chance that this dwarf will have facial hair.
      drupal_set_message('Assigning this self respecting dwarf some chin locks...');
      $facial_hair_options = _getopts('field_facial_hair_style');
      unset($facial_hair_options['_none']);
      $option = array_rand($facial_hair_options);
      $facial_hair = $option;
    }
  }
  return $facial_hair;
}

