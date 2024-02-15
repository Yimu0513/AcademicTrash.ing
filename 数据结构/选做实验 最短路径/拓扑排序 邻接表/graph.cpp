//graph.cpp
#include<iostream>
#include "graph.h"//引入头文件

/*
 *前置条件：图不存在
 *输    入：无
 *功    能：图的初始化
 *输    出：无
 *后置条件：得到一个有向图
 */
template <class T>
ALGraph<T>::ALGraph(T a[], int n, int e)
{
	arcNum = e;                             //边数
	vertexNum = n;                            //顶点数
	int i, j;
	for (i = 0; i < vertexNum; i++)
	{
		VertexNode<T> tempvertex;
		tempvertex.vertex = a[i];
		tempvertex.firstedge = NULL;
		adjlist[i] = tempvertex;
	}

	for (int k = 0; k < arcNum; k++)           //依次输入每一条边，并在相应边表中插入结点
	{
		cout << "请输入边所依附的两个顶点的序号";
		cin >> i >> j;                         //输入边所依附的两个顶点的序号
		ArcNode* s = new ArcNode; s->adjvex = j;  //生成一个边表结点s
		s->next = adjlist[i].firstedge;      //将结点s插入到结点i的边表的表头  
		adjlist[i].firstedge = s;
	}

	if (arcNum == 0)
	{
		//插入边,用于调试 教材ver3 P202 图6-27
		//B
		InsertArc(1, 0);
		InsertArc(1, 3);
		//C
		InsertArc(2, 0);
		InsertArc(2, 3);
		//D
		InsertArc(3, 0);
		InsertArc(3, 5);
		//E
		InsertArc(4, 2);
		InsertArc(4, 3);
		InsertArc(4, 5);

	}
}
/*   前置条件：图已存在
 *   输    入：无
 *   功    能：销毁图
 *   输    出：无
 *   后置条件：释放图所占用的存储空间
 */
template <class T>
ALGraph<T>::~ALGraph()
{
	for (int i = 0; i < vertexNum; i++)
	{
		ArcNode* p = adjlist[i].firstedge;
		while (p != NULL)                                              //循环删除
		{
			adjlist[i].firstedge = p->next;
			delete p;                                                 //释放结点空间
			p = adjlist[i].firstedge;
		}
	}
}
/*
 *前置条件：图已存在
 *输    入：顶点i
 *功    能：输出图中顶点i的数据信息
 *输    出：图中顶点i的数据信息
 *后置条件：图保持不变
 */
template <class T>
T ALGraph<T>::GetVex(int i)
{
	if (i > vertexNum || i < 0) throw string("输入顶点的位置不正确"); //顶点i不存在则抛出异常
	return adjlist[i].vertex;                               //返回第i个顶点的数据域  
}

/*
 *前置条件：图已存在
 *输    入：顶点i
 *功    能：将图中顶点i的数据域置为value
 *输    出：无
 *后置条件：图保持不变
 */
template <class T>
void ALGraph<T>::PutVex(int i, T value)
{
	if (i > vertexNum || i < 0) throw string("输入顶点的位置不正确"); //顶点i不存在则抛出异常
	adjlist[i].vertex = value;                              //第i个顶点的数据域置为value
}

/*
 *前置条件：图已存在
 *输    入：顶点value,位置i
 *功    能：在图中i位置插入一个顶点name
 *输    出：如果插入不成功，抛出异常
 *后置条件：如果插入成功，图中增加了一个顶点
 */
template <class T>
void ALGraph<T>::InsertVex(int i, T value)
{
	if (i > vertexNum || i < 0) throw string("输入顶点的位置不正确"); //顶点i不存在则抛出异常

	ArcNode* s;
	int k;
	for (k = 0; k < vertexNum; k++)               // 调整结点编号：编号大于等于i的结点编号加1
		if (adjlist[k].firstedge != NULL)
		{
			s = adjlist[k].firstedge;
			while (s != NULL)
			{
				if (s->adjvex >= i)
					s->adjvex++;
				s = s->next;
			}
		}

	for (k = vertexNum; k >= i + 1; k--)           //调整顶点表结点
	{
		adjlist[k] = adjlist[k - 1];
	}
	vertexNum++;   //顶点数加1                           

	VertexNode<T> tempvertex;
	tempvertex.vertex = value;
	tempvertex.firstedge = NULL;
	adjlist[i] = tempvertex;  	                    //第i个顶点的数据域置为value	

}

/*
 *前置条件：图已存在
 *输    入：顶点i
 *功    能：在图中删除顶点i
 *输    出：如果删除不成功，抛出异常
 *后置条件：如果删除成功，图中减少了一个顶点,相应顶点所建立的边也消去
 */
template <class T>
void ALGraph<T>::DeleteVex(int i)              //删除结点及相应的边
{
	if (i < 0 || i >= vertexNum) throw string("位置异常");       //顶点输入错误则抛出异常
	int k;

	for (k = 0; k < vertexNum; k++)               //删掉入度边
		if (k != i)	 DeleteArc(k, i);


	if (adjlist[i].firstedge != NULL)          //删掉出度边
	{

		ArcNode* p = adjlist[i].firstedge;
		while (p != NULL)                                              //循环删除
		{
			adjlist[i].firstedge = p->next;
			delete p;                                                 //释放结点空间
			p = adjlist[i].firstedge;
		}
	}

	for (k = i; k < vertexNum - 1; k++)           //调整顶点表结点
	{
		adjlist[k] = adjlist[k + 1];
	}

	vertexNum--;                             //顶点数减1
	//--------------------------------------------------------------------------
	ArcNode* s;
	for (k = 0; k < vertexNum; k++)               // 调整结点编号：编号大于i的结点编号减1
		if (adjlist[k].firstedge != NULL)
		{
			s = adjlist[k].firstedge;
			while (s != NULL)
			{
				if (s->adjvex > i)
					s->adjvex--;
				s = s->next;
			}
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
void ALGraph<T>::InsertArc(int i, int j)
{
	if (i > vertexNum - 1 || j > vertexNum - 1 || i < 0 || j < 0) throw string("位置异常");//顶点输入错误则抛出异常
	ArcNode* s = new ArcNode; s->adjvex = j;      //生成一个边表结点s
	s->next = adjlist[i].firstedge;             //将结点s插入到结点i的边表的表头  
	adjlist[i].firstedge = s;
}

/*
 *前置条件：图已存在
 *输    入：顶点i、j
 *功    能：在图中删除顶点i、j 依附的边
 *输    出：如果删除不成功，抛出异常
 *后置条件：如果删除成功，图中减少了一条边
*/
template <class T>
void ALGraph<T>::DeleteArc(int i, int j)
{
	if (i > vertexNum - 1 || j > vertexNum - 1 || i < 0 || j < 0) throw string("位置异常");  //顶点输入错误则抛出异常
	ArcNode* s;
	int flag = 0;
	ArcNode* pre;
	s = adjlist[i].firstedge;
	pre = adjlist[i].firstedge;
	while (s != NULL && s->adjvex != j)
	{
		pre = s;
		s = s->next;
		flag = 1;
	}
	if (s != NULL)
	{

		if (flag == 0)
			adjlist[i].firstedge = s->next;
		else
			pre->next = s->next;
		delete s;
	}
}

/*
 *前置条件：图已存在
 *输    入：遍历的起始顶点v
 *功    能：从顶点v出发深度优先遍历图
 *输    出：图中顶点的一个线性排列
 *后置条件：图保持不变
 */
template <class T>
void ALGraph<T>::DFSTraverse(int v)
{
	if (v >= vertexNum) throw string("位置异常");                          //顶点输入错误则抛出异常
	ArcNode* p;
	int j;
	cout << adjlist[v].vertex << " ";
	visited[v] = 1;
	p = adjlist[v].firstedge;
	while (p)                                                //依次搜索顶点v的邻接点j
	{
		j = p->adjvex;
		if (visited[j] == 0) DFSTraverse(j);
		p = p->next;
	}

}


 //基于深度度优先遍历的判定两点是否存在通路, 1:存在，0:不存在
template <class T>
void ALGraph<T>::DFSTconJudge(int vi, int vj)  
{
	if (MyFlag > 0)// MyFlag 全局变量 标记，1表示存在通路，否则为0
		return;  
	if (vi >= vertexNum || vj >= vertexNum || vi <0 || vj<0) throw string("位置异常");                          //顶点输入错误则抛出异常
	
	ArcNode* p;
	int j;
	cout << adjlist[vi].vertex << " ";
	visited[vi] = 1;

	p = adjlist[vi].firstedge;
	while (p)    //依次搜索顶点v的邻接点j
	{
		j = p->adjvex;
		if (j == vj)
		{
			cout << adjlist[j].vertex << " ";   MyFlag = 1; return;
		}

		if (visited[j] == 0) DFSTconJudge(j, vj);

		p = p->next;
	}
}

template <class T>
void ALGraph<T>::BFSTraverse(int v)
{
	if (v >= vertexNum || v<0) throw string("位置异常");   //顶点输入错误则抛出异常

	int front, rear, j;
	ArcNode* p;                                              //生成一个边表结点p
	
	int Q[MaxSize];
	front = rear = -1;    //初始化队列, 假设队列采用顺序存储且不会发生溢出
	cout << adjlist[v].vertex << " ";  visited[v] = 1; Q[++rear] = v; //被访问顶点入队
	
	while (front != rear)
	{
		v = Q[++front];
		p = adjlist[v].firstedge;                                //边表中的工作指针p初始化
		while (p)
		{
			j = p->adjvex;
			if (visited[j] == 0)
			{
				cout << adjlist[j].vertex << " "; visited[j] = 1; Q[++rear] = j;
			}
			p = p->next;
		}
	}
	cout << endl;
}

//基于广度优先遍历的判定两点是否存在通路, 1:存在，0:不存在
template <class T>
int ALGraph<T>::BFSTconJudge(int vi, int vj)         
{
	if (vi >= vertexNum || vj >= vertexNum || vi < 0 || vj < 0) throw string("位置异常");

	int front, rear, j;
	ArcNode* p;             //生成一个边表结点p
	int Q[MaxSize];
	front = rear = -1;       //初始化队列, 假设队列采用顺序存储且不会发生溢出
	
	cout << adjlist[vi].vertex << " ";  visited[vi] = 1; Q[++rear] = vi; //被访问顶点入队
	
	while (front != rear)
	{
		vi = Q[++front];
		p = adjlist[vi].firstedge;                                //边表中的工作指针p初始化
		while (p)
		{//所有未访问邻接点，访问，并入队列
			j = p->adjvex;
			if (visited[j] == 0)
			{
				cout << adjlist[j].vertex << " "; visited[j] = 1; Q[++rear] = j;
			}

			if (j == vj) return 1;//广度优先遍历，在邻接点中发现vj，说明存在通路
			
			p = p->next;
		}
	}
	cout << endl;
	return 0;
}


//拓扑排序
template <class T>
void ALGraph<T>::TopSort()
{
	ArcNode* p;
	int i, j, k;

	//==================计算顶点表中的入度域=====================
	for (i = 0; i < vertexNum; i++)
		adjlist[i].in = 0;
	for (i = 0; i < vertexNum; i++)   //扫描顶点表
	{
		p = adjlist[i].firstedge;
		while (p != NULL)            //扫描顶点i 的边表,处理入度
		{
			k = p->adjvex;
			adjlist[k].in++;	//从顶点i出发相连的顶点入度加1
			p = p->next;
		}

	}

	cout << "===========================" << endl;
	cout << "--------拓扑排序-----------" << endl;
	
	int S[100];//工作栈
	int top = -1;
	int count = 0;//计数，拓扑排序完 = 顶点数，否则有回路
	
	for (i = 0; i < vertexNum; i++)
		if (adjlist[i].in == 0)//没有入边的顶点，压栈
		{
			top++;
			S[top] = i;
		}

	while (top != -1)
	{
		j = S[top];
		top--;//栈顶元素出栈，进入拓扑序列
		cout << adjlist[j].vertex << ", ";
		count++;

		p = adjlist[j].firstedge;
		while (p != NULL)            //扫描顶点j 的边表,处理入度
		{
			k = p->adjvex;
			adjlist[k].in--; //出栈的顶点相连边的入度-1

			if (adjlist[k].in == 0)//检查入度，顶点k没有入度则压栈
			{
				top++;
				S[top] = k;
			}
			p = p->next;
		}
	}
	
	cout << endl;
	if (count < vertexNum)//拓扑排序完还剩余顶点（无法包含在拓扑序列中），则存在环
		cout << " 有回路!!!" << endl;
	cout << "------------------------" << endl;
}