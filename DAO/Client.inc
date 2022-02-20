<?php
    function ExisteClient($cin){
        $fc = fopen("../Resources/Client.txt","r");
        $lire = fread($fc,10000);
        $cherche = strpos($lire,$cin);
        $trv = 0;
        if($cherche)
            $trv = 1;
        fclose($fc);
        return $trv;
    }

    
    function Infos($x) {
        $fp = file("../Resources/Client.txt");
        foreach($fp as $line) {
            $row = explode("|", $line);
            if ($row[0] == $x) {
                echo $row[2]." ".$row[3]."<br>";
            }
        }
        $fp2 = file("../Resources/Compte.txt");
        foreach($fp2 as $ligne) {
            $row2 = explode("|", $ligne);
            if ($row2[1] == $x) {
                echo "Le numero de compte : ".$row2[0].
                " et Le Montant : ".$row2[2]."<br>";
            }
        }
    }

    function Supprimer($x){
        //  Client  
        $fp=file("../Resources/Client.txt");
        $out = array();
        foreach($fp as $line) {
            $row = explode("|", $line);
            if ($row[0] == $x) {
                $delete = $line;
            }
            if($line != $delete) {
                $out[] = $line;
            }
        }
        $fp = fopen("../Resources/Client.txt","w+");
        foreach($out as $line) {
            fwrite($fp, $line);
        }
        fclose($fp);

        //  Comptes
        $fp2=file("../Resources/Compte.txt");
        $out2 = array();
        foreach($fp2 as $ligne) {
            $row2 = explode("|", $ligne);
            if ($row2[1] == $x) {
                $delete = $ligne;
            }
            if($ligne != $delete) {
                $out2[] = $ligne;
            }
        }
        $fp2 = fopen("../Resources/Compte.txt","w+");
        foreach($out2 as $ligne) {
            fwrite($fp2, $ligne);
        }
        fclose($fp2);
        echo "<script>alert('La suppression bien effectuer!');</script>";
    }

    function Debiteurs() {
        $fp = file("../Resources/Compte.txt");
        $fp2 = file("../Resources/Client.txt");
        $out = array();
        foreach($fp as $line){
            $row = explode("|",$line);
            if($row[2]<0){
                $out[] = $row[1];
            }  
        }
        $i = 0;
        foreach($fp2 as $ligne){
            $row2 = explode("|",$ligne);
            if($row2[0] == $out[$i]){
                $i++;
                echo "<br>".$row2[2]." ".$row2[3];
            }
        }
    }
?>

