<?php require_once '../../config/config.php'?>

<!-- Para la cabecera con menú principal -->
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Inicio</title>

    <!-- Para agregar el ícono favicon -->
    <link rel="shortcut icon" href=<?php echo FROM_PAGES_TO_IMAGES . "/Logo-solo-agost.png"?> />

    <!-- LIBRERÍAS -->
    <link rel="stylesheet" type="text/css" href="../../lib/bootstrap/css/bootstrap.css"/>
    <script src="https://kit.fontawesome.com/00121ead02.js" crossorigin="anonymous"></script>
    <link href="https://fonts.googleapis.com/css?family=Montserrat" rel="stylesheet">
    
    <link rel="stylesheet" href="../../../public/css/4estilosInicio.css" />
  </head>
  <body>

    <?php require_once '../includes/navbar.php'?>

    <main id="seccionMain">
      <section class="seccionTitulo">
        <br />
        <h1 style="color: #E40C7B; font-weight: bold; text-transform: uppercase; margin-top: -30px">
          ¿Qué tiene a su disposición?
        </h1>
        <br />
        <!--<hr style="width: 80%; margin: auto; color: #AF0B19;">-->
      </section>
      <section class="seccionTarjetasInformativas" style="margin-top: -20px; margin-bottom: 30px;">
        <div id="cardTablas" class="card" style="width: 20rem">
          <img
            src=<?php echo FROM_PAGES_TO_IMAGES . "/tiempo-real.png" ?>
            class="card-img-top"
            alt="iconoGraficas"
          />
          <div class="card-body">
            <h5 class="card-title" style="font-weight: bold; color: #E40C7B;">REPORTES</h5>
            <hr />
            <p class="card-text">
              Para que pueda descargar los registros de temperatura y humedad, en los meses
              que usted necesite. 
            </p>
          </div>
        </div>
        <div id="cardGraficas" class="card" style="width: 20rem; box-shadow: rgba(0, 0, 0, 0.3) 0px 19px 38px, rgba(0, 0, 0, 0.22) 0px 15px 12px;">
          <img
            src=<?php echo FROM_PAGES_TO_IMAGES . "/iconoGraficas.png" ?>
            class="card-img-top"
            alt="iconoGraficas"
          />
          <div class="card-body">
            <h5 class="card-title" style="font-weight: bold; color: #E40C7B">GRÁFICAS</h5>
            <hr />
            <p class="card-text">
              Para que pueda observar de forma lineal los registros de temperatura y
              humedad, en los días que usted necesite.
            </p>
          </div>
        </div>
      </section>
      <svg style="margin-top: -170px" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 1440 320"><path fill="#0E2A47" fill-opacity="1" d="M0,128L80,149.3C160,171,320,213,480,208C640,203,800,149,960,154.7C1120,160,1280,224,1360,256L1440,288L1440,320L1360,320C1280,320,1120,320,960,320C800,320,640,320,480,320C320,320,160,320,80,320L0,320Z"></path></svg>
      <section class="secccionMapaGoogleUnidadDeSalud" style=" padding: 30px;">
        <div class="contenedorTituloUbicacion" style="display: flex; justify-content: center;">
          <h1 style="color: #E40C7B; font-weight: bold; text-transform: uppercase; margin-right: 20px;">
            Ubicación de
          </h1>
          <h1 style="color: #F0F3FC; font-weight: bold; text-transform: uppercase">
            Agost+
          </h1>
        </div>
        <div style="width: 100%"><iframe width="100%" height="600" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="https://maps.google.com/maps?width=100%25&amp;height=600&amp;hl=es&amp;q=Popay%C3%A1n,%20Cauca+(Unidad%20Agost+)&amp;t=&amp;z=14&amp;ie=UTF8&amp;iwloc=B&amp;output=embed"><a href="https://www.gps.ie/car-satnav-gps/">GPS car tracker</a></iframe></div>
      </section>
    </main>
  </body>
</html>

<script src=<?php echo FROM_PAGES_TO_JS . "/noDisplay.js" ?> ></script>
