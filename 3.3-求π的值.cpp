#define _CRT_SECURE_NO_WARNINGS 1;
//π的计算公式为：π=16*arctan（1/5）-4*arctan（1/239）
// arctan用一下级数计算：arctan x=x-x^3/3+x^5/5-.....直至某项绝对值不大于1e(-15)为止
//分析：关键写出arctan函数
//方法一：
// 第一步：确定各项前面的符号正负（-1）的n+1次方；第二步：求x的i次方,然后除以i；第三步：判断某项是否不大于1e(-15)
//#include <iostream>
//using namespace std;
//
//double power(double x, int n);
//double arctan(double x);
//
//int main()
//{
//	cout << "π的值为：" << 16.0 * arctan(1/ 5.0) - 4.0 * arctan(1/ 239.0) << endl;
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
//方法一的结果有问题（？）


//方法二：不需要重复计算阶乘
//分析：x^1,x^3,x^5...每一个都是相差了x^2，所以我们每次只需要将上一个分子乘以x的平方
//1、5、7为正；3、9、11为负，刚好是能4整除为正
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
	double sqr = x * x;//首先定义一个变量为x^2
	double e = x;//e作为分子
	double r = 0;//r就是各项之和
	int i = 1;//i作为分母，e/i就是每一项的绝对值
	while (e / i > 1e-15)
	{
		double f = e / i;//单独一个变量存放各项绝对值
		r = (i % 4 == 1) ? r + f : r - f;//恰好i整除4时r加上下一项，否则r减去下一项（省去了设置符号位）
		e = e * sqr;//分子然后乘以x^2
		i += 2;//分母加2
	}
	return r;
}
