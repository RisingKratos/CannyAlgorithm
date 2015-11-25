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
	// имя картинки
	char* filename = argc == 2 ? argv[1] : "Image.jpg";
	// получаем картинку
	image = cvLoadImage(filename, 1);

	cout << "[i] image: " + filename;
	assert(image != 0);

	// одноканальные-мини картинки
	gray = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);
	dst = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);

	// окно для отображения картинки
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("gray", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("cvCanny", CV_WINDOW_AUTOSIZE);

	// 50 оттенков серого
	cvCvtColor(image, gray, CV_RGB2GRAY);

	// определение границ
	cvCanny(gray, dst, 10, 100, 3);

	// картинки
	cvShowImage("original", image);
	cvShowImage("gray", gray);
	cvShowImage("cvCanny", dst);

	// чтобы не закрылась программа
	cvWaitKey(0);

	// освобождаем ресурсы
	cvReleaseImage(&image);
	cvReleaseImage(&gray);
	cvReleaseImage(&dst);
	// удаляем окна
	cvDestroyAllWindows();
	return 0;
}