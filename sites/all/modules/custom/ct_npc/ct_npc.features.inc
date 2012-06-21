<?php
/**
 * @file
 * ct_npc.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ct_npc_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ct_npc_node_info() {
  $items = array(
    'npc' => array(
      'name' => t('NPC'),
      'base' => 'node_content',
      'description' => t('Non Player Character'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
