<?php

    require FROM_PAGES_TO_MODELS . '/modeloReportesTemperaturaManana.php';
    require FROM_PAGES_TO_MODELS . '/modeloReportesHumedadManana.php';
    require FROM_PAGES_TO_MODELS . '/modeloReportesTemperaturaTarde.php';
    require FROM_PAGES_TO_MODELS . '/modeloReportesHumedadTarde.php';

    // Pasa al FrontEnd el mes y año seleccionado
	echo 
		"<script>
		 var mesSeleccionado = ". $mesSeleccionado . ";".
		 "var anioSeleccionado = ". $anioSeleccionado . ";
		</script>"
	;

    // Codificando los valores en formato JSON para usarlos en el FrontEnd
    $datosX_Temperatura_m = json_encode($valoresX_Temperatura_m);
	$datosY_Temperatura_m = json_encode($valoresY_Temperatura_m);

    $datosX_Humedad_m = json_encode($valoresX_Humedad_m);
	$datosY_Humedad_m = json_encode($valoresY_Humedad_m);

    $datosX_Temperatura_t = json_encode($valoresX_Temperatura_t);
	$datosY_Temperatura_t = json_encode($valoresY_Temperatura_t);

    $datosX_Humedad_t = json_encode($valoresX_Humedad_t);
	$datosY_Humedad_t = json_encode($valoresY_Humedad_t);

?>

<!-- CARGANDO TODA LA LÓGICA DE PARTE DEL FRONTEND -->

<script src=<?php echo FROM_PAGES_TO_JS . '/crearCadenaLineal.js' ?> > </script>
<script src=<?php echo FROM_PAGES_TO_JS . '/generadorDeGraficas.js'?> > </script>

<!-- Generar gráfica de Temperatura Mañana -->
<script type="text/javascript">
    datosX_Temperatura_m = crearCadenaLineal('<?php echo $datosX_Temperatura_m ?>');
    datosY_Temperatura_m = crearCadenaLineal('<?php echo $datosY_Temperatura_m ?>');

    var data = generarGraficasTemp(datosX_Temperatura_m, datosY_Temperatura_m, "Temperatura Mañana");

    var layout = generarLayoutTemp("FORMATO CONTROL TEMPERATURA - MAÑANA")

    var config = {responsive: true};

    // Cargar gráfico en GUI
    Plotly.newPlot('cargaLineal', data, layout, config);
</script>

<!-- Generar gráfica de Humedad Mañana -->
<script type="text/javascript">

    datosX_Humedad_m=crearCadenaLineal('<?php echo $datosX_Humedad_m ?>');
	datosY_Humedad_m=crearCadenaLineal('<?php echo $datosY_Humedad_m ?>');

    var data = generarGraficasHum(datosX_Humedad_m, datosY_Humedad_m, "Humedad Mañana");

    var layout = generarLayoutHum("FORMATO CONTROL HUMEDAD - MAÑANA")

    var config = {responsive: true};

	Plotly.newPlot('cargaLineal2', data,layout,config);
</script> 

<!-- Generar gráfica de Temperatura Tarde -->
<script type="text/javascript">
    datosX_Temperatura_t = crearCadenaLineal('<?php echo $datosX_Temperatura_t ?>');
    datosY_Temperatura_t = crearCadenaLineal('<?php echo $datosY_Temperatura_t ?>');

    var data = generarGraficasTemp(datosX_Temperatura_t, datosY_Temperatura_t, "Temperatura Tarde");

    var layout = generarLayoutTemp("FORMATO CONTROL TEMPERATURA - TARDE");

    var config = {responsive: true};

    Plotly.newPlot('cargaLineal3', data,layout,config);

</script>

<!-- Generar gráfica de Humedad Tarde -->
<script type="text/javascript">

    datosX_Humedad_t=crearCadenaLineal('<?php echo $datosX_Humedad_t ?>');
	datosY_Humedad_t=crearCadenaLineal('<?php echo $datosY_Humedad_t ?>');

    var data = generarGraficasHum(datosX_Humedad_t, datosY_Humedad_t, "Humedad Tarde");

    var layout = generarLayoutHum("FORMATO CONTROL HUMEDAD - TARDE");
    
    var config = {responsive: true};

	Plotly.newPlot('cargaLineal4', data,layout,config);
</script> 

<!-- Generar PDF -->
<script src=<?php echo FROM_PAGES_TO_JS . "/2generar2-PDF.js" ?> ></script>

<script>
    document.getElementById('presentarMes').innerHTML= mesSeleccionado;
    document.getElementById('presentarAnio').innerHTML= anioSeleccionado;
</script>
