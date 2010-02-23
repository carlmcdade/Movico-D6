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
 * This is a Singleton because there is no need to have more than one instance
 * and hooks should always be created from a single area. At present Drupal modules
 * can create hooks from anywhere which leads to confusion
 *
 */

class Common{

    static private $_instance;
    private $data = array();


    protected function __construct()
    {
        //Please extend this class to gain that functionality
    }

    final public function __clone()
    {
        throw new Exception('Please extend this Class to gain that functionality');
    }

    final public static function get_instance()
    {
        return isset(self::$_instance) ? self::$_instance : self::$_instance = new self();
    }


    function get_hooks($modules, $hook = NULL)
    {
        $output = array();

        // Need to get the name of the Class that is calling this function
        // Call its hook function directly and merge the result
        // This will prevent a infinate loop caaused by the use of a constuctor


        foreach ($modules as $module)
        {
            $Class = new ReflectionClass($module);
            
            // hook may not exist in all modules. Handle exception with 
            // continue
            
            try
            {
                $Method = new ReflectionMethod($Class->getName(), $hook);
            }
            catch(Exception $e)
            {
                continue;
            }
            
            $Instance = $Class->newInstance();
            

            /*
             * 
             * Static methods do not require a Class instance
             * Invoking a private method is not allowed. 
             * The exception is handled by ignoring the method and continuing on
             * 
             */

            if ($Method->isStatic())
            {
                $Instance = NULL;
            }
                
            try
            {
                $output = array_merge($output, $Method->invoke($Instance));
            }
            catch(Exception $e)
            {
                trigger_error('You are attempting to use a private method.');
                continue;
            }
             
        }

        $this->data = $output;
        return $this->data;
    }

    function get_all_hooks($modules, $hooks = array())
    {
        $output = array();

        foreach ($hooks as $hook)
        {
            $output[$hook] = $this->get_hooks($modules, $hook);
        }

        $this->data = $output;
        return $this->data;
    }
}

?>
