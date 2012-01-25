<?php

class example{
    
    function get_retrieve() {
             
        $sql = "SELECT all FROM table_one WHERE state='human'";
        return $sql;
    }
    
    function get_create() {
    	
    	$sql = "INSERT all FROM table_one WHERE state='cloning'";
        return $sql;
             
    }
    
    function get_update() {
    	
    	$sql = "UPDATE all SET dna_checked='TRUE' WHERE state='meta-human'";
        return $sql;
             
    }

}



?>
