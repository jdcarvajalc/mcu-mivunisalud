
const meses = [ "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"];

const mesReporte = meses[mesSeleccionado - 1];

const anioReporte = anioSeleccionado;

let now = new Date();

const fechaCreacionReporte = "La fecha de generación del reporte es: ";

const generarPDF = (grafica, tipo, horario) => {
  // Captura la imagen de la gráfica
  html2canvas(document.getElementById(grafica), {
    scale: 2 // aumenta la calidad de la imagen
  }).then(function(canvas) {

    // Crea un objeto jsPDF y agrega la imagen al archivo PDF
    var imgData = canvas.toDataURL('image/png');

    var pdf = new jsPDF('landscape', 'px');

    pdf.addImage(imgData, 'PNG', 25, 60, 600, 350);

    var img2 = new Image();
    img2.src = '../../../public/images/Logo-pdf.png';
    pdf.addImage(img2, 'png', 40, 20, 80, 30);

    // Cabecera títulos
    pdf.setTextColor('#005d99');
    pdf.setFontSize(17);
    pdf.setFont('Montserrat', 'bold');
    pdf.text('FARMACIA', 295,20);
    
    pdf.setTextColor('#005d99');
    pdf.setFontSize(17);
    pdf.setFont('Montserrat', 'bold');
    pdf.text('UNIDAD AGOST+', 275,35);
    
    pdf.setTextColor('#005d99');
    pdf.setFontSize(17);
    pdf.setFont('Montserrat', 'bold');
    pdf.text('NIT. 901.626.811-2', 275,50);

    // Lado superior derecho
    pdf.setTextColor('#005d99');
    pdf.setFontSize(11);
    pdf.setFont('Montserrat', 'bold');
    pdf.text('RESPONSABLE: ', 480,35);

    pdf.setTextColor('#000000');
    pdf.setFontSize(11);
    pdf.setFont('Montserrat', 'normal');
    pdf.text('Viviana ...', 547,35);

    pdf.setTextColor('#005d99');
    pdf.setFontSize(11);
    pdf.setFont('Montserrat', 'bold');
    pdf.text('CARGO: ', 480,45);

    pdf.setTextColor('#000000');
    pdf.setFontSize(11);
    pdf.setFont('Montserrat', 'normal');
    pdf.text('...', 515,45);

    pdf.setTextColor('#E40C7B');
    pdf.setFontSize(11);
    pdf.setFont('Montserrat', 'bold');
    pdf.text('ÁREA: ', 480,65);

    pdf.setTextColor('#000000');
    pdf.setFontSize(11);
    pdf.setFont('Montserrat', 'normal');
    pdf.text('Almacenamiento', 510,65);

    pdf.setTextColor('#E40C7B');
    pdf.setFontSize(11);
    pdf.setFont('Montserrat', 'bold');
    pdf.text('MES: ', 480,75);

    pdf.setTextColor('#000000');
    pdf.setFontSize(11);
    pdf.setFont('Montserrat', 'normal');
    pdf.text(mesReporte, 505,75);

    pdf.setTextColor('#E40C7B');
    pdf.setFontSize(11);
    pdf.setFont('Montserrat', 'bold');
    pdf.text('AÑO: ', 480,85);

    pdf.setTextColor('#000000');
    pdf.setFontSize(11);
    pdf.setFont('Montserrat', 'normal');
    pdf.text(String(anioReporte), 505,85);

    // Lado inferior izquierdo
    pdf.setTextColor('#E40C7B');
    pdf.setFontSize(12);
    pdf.setFont('Montserrat', 'bold');
    pdf.text(fechaCreacionReporte.toUpperCase(), 25,430);

    pdf.setTextColor('#000000');
    pdf.setFontSize(12);
    pdf.setFont('Montserrat', 'normal');
    pdf.text(now.toLocaleDateString()+' a las '+now.toLocaleTimeString(), 240,430);

    // Marca de copyrights
    pdf.setTextColor('#005d99');
    pdf.setFontSize(10);
    pdf.setFont('Montserrat', 'normal');
    pdf.text('© MIV-UNISALUD',545,430);

    pdf.save(`reporte_${tipo+'_'+horario+'_'+mesReporte+'/'+anioSeleccionado}.pdf`); // descarga el archivo PDF
  })
};

// Función que se encarga de llamar a las funciones para crear los reportes
document.getElementById('descargar-pdf').addEventListener('click', function() {
  
  generarPDF('cargaLineal', 'temperatura', 'mañana');
  generarPDF('cargaLineal2', 'humedad', 'mañana');
  generarPDF('cargaLineal3', 'temperatura', 'tarde');
  generarPDF('cargaLineal4', 'humedad', 'tarde');
     
});
  