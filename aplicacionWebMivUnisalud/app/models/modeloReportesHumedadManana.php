<?php
	require_once '../../config/config.php';

	$conn = mysqli_connect(DB_HOST,DB_USER,DB_PASSWORD,DB_NAME); 

	$sql = "SELECT hora, hum, fecha 
			FROM registros 
			WHERE MONTH(fecha) = '$mesSeleccionado'
			AND (
					(TIME(hora) BETWEEN '08:55:00' AND '09:05:00')
				)
			ORDER BY fecha";

	$result = mysqli_query($conn,$sql);


	$valoresY_Humedad_m = array();//montos
	$valoresX_Humedad_m = array();//fechas
	
	while ($ver = mysqli_fetch_row($result)) {
		$valoresY_Humedad_m[] = $ver[1];
		$valoresX_Humedad_m[] = $ver[2];
		
	}
?>