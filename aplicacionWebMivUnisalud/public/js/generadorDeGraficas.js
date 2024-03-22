function generarGraficasTemp(valoresX, valoresY, nombre){
    var trace1 = {
        x: valoresX,
        y: valoresY,
        mode: 'lines+markers',
        name: nombre,
        line: {
            width: 2,
            color: '#005d99'
        },
    };

    // Agregar una nueva trace para graficar una línea recta como límite superior a 30
    let limiteSuperior = [];
    for (var i = 0; i < valoresX.length; i++) {
        limiteSuperior.push(30);
    }

    var trace2 = {
        x: valoresX,
        y: limiteSuperior,
        mode: 'lines',
        name: 'Límite Superior 30°C',
        line: {
            width: .4,
            color: '#E40C7B'
        }
    };

    // Agregar una nueva trace para graficar una línea recta como límite superior a 30
    var limiteInferior = [];
    for (var i = 0; i < valoresX.length; i++) {
        limiteInferior.push(8);
    }

    var trace3 = {
        x: valoresX,
        y: limiteInferior,
        mode: 'lines',
        name: 'Límite Inferior 8°C',
        line: {
            width: .4,
            color: '#E40C7B '
        }
    };

    let  data = [trace1, trace2, trace3];
    return data;
};

function generarGraficasHum(valoresX, valoresY, nombre){
    var trace1 = {
        x: valoresX,
        y: valoresY,
		mode: 'lines+markers',
        type: 'scatter',
        name: nombre,
		line: {
			with: 2,
			color: '005d99',
		},
    };

    var limiteSuperior = [];
    for (var i = 0; i < valoresX.length; i++) {
        limiteSuperior.push(70);
    }

    var trace2 = {
        x: valoresX,
        y: limiteSuperior,
        mode: 'lines',
        name: 'Límite Superior 70%',
        line: {
            width: .4,
            color: '#E40C7B'
        }
    };

    var limiteInferior = [];
    for (var i = 0; i < valoresX.length; i++) {
        limiteInferior.push(40);
    }

    var trace3 = {
        x: valoresX,
        y: limiteInferior,
        mode: 'lines',
        name: 'Límite Inferior 40%',
        line: {
            width: .4,
            color: '#E40C7B'
        }
    };
    
    let data = [trace1, trace2, trace3];
    return data
};

function generarLayoutTemp(textoTitulo){
    let layout = {
        showlegend: false,
        title:{
            text: textoTitulo,
            font:{
                family: 'Montserrat',
                size: 25,
                color: '#E40C7B',
                weight: 'bold'
            }
        },
        xaxis: {
            type: 'date',
            tickmode: 'day',
            dtick: 86400000, // Un día en milisegundos
            title: {
                text:'FECHAS',
                font:{
                    family: 'Montserrat',    
                    color: '#E40C7B',
                }
            },
            // ticktext: textValues,
        },
        yaxis: {
            title:{
                text: 'TEMPERATURA [ °C ]',
                font:{
                    family: 'Montserrat',    
                    color: '#E40C7B',
                }
            },
            range: [5, 35] // Ajustar el rango para mostrar la línea recta como límite superior
        }
    };
    return layout;
};

function generarLayoutHum(textoTitulo){
    let layout = {
        showlegend: false,
        title:{
            text: textoTitulo,
            font:{
                family: 'Montserrat',
                size: 25,
                color: '#E40C7B',
                weight: 'bold'
            }
        },
        xaxis: {
            type: 'date',
            tickmode: 'day',
            dtick: 86400000, // Un día en milisegundos
            title: {
                text:'FECHAS',
                font:{
                    family: 'Montserrat',    
                    color: '#E40C7B',
                }
            },
            // ticktext: textValues,
        },
        yaxis: {
            title:{
                text: 'HUMEDAD [ % ]',
                font:{
                    family: 'Montserrat',    
                    color: '#E40C7B',
                }
            },
            range: [35, 75] // Ajustar el rango para mostrar la línea recta como límite superior
        }
    };
    return layout;
};

function generarGraficasTemp_Diarias(valoresX, valoresY, nombre){
    var trace1 = {
        x: valoresX,
        y: valoresY,
        mode: 'lines+markers',
        name: nombre,
        line: {
            width: 2,
            color: '#005d99'
        },
    };

    // Agregar una nueva trace para graficar una línea recta como límite superior a 30
    let limiteSuperior = [];
    for (var i = 0; i < valoresX.length; i++) {
        limiteSuperior.push(30);
    }

    var trace2 = {
        x: valoresX,
        y: limiteSuperior,
        mode: 'lines',
        name: 'Límite Superior 30°C',
        line: {
            width: .4,
            color: '#E40C7B'
        }
    };

    // Agregar una nueva trace para graficar una línea recta como límite superior a 30
    var limiteInferior = [];
    for (var i = 0; i < valoresX.length; i++) {
        limiteInferior.push(8);
    }

    var trace3 = {
        x: valoresX,
        y: limiteInferior,
        mode: 'lines',
        name: 'Límite Inferior 8°C',
        line: {
            width: .4,
            color: '#E40C7B '
        }
    };

    var data = [trace1, trace2, trace3];
    return data;
};

function generarGraficasHum_Diarias(valoresX, valoresY, nombre){

    var trace1 = {
        x: valoresX,
        y: valoresY,
		mode: 'lines+markers',
        type: 'scatter',
        name: nombre,
		line: {
			with: 2,
			color: '#005d99',
		},
    };

    var limiteSuperior = [];
    for (var i = 0; i < valoresX.length; i++) {
        limiteSuperior.push(70);
    }

    var trace2 = {
        x: valoresX,
        y: limiteSuperior,
        mode: 'lines',
        name: 'Límite Superior 70%',
        line: {
            width: .4,
            color: '#E40C7B'
        }
    };

    var limiteInferior = [];
    for (var i = 0; i < valoresX.length; i++) {
        limiteInferior.push(40);
    }

    var trace3 = {
        x: valoresX,
        y: limiteInferior,
        mode: 'lines',
        name: 'Límite Inferior 40%',
        line: {
            width: .4,
            color: '#E40C7B'
        }
    };
    
    let data = [trace1, trace2, trace3];
    return data
};

function generarLayoutDiarias(textoTitulo, textoYAxis, rango){
    let layout = {
        showlegend: false,
        title:{
			text: textoTitulo,
			font:{
				family: 'Montserrat',
				size: 25,
				color: '#E40C7B',
				bold: true,
			}
		},
		xaxis: {
            title: {
				text:'HORAS',
				font:{
					family: 'Montserrat',	
					color: '#E40C7B',
				}
			},
        },
        yaxis: {
            title:{
				text: textoYAxis,
				font:{
					family: 'Montserrat',	
					color: '#E40C7B',
				}
			},
			range: rango
        }
    }
    return layout;
};