#include <iostream>
#include <thread>
#include <highgui.h>
#include <unistd.h>
#include "opencv/cv.hpp"

#define ESCAPE 27
#define CAMERA_DELAY 10 //DÉCIMAS DE SEGUNDO

using namespace cv;
using namespace std;

int showVideoDelayed(unsigned int time, Mat frame){
    usleep(time);
    imshow("Video", frame);
    return 0;
}

int main() {
    cout << "Starting video capturing..." << endl;

    VideoCapture capture(0);

    if (!capture.isOpened()){
        cout << "error in VideoCapture: check device" << endl;
        return 1;
    }

    char keypressed = 0;
    bool success;
    int counter = 0;

    namedWindow("Video", CV_WINDOW_AUTOSIZE);
    vector<Mat> list;

    while (keypressed != ESCAPE){
        Mat frame;
        success = capture.read(frame);

        if (!success){
            cout << "Cannot read the frame from file" << endl;
            return 1;
        }

        list.push_back(frame);

        if (counter > CAMERA_DELAY){
            imshow("Video", list.front());
            list.erase(list.begin());
        }

        counter++;
        if (counter % 10 == 0){
            cout << "COUNTER" << counter << "SIZE: " << list.size() << endl;
        }


        //imshow("Video", frame);
        keypressed = (char) waitKey(20);


    }
    destroyWindow("Video");
    capture.release();
    cout << "Stopping video capturing..." << endl;


    return 0;


}