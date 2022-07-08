<?php

$host = "localhost";
$username = "root";
$password = "";
$dbname = "battlebot";

$conn = mysqli_connect($host, $username, $password, $dbname);

if (!$conn) {
    die("Connection failed: " . $conn->connect_error);
}

//update value in table
if (isset($_POST['submit'])) {
    $value = $_POST['submit'];
    $sql = "UPDATE `event` SET command =" . $value . " WHERE id = 1";

    if ($stmt = $conn->prepare($sql)) {
        $stmt->execute()
            or die("Could not run query: " . $conn->error);
    } else {
        echo "error";
    }  
} 
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>BattleBot Events</title>
</head>
<body>
  <h1>BattleBot Controls</h1>

  <form action="" method="POST">                   
      <button type="submit" id="btn" name = "submit" value = "1">Follow the line</button><br><br>
      <button type="submit" id="btn" name = "submit" value = "2">Unique skill</button><br><br>
      <button type="submit" id="btn" name = "submit" value = "3">Maze</button><br><br>
      <button type="submit" id="btn" name = "submit" value = "4">Stop</button> 
  </form>

  <br>
  <?php
    
        if (isset($_POST['submit'])) {
            $sql = "SELECT command FROM `event` WHERE id = 1";
            $result = $conn->query($sql);

            if ($result->num_rows > 0) {
                
                while($row = $result->fetch_assoc()) {
                    echo '<div id="command">'. $row["command"] . "<br> Current Task: ";

                    switch($row["command"]) {
                        case 1:
                            echo "Line following";
                            break;
                        case 2:
                            echo "Pre-defined route";
                            break;
                        case 3:
                            echo "maze";
                        case 4:
                            echo "Stop";
                            break;
                        default:
                            echo "No command";
                            break;    
                    }
                }
                echo ;
            } else {
                echo ;
            }
        }

        $conn->close();
    ?>
  
</body>
</html>