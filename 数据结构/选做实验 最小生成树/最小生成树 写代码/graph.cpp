#include<iostream>
#include <string>                  //引入标准库中的头文件
#include "graph.h"                //引入头文件
using namespace std;

//邻接矩阵  无向图

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

	for (i = 0; i < vertexNum; i++)    //初始化邻接矩阵,也可MAXSIZE，全部置大值
		for (j = 0; j < vertexNum; j++)
			arc[i][j] = 10000;

	int Weight;
	for (k = 0; k < arcNum; k++)   //依次输入每一条边，并修改邻接矩阵的相应元素
	{
		cin >> i >> j >> Weight;                    //边依附的两个顶点的序号
		arc[i][j] = Weight;                  //置有边标志
		arc[j][i] = Weight;
	}

	if (arcNum == 0)
	{
		//插入边,用于调试,教材第三版P190 图 6-16
		InsertArc(0, 1, 34);
		InsertArc(0, 2, 46);
		InsertArc(0, 5, 19);

		InsertArc(1, 4, 12);

		InsertArc(2, 3, 17);
		InsertArc(2, 5, 25);

		InsertArc(3, 4, 38);
		InsertArc(3, 5, 25);

		InsertArc(4, 5, 26);
	}
}

template <class T>
void MGraph<T>::PutVex(int i, T value)           //取所有顶点            
{
	if (i > vertexNum - 1 || i < 0) throw string("位置异常");
	vertex[i] = value;
}

/*
 *前置条件：图已存在
 *输    入：无
 *功    能：输出图中所有顶点的数据信息
 *输    出：图中所有顶点的数据信息
 *后置条件：图保持不变
 */
template <class T>
void MGraph<T>::PrintVex()
{
	//假设源点是第0个顶点，即顶点序号是0
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
	if (i > vertexNum - 1 || i < 0)
		throw string("位置异常");              //顶点i不存在则抛出异常
	else
		cout << vertex[i] << endl;                       //返回顶点i	
}

/*
 *前置条件：图已存在
 *输    入：顶点name,位置num
 *功    能：在图中num位置插入一个顶点name
 *输    出：如果插入不成功，抛出异常
 *后置条件：如果插入成功，图中增加了一个顶点
 */
template <class T>
void MGraph<T>::InsertVex(int num, T name)        //在图中插入一个顶点，其编号为i，值为value
{                                                //假设源点是第0个顶点，即顶点序号是0
	if (num<0 || num>vertexNum) throw string("位置异常");       //如果num输入不正确抛出异常
	int row;                                        //行
	int col;                                        //列
	int numv = vertexNum - 1;                                      //最后一个顶点所在的位置

	vertexNum++;                                   //顶点数加1

	for (int i = numv; i >= num; i--)                      //i从最后一个顶点的下一个位置开始循环
		vertex[i + 1] = vertex[i];                       //把从num位置的顶点到最后一个顶点均向后移一位

	vertex[num] = name;                            //把要插入的顶点的值放在num位置上

	for (row = numv; row >= 0; row--)                      //把从num列到最后一列的元素均向下移一列
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
	if (pos<0 || pos>vertexNum - 1) throw string("位置异常");       //如果pos输入不正确抛出异常
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
	//如果输入不正确抛出异常
	if (i > vertexNum - 1 || j > vertexNum - 1 || i < 0 || j < 0) throw string("位置异常");    
	
	if (arc[i][j] == 10000)
	{
		cout << "顶点之间没有边，无法删除" << endl;
	}
	else {
		arc[i][j] = 10000;
		arc[j][i] = 10000;
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
void MGraph<T>::InsertArc(int i, int j, int n)   //在图中插入一条边，其依附的两个顶点的编号为i和j，边权n
{
	//如果输入不正确抛出异常	
	if (i > vertexNum - 1 || j > vertexNum - 1 || i < 0 || j < 0) throw string("位置异常"); 
	
	if (arc[i][j] < 10000)
	{
		cout << "顶点之间已存在边，无法插入" << endl;
	}
	else {
		arc[i][j] = n;
		arc[j][i] = n;
		arcNum++;
	}
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
	if (v >= vertexNum) throw string("位置异常");   //如果输入不正确抛出异常

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
	if (v >= vertexNum) throw string("位置异常");   //如果输入不正确抛出异常

	int front = -1;
	int rear = -1;                         //初始化队列,假设队列采用顺序存储且不会发生溢出
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
	int row, col;
	for (row = 0; row < vertexNum; row++)
		for (col = 0; col < vertexNum; col++)
			if (arc[row][col] < 10000)
				cout << "从" << vertex[row] << "到" << vertex[col] << "的路径长度为：" << arc[row][col] << endl;
}

/*基于深度优先遍历的 深度优先生成树 教材 p217 3(5)*/
template <class T>
void MGraph<T>::SpaningTree(int v)
{

	if (v >= vertexNum) throw string("位置异常");   //如果输入不正确抛出异常

	visited[v] = 1;                    //已访问v顶点

	for (int j = 0; j < vertexNum; j++)
	{
		if (arc[v][j] < 10000 && visited[j] == 0)
		{
			cout << "(v" << v << " , v" << j << ") " << arc[v][j] << endl;
			SpaningTree(j);
		}
	}
}

template<class T>
void MGraph<T>::BFSTree(int v)
{
	if (v >= vertexNum) throw string("位置异常");   //如果输入不正确抛出异常
	int front = -1;
	int rear = -1;                         //初始化队列,假设队列采用顺序存储且不会发生溢出
	int Q[MaxSize];

	visited2[v] = 1;
	Q[++rear] = v;

	while (front != rear)
	{
		v = Q[++front];                     //将队头元素出队并送到v中
		for (int j = 0; j < vertexNum; j++)
		{
			if (arc[v][j] < 10000 && visited2[j] == 0) {
				cout << "(v" << v << " , v" << j << ") " << arc[v][j] << endl;
				visited2[j] = 1;
				Q[++rear] = j;
			}
		}
	}
}

/* Prim算法 从v开始建立最小生成树*/
template <class T>
void MGraph<T>::Prim(int v)  
{
	cout << "===============================" << endl;
	cout << "最小生成树Prim 算法" << endl;
	cout << "-------------------------------" << endl;

	int i, j, k;
	int adjvex[MaxSize]; //顶点相邻点信息（当前选中的顶点下标）
	int lowcost[MaxSize];//顶点相连边权信息（当前顶点所有相连边权）

	//更新顶点与初始顶点v相邻信息，以及顶点与v边权信息
	for (i = 0; i < vertexNum; i++)
	{
		lowcost[i] = arc[v][i];
		adjvex[i] = v;
	}
	lowcost[v] = 0;

	for (k = 1; k < vertexNum; k++)  //循环n-1次，需要找到n-1条边，构成最小生成树
	{
		//找与当前顶点相连最短边的邻接点下标j
		int min_cost = 10000;
		int	 j = -1;
		for (i = 0; i < vertexNum; i++)
		{
			if (lowcost[i] < min_cost && lowcost[i] != 0)
			{
				min_cost = lowcost[i];
				j = i;
			}
		}

		//选取最短边加入最小生成树
		cout << "(v" << adjvex[j] << " , v" << j << ") " << lowcost[j] << endl;

		//更新相邻顶点信息和边权信息，注意：与j相连边权比lowcost大的情况，不更新相邻点和边权
		lowcost[j] = 0;
		for (i = 0; i < vertexNum; i++)
		{
			if (arc[i][j] < lowcost[i])
			{
				lowcost[i] = arc[i][j];
				adjvex[i] = j;
			}
		}
	}
	cout << "-------------------------------" << endl;
}

template <class T>
int MGraph<T>::FindRoot(int parent[], int v)
{
	int t = v;
	while (parent[t] > -1)
		t = parent[t];
	return t;
}

/* Kruskal算法 建立最小生成树*/
template <class T>
void MGraph<T>::Kruskal()
{
	//边表数组定义（为后续操作：按边权递增排序，依次加入最小生成树，遇环则不加入，生成n-1条边为止
	struct EdgeType
	{
		int from, to;
		int weight;
	}Edge[50];//最多n*（n-1)/2条边，可根据具体应用修改

	//建立边表
	int i, j;
	int edgeNum = 0;
	for (i = 0; i < vertexNum; i++) // 扫描邻接矩阵上三角,无向图对称矩阵
	{
		for (j = i + 1; j < vertexNum; j++)
		{
			if (arc[i][j] < 10000)//存在边
			{
				edgeNum++;
				Edge[edgeNum - 1].from = i;
				Edge[edgeNum - 1].to = j;
				Edge[edgeNum - 1].weight = arc[i][j];
			}
		}
	}

	//实现：边集数组排序，可采用选择排序 --参考教材Ver3  P268 SelectSort()
	for (i = 0; i < edgeNum - 1; i++)
	{
		int index=i;
		EdgeType temp;
		for (j = i+1; j < edgeNum - 1; j++)
		{
			if (Edge[j].weight < Edge[index].weight)
			{
				index = j;
			}
		}
		if (index != i)
		{
			temp = Edge[i];
			Edge[i] = Edge[index];
			Edge[index] = temp;
		}
	}




	//依次加最小权的边，判断是否出现环，出现则跳过不加
	cout << "===========================" << endl;
	cout << "最小生成树 Kruskal 算法" << endl;
	cout << "---------------------------" << endl;
	int parent[MaxSize];//父节点下标数组,不为-1表示从父节点parent[i]到顶点i存在边（且被选中加入最小生成树），-1则无连通
	for (i = 0; i < vertexNum; i++)
		parent[i] = -1;

	int num = 0;
	int vex1, vex2;

	//实现：边集数组中检查并加入n-1条边
	for (i = 0; i < edgeNum; i++)
	{
		//找到根节点，判断是否出现环
		vex1 = FindRoot(parent, Edge[i].from);
		vex2 = FindRoot(parent, Edge[i].to);
		//无环则加入边，更新parent信息，一方并入另一方（根节点挂到另一棵树)
		if (vex1 != vex2)
		{
			cout << "(v" << Edge[i].from << ",v" << Edge[i].to << ")" << Edge[i].weight << endl;
			parent[Edge[i].to] = Edge[i].from;
			num++;
			if (num == vertexNum - 1)
			{
				break;
			}
		}
	}
	cout << "---------------------------" << endl;

}
