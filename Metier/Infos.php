<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Infos</title>
        <link rel="stylesheet" href="CSS/infos.css">
        <link rel="icon" href="IMG/icon.jpg">
    </head>
    <body>
        <div id="div_infos">
            <?php
                require "../DAO/Client.inc";
                $cin = $_POST['cin'];
                Infos($cin);
            ?>
        </div>
    </body>
</html>