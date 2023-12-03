#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <iomanip>

using namespace cv;
using namespace std;

int main() {
    // Capturar el tiempo de inicio
    auto start_time = chrono::high_resolution_clock::now();

    Mat image = imread("../images/bosque.jpg", IMREAD_COLOR); // Leer la imagen

    if (image.empty()) {
        cout << "No se pudo cargar la imagen." << endl;
        return -1;
    }

    Mat grayImage(image.rows, image.cols, CV_8UC1);

    // Convertir la imagen a escala de grises utilizando el método de luminosidad en paralelo con OpenMP
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            Vec3b pixel = image.at<Vec3b>(i, j);
            uchar gray_value = 
            static_cast<uchar>(0.2126 * pixel[2] + 0.7152 * pixel[1] + 0.0722 * pixel[0]);
            #pragma omp critical
            grayImage.at<uchar>(i, j) = gray_value;
        }
    }

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() / 1e6;
    cout << fixed << setprecision(6) << "Tiempo de compilación: " << duration << " segundos" << endl;

    namedWindow("Imagen en escala de grises", WINDOW_AUTOSIZE);
    imshow("Imagen en escala de grises", grayImage);

    waitKey(0);

    return 0;
}
