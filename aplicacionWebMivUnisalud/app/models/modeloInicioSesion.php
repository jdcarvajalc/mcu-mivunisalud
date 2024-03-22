<?php 
    require_once '../config/config.php';

    $conn = mysqli_connect(DB_HOST,DB_USER,DB_PASSWORD,DB_NAME); 

    $usuario = $_POST['user'];
    $clave = $_POST['pass'];

    $query = "SELECT COUNT(*)
              AS contar
              FROM users
              WHERE username = '$usuario' 
              AND password = '$clave'";

    $consulta = mysqli_query($conn,$query);

    $array = mysqli_fetch_array($consulta);
?>