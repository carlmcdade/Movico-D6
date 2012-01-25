<?php

/*
 * @author Carl McDade
 * @copyright Copyright (c) 2010, Carl McDade
 * @since 2010-02-19
 * @version 0.2
 * @license http://opensource.org/licenses/gpl-license.php GNU Public License
 * @link http://www.drupal.se Drupal Sweden
 *
 */


class ConClass1{
	
	private $common;


    function __construct()
    {
        //Test the Common settings
        $this->common = Common::get_instance();
    }

    function hook_links()
    {
        $var['one'] = l('class_one(1)','app/ConClass1/action_one');
        $var['two'] = l('class_one(2)','app/ConClass1/action_two');

        return $var;
    }

    function hook_forms()
    {
        $var['sho'] = l('form element','app/helloworld/hello_log/update');
        $var['foo'] = l('form element','app/helloworld/hello_log/create');

        return $var;
    }

    function action_one()
    {
        $output = implode(' | ', $this->common->get_hooks('hook_links'));
        $output .= '<br />';
    	$output .= 'method one content';

        return mvc_view('default', $variables, $output);
    }

    function action_two()
    {
        //some variables to load into the view will appear as $[variable name]
        $variables['start'] = '<div style="border:1px solid #eaeaea">start</div>'.mvc_access(__function__);
        $variables['my_array'] = array('one','ton','son');
        $variables['end'] = '<div style="border:1px solid #eaeaea">end</div>';
    	
    	$output = implode(' | ', $this->common->get_hooks('hook_links'));
        $output .= '<br />';
    	$output .= 'method two content';

        return mvc_view('default', $variables, $output);
    }
}

?>
