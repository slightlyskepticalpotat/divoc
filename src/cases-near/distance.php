<?php
  ini_set("allow_url_fopen", 1);
  ini_set('user_agent', 'Hackathon Hack');
  $first = $_POST['address'];
  $radius = $_POST['radius'];

  // Php trickery
  $address = file_get_contents("https://nominatim.openstreetmap.org/search/" . rawurlencode($first) . "/?format=json&limit=1");
  $decoded = json_decode($address, true);
  $lat = $decoded[0]["lat"];
  $lon = $decoded[0]["lon"];

  echo "Address: " . $first;
  echo "<br>";
  echo "Latitude: " . $lat;
  echo "<br>";
  echo "Longitude: " . $lon;
  echo '<hr>';

  echo exec("java distance $lat $lon $radius");
  // sample imput: "java distance 43.77 -79.28 1"
?>
