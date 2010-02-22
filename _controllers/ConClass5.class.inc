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

class ConClass5{

    function hook_links()
    {
        $var[1] = l('hello','app/ConClass5/hello');
        $var[11] = l('hello log view','app/ConClass5/hello_log_view');

        return $var;
    }
    
    function hello()
    {
        return 'Hello from the world.';
    }
    
    function hello_log($mode)
    {
        
        $variables = array();
        $view = 'default';
        
        switch($mode) 
        {
            // models return a view/model
            case 'create':
                $form = mvc_model('example','get_create');
                
                // things get interesting here because you don't need hook form alter
                unset($form['name']['#description']);
                
                $output = drupal_render($form);
                $view = 'movico';
                break;
            case 'retrieve':
                $variables = mvc_model('example','get_retrieve');
                $view = 'default';
                break;
            case 'update':
                $form = mvc_model('example','get_create');
                
                // things get interesting here because you don't need hook form alter
                $form['submit']['#weight'] = 10;
                
                // doing it a bit different and setting the form into a variable
                $variables['start'] = '<div style="border:1px solid #eaeaea">start</div>'.mvc_access(__function__);
                $variables['myform'] = drupal_render($form);
                $variables['end'] = '<div style="border:1px solid #eaeaea">end</div>';
                $view = 'movico_form';
                break;
            case 'delete':
                mvc_model('example','get_delete');
                $view = 'deleted';
                break;
        }        
            return mvc_view($view, $variables, $output);
    }
    
    function hello_log_view()
    {
            // It is okay to create variables with values here but they should
            // really be part of the model and not here or in the theme template.php
            // file

            $variables['title'] = 'Title';
            $variables['name'] = 'Obama';
            $variables['date'] = '2010/02/14';
            $variables['more'] = 'read';

            return mvc_view('default', $variables);
    }
}

?>
