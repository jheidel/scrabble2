#ifndef DIPS_H
#define DIPS_H

#include <algorithm>
#include <assert.h>
#include <opencv2/opencv.hpp>

const int DIPS_PER_IMAGE_RELATIVE = 1000;

// A crude class for scaling pixels with respect to image size.
class Dips {
  public:
    Dips(const cv::Size& sz) {
      min_ = std::min(sz.width, sz.height);
      assert(min_ >= 0);
    }

    int ToPixels(double dips) {
      assert(dips >= 0);
      int d = dips / DIPS_PER_IMAGE_RELATIVE * min_;
      if (dips > 0 && d <= 0) return 1; // At least 1 pixel for a positive dips
      return d;
    }

    double ToDips(int pixels) {
      assert(pixels >= 0);
      return pixels / min_ * DIPS_PER_IMAGE_RELATIVE;
    }

  private:
    int min_;
};

#endif // DIPS_H
