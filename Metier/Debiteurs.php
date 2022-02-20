<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Document</title>
        <link rel="stylesheet" href="../GUI/CSS/main1.css">
        <link rel="icon" href="IMG/icon.jpg">
    </head>
    <body>
        <div id="debiteurs">
            <h1>Les Debiteurs</h1>
            <?php
                require "../DAO/Client.inc";
                @Debiteurs();
            ?>
        </div>
    </body>
</html>