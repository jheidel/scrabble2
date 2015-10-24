#include <opencv2/opencv.hpp>

#include "board_detector.h"

using namespace cv;


void Preview(const string& window_name, Mat img) {
  Mat smaller;
  double f = 0.25;
  resize(img, smaller, Size(), f, f, CV_INTER_AREA);
  imshow(window_name, smaller);
}


int main() {
  // Load Image
  Mat i = imread("data/20151016/IMG_20151016_165950.jpg");

  Preview("input", i);

  // Initial resize.
  BoardDetector b;
  b.Detect(i);

  // Wait for 'x' keypress.
  while (waitKey(100) != 120);
  return 0;
}
