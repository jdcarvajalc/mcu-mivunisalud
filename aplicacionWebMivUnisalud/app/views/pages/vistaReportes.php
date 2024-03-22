<?php require_once '../../config/config.php'?>

<!-- Para la cabecera con menú principal -->
<!DOCTYPE html>
<html lang="en">

  <head>
    <?php require_once '../includes/head.php'?>
    <title>Reportes</title>
    <link rel="shortcut icon" href=<?php echo FROM_PAGES_TO_IMAGES . "/Logo-solo-agost.png"?> />
    <link href="https://fonts.googleapis.com/css?family=Montserrat" rel="stylesheet">
    <link rel="stylesheet" href="<?php echo FROM_PAGES_TO_STYLES . '/3estilosReportes.css'?>" />
  </head>

  <body>
    <?php require_once '../includes/navbar.php'?>

    <main style="margin: 20px;">
      <section class="contenedor-mes">
        <form action="vistaReportes.php" method="POST">
            <label for="mes-seleccionado" class="etiqueta-select">Seleccione una fecha: </label>
            <!-- cambiar a type month -->
            <input 
              type="month" 
              name="mes" 
              class="mes-seleccionado" 
              id="mes-seleccionado" 
              value=""
            >
            <button id="consultar" type="submit" class="consulta">
              <i class="fa-solid fa-magnifying-glass"></i>
            </button>  
        </form>
        <button class="boton-reporte" id="descargar-pdf"><i class="fa-solid fa-download"></i> Reporte</button>
      </section>
      <section style="margin: 2px 0 0 60px">
        <div style="margin: 0; display: flex; justify-content: flex-start; flex-direction: row;">
          <p style="font-weight: bold; color: #E40C7B;margin: 0; padding-right: 5px">Mes: </p>
          <p style="font-weight: bold; color: #0E2A47; margin:0; padding-right: 20px;" id="presentarMes"></p>
          <p style="font-weight: bold; color: #E40C7B;margin: 0; padding-right: 5px">Año: </p>
          <p style="font-weight: bold; color: #0E2A47; margin:0;" id="presentarAnio"></p>
        </div>
      </section>
      <section id="seccion-tarjetas" class="cont" style="margin-top: -40px;">
        <div id="contenido-div1" class="card">
          <div id="cargaLineal" class="mi-grafica"></div>  
        </div>

        <div id="contenido-div2" class="card">
          <div id="cargaLineal2" class="mi-grafica"></div>  
        </div>

        <div id="contenido-div3" class="card">
          <div id="cargaLineal3" class="mi-grafica"></div>  
        </div>

        <div id="contenido-div4" class="card">
          <div id="cargaLineal4" class="mi-grafica"></div>  
        </div>
      </section>
    </main>
  </body>

</html>

<?php
  require_once FROM_PAGES_TO_CONTROLLERS . '/controladorReportes.php';
?>



