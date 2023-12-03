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

    Mat grayImage(image.rows, image.cols, CV_8UC1); // Crear una imagen en escala de grises

    // Convertir la imagen a escala de grises en paralelo utilizando OpenMP
    #pragma omp parallel for
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            Vec3b pixel = image.at<Vec3b>(i, j);
            grayImage.at<uchar>(i, j) = static_cast<uchar>((pixel[0] + pixel[1] + pixel[2]) / 3);
        }
    }

    namedWindow("Imagen en escala de grises", WINDOW_AUTOSIZE); // Crear una ventana para mostrar la imagen
    imshow("Imagen en escala de grises", grayImage); // Mostrar la imagen

    waitKey(0);

    return 0;
}


