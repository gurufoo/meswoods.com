<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */



/**
* This function can be called with different variables passed in. When called from a view template
* the param is a number (inches). When called from a  field template the param is a deep array.
*/
function rpg_field__field_height($variables) {
  if (!is_array($variables)) {
    $total_inches = $variables;
  }else if (is_array($variables)) {
    $total_inches = $variables['element']['#items'][0]['value'];
  }
  return _inches_display($total_inches);
}


function _inches_display ($total_inches) {
  $feet = floor($total_inches/12);
  $remaining_inches = $total_inches%12;
  $display = "$feet' $remaining_inches\"";
  return $display;
}


function rpg_field__field_npc_mannerisms($variables, $node = NULL) {

  if (is_array($variables)) {
    //dpm('Array');
    $node = $variables['element']['#object'];
    $mannerisms = $variables['element'][0]['#markup'];
    //dpm($variables['element']);
    //dpm($mannerisms, '$mannerisms with array');
  }else if (!is_array($variables)) {
    //dpm('Not Array');
    $mannerisms = $variables;
  }
  return _placeholder_display($mannerisms, $node);
}



