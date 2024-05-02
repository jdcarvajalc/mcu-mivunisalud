<?php

    require FROM_PAGES_TO_MODELS . '/modeloGraficasTemperatura.php';
    require FROM_PAGES_TO_MODELS . '/modeloGraficasHumedad.php';

    $datosX_Temperatura = json_encode($valoresX_Temperatura);
	$datosY_Temperatura = json_encode($valoresY_Temperatura);

    $datosX_Humedad = json_encode($valoresX_Humedad);
	$datosY_Humedad = json_encode($valoresY_Humedad);

    echo 
		"<script>
            var diaSeleccionado = ". $diaSeleccionado .";".
		    "var mesSeleccionado = ". $mesSeleccionado . ";".
		    "var anioSeleccionado = ". $anioSeleccionado . ";
		</script>"
	;

?>

<script src=<?php echo FROM_PAGES_TO_JS . '/crearCadenaLineal.js' ?> > </script>
<script src=<?php echo FROM_PAGES_TO_JS . '/generadorDeGraficas.js' ?> > </script>

<!-- Generar gráfica de Temperatura -->
<script type="text/javascript">

    datosX_Temperatura = crearCadenaLineal('<?php echo $datosX_Temperatura ?>');
    datosY_Temperatura = crearCadenaLineal('<?php echo $datosY_Temperatura ?>');

    var data = generarGraficasTemp_Diarias(datosX_Temperatura, datosY_Temperatura, 'temp');

    var layout = generarLayoutDiarias("GRÁFICAS DIARIAS TEMPERATURA", "TEMPERATURA [ °C ]", [5, 35])

    var config = {responsive: true};

    Plotly.newPlot('cargaLineal', data,layout,config);

</script>

<!-- Generar gráfica de Humedad -->
<script type="text/javascript">

    datosX_Humedad=crearCadenaLineal('<?php echo $datosX_Humedad ?>');
	datosY_Humedad=crearCadenaLineal('<?php echo $datosY_Humedad ?>');

    var data = generarGraficasHum_Diarias(datosX_Humedad, datosY_Humedad, "hum");

    var layout = generarLayoutDiarias("GRÁFICAS DIARIAS HUMEDAD", "HUMEDAD [ % ]", [35, 75])

    var config = {responsive: true};

	Plotly.newPlot('cargaLineal2', data,layout,config);
</script> 

<script>
    document.getElementById("presentarDia").innerHTML = diaSeleccionado;
    document.getElementById("presentarMes").innerHTML = mesSeleccionado;
    document.getElementById("presentarAnio").innerHTML = anioSeleccionado;
</script>
