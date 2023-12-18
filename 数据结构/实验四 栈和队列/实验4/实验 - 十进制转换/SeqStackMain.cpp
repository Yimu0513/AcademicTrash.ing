//SeqStackMain.cpp
#include <iostream>
using namespace std;
#include "SeqStack.cpp"

void ChangToM(int n,int m);

int main()
{    
	for (int j = 0; j < 8; j++)
	{
		int n, m;
		cout << "请输入一个待转换的整数 :";
		cin >> n;
		cout << endl;
		cout << "要转换成的进制数(2-9) :";
		cin >> m;
		cout << endl;

		ChangToM(n, m);
	}
    
	return 0;
}

/*用m去除十进制整数，可以得到一个商和余数；再用m去除商，又会得到一个商和余数，如此进行，
直到商为零时为止，然后把先得到的余数作为m进制数的低位有效位，后得到的余数作为m进制数的高位有效位，依次排列起来*/
void ChangToM(int n,int m)
{ 
	//-------------------- 学生完成 ----------------------
  
	SeqStack<int> Result;
	int divisor; 
	int remainder;
	divisor = n;
	//开始进制转换
	while (divisor != 0)
	{
		remainder = divisor % m;
		divisor = divisor / m;
		Result.Push(remainder);
	}
	//输出转换结果，“转换结果为：”
	cout << "转换结果为：";
	while (!Result.Empty())
	{
		int num = Result.Pop();
		cout << num;
	}
	cout << endl;
	cout << endl;
}
