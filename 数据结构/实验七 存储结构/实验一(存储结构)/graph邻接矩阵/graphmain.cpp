#include <iostream>
#include <string>                   //引入标准库中的头文件
#include "graph.cpp"                //引用graph.cpp文件
using namespace std;

int visited[MaxSize];
int visited2[MaxSize];

int main(int argc, char* argv[])
{
	int i;
	int choose = 1;                      //控制
	int which;                         //功能选择变量	
	string name;                       //插入顶点的值	                                                          
	string vname[5] = { "V0-浙大","V1-浙工大","V2-浙江传媒","V3-杭电","V4-浙理工" };  //初始化各顶点
	int pos1;                           //顶点
	int pos2;                           //顶点
	int m;
	MGraph<string> g(vname, 5, 0);        //调用Graph程序
	//MGraph<string> g(vname, 5, 11);   //手动输入边

	while (choose == 1)                  //控制
	{

		cout << "==================================" << "\n";
		cout << "需要输出顶点信息请按0" << "\n";		   //输入所要进行的操作的序号
		cout << "需要输出任意一个顶点信息请按1" << "\n";
		cout << "需要输出边信息请按2" << "\n";
		cout << "需要删除顶点请按3" << "\n";
		cout << "需要插入顶点请按4" << "\n";
		cout << "需要删除某条边请按5" << "\n";
		cout << "需要插入某条边请按6" << "\n";
		cout << "需要深度优先遍历请按7" << "\n";
		cout << "需要广度优先遍历请按8" << "\n";
		cout << "需要退出请按10" << "\n";
		cout << "==================================" << "\n";
		cin >> which;
		switch (which)                  //功能选择
		{

		case 0:                   //输出图的各顶点的值
			g.PrintVex();

			break;

		case 1:                   //输出图的任意顶点的值
			try
			{
				int i;
				cout << "请输入顶点：" << "\n";
				cin >> i;
				g.GetVex(i);

			}
			catch (string s)
			{
				cout << s << endl;
			}

			break;

		case 2:                       //输出图中的边	     
			cout << "所有的边的信息为:" << "\n";
			g.PrintArc();
			break;

		case 3:                        //删除hh顶点
			int hh;
			cout << "请输入要删除的顶点" << "\n";
			cin >> hh;
			try
			{
				g.DeleteVex(hh);
			}
			catch (string s)
			{
				cout << s << "，删除失败！" << endl;
			}
			break;

		case 4:                        //在nn位置插入值为name的顶点
			int nn;
			cout << "请输入要插入的顶点位置及名称" << "\n";
			cin >> nn >> name;
			try
			{
				g.InsertVex(nn, name);
			}
			catch (string s)
			{
				cout << s << ", 插入失败！" << endl;
			}
			break;

		case 5:                      //删除两顶点之间的路径         
			cout << "请输入两顶点：" << "\n";
			cin >> pos1 >> pos2;
			try
			{
				g.DeleteArc(pos1, pos2);
			}
			catch (string s)
			{
				cout << s << "，插入失败！" << endl;
			}

			break;

		case 6:                   //插入一条边         
			cout << "请输入两顶点：" << "\n";
			cin >> pos1 >> pos2;
			cout << "请输入路径：" << "\n";
			cin >> m;
			try
			{
				g.InsertArc(pos1, pos2, m);
			}
			catch (string s)
			{
				cout << s << "，插入失败！" << endl;
			}

			break;

		case 7:                  //深度遍历
			cout << "请输入顶点：" << "\n";
			int mm;
			cin >> mm;

			for (i = 0; i < MaxSize; i++)
				visited[i] = 0;
			cout << endl;
			cout << "----递归算法----" << endl;
			try {
				g.DFSTraverse(mm);   //递归算法
			}
			catch (string s)
			{
				cout << s << "，输入失败！" << endl;
			}
			cout << endl;
			cout << "-----------------------" << endl;

			//------------------------------
			cout << endl;
			for (i = 0; i < MaxSize; i++)
				visited[i] = 0;
			try {
				g.FDG_DFSTraverse(mm);  //非递归算法             
			}
			catch (string s)
			{
				cout << s << "，输入失败！" << endl;
			}
			break;

		case 8:                  //广度遍历
			cout << "请输入顶点：" << "\n";

			for (i = 0; i < MaxSize; i++)
				visited2[i] = 0;

			int mr;
			cin >> mr;
			try
			{
				g.BFSTraverse(mr);
				cout << endl;
			}
			catch (string s)
			{
				cout << s<<"，输入失败！" << endl;
			}
			break;

		case 10:              //退出
			choose = 0;
			break;
		}
	}
	return 0;
}
