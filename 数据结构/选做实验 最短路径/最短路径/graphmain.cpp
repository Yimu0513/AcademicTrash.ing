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
	string vname[7] = { "美食广场","第一教学楼","第二教学楼","图书馆","第一实验楼","第二实验楼","现代教育中心" };  //初始化各顶点 教材ver2 P168(图6-28)；ver3 教材P195(图6-20)
	//string vname[7]={"v0","v1","v2","v3","v4","v5","v6"};  //初始化各顶点 教材ver2P185(图6-51)
	int pos1;                           //顶点
	int pos2;                           //顶点
	int m;
	MGraph<string> g(vname, 7, 0);        //调用Graph程序 教材ver2 P168(图6-28)；ver3 教材P195(图6-20)
	//MGraph<string> g(vname,7,0);        //调用Graph程序  教材ver2 P185(图6-51)
	while (choose == 1)                  //控制
	{
		cout << "++++++++++++++++++++++++++++++++" << "\n";
		cout << "需要输出顶点信息请按0" << "\n";		   //输入所要进行的操作的序号
		cout << "需要输出任意一个顶点信息请按1" << "\n";
		cout << "需要边的信息输出请按2" << "\n";
		cout << "需要删除请按3" << "\n";
		cout << "需要插入请按4" << "\n";
		cout << "需要删除某条边请按5" << "\n";
		cout << "需要插入某条边请按6" << "\n";
		cout << "需要深度优先遍历请按7" << "\n";
		cout << "需要广度优先遍历请按8" << "\n";

		cout << "Dijkstra最短路径(单点源)请按11" << "\n";
		cout << "Dijkstra最短路径(两点间)请按12" << "\n";
		cout << "Floyd最短路径请按13" << "\n";
		cout << "需要退出请按10" << "\n";
		cout << "++++++++++++++++++++++++++++++++" << "\n";
		cin >> which;
		switch (which)                  //功能选择
		{

		case 0:                   //输出图的各顶点的值
			g.PutVex();

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
			g.PutArc();
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
				cout << "删除失败:" << s<< endl;
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
				cout << "插入失败:"<<s << endl;
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
				cout << "删除失败:" <<s<< endl;
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
				cout << "插入失败:"<<s << endl;
			}

			break;

		case 7:                  //深度遍历
			cout << "请输入顶点：" << "\n";
			for (i = 0; i < MaxSize; i++)
				visited[i] = 0;
			int mm;
			cin >> mm;
			try
			{
				g.DFSTraverse(mm);
			}
			catch (string s)
			{
				cout << s << endl;
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
				cout << "\n";
			}
			catch (string s)
			{
				cout <<s << endl;
			}
			break;

		case 10:              //退出
			choose = 0;
			break;

		case 11:                  //Dijkstra 最短路径
			cout << "请输入源点：" << endl;

			int from;
			cin >> from;
			g.Dijkstra(from);
			cout << endl;
			break;

		case 12:                  //Dijkstra 最短路径		  
			int from1, to1;
			cout << "请输入源点：" << endl;
			cin >> from1;
			cout << "请输入终点：" << endl;
			cin >> to1;
			g.Dijkstra2(from1, to1);
			cout << endl;
			break;
		case 13:                  //Floyd 任意两点最短路径

			g.Floyd();
			cout << endl;
			break;

		} //for switch
	}
	return 0;
}
