<?php
	require_once '../../config/config.php';

	$conn = mysqli_connect(DB_HOST,DB_USER,DB_PASSWORD,DB_NAME); 

	$sql = "SELECT hora, hum, fecha 
			FROM registros 
			WHERE MONTH(fecha) = '$mesSeleccionado'
			AND (
					(TIME(hora) BETWEEN '14:55:00' AND '15:05:00')
				)
			ORDER BY fecha";

	$result = mysqli_query($conn,$sql);


	$valoresY_Humedad_t = array();//montos
	$valoresX_Humedad_t = array();//fechas
	
	while ($ver = mysqli_fetch_row($result)) {
		$valoresY_Humedad_t[] = $ver[1];
		$valoresX_Humedad_t[] = $ver[2];
		
	}
?>