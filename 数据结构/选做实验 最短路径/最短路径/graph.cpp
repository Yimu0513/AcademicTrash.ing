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
		//插入边,用于调试,教材ver2 P168(图6-28)；ver3 教材P195(图6-20)
		InsertArc(0, 1, 10);
		InsertArc(0, 2, 10);
		InsertArc(0, 3, 12);
		InsertArc(1, 3, 5);
		InsertArc(1, 6, 6);
		InsertArc(1, 2, 2);
		InsertArc(1, 4, 4);
		InsertArc(1, 5, 3);
		InsertArc(2, 3, 1);
		InsertArc(2, 5, 4);
		InsertArc(2, 6, 5);
		InsertArc(2, 4, 6);
		InsertArc(3, 4, 4);
		InsertArc(3, 5 ,3);
		InsertArc(4, 5, 2);
		InsertArc(4, 6, 7);
		InsertArc(5, 6, 2);





		//插入边,用于调试,教材ver2  P185(图6-51)
	   /* InsertArc(1,2,4);
		InsertArc(1,3,15);
		InsertArc(1,5,15);

		InsertArc(2,5,15);
		InsertArc(2,4,20);
		InsertArc(2,6,15);

		InsertArc(3,1,10);
		InsertArc(3,2,10);
		InsertArc(3,4,60);

		InsertArc(4,2,30);
		InsertArc(4,6,20);
		*/
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
void MGraph<T>::PutVex()           //取所有顶点            
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
	if (i > vertexNum - 1 || i < 0)
		throw string("位置异常");              //顶点i不存在则抛出异常
	else
		cout << vertex[i]<< endl;                       //返回顶点i	
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
	if (num<0 || num>vertexNum) throw string("插入位置异常");       //如果num输入不正确抛出异常
	int row;                                        //行
	int col;                                        //列
	int numv = vertexNum-1;//最后一个顶点所在的位置
	
	vertexNum++;                                   //顶点数加1
	
	//把num~numv，即插入位置原顶点到最后一个顶点往后移一位
	for (int i = numv; i >= num; i--)
		vertex[i + 1] = vertex[i];

	vertex[num] = name;                            //把要插入的顶点的值放在num位置上

	//调整边数组！！！！！！！！！！
	for (row = numv; row >= 0; row--)                      //把从num列到最后一列的元素均向右移一列
	{
		for (col = numv; col >= num; col--)
			arc[row][col + 1] = arc[row][col];
		arc[row][num] = 10000;						//把num位置所在的列值均置为无穷大
	}

	for (row = numv; row >= num; row--)                   //把从num行到最后一行的元素均向下移一行
		for (col = 0; col <= numv + 1; col++)
			arc[row + 1][col] = arc[row][col];

	for (col = 0; col < vertexNum; col++)
		arc[num][col] = 10000;                   //把num位置所在的行所有值均置为无穷大

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
{      
	//假设源点是第0个顶点，即顶点序号是0
	if (pos<0 || pos>vertexNum - 1) throw string("位置异常");       //如果pos输入不正确抛出异常
	int row;                                       //行
	int col;                                       //列
	int numv = vertexNum;                            //numv等于顶点数

	//pos存在 
	for (int i = pos; i < numv - 1; i++)
		vertex[i] = vertex[i + 1];                       //把从pos到最后的每个点的位置依次向前移一位

	vertexNum--;                                 //顶点数减1

	for (row = 0; row < numv; row++)
	{
		for (col = pos; col < numv; col++)
			arc[row][col] = arc[row][col + 1];        //把从pos列到最后一列的元素均向左移一列
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
	if (i > vertexNum - 1 || j > vertexNum - 1 || i < 0 || j < 0) throw string("位置异常");    //如果输入不正确抛出异常
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

	if (v >= vertexNum) throw string("位置异常");   //如果输入不正确抛出异常

	cout << vertex[v] << " ";
	visited[v] = 1;                    //已访问v顶点	  
	for (int j = 0; j < vertexNum; j++)
	{
		if (arc[v][j] < 10000 && visited[j] == 0)//所有与顶点v连通的顶点依次进行递归访问
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

	while (front != rear)//队列不空
	{
		v = Q[++front];                     //将队头元素出队，v存队头元素
		for (int j = 0; j < vertexNum; j++)
			//广度优先遍历，当前顶点v的所有邻接点（所有从v出发可到达的顶点）
			if (arc[v][j] < 10000 && visited2[j] == 0) {
				cout << vertex[j] << " ";
				visited2[j] = 1;
				Q[++rear] = j; //被访问顶点入队
			}
	}
}


template <class T>
void MGraph<T>::PutArc()
{
	//非对称矩阵，带权有向图
	int row, col;
	for (row = 0; row < vertexNum; row++)
		for (col = 0; col < vertexNum; col++)
			if (arc[row][col] != 10000)
				cout << "从" << vertex[row] << "到" << vertex[col] << "的路径长度为：" << arc[row][col] << "\n";

}

//贪婪法思想
template <class T>
void MGraph<T>::Dijkstra(int v) //单点源
{
	int dist[MaxSize];//v到各个顶点距离
	int i, k;
	int s[MaxSize];
	T path[MaxSize];//其实已默认节点数据类型是字串

	for (i = 0; i < vertexNum; i++)
	{
		dist[i] = arc[v][i];

		if (dist[i] != 10000) 
			path[i] = vertex[v] + "->" + vertex[i];//其实已默认节点数据类型是字串
		else  
			path[i] = "";
	}

	s[0] = v;
	dist[v] = 0;
	int num = 1;

	//观察dist数组的变化！！！！！！！！！！！！！！！！！

	while (num < vertexNum)
	{
		//找到第一个dist不为0的顶点
		for (i = 0; i < vertexNum; i++)
			if (dist[i] != 0) { k = i;  break; }

		//找到dist不为0顶点中dist最小的那个
		for (i = 0; i < vertexNum; i++)
			if (dist[i] != 0 && dist[i] < dist[k])    
				k = i;

		if (dist[k] != 10000)
			cout << path[k] << "(" << dist[k] << ")" << endl;

		s[num++] = k;//将此顶点加入已访问数组

		//更新距离
		for (i = 0; i < vertexNum; i++)
			if (dist[i] > dist[k] + arc[k][i])
			{
				dist[i] = dist[k] + arc[k][i];
				path[i] = path[k] + "->" + vertex[i];
			}

		dist[k] = 0;//将此顶点标记已访问，不再下次迭代中进入dist比较
	} // for while
}


template <class T>
void MGraph<T>::Dijkstra2(int v, int vto) //两点间最短路径
{
	int dist[MaxSize], i, k;
	int s[MaxSize];
	T path[MaxSize];

	for (i = 0; i < vertexNum; i++)
	{
		dist[i] = arc[v][i];
		if (dist[i] != 10000) path[i] = vertex[v] + "->" + vertex[i];
		else  path[i] = "";
	}

	s[0] = v;
	dist[v] = 0;
	int num = 1;

	while (num < vertexNum)
	{
		for (i = 0; i < vertexNum; i++)
			if (dist[i] != 0) 
			{ k = i;  break; }

		for (i = 0; i < vertexNum; i++)
			if (dist[i] != 0 && dist[i] < dist[k])    
				k = i;

		if (k == vto)
		{
			cout << path[k] << "(" << dist[k] << ")" << endl;
			return; //终止过程
		}

		s[num++] = k;

		for (i = 0; i < vertexNum; i++)
			if (dist[i] > dist[k] + arc[k][i])
			{
				dist[i] = dist[k] + arc[k][i];
				path[i] = path[k] + "->" + vertex[i];
			}
		dist[k] = 0;
	} // for while
}

//www.bilibili.com/video/BV1q4411M7r9/

//动态规划思想
template <class T>
void MGraph<T>::Floyd()
{
	int dist[MaxSize][MaxSize], i, j, k;
	T path[MaxSize][MaxSize];

	//根据邻接矩阵信息，初始化dist数组和path（直接相连部分）
	for (i = 0; i < vertexNum; i++)
		for (j = 0; j < vertexNum; j++)
		{
			dist[i][j] = arc[i][j];
			if (dist[i][j] != 10000)
				path[i][j] = vertex[i] + "->" + vertex[j];
			else path[i][j] = "";
		}

	for (k = 0; k < vertexNum; k++)
		for (i = 0; i < vertexNum; i++)
			for (j = 0; j < vertexNum; j++)
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[i][k] + "->" + path[k][j];
				}

	for (i = 0; i < vertexNum; i++)    //输出   
		for (j = 0; j < vertexNum; j++)
			if (i != j && dist[i][j] != 10000)
				cout << path[i][j] << "(" << dist[i][j] << ")" << endl;


}