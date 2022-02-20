<?php

    require "Client.inc";

    function ExisteCompte($cin){
        $fc = fopen("../Resources/Compte.txt","r");
        $lire = fread($fc,10000);
        $cherche = strpos($lire,$cin);
        $trv = 0;
        if($cherche){
            $trv = 1;
        }
        fclose($fc);
        return $trv;
    }

    function NouveauCompte($cin,$num,$montant){
        $nc = fopen("../Resources/Compte.txt","a");
        $trv = 0;
        if((ExisteClient($cin) != NULL) && (ExisteCompte($num) == NULL)){
            $cpt = $num."|".$cin."|".$montant."\r";
            fputs($nc,$cpt);
            echo("<script>alert('Success');</script>");
            $trv = 1;
        }
        else
            echo("<script>alert('Ce compte existe deja.');</script>");
        fclose($nc);
        return $trv;
    }

    function Virement($x, $y){
        $fp = file("../Resources/Compte.txt");
        $trouve = 0;
        foreach($fp as $index=>$line) { 
            $row = explode("|", $line);
            if ($row[0] == $x){ 
                $row[2] = $row[2] + $y;
                $fp[$index] = $row[0]."|".$row[1]."|".$row[2]."\n";
                echo $fp[$index];
                $trouve = 1;
            }
        }
        if ($trouve == 1){
            $file = fopen("../Resources/Compte.txt", "w");
            foreach($fp as $line){
                fputs($file, $line);
            }
            fclose($file);
            echo("<script>alert('Votre virement a été bien effectué!');</script>");   
        }
        else
            echo("<script>alert('Votre virement n'a pas effectué!');</script>"); 
    }

?>