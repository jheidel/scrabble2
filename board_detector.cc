#include "board_detector.h"

#include <vector>

using namespace cv;
using namespace std;

void BoardDetector::Detect(const Mat img, vector<Point>& corners) {
  corners.push_back(Point(100, 100));
  corners.push_back(Point(300, 100));
  corners.push_back(Point(500, 200));
  corners.push_back(Point(100, 200));
}
