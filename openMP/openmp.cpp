#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat image = imread("../images/bosque.jpg", IMREAD_COLOR); //Leer la imagen

    if (image.empty()) {
        cout << "No se pudo cargar la imagen." << endl; //Verificar que la imagen se haya cargado correctamente
        return -1;
    }

    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);//Convertir la imagen a escala de grises

    //Obtener el número de filas y columnas de la imagen
    int rows = grayImage.rows;
    int cols = grayImage.cols;

    #pragma omp parallel for collapse(2)//Paralelizar el ciclo for
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            uchar* pixel = grayImage.ptr<uchar>(r, c);
            *pixel = 255 - *pixel;
        }
    }

    namedWindow("Imagen procesada", WINDOW_AUTOSIZE);//Crear una ventana para mostrar la imagen
    imshow("Imagen procesada", grayImage);//Mostrar la imagen

    waitKey(0);

    return 0;
}
