//CirQueueMain.cpp
#include <iostream>        //引用输入输出流
using namespace std;
#include "CirQueue.cpp"    //引入成员函数文件

int main()
{
	CirQueue<int>a;           //创建模版类的实例 

	if (a.Empty()) {

		cout << "循环队列空,对10执行入队操作" << endl;
		try
		{
			a.EnQueue(10);                      //入队操作
		}
		catch (string wrong)
		{
			cout << wrong << endl;
		}

		cout << "读取队头元素:" << endl;
		try
		{
			cout << a.GetQueue() << endl;           //读队头元素
		}
		catch (string wrong)
		{
			cout << wrong << endl;
		}

		cout << "对15执行入队操作" << endl;
		try
		{
			a.EnQueue(15);
		}
		catch (string wrong)
		{
			cout << wrong << endl;
		}

		cout << "读取队头元素" << endl;
		try
		{
			cout << a.GetQueue() << endl;
		}
		catch (string wrong)
		{
			cout << wrong << endl;
		}

		cout << "执行出队操作" << endl;     //出队操作
		try
		{
			a.DeQueue();
		}
		catch (string wrong)
		{
			cout << wrong << endl;
		}

		cout << "读取队头元素:" << endl;
		try
		{
			cout << a.GetQueue() << endl;
		}
		catch (string wrong)
		{
			cout << wrong << endl;
		}
	}
	else {

		cout << "循环队列不空" << endl;
	}


	//========= 学生完成：根据上述代码，继续设计测试代码，对循环队列 - 队空和队满 情况进行测试===============

    if (!a.Empty()) {
        cout << "循环队列为空，对10执行入队操作" << endl;
        try
        {
            a.EnQueue(10); //入队操作
        }
        catch (string wrong)
        {
            cout << wrong << endl;
        }

        cout << "读取队头元素:" << endl;
        try
        {
            cout << a.GetQueue() << endl; //读队头元素
        }
        catch (string wrong)
        {
            cout << wrong << endl;
        }
    }
    else
    {
        cout << "循环队列不空" << endl;

    }
    
	// 队满测试
    if (a.Full())
    {
        cout << "循环队列满，执行出队操作" << endl;
        try
        {
            a.DeQueue(); //出队操作
        }
        catch (string wrong)
        {
            cout << wrong << endl;
        }
        cout << "读取队头元素:" << endl;
        try
        {
            cout << a.GetQueue() << endl;
        }
        catch (string wrong)
        {
            cout << wrong << endl;
        }
    }
    else
    {
        cout << "循环队列不满" << endl;
    }
    return 0;

}



