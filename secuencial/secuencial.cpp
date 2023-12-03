#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <iomanip>

using namespace cv;
using namespace std;

int main() {
    // Capturar el tiempo de inicio
    auto start_time = chrono::high_resolution_clock::now();

    // Leer la imagen en color
    Mat image = imread("../images/bosque.jpg", IMREAD_COLOR);

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

    // Capturar el tiempo de finalización
    auto end_time = chrono::high_resolution_clock::now();

    // Calcular la duración e imprimir el tiempo de ejecución en segundos con 6 decimales
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() / 1e6;
    cout << fixed << setprecision(6) << "Tiempo de ejecución: " << duration << " segundos" << endl;

    // Mostrar la imagen en escala de grises en una ventana emergente
    namedWindow("Imagen en escala de grises", WINDOW_AUTOSIZE);
    imshow("Imagen en escala de grises", image_gray);

    // Esperar hasta que se presione una tecla
    waitKey(0);

    return 0;
}
