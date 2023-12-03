Intrucciones VSC:
1° Descargar el repositorio con "git clone https://github.com/Johan1901/Tarea2_SSOO.git"
2° Entrar en la carpeta, hacer click derecho y buscar "abrir en terminal" o "abrir git bash here"
3° Al abrir la terminal escribir "code ." para abrir con VSC
4° Abrir una bash en la carpeta "openMP", la direccion correcta deberia ser "../Tarea2_SSOO/openMP"
5° Ya estando dentro de la carpeta correcta, ejecutar comando "make"
6° Ejecutar comando ./openMP
7° Se muestra la imagen en escala de grises
8° En caso de error, leer "EN CASO DE ERRORES"

INSTRUCCIONES TERMINAL:
1° Descargar el repositorio con "git clone https://github.com/Johan1901/Tarea2_SSOO.git"
2° Click derecho en la carpeta descargada y seleccionar "abrir terminal"
3° La ruta debe ser "../Tarea2_SSOO/openMP"
4° Ejecutar comando "make"
5° Ejecutar comando "./openmp"
6° Se muestra la imagen en escala de grises

Como tip adicional, se tiene que cambiar el path de las imagenes al que se tenga, ya que en nuestra tarea agregamos la carpeta en el .gitignore y no se mostrará.

EN CASO DE ERRORES: 
1° ./openmp: symbol lookup error: /snap/core20/current/lib/x86_64-linux-gnu/libpthread.so.0: undefined symbol: __libc_pthread_init, version GLIBC_PRIVATE
SOL: Ejecutar en Bash de VSC el comando "unset GTK_PATH" ya que el error aparece gracias al propio VSC.