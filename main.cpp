#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
using namespace cv;

int main()
{
    string face_cascade_path = "../Face/haarcascade_frontalface_alt.xml";

    // Load image and cascade classifier files
    Mat image;
    VideoCapture cap(0);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
    cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
    CascadeClassifier face_cascade;
    face_cascade.load(face_cascade_path);

    for(;;)
    {
        cap >> image;
        vector< Rect_<int> > faces;
        face_cascade.detectMultiScale(image, faces, 1.15, 3,
                                      0 | CASCADE_SCALE_IMAGE, Size(30, 30));
        for(size_t i = 0; i < faces.size(); ++i)
        {
            Rect_<int> &face = faces[i];
            rectangle(image, Point(face.x, face.y), Point(face.x + face.width,
                                                          face.y + face.height),
                                                       Scalar(255, 0, 0), 3, 4);
        }
        imshow("Result", image);

        if(waitKey(1) == 27) break;
    }

    return 0;
}
