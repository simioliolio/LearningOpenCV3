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
#include <iostream>
#include <fstream>

using namespace std;

int g_slider_position = 0;
int g_run = 1, g_dontset = 0; // start in single step
cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void *) {
    g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
    if (!g_dontset) {
        g_run = 1;
    }
    g_dontset = 0;
}

int main(int argc, const char * argv[]) {
    cv::namedWindow("Example2_4", cv::WINDOW_AUTOSIZE);
    if (argc == 1) {
        g_cap.open(0);
    } else {
        g_cap.open( cv::String(argv[1]) );
    }
    
    int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    cout << "Video has " << frames << " frames of dimentionas(" << tmpw << ", " << tmph << ")." << endl;
    
    cv::createTrackbar("Position", "Example2_4", &g_slider_position, frames, onTrackbarSlide);
    
    cv::Mat frame;
    for (;;) {
        if (g_run != 0) {
            g_cap >> frame;
            if (frame.empty()) break;
            int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
            g_dontset = 1;
            
            cv::setTrackbarPos("Position", "Example 2_4", current_pos);
            cv::Mat cannyFrame;
            cv::Canny(frame, cannyFrame, 10, 100);
            cv::imshow( "Example 2_4", cannyFrame);
            g_run -= 1;
        }
        
        char c = (char) cv::waitKey(10);
        if (c == 's') {
            g_run = 1;
            cout << "Single step, run = " << g_run << endl;
        }
        if (c == 'r') {
            g_run = -1;
            cout << "Run mode, run = " << g_run << endl;
        }
        if (c == 27) {
            break;
        }
    }
    return(0);
}
