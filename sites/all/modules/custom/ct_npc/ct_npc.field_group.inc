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
  $field_group->identifier = 'group_npc_general|node|npc|form';
  $field_group->group_name = 'group_npc_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'npc';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_npc_main_group';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '17',
    'children' => array(
      0 => 'field_gender',
      1 => 'field_npc_race',
      2 => 'field_profession_mundane',
      3 => 'field_profession_adventurer',
      4 => 'field_alignment',
      5 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_npc_general|node|npc|form'] = $field_group;

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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_npc_main_group|node|npc|form';
  $field_group->group_name = 'group_npc_main_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'npc';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Group',
    'weight' => '0',
    'children' => array(
      0 => 'group_npc_general',
      1 => 'group_npc_physical',
      2 => 'group_npc_social',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_npc_main_group|node|npc|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_npc_physical|node|npc|form';
  $field_group->group_name = 'group_npc_physical';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'npc';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_npc_main_group';
  $field_group->data = array(
    'label' => 'Physical',
    'weight' => '18',
    'children' => array(
      0 => 'field_facial_hair_style',
      1 => 'field_hair_color',
      2 => 'field_distinguishing_features',
      3 => 'field_height',
      4 => 'field_weight',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_npc_physical|node|npc|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_npc_social|node|npc|form';
  $field_group->group_name = 'group_npc_social';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'npc';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_npc_main_group';
  $field_group->data = array(
    'label' => 'Social',
    'weight' => '19',
    'children' => array(
      0 => 'field_npc_mannerisms',
      1 => 'field_motivation',
      2 => 'field_instinct',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_npc_social|node|npc|form'] = $field_group;

  return $export;
}
