<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="shortcut icon" href="public/images/Logo-solo-agost.png"> <!-- Para agregar el ícono favicon -->
        <title>Inicio de sesión</title>
        
       <!-- LIBRERÍAS -->
        <script src="https://kit.fontawesome.com/00121ead02.js" crossorigin="anonymous"></script>
        <link href="http://fonts.cdnfonts.com/css/baskerville" rel="stylesheet">
        <link href="https://fonts.googleapis.com/css?family=Muli" rel="stylesheet">

        <link rel="stylesheet" href="public/css/3Index.css">

    </head>
    <body>
        <div class="contenedorImagen">
            <img src="public/images/Logo-general.png" alt="logo de la compañia">
        </div>
        
        <div class="formulario">
            <img style="border: solid .1px #efffff; background-color: #efffff" src="public/images/Logo-solo-agost.png" alt="logo de la compañia">
            <h1>Iniciar Sesión </h1>
            
            <form action="app/controllers/controladorInicioSesion.php" method="POST">
                <!-- USER -->
                <label for="username">
                    <i class="fa-solid fa-user"></i>
                    Usuario
                </label>
                <input type="text" placeholder="Ingrese usuario" id="pUsuario" name="user" required>

                <!-- PASSWORD -->
                <label for="password">
                    <i class="fa-solid fa-key"></i>
                    Contraseña
                </label>
                <input type="password" placeholder="Ingrese contraseña" id="pContra" name="pass" required>

                <input type="submit" name="ingresar" value="INGRESAR">

                <!-- Para Registro -->
                <div class="referencias">
                    <a href="registro.php">¡Registrarse!</a>
                </div>
                
            </form>
        </div> 
    </body>
</html>