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
		InsertArc(0, 1);                   //插入边,用于调试
		InsertArc(0, 2);
		InsertArc(0, 3);
		InsertArc(1, 3);
		InsertArc(1, 4);
		InsertArc(2, 0);
		InsertArc(2, 4);
		InsertArc(3, 1);
		InsertArc(3, 4);
		InsertArc(4, 2);
		InsertArc(4, 3);
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
	//删除边表结点
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
	if (i > vertexNum-1 || i < 0) throw string("输入顶点的位置不正确"); //顶点i不存在则抛出异常
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
	if (i > vertexNum-1 || i < 0) throw string("输入顶点的位置不正确"); //顶点i不存在则抛出异常
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
	if (i > vertexNum || i<0 || i>MaxSize) throw string("输入顶点的位置不正确"); //顶点i不存在则抛出异常

	if (i < vertexNum) {
		// 调整结点编号：编号大于等于i的结点编号加1
		ArcNode* s;
		int k;
		//处理边表中顶点编号
		for (k = 0; k < vertexNum; k++)              
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

		//调整顶点表结点，编号i+1到n的顶点在顶点数组中往后移
		for (k = vertexNum; k >= i + 1; k--)           
		{
			adjlist[k] = adjlist[k - 1];
		}
	}
	vertexNum++;   //顶点数加1      

	//************************************
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
	//有效可删顶点编号0~n-1
	if (i<0 || i>vertexNum - 1) throw string("位置异常");       //顶点输入错误则抛出异常
	int k;

	//--------------删掉入度边----------------------------       
	for (k = 0; k < vertexNum; k++) 
		if (k != i)	 DeleteArc(k, i);

	//--------------删掉出度边，类似析构----------------------------                             
	if (adjlist[i].firstedge != NULL)
	{
		ArcNode* p = adjlist[i].firstedge;
		while (p != NULL)                                              //循环删除
		{
			adjlist[i].firstedge = p->next;
			delete p;                                                 //释放结点空间
			p = adjlist[i].firstedge;
		}
	}

	//-------//调整顶点表结点，编号i到n-1的顶点在顶点数组中往前移-----------
	for (k = i; k < vertexNum - 1; k++)
	{
		adjlist[k] = adjlist[k + 1];
	}

	vertexNum--;                             //顶点数减1

	//-------------------调整结点编号：编号大于i的结点编号减1-----------------------
	ArcNode* s;
	for (k = 0; k < vertexNum; k++) 
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
	if (i > vertexNum - 1 || j > vertexNum - 1 || i<0 || j<0) throw string("位置异常");//顶点输入错误则抛出异常

	//新增一条i到j的边，即新增边表节点，adjvex邻接点下标j，链到i结点的边表
	ArcNode* s = new ArcNode; s->adjvex = j;      //生成一个边表结点s
	//将结点s插入到结点i的边表的表头  (可改写 插入到表尾）
	s->next = adjlist[i].firstedge;    
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
	if (i > vertexNum-1 || j > vertexNum - 1 || i<0 || j<0) throw string("位置异常");  //顶点输入错误则抛出异常
	
	int flag = 0;//是否删除边是边表第一个结点，1非第一个结点，0是第一个
	
	ArcNode* s;//指向待删边表结点
	ArcNode* pre;//指向待删边表结点的前一个结点
	//s和pre指向顶点i的边表第一个结点
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
			adjlist[i].firstedge = s->next;  //删除第一个结点
		else
			pre->next = s->next;//单链表删结点
		delete s;
		cout << "删除从顶点" << i << "到顶点" << j << "的边" << endl;
	}
	else {
		cout << "从顶点" << i << "到顶点" << j << "没有边，无法删除" << endl;
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
	if (v > vertexNum-1) throw string("位置异常");                          //顶点输入错误则抛出异常

	ArcNode* p;
	int j;
	cout << adjlist[v].vertex << " ";

	visited[v] = 1;
	
	p = adjlist[v].firstedge;//顶点v边表的第一个结点

	while (p)                                                //依次搜索顶点v的邻接点j
	{
		j = p->adjvex;
		if (visited[j] == 0) 
			DFSTraverse(j); //递归实现深度优先，从顶点v开始，所有连通的顶点
		p = p->next;
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
void ALGraph<T>::BFSTraverse(int v)
{
	if (v > vertexNum-1) throw string("位置异常");                           //顶点输入错误则抛出异常

	int front, rear, j;
	int Q[MaxSize];//顶点编号队列
	front = rear = -1;       //初始化队列, 假设队列采用顺序存储且不会发生溢出

	ArcNode* p;                                              //生成一个边表结点p

	cout << adjlist[v].vertex << " ";  
	visited[v] = 1; 
	Q[++rear] = v; //被访问顶点入队

	while (front != rear) //队列不空
	{
		v = Q[++front]; //当前队头顶点出队

		//访问所有v的邻接点（从顶点v出发连通的顶点）
		p = adjlist[v].firstedge;           //边表中的工作指针p初始化
		while (p)
		{
			j = p->adjvex;
			if (visited[j] == 0) {
				cout << adjlist[j].vertex << " "; 
				visited[j] = 1; 
				Q[++rear] = j;//已访问顶点入队
			}
			p = p->next;
		}
	}
	cout << endl;
}

template <class T>
int ALGraph<T>::GetVNum()
{
	return vertexNum;
}

//输出所有边信息
template <class T>
void ALGraph<T>::PrintArc()
{
	int i;
	ArcNode* p;

	for (i = 0; i < vertexNum; i++)
	{
		cout << adjlist[i].vertex << " ";
		p = adjlist[i].firstedge;
		while (p)
		{
			cout << "-->";
			cout << "顶点编号" << p->adjvex;
			p = p->next;
		}
		cout << "^" << endl;
	}
}