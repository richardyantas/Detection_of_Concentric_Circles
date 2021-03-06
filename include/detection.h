#pragma once

#include "../headers.h"
#include "utils.h"
#include "detection.h"

namespace detect
{



	vector<Point2f> refinement(const Mat& frame_input)
	{
		vector<Point2f> centers;

		
		vector<Point2f> grid_point;
		int width_grid = 50;
		//a.push_back( Point2f(2.0,3.0) );

		//cout<<" width: "<<frame_input.cols<<endl;

		for (int i = 0; i < frame_input.cols; i = i+width_grid)
		{
			for (int j = 0; j < frame_input.rows; j=j+width_grid)
			{
				Point2f aux = Point2f(i,j);
				grid_point.push_back(aux);
			}
		}

		//namedWindow("detection_circles",0);
		//resizeWindow("detection_circles", 500, 500);
		cv::Scalar black( 255, 0, 0 );
		for (int i = 0; i < grid_point.size(); ++i)
		{
			cv::circle( frame_input, grid_point[i], 5, black );
		}

		cv::line(frame_input,Point2f(0.0, 0.0), Point2f(200.0,200.0), Scalar(156,240,234), 1, 8, 0);

    	//cv::circle( frame_input, grid_point, 5, black );
    	
		//Point2f seed_point = grid_point(random(grid_point.size));
		
    	cout<<"show images..."<<endl;
		//imshow("images", frame_input);
		vector<Point2f> center_temp;

		bool is_tracking;
		vector<Point2f> old_points;
		imshow("images", frame_input);
		
	
		return centers;
	}
	

}