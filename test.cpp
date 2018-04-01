#include "../headers.h"
#include "detection.h"

using namespace detect;

int main()
{

	VideoCapture cap("../videos/lif/rings.webm");
	namedWindow("video1", 0);
	resizeWindow("video1", 500, 500);
	
	int n = 0;

	Mat frame;
	vector< Mat > img;
	while(true)
	{	
		//Mat frame(640,480, CV_8UC3, Scalar(0,0,255));	
		cap >> frame;
		if(frame.empty())
		{
			break;
		}
		imshow("video1", frame);
		int key = waitKey(1);
		if( key == 99 )
		{
			cout << "push" << endl;
			img.push_back(frame.clone());
		}
		if( key == 27 )
		{
			break;
		}
		
	}

	namedWindow("images",0);
	resizeWindow("images", 500, 500);

	cout << img.size() << endl;

	/*for(int i = 0; i < img.size(); i++)
	{
		imshow("images",img[i]);
		waitKey(1000);
	}*/
	
	vector<Point2f> centers;
	centers = detection_circles(img[0]);
	imshow("images...",img[0]);
	waitKey(100000);
}