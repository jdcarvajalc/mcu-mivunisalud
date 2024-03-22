const checkbox = document.getElementById('check');
const seccion = document.getElementById('seccionMain');

checkbox.addEventListener('click', () => {
    if (checkbox.checked) {
      seccion.style.display = 'none';
    } else {
      seccion.style.display = 'block';
    }
  });