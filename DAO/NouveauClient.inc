<?php
    function NouveauClient(){
        $nc = fopen("../Resources/Client.txt","a");
        $cpt = $GLOBALS['cin']."|".$GLOBALS['ads']."|".$GLOBALS['nom']."|".$GLOBALS['pre']."\n";
        fputs($nc,$cpt);
        fclose($nc);
    }
?>