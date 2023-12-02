#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    // Leer la imagen en color
    Mat image = imread(" ", IMREAD_COLOR); // Poner la ruta de la imagen en los paréntesis

    // Verificar si se pudo cargar la imagen
    if (image.empty()) { 
        cout << "No se pudo cargar la imagen" << endl;
        return -1;
    }

    // Obtener las dimensiones de la imagen
    int rows = image.rows;
    int cols = image.cols;

    // Crear una nueva matriz para la imagen en escala de grises
    Mat image_gray(rows, cols, CV_8UC1);

    // Convertir la imagen a escala de grises
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            Vec3b pixel = image.at<Vec3b>(r, c);
            uchar gray_value = 0.2126 * pixel[2] + 0.7152 * pixel[1] + 0.0722 * pixel[0];
            image_gray.at<uchar>(r, c) = gray_value;
        }
    }

    // Mostrar y guardar la imagen en escala de grises
    imshow("Imagen en escala de grises", image_gray);
    imwrite("imagen_gris.jpg", image_gray);

    return 0;
}