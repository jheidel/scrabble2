#include "board_detector.h"
#include "dips.h"
#include "draw_util.h"
#include "colors.h"

#include <opencv2/opencv.hpp>
#include <vector>
#include <map>

using namespace cv;
using namespace std;


void PreviewMat(const string& window_name, const Mat& img) {
  Mat smaller;
  double f = 0.25;
  resize(img, smaller, Size(), f, f, CV_INTER_AREA);
  imshow(window_name, smaller);
}


void HighlightCorners(const vector<Point>& corners, Mat& img) {
  Dips d(img.size());

  // Draw connecting lines
  DrawPolygon(img, corners, true /*closed*/, COLOR_GREEN, d.ToPixels(3) /*thickness*/);

  // Draw circle for corner
  for (const auto& corner : corners) {
    circle(img, corner, d.ToPixels(10) /*radius*/, COLOR_RED,
           d.ToPixels(3) /*thickness*/, CV_AA);
  }
}


int main() {
  // Load Image
  Mat i = imread("data/20151016/IMG_20151016_165950.jpg");
  // PreviewMat("input", i);

  BoardDetector b;
  vector<Point> corners;
  b.Detect(i, corners);
  HighlightCorners(corners, i);
  PreviewMat("corners", i);

  // Wait for 'x' keypress.
  while (waitKey(100) != 120);
  return 0;
}
