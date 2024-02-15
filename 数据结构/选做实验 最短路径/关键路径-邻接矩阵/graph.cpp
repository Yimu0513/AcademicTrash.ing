#include<iostream>
#include <string>                  //引入标准库中的头文件
#include "graph.h"                //引入头文件
using namespace std;

/*
 *前置条件：图不存在
 *输    入：无
 *功    能：图的初始化
 *输    出：无
 *后置条件：构造一个空的图
 */
template <class T>
MGraph<T>::MGraph(T a[], int n, int e)
{
	vertexNum = n;                 //顶点数
	arcNum = e;                    //边数
	int i, j, k;

	for (i = 0; i < vertexNum; i++)
		vertex[i] = a[i];
	for (i = 0; i < vertexNum; i++)    //初始化邻接矩阵
		for (j = 0; j < vertexNum; j++)
			arc[i][j] = 10000;

	int Weight;
	for (k = 0; k < arcNum; k++)   //依次输入每一条边，并修改邻接矩阵的相应元素
	{
		cin >> i >> j >> Weight;                    //边依附的两个顶点的序号
		arc[i][j] = Weight;                  //置有边标志

	}

	if (arcNum == 0)
	{
		//插入边,用于调试，教材ver2 P176(图6-37),ver3 P217(图6-52)
		InsertArc(0, 1, 6);
		InsertArc(0, 2, 4);
		InsertArc(0, 3, 5);
		InsertArc(1, 4, 1);
		InsertArc(2, 4, 1);
		InsertArc(3, 5, 2);
		InsertArc(4, 6, 9);
		InsertArc(4, 7, 7);
		InsertArc(5, 7, 4);
		InsertArc(6, 8, 2);
		InsertArc(7, 8, 4);
	}
}

/*
 *前置条件：图已存在
 *输    入：无
 *功    能：输出图中所有顶点的数据信息
 *输    出：图中所有顶点的数据信息
 *后置条件：图保持不变
 */
template <class T>
void MGraph<T>::PrintVex()           //取所有顶点            
{                                   //假设源点是第0个顶点，即顶点序号是0
	int i = 0;
	for (i = 0; i < vertexNum; i++)
	{                            //输出图中所有的顶点
		cout << vertex[i] << endl;
	}
}

/*
 *前置条件：图已存在
 *输入：顶点i
 *功能：输出图中顶点i的数据信息
 *输出：图中顶点i的数据信息
 *后置条件：图保持不变
 */
template <class T>
void MGraph<T>::GetVex(int i)      //取顶点i             
{
	//假设源点是第0个顶点，即顶点序号是0

	if (i > vertexNum - 1 || i < 0) throw  string("位置异常");              //顶点i不存在则抛出异常
	else
		cout << vertex[i] << endl;
}

/*
 *前置条件：图已存在
 *输    入：顶点name,位置num
 *功    能：在图中num位置插入一个顶点name
 *输    出：如果插入不成功，抛出异常
 *后置条件：如果插入成功，图中增加了一个顶点
 */
template <class T>
void MGraph<T>::InsertVex(int num, T name)        //在图中插入一个顶点，其编号为num，值为name
{
	//假设源点是第0个顶点，即顶点序号是0
	if (num<0 || num>vertexNum) throw string("位置异常");           //如果num输入不正确抛出异常
	int row;                                        //行
	int col;                                        //列
	int numv = vertexNum - 1;                      //最后一个顶点所在的位置

	vertexNum++;                                   //顶点数加1

	//把num~numv，即插入位置原顶点到最后一个顶点往后移一位
	for (int i = numv; i >= num; i--)
		vertex[i + 1] = vertex[i];

	vertex[num] = name;                            //把要插入的顶点的值放在num位置上

	for (row = numv; row >= 0; row--)                      //把从num列到最后一列的元素均向右移一列
	{
		for (col = numv; col >= num; col--)
			arc[row][col + 1] = arc[row][col];
		arc[row][num] = 10000;
	}

	for (row = numv; row >= num; row--)                   //把从num行到最后一行的元素均向下移一行
		for (col = 0; col <= numv + 1; col++)
			arc[row + 1][col] = arc[row][col];
	for (col = 0; col < vertexNum; col++)
		arc[num][col] = 10000;                   //把num位置所在的行、列的值均置为无穷大
}

/*
 *前置条件：图已存在
 *输    入：顶点pos
 *功    能：在图中删除顶点pos
 *输    出：如果删除不成功，抛出异常
 *后置条件：如果删除成功，图中减少了一个顶点,相应顶点所建立的边也消去
 */
template <class T>
void MGraph<T>::DeleteVex(int pos)              //删除第pos个顶点
{                                               //假设源点是第0个顶点，即顶点序号是0
	if (pos<0 || pos>vertexNum - 1) throw string("位置异常");        //如果pos输入不正确抛出异常
	int row;                                       //行
	int col;                                       //列
	int numv = vertexNum;                            //numv等于顶点数

	for (int i = pos; i < numv - 1; i++)
		vertex[i] = vertex[i + 1];                       //把从pos到最后的每个点的位置依次向前移一位

	vertexNum--;                                 //顶点数减1

	for (row = 0; row < numv; row++)
	{
		for (col = pos; col < numv; col++)
			arc[row][col] = arc[row][col + 1];        //把从pos列到最后一列的元素均向前移一列
		arc[row][numv - 1] = 10000;                    //把pos所在的列上的值置为无穷大
	}

	for (row = pos; row < numv; row++)
		for (col = 0; col < numv; col++)
			arc[row][col] = arc[row + 1][col];        //把从pos行到最后一行的元素均向上移一行
}

/*
 *前置条件：图已存在
 *输    入：顶点n、w
 *功    能：在图中删除顶点n、w 依附的边
 *输    出：如果删除不成功，抛出异常
 *后置条件：如果删除成功，图中减少了一条边
 */
template <class T>
void MGraph<T>::DeleteArc(int i, int j)        //在图中删除一条边，其依附的两个顶点的编号为i和j
{
	if (i > vertexNum - 1 || j > vertexNum - 1 || i < 0 || j < 0) throw string("位置异常");;    //如果输入不正确抛出异常
	if (arc[i][j] == 10000) {
		cout << "从顶点" << i << "到顶点" << j << "没有边，无法删除" << endl;
	}
	else {
		arc[i][j] = 10000;
		arcNum--;
	}
}

/*
 *前置条件：图已存在
 *输    入：顶点i、j
 *功    能：在图中插入顶点i、j及其所依附的边
 *输    出：如果插入不成功，抛出异常
 *后置条件：如果插入成功，图中增加了一条边
 */
template <class T>
void MGraph<T>::InsertArc(int i, int j, int n)   //在图中插入一条边，其依附的两个顶点的编号为i和j
{
	if (i > vertexNum - 1 || j > vertexNum - 1 || i < 0 || j < 0) throw string("位置异常");   //如果输入不正确抛出异常	
	arc[i][j] = n;
	arcNum++;
	//cout << "从" << vertex[i] << "到" << vertex[j] << "的路径长度为：" << arc[i][j] << "\n"; //输出插入的两顶点之间的路径
}

/*
 *前置条件：图已存在
 *输    入：遍历的起始顶点v
 *功    能：从顶点v出发深度优先遍历图
 *输    出：图中顶点的一个线性排列
 *后置条件：图保持不变
 */
template <class T>
void MGraph<T>::DFSTraverse(int v)     //深度优先遍历图
{

	if (v >= vertexNum) throw string("位置异常");  //如果输入不正确抛出异常
	cout << vertex[v] << " ";
	visited[v] = 1;                    //已访问v顶点	  
	for (int j = 0; j < vertexNum; j++)
	{
		if (arc[v][j] < 10000 && visited[j] == 0)
			DFSTraverse(j);
	}
}

/*
 *前置条件：图已存在
 *输    入：遍历的起始顶点v
 *功    能：从顶点v出发广度优先遍历图
 *输    出：图中顶点的一个线性排列
 *后置条件：图保持不变
 */
template <class T>
void MGraph<T>::BFSTraverse(int v)     //广度优先遍历图
{
	if (v >= vertexNum) throw string("位置异常");      //如果输入不正确抛出异常

	//初始化队列,假设队列采用顺序存储且不会发生溢出
	int front = -1;
	int rear = -1;                         
	int Q[MaxSize];

	cout << vertex[v] << " ";                //被访问顶点入队
	visited2[v] = 1;
	Q[++rear] = v;

	while (front != rear)
	{
		v = Q[++front];                     //将队头元素出队并送到v中
		for (int j = 0; j < vertexNum; j++)
			if (arc[v][j] < 10000 && visited2[j] == 0) {
				cout << vertex[j] << " ";
				visited2[j] = 1;
				Q[++rear] = j;
			}
	}
}

template <class T>
void MGraph<T>::PrintArc()
{
	//非对称矩阵，带权有向图
	int row, col;
	for (row = 0; row < vertexNum; row++)
		for (col = 0; col < vertexNum; col++)
			if (arc[row][col] != 10000)
				cout << "从" << vertex[row] << "到" << vertex[col] << "的路径长度为：" << arc[row][col] <<endl;
}

//运行前提：(1)节点序号递增序列满足拓扑排序；（2）边的序号与拓扑适应
template <class T>
void MGraph<T>::KeyPath(int Vfrom, int Vto)
{
	int ve[MaxSize], vl[MaxSize];//顶点（事件）最早开始时间和最晚开始时间

	struct EdgeType
	{
		int from, to;//有向边起始和终端顶点编号
		int weight;//边权
		int ee, el;//边（活动）最早开始时间和最晚开始时间
	};

	EdgeType edge[30];
	int vk, vj,i, j, k;

	//建立边表
	int edgeCounter = 0;   //有效边数目
	for (i = Vfrom; i <= Vto; i++)
	{
		for (int j = Vfrom + 1; j <= Vto; j++)
		{
			if (arc[i][j] > 0 && arc[i][j] < 10000)
			{
				edge[edgeCounter].from = i;
				edge[edgeCounter].to = j;
				edge[edgeCounter].weight = arc[i][j];
				edge[edgeCounter].ee = -1;
				edge[edgeCounter].el = -1;
				edgeCounter++;
			}
		}
	}
	//----------------------- 以下计算顶点和边最早/最晚开始时间，边界check！！！！！！！！！
	//计算VE
	ve[Vfrom] = 0;
	int maxve = 0;
	cout << "ve[" << Vfrom << "]=" << ve[Vfrom] << "  ";

	for (vk = Vfrom + 1; vk <= Vto; vk++)
	{
		maxve = 0;
		for (vj = Vfrom; vj <= vk - 1; vj++)
		{//j到k的边存在，拓扑序
			if (arc[vj][vk] > 0 && arc[vj][vk] < 10000 && (arc[vj][vk] + ve[vj] > maxve))
			{
				maxve = arc[vj][vk] + ve[vj];
			}
		}
		ve[vk] = maxve;
		cout << "ve[" << vk << "]=" << ve[vk] << "  ";
	}
	cout << endl << "--------------------" << endl;

	//计算VL
	vl[Vto] = ve[Vto];
	cout << "vl[" << Vto << "]=" << ve[Vto] << "  ";
	int minvl = 10000;

	for (vk = Vto - 1; vk >= Vfrom; vk--)
	{
		minvl = 10000;
		for (vj = vk + 1; vj <= Vto; vj++)
		{//k到j的边存在，逆拓扑序
			if (arc[vk][vj] > 0 && arc[vk][vj] < 10000 && (vl[vj] - arc[vk][vj] < minvl))
				minvl = vl[vj] - arc[vk][vj];
		}
		vl[vk] = minvl;
		cout << "vl[" << vk << "]=" << vl[vk] << "  ";
	}
	cout << endl << "--------------------" << endl;

	//计算ee[i]
	for (i = 0; i < edgeCounter; i++)
	{
		edge[i].ee = ve[edge[i].from];
	}

	//计算el[i]
	for (i = edgeCounter - 1; i >= 0; i--)
	{
		edge[i].el = vl[edge[i].to] - edge[i].weight;

	}

	cout << endl << "-----边的信息---------------" << endl;
	cout << "ee[i]: ";
	for (i = 0; i < edgeCounter; i++)
		cout << edge[i].ee << ",";
	cout << endl;
	cout << "el[i]: ";
	for (i = 0; i < edgeCounter; i++)
		cout << edge[i].el << ",";
	cout << endl;
	cout << endl << "--------------------" << endl;

	//输出关键节点
	cout << "从" << vertex[Vfrom] << " 到 " << vertex[Vto] << "关键节点为：";
	for (i = Vfrom; i <= Vto; i++)
	{
		if (ve[i] == vl[i])
			cout << vertex[i] << ", ";
	}
	cout << endl;

	//输出关键边
	cout << "从" << vertex[Vfrom] << " 到 " << vertex[Vto] << "关键活动(边)为：" << endl;
	for (i = 0; i < edgeCounter; i++)
	{
		if (edge[i].ee == edge[i].el)
		{
			cout << "< " << vertex[edge[i].from] << " , " << vertex[edge[i].to] << ">  " << edge[i].weight << endl;
		}
	}
	cout << endl << "--------------------" << endl;

	//输出最大路径长度
	cout << "从" << vertex[Vfrom] << " 到 " << vertex[Vto] << "工期(最大路径长度)为：";
	cout << vl[Vto] << endl;
}