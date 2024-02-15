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
	string vname[6] = { "v0","v1","v2","v3","v4","v5" };  //初始化各顶点
	int pos1;                           //顶点
	int pos2;                           //顶点
	int m;
	MGraph<string> g(vname, 6, 0);        //调用Graph程序,注意是无向图
	while (choose == 1)                  //控制
	{
		cout << "==================================" << "\n";
		cout << "需要输出顶点信息请按0" << "\n";		   //输入所要进行的操作的序号
		cout << "需要输出任意一个顶点信息请按1" << "\n";
		cout << "需要边的信息输出请按2" << "\n";
		cout << "需要删除请按3" << "\n";
		cout << "需要插入请按4" << "\n";
		cout << "需要删除某条边请按5" << "\n";
		cout << "需要插入某条边请按6" << "\n";
		cout << "需要深度优先遍历请按7" << "\n";
		cout << "需要广度优先遍历请按8" << "\n";
		cout << "最小生成树Prim 算法 请按9" << "\n";
		cout << "深度优先生成树 请按10" << "\n";
		cout << "最小生成树 Kruskal 算法 请按11" << "\n";
		cout << "需要退出请按12" << "\n";
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
				cout <<s<< "，输出不正确！" << endl;
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
				cout << s<<"，删除失败！" << endl;
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
				cout << s<<"，插入失败！" << endl;
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
				cout << s<<"，插入失败！" << endl;
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
				cout << s<<",插入失败！" << endl;
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
				cout <<s<< "，输入失败！" << endl;
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
				cout << s<<"，输入失败！" << endl;
			}
			break;

		case 9:
			cout << "请输入最小生成树起始顶点编号：" << "\n";
			int vs;
			cin >> vs;
			g.Prim(vs);  //从任意点开始建立最小生成树

			break;
		case 10:
			cout << "===============================" << endl;
			cout << "基于深度遍历的深度优先生成树" << endl;
			cout << "-------------------------------" << endl;
			for (i = 0; i < MaxSize; i++)
				visited[i] = 0;
			cout << "请输入生成树起始顶点编号：" << "\n";
			cin >> vs;
			g.SpaningTree(vs);  //基于深度遍历的深度优先生成树 教材ver3 p217 3(5)
			break;

		case 11:
			g.Kruskal();
			break;
		case 12:              //退出
			choose = 0;
			break;
		}
	}
	return 0;
}
