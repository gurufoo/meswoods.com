<?php

function generate_npc_name ($form, &$form_state) {
  //dpm('begin generate_npc_name()');
  //dpm($form['#validate'], '#validate');
  //dpm($form_state['values'], 'values in ()');
  
  if (
      $form_state['values']['title'] == 'Choose a random name for me'
      ||
      !isset($form_state['values']['title'])
     ) {

    //dpm('pick a random name');
    $race = $form_state['values']['field_npc_race']['und'][0]['value'];
    $gender = $form_state['values']['field_gender']['und'][0]['value'];
    $npc_name = _generate_random_name($race, $gender);
    

  }else {
    $npc_name = $form_state['values']['title'];
  }
  form_set_value($form['title'], $npc_name, $form_state);

}

function _generate_random_name($race, $gender) {
  //dpm($race, '$race in _generate_random_name()');
  //dpm($gender, '$gender in _generate_random_name()');

  $query = "SELECT givenname FROM name_npc_given WHERE race = :race AND gender = :gender ORDER BY RAND() LIMIT 1";
  $args = array(':race' => $race, ':gender' => $gender);
  $given_name = db_query($query, $args)->fetchField();


  switch ($race) {
    case 'dwarf':
      $given_name = _generate_dwarf_given($gender);
      dpm($given_name);
      $display_type = rand(1,2);

      switch ($display_type) {
        case 1: // Given [Creature]bane

          $query = "SELECT creature FROM creatures ORDER BY RAND() LIMIT 1";
          $creature = db_query($query)->fetchField();

          $format = "%s %sbane";  
          $name = sprintf($format, ucfirst($given_name), ucfirst($creature));

          break;

        case 2: // Given [stone][weapon]

          $query = "SELECT noun FROM nouns_stone ORDER BY RAND() LIMIT 1";
          $stone = db_query($query)->fetchField();
          $query = "SELECT noun FROM nouns_weapon ORDER BY RAND() LIMIT 1";
          $weapon = db_query($query)->fetchField();

          $format = "%s %s%s";
          $name = sprintf($format, ucfirst($given_name), ucfirst($stone), strtolower($weapon));

          break;
      }

      break;

    case 'elf':
    $given_name = _generate_elf_given($gender);
      // Given [color][nature]
      $format = "%s %s%s";
      $query = "SELECT color FROM colors WHERE color NOT IN ('Purple') ORDER BY RAND() LIMIT 1";
      $color = db_query($query)->fetchField();

      $query = "SELECT noun FROM nouns_nature ORDER BY RAND() LIMIT 1";
      $nature = db_query($query)->fetchField();

      $name = sprintf($format, $given_name, ucfirst($color), strtolower($nature));
      break;

    default:
      $name = $given_name;
  }

  return $name;
}


function _get_consonants () {
  return array('b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z');
}

function _get_vowels() {
  return array('a','e','i','o','u');
}

function _generate_dwarf_given ($gender = 'male') {
  //dpm(_get_consonants());
  //dpm(_get_vowels());
  $consonants = _get_consonants();
  $vowels = _get_vowels();
  $nostarts = array(12,18);
  foreach ($nostarts as $nostart) {
    unset($consonants[$nostart]); // Dwarf names don't start with some letters
  }
  $firsts = array('k', 'r','m');
  if ($gender == 'male') {
  $suffixes = array('dek', 'tak', 'kon', 'tok', 'kron', 'kin', 'ard', 'nan', 'ril', 'has', 'ros', 'ian', 'ter', 'orn', 'ver', 'ry', 'on', 'kas', 'ben');
  } else {
    $suffixes= array('ath', 'ove', 'ys', 'ynn');
  }
  $names = array();
  foreach ($consonants as $c) {
    foreach ($vowels as $v) {
      foreach ($suffixes as $s) {
        foreach ($firsts as $f) {
          //dpm($c . $v . $f . $s, $i);
          //$i++;
          $names[] = $c . $v . $f . $s;
        }
      }
    }
  }
  $index = array_rand($names);
  return $names[$index];
}

function _generate_elf_given ($gender = 'male') {
  $consonants = _get_consonants();
  $vowels = _get_vowels();
  $firsts = array('n', 'l', 'ra', 'g');
  if ($gender == 'male') {
  $suffixes = array('dir', 'egnor', 'iros', 'ithas', 'olas');
  } else {
    $suffixes = array('la', 'ja', 'tath');
  }
   $names = array();
  foreach ($consonants as $c) {
    foreach ($vowels as $v) {
      foreach ($suffixes as $s) {
        foreach ($firsts as $f) {
          //dpm($c . $v . $f . $s, $i);
          //$i++;
          $names[] = $c . $v . $f . $s;
        }
      }
    }
  }
 //dpm($names);
 $index = array_rand($names);
 return ucfirst($names[$index]);
}
