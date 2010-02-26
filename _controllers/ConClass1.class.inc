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
        $output = 'method one content';

        return mvc_view('default', $variables, $output);
    }

    function action_two()
    {
        $output = 'method two content';

        return mvc_view('default', $variables, $output);
    }
}

?>
