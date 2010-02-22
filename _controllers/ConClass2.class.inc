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


class ConClass2 {

    function hook_links()
    {
        $var[2] = 'link text(2)';
        $var[22] = 'link text(22)';

        return $var;
    }
}

?>
