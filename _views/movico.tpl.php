<?php
    
drupal_set_message('movico template message!');

	$output = '<div style="clear:both"> This is a new template for the search form.</div>';
	$output .= drupal_render($form);
    echo $output;
	
?>
