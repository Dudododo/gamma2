#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat srcMat = imread("gtest.jpg", 0);
	cv::Mat resMat = srcMat.clone();

	float gamma = 0.3;
	float LUT[256];

	for (int i = 0; i < 256; i++)
	{
		LUT[i] = pow(i * 1.0 / 255.0, gamma);
	}

	for (int i = 0; i < resMat.rows; i++)
	{
		for (int j = 0; j < resMat.cols; j++)
		{
			resMat.at<uchar>(i, j) = LUT[resMat.at<uchar>(i, j)] * 255;
		}
	}

	imshow("srcMat", srcMat);
	imshow("resMat", resMat);
	waitKey(0);
	return 0;
}

