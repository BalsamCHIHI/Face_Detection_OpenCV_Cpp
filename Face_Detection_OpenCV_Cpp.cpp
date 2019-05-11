#include "pch.h"
#include <iostream>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void detectAndDisplay(Mat frame);

CascadeClassifier face_cascade;
unsigned int total = 0;

int main(void)
{
	int camera_device = 0;
	String face_cascade_name = "haarcascade_frontalface_alt.xml";

	//-- 1. Load the cascades
	if (!face_cascade.load(face_cascade_name))
	{
		cout << "--(!)Error loading face cascade\n";
		return -1;
	}

	VideoCapture capture;

	//-- 2. Read the video stream
	capture.open(camera_device);
	if (!capture.isOpened())
	{
		cout << "--(!)Error opening video capture\n";
		return -1;
	}

	Mat frame;
	while (capture.read(frame))
	{
		if (frame.empty())
		{
			cout << "--(!) No captured frame -- Break!\n";
			break;
		}
		//-- 3. Apply the classifier to the frame
		detectAndDisplay(frame);
		cout << "source FPS = " << capture.get(CAP_PROP_FPS) << endl << endl;
		if (waitKey(1) == 27)
		{
			break; // escape
		}
	}
	return 0;
}

void detectAndDisplay(Mat frame)
{
	Mat frame_gray, frame_gray_eql;
	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray_eql);

	//-- Detect faces
	vector<Rect> faces;
	vector<int> nbr_detect;

	face_cascade.detectMultiScale(frame_gray_eql, faces, nbr_detect);
	for (size_t i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
		ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4);
		Mat faceROI = frame(faces[i]);

		//imshow("roi", faceROI);
		cout << "nbr of detections = " << nbr_detect[i] << endl;
		cout << "detected faces = " << faces.size() << endl;
	}

	total = total + faces.size();
	cout << "total faces detected = " << total << endl;

	imshow("Capture - Face detection", frame);
	//imshow("Capture - Face detection gray", frame_gray);
	//imshow("Capture - Face detection gray_eal", frame_gray_eql);
}