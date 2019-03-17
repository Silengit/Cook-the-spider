#pragma once
#include<E:/Study/DataStructure/opencv/build/include/opencv2/opencv.hpp>
#include<iostream>
#include"Matrix.h"
#include<string>
using namespace std;
using namespace cv;


class PixImage {
private:
	Matrix R;//红色通道像素矩阵
	Matrix G;//绿色通道像素矩阵
	Matrix B;//蓝色通道像素矩阵
	Matrix Grey;//灰度值
	string name;//图像名称
	int len;//图像长度
	int height;//图像高度
	int size;//图像大小
public:
	PixImage(Mat img);//通过传入的Mat类构造自己的PixImage类
	PixImage(Mat img, string my_name); //传入带名字的的Mat类构造自己的PixImage类
	void display();//显示图像信息
	void display(int x, int y);//显示(x,y)坐标处的图像信息
	void bluring(int n);//对图像进行均值过滤模糊化处理，即对于任意一个像素，使用其周围 n x n 像素范围内的平均值来置换该像素值。
	void sobel();//图像边缘检测算法
	Mat ret_value();//返回一个Mat对象
};