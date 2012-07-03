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
  $field_group->identifier = 'group_npc_basics|node|npc|form';
  $field_group->group_name = 'group_npc_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'npc';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_npc_general';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '23',
    'children' => array(
      0 => 'field_gender',
      1 => 'field_npc_race',
      2 => 'field_alignment',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Basics',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_npc_basics|node|npc|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_npc_body|node|npc|form';
  $field_group->group_name = 'group_npc_body';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'npc';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_npc_physical';
  $field_group->data = array(
    'label' => 'Body',
    'weight' => '30',
    'children' => array(
      0 => 'field_height',
      1 => 'field_weight',
      2 => 'field_skin_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Body',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_npc_body|node|npc|form'] = $field_group;

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
    'label' => 'General Information',
    'weight' => '17',
    'children' => array(
      0 => 'title',
      1 => 'group_npc_profession',
      2 => 'group_npc_basics',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'General Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
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
  $field_group->parent_name = 'group_npc_physical';
  $field_group->data = array(
    'label' => 'Hair',
    'weight' => '31',
    'children' => array(
      0 => 'field_facial_hair_style',
      1 => 'field_hair_color',
      2 => 'field_hair_style',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Hair',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
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
    'label' => 'Physical Description',
    'weight' => '18',
    'children' => array(
      0 => 'group_npc_hair',
      1 => 'group_npc_body',
      2 => 'group_physical_other',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Physical Description',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_npc_physical|node|npc|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_npc_profession|node|npc|form';
  $field_group->group_name = 'group_npc_profession';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'npc';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_npc_general';
  $field_group->data = array(
    'label' => 'Profession',
    'weight' => '24',
    'children' => array(
      0 => 'field_profession_mundane',
      1 => 'field_profession_adventurer',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Profession',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_npc_profession|node|npc|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_npc_social_1|node|npc|form';
  $field_group->group_name = 'group_npc_social_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'npc';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_npc_social';
  $field_group->data = array(
    'label' => 'Social 1',
    'weight' => '37',
    'children' => array(
      0 => 'field_npc_mannerisms',
      1 => 'field_motivation',
      2 => 'field_instinct',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Social 1',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_npc_social_1|node|npc|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_npc_social_2|node|npc|form';
  $field_group->group_name = 'group_npc_social_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'npc';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_npc_social';
  $field_group->data = array(
    'label' => 'Social 2',
    'weight' => '38',
    'children' => array(
      0 => 'field_npc_approach',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Social 2',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_npc_social_2|node|npc|form'] = $field_group;

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
    'label' => 'Social Interactions',
    'weight' => '20',
    'children' => array(
      0 => 'group_npc_social_1',
      1 => 'group_npc_social_2',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Social Interactions',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_npc_social|node|npc|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_physical_other|node|npc|form';
  $field_group->group_name = 'group_physical_other';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'npc';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_npc_physical';
  $field_group->data = array(
    'label' => 'Other',
    'weight' => '33',
    'children' => array(
      0 => 'field_distinguishing_features',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Other',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_physical_other|node|npc|form'] = $field_group;

  return $export;
}
