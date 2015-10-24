#ifndef BOARD_DETECTOR_H
#define BOARD_DETECTOR_H

#include <opencv2/opencv.hpp>
#include <vector>


// Detects the corners of a board.
// TODO: virtual class for different board detection methods.
class BoardDetector {
  public:

    // Given an image, returns the corners of the board starting top left
    // going clockwise. 
    // TODO: return status code
    void Detect(const cv::Mat img, std::vector<cv::Point>& corners);

  private:

};

#endif  // BOARD_DETECTOR_H


