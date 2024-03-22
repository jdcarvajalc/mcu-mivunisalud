<?php require_once '../../config/config.php'?>

<!-- Para la cabecera con menú principal -->
<!DOCTYPE html>
<html lang="en">

  <head>
    <?php require_once '../includes/head.php'?>
    <title>Gráficas</title>
    <link rel="shortcut icon" href=<?php echo FROM_PAGES_TO_IMAGES . "/Logo-solo-agost.png"?> />
    <link href="https://fonts.googleapis.com/css?family=Montserrat" rel="stylesheet">
    <link rel="stylesheet" href="<?php echo FROM_PAGES_TO_STYLES . '/5estilosGraficas.css'?>" />
  </head>

  <body>

    <?php require_once '../includes/navbar.php'?>

    <main style="margin: 20px;">
      <section class="contenedor-mes">
        <form action="vistaGraficas.php" method="POST">
            <label for="mes-seleccionado" class="etiqueta-select">Seleccione una fecha: </label>
            <!-- cambiar a type month -->
            <input 
              type="date" 
              name="dia" 
              class="mes-seleccionado" 
              id="mes-seleccionado" 
              value=""
            >
            <button id="consultar" type="submit" class="consulta">
              <i class="fa-solid fa-magnifying-glass"></i>
            </button>
          </form>
      </section>
      <section style="margin: 2px 0 0 60px">
        <div style="margin: 10px 0 0 0; display: flex; justify-content: flex-start; flex-direction: row;">
          <p style="font-weight: bold; color: #E40C7B;margin: 0; padding-right: 5px">Día: </p>
          <p style="font-weight: bold; color: #0E2A47; margin:0; padding-right: 20px;" id="presentarDia"></p>
          <p style="font-weight: bold; color: #E40C7B;margin: 0; padding-right: 5px">Mes: </p>
          <p style="font-weight: bold; color: #0E2A47; margin:0; padding-right: 20px;" id="presentarMes"></p>
          <p style="font-weight: bold; color: #E40C7B;margin: 0; padding-right: 5px">Año: </p>
          <p style="font-weight: bold; color: #0E2A47; margin:0;" id="presentarAnio"></p>
        </div>
      </section>
      <section class="cont" style="margin-top: -40px;">
        <div id="contenido-div1" class="card">
          <div id="cargaLineal" class="mi-grafica"></div>  
        </div>

        <div id="contenido-div2" class="card">
          <div id="cargaLineal2" class="mi-grafica"></div>  
        </div>
      </section>
    </main>
  </body>

</html>

<?php
  require_once FROM_PAGES_TO_CONTROLLERS . '/controladorGraficas.php';
?>



