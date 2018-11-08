#include "opencv2/opencv.hpp"
#include <string>
#include <vector>

//https://docs.opencv.org/3.3.1/d7/d8b/tutorial_py_lucas_kanade.html

using namespace cv;
using namespace std;

//The corner detection parameters copied from tutorial
const int maxCorners = 100;
const double qualityLevel = 0.3;
const int minDistance = 7;
const int blockSize = 7;

//Parameters for Lucas Kanade Optical Flow
//Follow the tutorial, I don't know what these numbers mean
const vector<int> winSize{15, 15};
const int maxLevel = 2;
//const vector<int> criteria{cv::TERM_CRITERIA_EPS | cv::TERM_CRITERIA_COUNT, 10};
const double thirdCriteria = 0.03;

int main() {
    VideoCapture cap(0); //Starts video stream of default camera
    cv::Point pt;
    pt.x = 100;
    pt.y = 100;
    cv::Mat oldFrame;
    cap >> oldFrame;


    cv::Mat pts ;
    cv::Mat nextpts;
    cv::Mat status;
    cv::Mat err;

    
    while(1) {
        //Creates matrix (image)
        cv::Mat frame;
        cap >> frame;

        //Copying from code
        cap.read(frame);
        //cv::circle(frame, pt, 3, 1);
        cv::calcOpticalFlowPyrLK(oldFrame, frame, pts, nextpts, status, err);

        

        //Shows image
        imshow("Frame", frame);

        //If we press ESC, the loop breaks
        char c = (char) cv::waitKey(25);
        if(c == 27) {
            break;
        }
        frame = oldFrame;
    }
    cap.release();

}