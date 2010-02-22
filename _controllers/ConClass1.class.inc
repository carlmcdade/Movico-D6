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
        $var['one'] = l('link text(1)','app/ConClass5/hello');
        $var['two'] = l('link text(11)','app/ConClass5/hello_log_view');

        return $var;
    }

    function hook_forms()
    {
        $var['sho'] = l('form element','app/helloworld/hello_log/update');
        $var['foo'] = l('form element','app/helloworld/hello_log/create');

        return $var;
    }
}

?>
