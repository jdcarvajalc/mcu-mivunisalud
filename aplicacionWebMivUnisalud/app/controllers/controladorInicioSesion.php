<?php 
    require_once '../models/modeloInicioSesion.php';

    if ($array['contar'] > 0) {
        
        header("location: ../views/pages/vistaInicio.php");

    }
    else{
        echo 
        "<script>
            confirm('Datos incorrectos')
            open('../../index.php ')
            close('/app/controllers/controladorInicioSesion.php')
        </script>";
    }

?>
