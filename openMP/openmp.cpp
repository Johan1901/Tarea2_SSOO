#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat image = imread("../images/bosque.jpg", IMREAD_COLOR); // Leer la imagen

    if (image.empty()) {
        cout << "No se pudo cargar la imagen." << endl; // Verificar que la imagen se haya cargado correctamente
        return -1;
    }

    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY); // Convertir la imagen a escala de grises

    // Obtener el número de filas y columnas de la imagen
    int rows = grayImage.rows;
    int cols = grayImage.cols;

    namedWindow("Imagen en escala de grises", WINDOW_AUTOSIZE); // Crear una ventana para mostrar la imagen
    imshow("Imagen en escala de grises", grayImage); // Mostrar la imagen

    waitKey(0);

    return 0;
}

