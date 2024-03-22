<?php

    require_once '../../config/config.php';

	$conn = mysqli_connect(DB_HOST,DB_USER,DB_PASSWORD,DB_NAME);

	$fecha = isset($_POST['dia']) ? $_POST['dia'] : date('Y-m-d');

	$diaSeleccionado = date('d', strtotime($fecha));
	$mesSeleccionado = date('m', strtotime($fecha));
	$anioSeleccionado = date('Y', strtotime($fecha));

	$sql = "SELECT hora,temp,fecha 
			FROM registros 
			WHERE DAY(fecha) = '$diaSeleccionado'
			AND MONTH(fecha) = '$mesSeleccionado'
			AND YEAR(fecha) = '$anioSeleccionado'
			ORDER BY hora"; 

	$result = mysqli_query($conn,$sql);

	$valoresY_Temperatura = array();//montos
	$valoresX_Temperatura = array();//fechas
	
	while ($ver = mysqli_fetch_row($result)) {
		$valoresY_Temperatura[] = $ver[1];
		$valoresX_Temperatura[] = $ver[0];
	}
?>