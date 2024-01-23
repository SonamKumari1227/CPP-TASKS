#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {

    Mat image = imread("path_to_your_image.jpg");

    if (image.empty()) {
        cout << "Error: Unable to load the image.\n";
        return -1;
    }

    namedWindow("Original Image", WINDOW_AUTOSIZE);
    imshow("Original Image", image);
    waitKey(0);

    cvtColor(image, image, COLOR_BGR2GRAY);

    namedWindow("Grayscale Image", WINDOW_AUTOSIZE);
    imshow("Grayscale Image", image);
    waitKey(0);

    imwrite("processed_image.jpg", image);
    cout << "Processed image saved successfully.\n";

    return 0;
}
