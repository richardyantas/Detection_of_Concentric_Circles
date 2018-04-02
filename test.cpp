#include "../headers.h"
#include "../config.h"
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
		bool is_tracking = false;
		vector<Point2f> old_points;
		vector<Point2f> center_temp;

		if(findRingsGridPattern(frame, Size(4,5), center_temp, is_tracking, old_points))
		{
			cout << "center found: " << center_temp.size() << endl;
			for (int i = 0; i < center_temp.size(); ++i)
			{
				cv::circle( frame, center_temp[i], 5, Scalar(0,0,255) );
			}
			imshow("video1", frame);
			int key = waitKey(1);
			if( key == 99 )
			{
				cout << "push" << endl;
				img.push_back(frame.clone());
				break;
			}
			if( key == 27 )
			{
				break;
			}				
	}

	//namedWindow("images",0);
	//resizeWindow("images", 500, 500);

	cout << "The size is: " << img.size() << endl;

	for(int i = 0; i < img.size(); i++)
	{
		imshow("video1",img[i]);
		waitKey(1000);
	}
	
	vector<Point2f> centers;
	centers = refinement(img[0]);
	imshow("images ......",img[0]);

	waitKey(100000);
}