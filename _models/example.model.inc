<?php

class example{
    
    function get_retrieve() {
             
        $variables['usage'] = '50%';
        $variables['limits'] = 'none';
        
        return $variables;
    }
    
    function get_create($form_state) {
             
      // Access log settings:
      $options = array('1' => t('Enabled'), '0' => t('Disabled'));
      $form['access'] = array(
        '#type' => 'fieldset',
        '#title' => t('Access log settings'),
        '#tree' => TRUE,
      );
      $form['access']['log'] = array(
        '#type' => 'radios',
        '#title' => t('Log'),
        '#default_value' =>  variable_get('log', 0),
        '#options' => $options,
        '#description' => t('The log.'),
      );
      $period = drupal_map_assoc(array(3600, 10800, 21600, 32400, 43200, 86400, 172800, 259200, 604800, 1209600, 2419200, 4838400, 9676800), 'format_interval');
      $form['access']['timer'] = array(
        '#type' => 'select',
        '#title' => t('Discard logs older than'),
        '#default_value' => variable_get('timer', 259200),
        '#options' => $period,
        '#description' => t('The timer.'),
      );
      // Description
      $form['details'] = array(
        '#type' => 'fieldset',
        '#title' => t('Details'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form['details']['description'] = array(
        '#type' => 'textarea',
        '#title' => t('Describe it'),
        '#default_value' =>  variable_get('description', ''),
        '#cols' => 60,
        '#rows' => 5,
        '#description' => t('Log description.'),
      );
      $form['details']['admin'] = array(
        '#type' => 'checkbox',
        '#title' => t('Only admin can view'),
        '#default_value' => variable_get('admin', 0),
      );
      $form['name'] = array(
        '#type' => 'textfield',
        '#title' => t('Name'),
        '#size' => 30,
        '#maxlength' => 64,
        '#description' => t('Enter the name for this group of settings'),
      );
      $form['hidden'] = array('#type' => 'value', '#value' => 'is_it_here');
      $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));
      
      return $form;

    }
    
    

}



?>
