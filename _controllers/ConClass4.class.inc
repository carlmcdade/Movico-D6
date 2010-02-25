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

        //Test the Common settings
        $common = Common::get_instance();
        
        $common->var_set("appname", "movico is damn cool!");
        $common->var_set("trial", "error");
        

        $output = implode(' | ', $common->get_hooks('hook_links'));
        $output .= '<pre>' . print_r($common->get_all_hooks(), 1) . '</pre>';

        $output .= '<br />';
        $output .= $common->var_get("trial");

        $common->var_delete('appname');

        $common->var_set("trial", " new new error");

        $output .= '<br />';
        $output .= $common->var_get("trial");


        $output .= '<br />';
        $output .= $common->var_get("appname");

        $output .= '<br />';
        $output .= $common->var_get("password");
        

        $common->var_set('truck', "catapiller");

        $output .= '<br />';
        $output .= $common->var_get("truck") . '<br />' . ' print';

        $common->var_set("trial", "a new error");
        
        
        return mvc_view('default', $variables, $output);
        
    }
}

?>