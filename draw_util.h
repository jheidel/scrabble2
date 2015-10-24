#ifndef DRAW_UTIL_H
#define DRAW_UTIL_H

#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

void DrawPolygon(cv::Mat& img, const vector<Point>& points, bool closed,
    Scalar color, int thickness) {
  Point last = closed ? points.back() : points.front();
  for (const auto& pt : points) {
    if (pt != last) line(img, last, pt, color, thickness, CV_AA);
    last = pt;
  }
}


#endif // DRAW_UTIL_H
