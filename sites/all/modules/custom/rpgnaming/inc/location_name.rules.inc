<?php

function validate_location_names ($form, &$form_state) {
  dpm('validate_location_names()');
  //dpm($form['#validate'], '#validate');
  //dpm($form_state['values'], 'values in ()');

  // If the user wants a random name, assemble the variables and call the random name function.
  if ($form_state['values']['title'] == 'Choose a random name for me'
      ||
      !isset($form_state['values']['title'])
     ) {
    $type = $form_state['values']['field_location_type']['und'][0]['value'];
    $location_name = _generate_random_location_name($type);
  }else { // The user entered their own name, use it.
    $location_name = $form_state['values']['title'];
  }
  form_set_value($form['title'], $location_name, $form_state);
}



function _generate_random_location_name ($type) {
  switch ($type) {
    case 391:
      $name = _generate_tavern_name();
      break;
    default:
      $name = "Random name for <strong>$type</strong> TBD.";
  }
  return $name;

}


function _generate_tavern_name() {

  $name_type = rand(1,4);

  switch ($name_type) {
    case 1: // Adjective Creature Synonym

      $adj = _get_adjective();
      $creature = _get_creature();
      $synonym = _get_synonym();

      $format = "%s %s %s";
      $name = sprintf($format, ucfirst($adj), strtolower($creature), strtolower($synonym));

      break;
    case 2: // The Verb Creature Synonym
      $verb = _get_verb();
      $creature = _get_creature();
      $synonym = _get_synonym();

      $format = "The %s of the %s %s";
      $name = sprintf($format, ucfirst($synonym), ucfirst($verb), ucfirst($creature));
      break;
    case 3: // Verb Profession Synonym
      $verb = _get_verb();
      $professions = _getopts('field_profession');
      $rnd = array_rand($professions);
      $profession = $professions[$rnd];
      $synonym = _get_synonym();
      $format = "%s %s %s";
      $name = sprintf($format, $verb, $profession, $synonym);

    break;
    case 4: // Profession and the  Creature Synonym
    $professions = _getopts('field_profession');
    $rnd = array_rand($professions);
    $profession = $professions[$rnd];
    $creature = _get_creature();
    $synonym = _get_synonym();
    $format = "The %s and %s %s";
    $name = sprintf($format, $profession, $creature, $synonym);


  }

  return $name;

}

function _get_verb () {
$verbs = array(
'Chopping',
'Digging',
'Drowning',
'Flying',
'Hacking',
'Jumping',
'Laughing',
'Leaping',
'Mumbling',
'Prancing',
'Roaring',
'Running',
'Snickering',
'Soaring',
'Sprinting',
'Swimming',
'Walking',
'Striking',
'Dancing',
'Singing',
'Fighting',
'Diving',
'Climbing',
'Floating',
'Digging',
'Hunting',
'Bouncing',
'Breaking',
'Wailing',
'Rising',

);
$rnd = array_rand($verbs);
return $verbs[$rnd];
}


function _get_synonym () {
$synonyms = array(
'alehouse',
'bar',
'barroom',
'beer joint',
'dive',
'drinkery',
'gin mill',
'grog shop',
'inn',
'lodge',
'lounge',
'pub',
'public house',
'roadhouse',
'saloon',
'taphouse',
'taproom',
'watering hole ',

);
$rnd = array_rand($synonyms);
return $synonyms[$rnd];
}

function _get_creature () {
  $creatures = array(
      'Banshee',
      'Centaur',
      'Changeling',
      'Dragon',
      'Druid',
      'Dwarf',
      'Faerie',
      'Ghost',
      'Ghoul',
      'Giant',
      'Gnome',
      'Gremlin',
      'Griffin',
      'Hellhound',
      'Hydra',
      'Leprechan',
      'Leviathan',
      'Manticore',
      'Mermaid',
      'Minotaur',
      'Nymph',
      'Orc',
      'Phoenix',
      'Satyr',
      'Spectre',
      'Sphinx',
      'Sprite',
      'Succubus',
      'Troll',
      'Unicorn',
      'Vampire',
      'Warlock',
      'Wherewolf',
      'Wight',
      'Witch',
      'Zombie',

      );
      $rnd = array_rand($creatures);
      return $creatures[$rnd];
}

function _get_adjective () {
  $adjectives = array(
    'adorable ',
    'adventurous',
    'aggressive',
    'agreeable ',
    'alert ',
    'amused ',
    'angry ',
    'annoyed ',
    'anxious ',
    'arrogant ',
    'ashamed ',
    'attractive',
    'average ',
    'awful ',
    'bad ',
    'beautiful ',
    'bewildered ',
    'bitter',
    'black',
    'bloody ',
    'blue',
    'blue-eyed',
    'blushing ',
    'boiling ',
    'bored ',
    'brave ',
    'breezy ',
    'bright ',
    'broken ',
    'bumpy ',
    'calm ',
    'charming ',
    'cheerful ',
    'chilly ',
    'clean ',
    'clear ',
    'cloudy ',
    'clumsy',
    'cold ',
    'colorful ',
    'combative ',
    'comfortable ',
    'condemned ',
    'confused ',
    'cool ',
    'cooperative ',
    'courageous ',
    'crazy',
    'creepy ',
    'creepy ',
    'crooked ',
    'crowded ',
    'cruel ',
    'cuddly ',
    'curly ',
    'cute ',
    'damaged ',
    'damp ',
    'dangerous ',
    'dark ',
    'defeated ',
    'defiant ',
    'delicious',
    'delightful ',
    'depressed ',
    'determined ',
    'dirty ',
    'disgusted ',
    'distinct ',
    'disturbed ',
    'dizzy',
    'drab ',
    'dry ',
    'dull',
    'dull ',
    'dusty ',
    'eager ',
    'elated ',
    'elegant ',
    'embarrassed ',
    'enchanting ',
    'encouraging ',
    'energetic ',
    'enthusiastic ',
    'envious ',
    'evil ',
    'excited',
    'excited ',
    'exuberant ',
    'fair ',
    'faithful ',
    'fancy ',
    'fantastic ',
    'fierce ',
    'filthy',
    'filthy ',
    'fine ',
    'flaky ',
    'fluffy ',
    'fluttering',
    'foolish ',
    'frantic ',
    'freezing',
    'fresh',
    'friendly ',
    'frightened',
    'funny ',
    'fuzzy',
    'gentle ',
    'glamorous ',
    'gleaming ',
    'glorious',
    'good ',
    'gorgeous',
    'graceful ',
    'greasy',
    'grieving',
    'grotesque ',
    'grubby',
    'grumpy',
    'handsome',
    'happy ',
    'hard',
    'healthy ',
    'helpful ',
    'helpless ',
    'hilarious ',
    'homeless ',
    'homely ',
    'hot',
    'hot',
    'hungry ',
    'hurt ',
    'icy',
    'ill ',
    'itchy',
    'jealous ',
    'jittery',
    'jolly ',
    'joyous ',
    'juicy',
    'kind ',
    'lazy',
    'light ',
    'lively ',
    'lonely ',
    'long',
    'loose',
    'lovely ',
    'lucky ',
    'magnificent',
    'melted',
    'misty ',
    'motionless ',
    'muddy ',
    'mysterious',
    'nasty',
    'naughty ',
    'nervous ',
    'nice',
    'nutritious',
    'nutty',
    'obedient ',
    'obnoxious ',
    'old-fashioned',
    'outrageous ',
    'panicky ',
    'perfect ',
    'plain ',
    'pleasant ',
    'poised ',
    'precious',
    'prickly',
    'proud ',
    'quaint ',
    'rainy',
    'relieved ',
    'repulsive ',
    'ripe',
    'rotten',
    'rough',
    'salty',
    'scary ',
    'scattered',
    'selfish ',
    'shaggy',
    'shaky',
    'sharp',
    'shiny ',
    'shivering',
    'silky',
    'silly ',
    'slimy',
    'slippery',
    'smiling ',
    'smoggy ',
    'smooth',
    'soft',
    'solid',
    'sore ',
    'sour',
    'sparkling ',
    'spicy',
    'splendid ',
    'spotless ',
    'stale',
    'steady',
    'sticky',
    'sticky',
    'stormy ',
    'strange ',
    'strong',
    'successful ',
    'sweet',
    'tart',
    'tasteless',
    'tasty',
    'tender',
    'tense ',
    'terrible ',
    'testy',
    'thankful',
    'thirsty',
    'thoughtful ',
    'thoughtless ',
    'tight',
    'tired ',
    'troubled ',
    'ugliest',
    'ugly ',
    'uneven',
    'unsightly ',
    'unusual',
    'upset ',
    'uptight ',
    'victorious ',
    'vivacious ',
    'warm',
    'weak',
    'weary ',
    'wet',
    'wet',
    'wicked ',
    'wide-eyed',
    'witty ',
    'wonderful ',
    'wooden',
    'worried',
    'yummy',
    'zany',
    'zealous ',

    );
  $rnd = array_rand($adjectives);
  return $adjectives[$rnd];
}
