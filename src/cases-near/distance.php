<?php
  ini_set("allow_url_fopen", 1);
  ini_set('user_agent', 'Hackathon Hack');
  $first = $_POST['address'];
  $address = file_get_contents("https://nominatim.openstreetmap.org/search/" . rawurlencode($first) . "/?format=json&limit=1");
  $decoded = json_decode($address, true);

  $lat = $decoded[0]["lat"];
  $lon = $decoded[0]["lon"];
  echo $lat;
  echo "<br>";
  echo $lon;
  echo '<hr>';

  $second = $_POST['radius'];
  $third = $_POST['arg3'];
  echo exec("./testing $first $second $third");
?>
