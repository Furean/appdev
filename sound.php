<?php

$data = $_POST['data'];
$high = $_POST['high'];
$today = date("Y-m-d H:i:s");
$record = "DATE:" . $today . ", PEAKS:" . $data . ", MAX DECIBEL VALUE:" . $high . "\n";

$file = "sound.log";
if(file_exists($file))
	$fp = fopen($file, "a");
else
	$fp = fopen($file, "w");
fwrite($fp, $record);
fclose($fp);
echo "Data saved!\n";
?>
