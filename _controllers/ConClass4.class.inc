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

/*
 * Normally the Classes would be in individual files and loaded via an iterator
 *
 */

class ConClass4{


    function hook_links()
    {
        $var['nksj'] = l('update','app/ConClass5/hello_log/update');
        $var['nksk'] = l('create','app/ConClass5/hello_log/create');

        return $var;
    }

    function hook_forms()
    {
        $var['ormu'] = l('form element','app/ConClass5/hello_log/update');
        $var['ormb'] = l('form element','app/ConClass5/hello_log/create');

        return $var;
    }

    function action3()
    {      
        global $hook_links, $hook_all;

        $output = implode(' | ', $hook_links);
        $output .= '<pre>' . print_r($hook_all, 1) . '</pre>';
        

        return mvc_view('default', $variables, $output);
    }
}

?>