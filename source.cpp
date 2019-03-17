#include"PixImage.h"
int main() {
	const char* imagename = "E:/Study/DataStructure/dai.jpg";
	Mat img = imread(imagename);
	if (img.empty()) {
		fprintf(stderr, "Open Failed %s\n", imagename);
		return -1;
	}
	PixImage myimg(img);
	myimg.sobel();
	/*Mat c = myimg.ret_value();
	imshow("1img", c);
	myimg.bluring(3);
	c = myimg.ret_value();
	imshow("2img", c);
	myimg.bluring(5);
	c = myimg.ret_value();
	imshow("3img", c);
	myimg.bluring(7);
	c = myimg.ret_value();
	imshow("4img", c);
	waitKey();*/
	/*Mat c = myimg.ret_value();
	imshow("1img", c);
	myimg.bluring(3);
	c = myimg.ret_value();
	imshow("2img", c);
	myimg.bluring(5);
	c = myimg.ret_value();
	imshow("3img", c);
	myimg.bluring(7);
	c = myimg.ret_value();
	imshow("4img", c);
	myimg.sobel();
	//myimg.display();
	//【3】进行均值滤波操作 
	//cout << img.channels();
	Mat Greyimg;
	cvtColor(img, Greyimg, CV_BGR2GRAY);
	imshow("Greyimage", Greyimg);
	vector<Mat> channels;
	split(img, channels);
	//cout << c;
	Mat B = channels.at(0);
	//cout << B;
	//cout << "B=" << endl << B << endl;
	//cout << img.cols;
	//cout << img.rows;
	Mat dstImage;
	//cout<<imread(imagename);
	//cout << img.at<Vec3b>(300, 500)<<endl;// [0];
	//myimg.display(300, 500);
	//int x = img.at<Vec3b>(300, 300)[0];
	//int y = img.at<Vec3b>(300, 300)[1];
	//int z = img.at<Vec3b>(300, 300)[2];
	//cout << x << " " << y << " "<<z << endl;
	//cout << img.at<cv::Vec3b>(0, 0)[1];
	//cout << img.at<cv::Vec3b>(0, 0)[2];
	blur(img, dstImage, Size(15, 15));
	//cout << img.rows<<endl<<img.cols<<endl;
	//【4】显示效果图  
//	imshow("均值滤波【效果图】", dstImage);
	//imshow("image", img);
	//imshow("dstImage", img);
	waitKey();
	system("pause");
	return 0;*/
}