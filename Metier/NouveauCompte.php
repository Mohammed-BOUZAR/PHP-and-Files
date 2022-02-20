<?php
    require "../DAO/Compte.inc";
    $cin = $_POST['cin'];
    $num = $_POST['num'];
    $montant = $_POST['montant'];
    NouveauCompte($cin,$num,$montant);
?>