//SeqStackMain.cpp
#include <iostream> 
using namespace std;
#include "SeqStack.cpp"
#include <string>
int main()
{    
	//输入表达式，自定测试用例
    char myexp[100];
	cout<<"请输入一个表达式包含括号'(',')' :";
	cin >> myexp;
	
	cout<<"'"<<myexp<<"'"<< endl;
	
	//创建顺序栈的实例
	SeqStack<char> S;
    
    int i,flag;
	i=0;
	flag=1;//匹配标记符，1为匹配，0为无法匹配
	int len = sizeof(myexp);
	for (int j = 0; j < len; j++)
	{
		if (myexp[j] == '(')
		{
			flag = 0;
			S.Push('(');
			i = j;
		}
		else if(myexp[j] == ')')
		{
			if (S.Empty())
			{
				flag = 0;
				i = j;
			}
			else 
			{
				flag = 1;
				S.Pop();
			}
		}
		else
		{
			continue;
		}
	}

	if (flag == 1 && S.GetTop()!=-1)
	{
		cout << "括号匹配成功！" << endl;
	}
	else 
	{
		cout << "括号在第" << i+1 <<"个符号处匹配失败" << endl;
	}

	//------------------ 学生完成 --------------
	/*-----------------括号匹配过程---------------
	字符串匹配未结束：
	1. 若为左括号，压栈
	2. 若为右括号：
		栈不空，检查栈顶元素，栈顶为左括号，则匹配，弹出栈顶元素；
		否则，不匹配，跳出匹配过程
	继续下一轮匹配
	*/


	//匹配结束，栈空，且匹配记号为1，输出“括号匹配成功！”
	//否则，输出匹配失败位置：“括号在第xxx个符号处匹配失败。”
	return 0;
}

