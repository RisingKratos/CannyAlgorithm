#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>

IplImage* image = 0;
IplImage* gray = 0;
IplImage* dst = 0;

int main(int argc, char* argv[])
{
	// ��� ��������
	char* filename = argc == 2 ? argv[1] : "Image.jpg";
	// �������� ��������
	image = cvLoadImage(filename, 1);

	cout << "[i] image: " + filename;
	assert(image != 0);

	// �������������-���� ��������
	gray = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);
	dst = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);

	// ���� ��� ����������� ��������
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("gray", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("cvCanny", CV_WINDOW_AUTOSIZE);

	// 50 �������� ������
	cvCvtColor(image, gray, CV_RGB2GRAY);

	// ����������� ������
	cvCanny(gray, dst, 10, 100, 3);

	// ��������
	cvShowImage("original", image);
	cvShowImage("gray", gray);
	cvShowImage("cvCanny", dst);

	// ����� �� ��������� ���������
	cvWaitKey(0);

	// ����������� �������
	cvReleaseImage(&image);
	cvReleaseImage(&gray);
	cvReleaseImage(&dst);
	// ������� ����
	cvDestroyAllWindows();
	return 0;
}