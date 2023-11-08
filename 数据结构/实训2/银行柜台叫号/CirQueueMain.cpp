//CirQueueMain.cpp
#include <iostream> 
using namespace std;
#include "CirQueue.cpp" 

//==================银行柜台叫号系统==============================
int main()
{
	//需编写代码后才可正常运行，下面由学生完成
	CirQueue<int> Vip;
	CirQueue<int> NVip;

	//选择合适的数据结构，模拟Vip客户和普通客户正常排队
	//Vip - Vip客户排队，NVip - 普通客户排队

	int CountVip = 0;				//当前排队的Vip客户个数
	int CountNVip = 0;			//当前排队的普通客户个数
	int PosNo = 0;				//当前服务柜台编号
	int flag = 1;					//服务系统是否继续运行标记
	int temp;					//临时变量，可存客户编号
	int choose;					//系统运行中的选项

	while (flag == 1)
	{
		cout << "++++++++功能选择+++++++++" << endl;
		cout << "[1] Vip客户取号，请输入1" << endl;
		cout << "[2] 普通客户取号，请输入2" << endl;
		cout << "[3] Vip柜台服务员叫号服务，请输入3" << endl;
		cout << "[4] 普通柜台服务员叫号服务，请输入4" << endl;
		cout << "[5] 退出系统请按5" << endl;
		cout << "您的选择是：      ";
		cin >> choose;
		cout << endl;

		if (choose == 3 || choose == 4)
		{
			cout << "     请输入您的柜台编号:";
			cin >> PosNo;
			cout << endl;
		}
		cout << "++++++++++++++++++++++++++" << endl;
		cout << "---------------------------" << endl;

		switch (choose)
		{
		case 1:
			//实现Vip客户取号排队，并输出："您的序号为 Vxxx ,前面有 xxx 人在等待"
			CountVip++;
			Vip.EnQueue(CountVip);
			cout << "您的序号为 V" << CountVip << " ,前面有 " << CountVip - 1 << " 人在等待"<< endl;
			break;

		case 2:
			//实现普通客户取号排队，并输出："您的序号为 Nxxx ,前面有 xxx 人在等待"
			CountNVip++;
			Vip.EnQueue(CountNVip);
			cout << "您的序号为 N" << CountNVip << " ,前面有 " << CountNVip - 1 << " 人在等待" << endl;
			break;

		case 3:
			//实现Vip柜台服务员叫号服务
			//优先服务排队的Vip客户，并输出："请 Vip客户 xx 号到Vip柜台 xx 号窗口来！"
			//若无排队的Vip客户，可服务排队的普通客户，并输出："请普通客户 xx 号到Vip柜台 xx 号窗口来！"
			//若都无客户排队，输出："没有客户在排队！！"
			if (Vip.Empty()!=1)
			{
				cout << "请 Vip客户 " << CountVip << "号到Vip柜台 " << PosNo << "号窗口来！" << endl;
				Vip.DeQueue();
				CountVip--;
			}
			else if(NVip.Empty() != 1)
			{
				cout << "请普通客户 " << CountNVip << "号到Vip柜台 " << PosNo << "号窗口来！" << endl;
				NVip.DeQueue();
				CountNVip--;
			}
			else 
			{
				cout << "没有客户在排队！！" << endl;
			}
			break;

		case 4:
			// 实现普通柜台服务员叫号服务
			// 优先服务排队的普通客户，并输出："请普通客户 xx 号到普通柜台 xx 号窗口来！"
			// 若无排队的普通客户，可服务排队的Vip客户，并输出："请Vip客户 xx 号到普通柜台 xx 号窗口来！"
			//若都无客户排队，输出："没有客户在排队！！"
			if (NVip.Empty() != 1)
			{
				cout << "请普通客户 " << NVip.GetQueue() << "号到普通柜台 " << PosNo << "号窗口来！" << endl;
				NVip.DeQueue();
			}
			else if (Vip.Empty() != 1)
			{
				cout << "请 Vip客户 " << Vip.GetQueue() << "号到普通柜台 " << PosNo << "号窗口来！" << endl;
				Vip.DeQueue();
			}
			else
			{
				cout << "没有客户在排队！！" << endl;
			}

			break;

		case 5:
			cout << "退出银行服务系统..." << endl;
			flag = 0;

			break;

		default:
			cout << "       输入错误，请重新选择！" << endl;
			break;

		}
		cout << "---------------------------" << endl;


	} // while
	return 0;
}