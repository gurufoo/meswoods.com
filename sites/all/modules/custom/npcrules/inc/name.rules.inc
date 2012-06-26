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
 								$npc_name = _generate_random_name($race, $gender, $form, $form_state);
				}else {
					$npc_name = $form_state['values']['title'];
}
form_set_value($form['title'], $npc_name, $form_state);
}

function _generate_random_name($race, $gender) {
				//dpm($race, '$race in _generate_random_name()');
				//dpm($gender, '$gender in _generate_random_name()');
				//$filename = $GLOBALS['_SERVER']['DOCUMENT_ROOT'] . drupal_get_path('module', 'npcrules') . '/inc/names.csv';
				$docroot = $GLOBALS['_SERVER']['DOCUMENT_ROOT'];
				$module_path = drupal_get_path('module', 'npcrules');
				$filename = $docroot . '/' . $module_path . '/inc/names.csv';
				$file_handle = fopen($filename, "r");
				$names = array();
				while (!feof($file_handle)) {
								$line = fgets($file_handle);
								//dpm($line, '$line');
								if (trim($line) != '') {
												$namearr = explode(',', trim($line));
												if ($namearr[1] == $race && $namearr[2] == $gender) {
																$names[$namearr[0]]['race'] = $namearr[1];
																$names[$namearr[0]]['gender'] = $namearr[2];
												}
								}
				}

				fclose($file_handle);
				//dpm($names, '$names');
				$option = array_rand($names);
				return $option;
}

