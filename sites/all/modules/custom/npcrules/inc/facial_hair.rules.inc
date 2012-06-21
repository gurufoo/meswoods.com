<?php

/**
 * Females don't have facial  hair
 */
function facial_hair_female_no_hair ($form, &$form_state) {
//dpm($form_state, '$form_state');
  if ($form_state['values']['field_gender']['und'][0]['value'] == 'female') {
    form_set_value($form['field_facial_hair_style'], array('und' => array(0 => array('value' => 'none'))), $form_state);
  }
}

/**
 *Male Dwarves have are likely to have facial hair
 */
function facial_hair_male_dwarf_likely ($form, &$form_state) {
  if (
      $form_state['values']['field_gender']['und'][0]['value'] == 'male'
      &&
      $form_state['values']['field_npc_race']['und'][0]['value'] == 'dwarf'
      &&
      is_null($form_state['values']['field_facial_hair_style']['und'][0]['value'])
      )
    {
      
      if (_rollpercentile(85)) { // 85% chance that this dwarf will have facial hair.
        $facial_hair_options = _getopts($form, 'field_facial_hair_style');
        foreach ($facial_hair_options as $key => $option) {
          if ($key == '_none' || $key == 'none') {
            unset($facial_hair_options[$key]);
          }
        }
        $option = array_rand($facial_hair_options);
        form_set_value($form['field_facial_hair_style'], array('und' => array(0 => array('value' => $option))), $form_state);
      }
    }
}