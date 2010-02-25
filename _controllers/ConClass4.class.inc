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

    private $common;


    function __construct()
    {
        //Test the Common settings
        $this->common = Common::get_instance();
    }


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

    function test_me()
    {      
        
        $this->common->var_set("appname", "movico is damn cool!");
        $this->common->var_set("trial", "error");
        $this->common->var_set("password", array('user', 'pass'));

        $output = implode(' | ', $this->common->get_hooks('hook_links'));
        $output .= '<pre>' . print_r($this->common->get_all_hooks(), 1) . '</pre>';

        $output .= '<br />';
        $output .= $this->common->var_get("trial");

        $this->common->var_set("trial", "tribulations");

        $output .= '<br />';
        $output .= $this->common->var_get("trial");

        $output .= '<br />';
        $output .= $this->common->var_get("appname");

        $output .= '<br />';
        $output .= implode(' ', $this->common->var_get("password"));

        $this->common->var_set("truck", "catapiller tractors");

        $output .= '<br />';
        $output .= $this->common->var_get("truck");
        
        return mvc_view('default', $variables, $output);
        
    }
}

?>