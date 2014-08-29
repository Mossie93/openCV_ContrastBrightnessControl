#include <iostream>
#include <cv.h>
#include <highgui.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat inputImg, outputImg;
	double alpha;	//controls contrast
	int beta;		//controls brightness
	stringstream s1, s2;

	//checking if all parameters are present
	if(argc != 5)
	{
		cout << "There should be exactly  parameters!\n";
		return -1;
	}

	//loading images, alpha and beta
	inputImg = imread(argv[1]);
	if(!inputImg.data)
	{
		cout << "Error: input file opening failure!\n";
	}
	outputImg = Mat::zeros(inputImg.size(), inputImg.type());
	s1 << argv[3];
	s1 >> alpha;
	s2 << argv[4];
	s2 >> beta;

	//transofrmating image
	for(int y = 0; y < inputImg.rows; y++)
	{
		for(int x = 0; x < inputImg.cols; x++)
		{
			for(int c = 0; c < 3; c++)	//c stands for channel
			{
				outputImg.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( alpha * ( inputImg.at<Vec3b>(y,x)[c] ) + beta );
			}
		}
	}

	//saving output image
	imwrite(argv[2], outputImg);

	//displaying images
	namedWindow("Input image", CV_WINDOW_AUTOSIZE);
	namedWindow("Output image", CV_WINDOW_AUTOSIZE);
	imshow("Input image", inputImg);
	imshow("Output image", outputImg);

	//waiting for signal to close application
	waitKey(0);
	return 0;
}