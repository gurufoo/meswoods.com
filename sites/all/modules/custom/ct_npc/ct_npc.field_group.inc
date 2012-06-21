<?php
/**
 * @file
 * ct_npc.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ct_npc_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_npc_hair|node|npc|form';
  $field_group->group_name = 'group_npc_hair';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'npc';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hair',
    'weight' => '3',
    'children' => array(
      0 => 'field_facial_hair_style',
      1 => 'field_hair_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_npc_hair|node|npc|form'] = $field_group;

  return $export;
}
