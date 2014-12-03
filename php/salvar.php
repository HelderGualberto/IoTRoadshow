<?php

$myfile = fopen("getTemperature.txt", "w") or die("Unable to open file!");

$temperature = $_GET["temperatura"];

fwrite($myfile, $temperature);

echo "Saved sucefully";

fclose($myfile);

?> 
