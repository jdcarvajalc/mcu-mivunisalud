<?php
	require_once '../../config/config.php';

	$conn = mysqli_connect(DB_HOST,DB_USER,DB_PASSWORD,DB_NAME); 

	$sql = "SELECT hora,hum,fecha 
			FROM registros 
			WHERE DAY(fecha) = '$diaSeleccionado'
			AND MONTH(fecha) = '$mesSeleccionado'
			AND YEAR(fecha) = '$anioSeleccionado'
			ORDER BY hora "; 

	$result = mysqli_query($conn,$sql);


	$valoresY_Humedad = array();//montos
	$valoresX_Humedad = array();//fechas
	
	while ($ver = mysqli_fetch_row($result)) {
		$valoresY_Humedad[] = $ver[1];
		$valoresX_Humedad[] = $ver[0];
		
	}
?>