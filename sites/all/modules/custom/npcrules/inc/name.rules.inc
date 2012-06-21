<?php

function generate_npc_name ($form, &$form_state) {
				//dpm($form_state['values'], 'values in ()');
				if (
												$form_state['values']['title'] == 'Choose a random name for me'
												||
												!isset($form_state['values']['title'])
					 ) {
								$race = $form_state['values']['field_npc_race']['und'][0]['value'];
								$gender = $form_state['values']['field_gender']['und'][0]['value'];
 								$random_name = _generate_random_name($race, $gender);
								dpm('TODO: Generate a random name');
				}else {
								dpm('Use the name provided');
				}
}

function _generate_random_name($race, $gender) {
	//dpm($race, '$race in _generate_random_name()');
	//dpm($gender, '$gender in _generate_random_name()');
}

