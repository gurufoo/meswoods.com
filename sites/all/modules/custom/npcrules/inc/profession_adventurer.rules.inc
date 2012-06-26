<?php

function profession_adventurer_unlikely ($form, &$form_state) {	
				if (_rollpercentile(15)) { // 15% chance that an npc has an adventuring profession
								// Get the list of adventurer professions
								$profession_adventurer_options = _getopts($form, 'field_profession_adventurer');
								// don't let "None" be an option
								unset($profession_adventurer_options['_none']);
								// Choose an adventuring profession
								$option = array_rand($profession_adventurer_options);
								_npc_setopt('field_profession_adventurer', $option, $form, $form_state);
								// Adventureers don't have time for mundane professions...
								_npc_setopt('field_profession_mundane', '_none', $form, $form_state);
				}	else { // Nope, not the adventuring sort, just a mundane profession
								_npc_setopt('field_profession_adventurer', '_none', $form, $form_state);
				}
}
