#define _CRT_SECURE_NO_WARNINGS 1;
//�еļ��㹫ʽΪ����=16*arctan��1/5��-4*arctan��1/239��
// arctan��һ�¼������㣺arctan x=x-x^3/3+x^5/5-.....ֱ��ĳ�����ֵ������1e(-15)Ϊֹ
//�������ؼ�д��arctan����
//����һ��
// ��һ����ȷ������ǰ��ķ���������-1����n+1�η����ڶ�������x��i�η�,Ȼ�����i�����������ж�ĳ���Ƿ񲻴���1e(-15)
//#include <iostream>
//using namespace std;
//
//double power(double x, int n);
//double arctan(double x);
//
//int main()
//{
//	cout << "�е�ֵΪ��" << 16.0 * arctan(1/ 5.0) - 4.0 * arctan(1/ 239.0) << endl;
//	return 0;
//}
//double power(double x, int n)
//{
//	double val = 1.0;
//	while (n--)
//		val *= x;
//	return val;
//}
//double arctan(double x)
//{
//	double sum = 0;
//	int i = 1;
//	while (power(x, i) / i > 1e-15)
//	{
//		sum += power(-1, i + 1) * power(x, i) / i;
//		i+=2;
//	}
//	return sum;
//}


//������������Ҫ�ظ�����׳�
//������x^1,x^3,x^5...ÿһ�����������x^2����������ÿ��ֻ��Ҫ����һ�����ӳ���x��ƽ��
//1��5��7Ϊ����3��9��11Ϊ�����պ�����4����Ϊ��
#include <iostream>
using namespace std;

double arctan(double x);
int main()
{
	cout << "PI=" << 16.0 * arctan(1 / 5.0) - 4.0 * arctan(1 / 239.0) << endl;
	return 0;
}
double arctan(double x)
{
	double sqr = x * x;//���ȶ���һ������Ϊx^2
	double e = x;//e��Ϊ����
	double r = 0;//r���Ǹ���֮��
	int i = 1;//i��Ϊ��ĸ��e/i����ÿһ��ľ���ֵ
	while (e / i > 1e-15)
	{
		double f = e / i;//����һ��������Ÿ������ֵ
		r = (i % 4 == 1) ? r + f : r - f;//ǡ��i����4ʱr������һ�����r��ȥ��һ�ʡȥ�����÷���λ��
		e = e * sqr;//����Ȼ�����x^2
		i += 2;//��ĸ��2
	}
	return r;
}