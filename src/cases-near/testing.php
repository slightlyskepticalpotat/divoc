<?php
  $first = $_POST['arg1'];
  $second = $_POST['arg2'];
  $third = $_POST['arg3'];
  echo exec("./testing $first $second $third");
?>
