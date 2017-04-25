//
//  main.cpp
//  videoPlayer
//
//  Created by Simon Haycock on 25/04/2017.
//  Copyright © 2017 oxygn. All rights reserved.
//

#include <iostream>
//#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main(int argc, const char * argv[]) {
    cv::namedWindow("Example3", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap;
    cap.open( cv::String(argv[1]) );
    
    cv::Mat frame;
    for (;;) {
        cap >> frame;
        if (frame.empty()) break;
        cv::imshow( "Example 3", frame);
        if (cv::waitKey(33) == 0) break;
    }
}
