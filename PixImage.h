#pragma once
#include<E:/Study/DataStructure/opencv/build/include/opencv2/opencv.hpp>
#include<iostream>
#include"Matrix.h"
#include<string>
using namespace std;
using namespace cv;


class PixImage {
private:
	Matrix R;//��ɫͨ�����ؾ���
	Matrix G;//��ɫͨ�����ؾ���
	Matrix B;//��ɫͨ�����ؾ���
	Matrix Grey;//�Ҷ�ֵ
	string name;//ͼ������
	int len;//ͼ�񳤶�
	int height;//ͼ��߶�
	int size;//ͼ���С
public:
	PixImage(Mat img);//ͨ�������Mat�๹���Լ���PixImage��
	PixImage(Mat img, string my_name); //��������ֵĵ�Mat�๹���Լ���PixImage��
	void display();//��ʾͼ����Ϣ
	void display(int x, int y);//��ʾ(x,y)���괦��ͼ����Ϣ
	void bluring(int n);//��ͼ����о�ֵ����ģ������������������һ�����أ�ʹ������Χ n x n ���ط�Χ�ڵ�ƽ��ֵ���û�������ֵ��
	void sobel();//ͼ���Ե����㷨
	Mat ret_value();//����һ��Mat����
};