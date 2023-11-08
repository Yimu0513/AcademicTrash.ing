#include <iostream>      //引用输入输出流
#include <string>
using namespace std;

int main()
{
	char myexp[100];
	cout<<"请输入一个表达式包含括号'(',')' :";
	gets_s(myexp);//从标准输入中读取数据
	cout<<myexp<< endl;

	char S[100];//模拟栈
	int top,i,flag;
	top=-1;//top栈顶指针
	i=0;
	flag=1;//当前是否匹配成功
 
	//while(myexp[i]!='\0')//字符串匹配未结束
	for(int j=0;j<sizeof(myexp);j++)
	{
		//------------------ 学生完成 --------------
		//1. 若为左括号，压栈
		//2. 若为右括号：
		//	栈不空，检查栈顶元素，栈顶为左括号，则匹配，弹出栈顶元素；
		//	否则，不匹配，跳出匹配过程
		if (myexp[j] == '(')
		{
			top++;
			flag=0;
			i = j;
	    }
		else if (myexp[j] == ')')
		{
			if (top>-1)
			{
				top--; 
				flag = 1;
			}
			else 
			{
				i = j;
				flag = 0;
				break;
			}
		}
		else 
		{
			continue;
		}
        //i++;//继续下一轮匹配
	}

  	if (flag==1&& top==-1)
		cout<<"括号匹配成功！"<<endl;
	else
		cout<<"括号在第"<<i+1<<"个符号处匹配失败。"<<endl;
	return 0;
}

