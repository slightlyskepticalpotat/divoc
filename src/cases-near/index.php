<?php
  $first = 'ree1';
  $second = 'ree2';
  $third = 'ree3';
  exec("./testing.exe $first $second $third", $out);
  echo $out;
?>
