#include "PixImage.h"
#include <cmath>

PixImage::PixImage(Mat img) {//ͨ�������Mat�๹���Լ���PixImage��
	len = img.cols;
	height = img.rows;
	size = len * height;
	name = "δ����";
	Matrix R_temp(height, len);
	Matrix G_temp(height, len);
	Matrix B_temp(height, len);
	Matrix temp_Grey(height, len);
	Grey = temp_Grey;
	for (int i = 0; i<height; i++)
		for (int j = 0; j < len; j++) {
			int b = img.at<Vec3b>(i, j)[0];
			int g = img.at<Vec3b>(i, j)[1];
			int r = img.at<Vec3b>(i, j)[2];
			R_temp[i][j] = r;
			G_temp[i][j] = g;
			B_temp[i][j] = b;
		}
	R = R_temp;
	G = G_temp;
	B = B_temp;
}

PixImage::PixImage(Mat img, string my_name) {//ͨ�������Mat�๹���Լ���PixImage��
	len = img.cols;
	height = img.rows;
	size = len * height;
	name = my_name;
	Matrix R_temp(height, len);
	Matrix G_temp(height, len);
	Matrix B_temp(height, len);
	Matrix temp_Grey(height, len);
	Grey = temp_Grey;
	for (int i = 0; i<height; i++)
		for (int j = 0; j < len; j++) {
			int b = img.at<Vec3b>(i, j)[0];
			int g = img.at<Vec3b>(i, j)[1];
			int r = img.at<Vec3b>(i, j)[2];
			R_temp[i][j] = r;
			G_temp[i][j] = g;
			B_temp[i][j] = b;
		}
	R = R_temp;
	G = G_temp;
	B = B_temp;
}

void PixImage::display() {
	cout << "ͼƬ��СΪ" << size;
	cout << ",���г�Ϊ" << len;
	cout << ",��Ϊ" << height;
	cout << endl;
	for (int i = 0; i<height; i++)
		for (int j = 0; j < len; j++) {
			cout << "[" << B[i][j] << "," << G[i][j] << "," << R[i][j] << "]" << " ";
		}
	cout << endl;
}

void PixImage::display(int x, int y) {
	cout << "[" << B[x][y] << ", " << G[x][y] << ", " << R[x][y] << "]" << endl;
}

void PixImage::bluring(int n) {//�������Ϊż�����Զ�תΪ�������д���
	if (n <= 0) {//����С�ڵ���0���˳�����
		cerr << "Error!" << endl;
		exit(-1);
	}

	if (n == 1)//����Ϊ1�������κδ���
		return;
	int r = (int)(n / 2);


	//�м䲿��
	for(int i=r;i<height-r;i++)//����Χӵ���㹻���Ԫ�ص�Ԫ�ؽ��д���
		for (int j = r; j < len - r; j++) {
			int sum_R = 0;//�洢��Χn*n����ĸ�Ԫ��֮��
			int sum_G = 0;
			int sum_B = 0;
			for (int x = i - r; x <= i + r; x++)
				for (int y = j - r; y <= j + r; y++) {
					sum_R += R[x][y];
					sum_G += G[x][y];
					sum_B += B[x][y];
				}
			R[i][j] = sum_R / ((2 * r + 1)*(2 * r + 1));//����ƽ��ֵ
			G[i][j] = sum_G / ((2 * r + 1)*(2 * r + 1));
			B[i][j] = sum_B / ((2 * r + 1)*(2 * r + 1));
		}


	//���Ϸ�
	for (int i = 1; i < r; i++)//������Ԫ�ؽ��д���,��Ϊ�°뾶Ϊ1
		for (int j = 1; j < r; j++) {
			int sum_R = 0;//�洢��Χn*n����ĸ�Ԫ��֮��
			int sum_G = 0;
			int sum_B = 0;
			for (int x = i - 1; x <= i + 1; x++)
				for (int y = j - 1; y <= j + 1; y++) {
					sum_R += R[x][y];
					sum_G += G[x][y];
					sum_B += B[x][y];
				}
			R[i][j] = sum_R / 9;//����ƽ��ֵ
			G[i][j] = sum_G / 9;
			B[i][j] = sum_B / 9;
		}

	//���Ϸ�
	for (int i = 1; i < r; i++)//������Ԫ�ؽ��д���,��Ϊ�°뾶Ϊ1
		for (int j = len -r; j < len-1; j++) {
			int sum_R = 0;//�洢��Χn*n����ĸ�Ԫ��֮��
			int sum_G = 0;
			int sum_B = 0;
			for (int x = i - 1; x <= i + 1; x++)
				for (int y = j - 1; y <= j + 1; y++) {
					sum_R += R[x][y];
					sum_G += G[x][y];
					sum_B += B[x][y];
				}
			R[i][j] = sum_R / 9;//����ƽ��ֵ
			G[i][j] = sum_G / 9;
			B[i][j] = sum_B / 9;
		}

	//���·�
	for (int i = height - r; i < height - 1; i++)//������Ԫ�ؽ��д���,��Ϊ�°뾶Ϊ1
		for (int j = 1; j < r; j++) {
			int sum_R = 0;//�洢��Χn*n����ĸ�Ԫ��֮��
			int sum_G = 0;
			int sum_B = 0;
			for (int x = i - 1; x <= i + 1; x++)
				for (int y = j - 1; y <= j + 1; y++) {
					sum_R += R[x][y];
					sum_G += G[x][y];
					sum_B += B[x][y];
				}
			R[i][j] = sum_R / 9;//����ƽ��ֵ
			G[i][j] = sum_G / 9;
			B[i][j] = sum_B / 9;
		}

	//���·�
	for (int i = height - r; i < height - 1; i++)//������Ԫ�ؽ��д���,��Ϊ�°뾶Ϊ1
		for (int j = len - r; j < len - 1; j++) {
			int sum_R = 0;//�洢��Χn*n����ĸ�Ԫ��֮��
			int sum_G = 0;
			int sum_B = 0;
			for (int x = i - 1; x <= i + 1; x++)
				for (int y = j - 1; y <= j + 1; y++) {
					sum_R += R[x][y];
					sum_G += G[x][y];
					sum_B += B[x][y];
				}
			R[i][j] = sum_R / 9;//����ƽ��ֵ
			G[i][j] = sum_G / 9;
			B[i][j] = sum_B / 9;
		}
}

void PixImage::sobel() {
	//�м䲿��
	Mat Greyimg;
	Mat img = ret_value();
	cvtColor(img, Greyimg, CV_BGR2GRAY);
	imshow("Greyimage", Greyimg);

	for (int i = 0; i<height; i++)
		for (int j = 0; j < len; j++) {
			Grey[i][j] = Greyimg.at<uchar>(i, j);
			//cout << Grey[i][j]<<" " ;
		}


	Matrix Gx(height, len);
	Matrix Gy(height, len);
	Matrix G(height, len);
	for (int i = 1; i<height - 1; i++)//����Χӵ���㹻���Ԫ�ص�Ԫ�ؽ��д���
		for (int j = 1; j < len - 1; j++) {
			Gx[i][j] = (-1)*Grey[i - 1][j - 1] + 0 * Grey[i][j - 1] + 1 * Grey[i + 1][j - 1]
				+ (-2)*Grey[i- 1][j] + 0 * Grey[i][j] + 2 * Grey[i + 1][j]
				+ (-1)*Grey[i - 1][j + 1] + 0 * Grey[i][j + 1] + 1 * Grey[i + 1][j + 1];
			Gy[i][j] = 1*Grey[i - 1][j - 1] + 2* Grey[i][j - 1] + 1 * Grey[i + 1][j - 1]
				+ 0*Grey[i - 1][j] + 0 * Grey[i][j] + 0 * Grey[i + 1][j]
				+ (-1)*Grey[i - 1][j + 1] + (-2) * Grey[i][j + 1] + (-1) * Grey[i + 1][j + 1];
			G[i][j] = (int)sqrt(pow(Gx[i][j], 2) + pow(Gy[i][j], 2));
			//cout << G[i][j] << "  ";
		}


	long long sum=0;
	for (int i = 1; i<height - 1; i++)//����Χӵ���㹻���Ԫ�ص�Ԫ�ؽ��д���
		for (int j = 1; j < len - 1; j++) {
			sum += G[i][j];
		}
	int mean = (int)(sum / ((height - 2)*(len - 2)));
	//cout << mean<<endl;
	int scale = 200;
	int cutoff = scale * mean;
	int thresh = (int)sqrt(cutoff);//��ֵ

	//���Ҷ�ͼתΪ�ڰ�ͼ
	for (int i = 1; i<height - 1; i++)
		for (int j = 1; j < len - 1; j++) {
			if (G[i][j] > thresh) {
				Greyimg.at<uchar>(i, j) = 0xFF;
			}
			else
				Greyimg.at<uchar>(i, j) = 0x00;
		}
	imshow("BAWimage", Greyimg);
	waitKey();
}

Mat PixImage::ret_value() {
	Mat temp(height, len, CV_8UC3);
	uchar *pxvec = temp.ptr<uchar>(0);//ȡ���������׵�ַ
	for (int i = 0; i < height; i++) {
		pxvec = temp.ptr<uchar>(i);//ȡÿһ�е������׵�ַ
		for (int j = 0; j < len * 3; j++) {
			uchar x = 0xFF;
			if (j % 3 == 0) {
				pxvec[j] = (unsigned char)B[i][(int)(j / 3)];
				//cout << (int)pxvec[j] << " ";
			}
			else if (j % 3 == 1) {
				pxvec[j] = (unsigned char)G[i][(int)(j / 3)];
				//cout << (int)pxvec[j] << " ";
			}
			else {
				pxvec[j] = (unsigned char)R[i][(int)(j / 3)];
				//cout << (int)pxvec[j] << " ";
			}
		}
	}
	return temp;
}