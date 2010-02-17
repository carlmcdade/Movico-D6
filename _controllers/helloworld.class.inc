<?php

class helloworld {
    
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
        // Create variables here because they become part of the module not the theme template.php file
        $variables['title'] = 'Title';
        $variables['name'] = 'Obama';
        $variables['date'] = '2010/02/14';
        $variables['more'] = 'read';
        
        return mvc_view('default', $variables);
	}
}

?>
