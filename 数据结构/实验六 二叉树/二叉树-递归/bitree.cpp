//定义类中的成员函数，文件名为bitree.cpp
#include<iostream>
#include<string>
#include"bitree.h"
using namespace std;

/*
 *前置条件：二叉树不存在
 *输    入：无
 *功    能：构造一棵二叉树
 *输    出：无
 *后置条件：产生一棵二叉树 
 */
template<class T>
BiTree<T>::BiTree( int flag)
{   if (flag>0)
    	this->root = Creat( ); //键盘输入
    else
	    this->root = Creat1( );	 //自动
}

/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：释放二叉链表中各结点的存储空间
 *输    出：无
 *后置条件：二叉树不存在 
 */
template<class T>
BiTree<T>::~BiTree(void)
{
	Release(root);
}

/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：获取指向二叉树根结点的指针
 *输    出：指向二叉树根结点的指针
 *后置条件：二叉树不变 
 */
template<class T>
BiNode<T>* BiTree<T>::Getroot( )
{
	return root;
}

/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：前序遍历二叉树
 *输    出：二叉树中结点的一个线性排列
 *后置条件：二叉树不变 
 */
template<class T>
void BiTree<T>::PreOrder(BiNode<T> *root)
{
	if(root==NULL)  return;
	else{		
		cout<<root->data<<" ";
        PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}

/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：中序遍历二叉树
 *输    出：二叉树中结点的一个线性排列
 *后置条件：二叉树不变 
 */
template <class T>
void BiTree<T>::InOrder (BiNode<T> *root)
{
    if (root==NULL)  return;      //递归调用的结束条件	          
    else{	
        InOrder(root->lchild);    //中序递归遍历root的左子树
        cout<<root->data<<" ";    //访问根结点的数据域
        InOrder(root->rchild);    //中序递归遍历root的右子树
	}
}

/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：后序遍历二叉树
 *输    出：二叉树中结点的一个线性排列
 *后置条件：二叉树不变 
 */
template <class T>
void BiTree<T>::PostOrder(BiNode<T> *root)
{ 
    if (root==NULL)   return;       //递归调用的结束条件
    else{	
        PostOrder(root->lchild);    //后序递归遍历root的左子树
        PostOrder(root->rchild);    //后序递归遍历root的右子树
        cout<<root->data<<" ";      //访问根结点的数据域
	}
}

/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：层序遍历二叉树
 *输    出：二叉树中结点的一个线性排列
 *后置条件：二叉树不变
 */
template <class T>
void BiTree<T>::LevelOrder(BiNode<T> *root)
{
	const int MaxSize = 100;

	int front = 0;
	int rear = 0;  //采用顺序队列，并假定不会发生上溢

	BiNode<T>* Q[MaxSize];
    BiNode<T>* q;

	if (root==NULL) return;
	else{
		Q[rear++] = root;
		while (front != rear)
		{
			q = Q[front++];
     		cout<<q->data<<" "; 		
    		if (q->lchild != NULL)    Q[rear++] = q->lchild;		
			if (q->rchild != NULL)    Q[rear++] = q->rchild;
		}
	}
}


/*
 *前置条件：空二叉树
 *输    入：数据ch;
 *功    能：初始化一棵二叉树,构造函数调用
 *输    出：无
 *后置条件：产生一棵二叉树
 */
template <class T>
BiNode<T>* BiTree<T>::Creat( )
{
	BiNode<T>* bt;
	T ch;
	cout<<"请输入创建一棵二叉树的结点数据"<<endl;
	cin>>ch;
    if (ch=="#") bt = NULL;
    else{ 
	     bt = new BiNode<T>;       //生成一个结点
         bt->data=ch;
         bt->lchild = Creat( );    //递归建立左子树
         bt->rchild = Creat( );    //递归建立右子树
    } 
    return bt;
}

//-------------自动创建--------------------------------
template <class T>
BiNode<T>* BiTree<T>::Creat1( )
{
	BiNode<T>* bt;
	T ch;

	ch=PreOrderString[chCnt]; //PreOrderString 全局变量
	chCnt++;

    if (ch=="#") bt = NULL;
    else{ 
	     bt = new BiNode<T>;       //生成一个结点
         bt->data=ch;
         bt->lchild = Creat1( );    //递归建立左子树
         bt->rchild = Creat1( );    //递归建立右子树
    } 
    return bt;
}


/*
 *前置条件：二叉树已经存在
 *输    入：无
 *功    能：释放二叉树的存储空间，析构函数调用
 *输    出：无
 *后置条件：二叉树不存在
 */
template<class T>
void BiTree<T>::Release(BiNode<T>* root)
{
  if (root != NULL){                  
	  Release(root->lchild);   //释放左子树
      Release(root->rchild);   //释放右子树
      delete root;
  }  
}

template<class T>
void BiTree<T>::CountNode(BiNode<T>* root)
{
	if (root == NULL) return;
	else
	{
		Count++;  //定义全局静态变量并初始化为0
		CountNode(root->lchild);
		CountNode(root->rchild);
	}
}

template<class T>
void BiTree<T>::PrintLeafNode(BiNode<T>* root)
{
	if (root == NULL) return;
	else
	{
		if (root->lchild == NULL && root->rchild == NULL)
		{
			cout <<root->data<<" ";
		}
		PrintLeafNode(root->lchild);
		PrintLeafNode(root->rchild);
	}
}

template<class T>
int BiTree<T>::DepthTree(BiNode<T>* root)
{
	if (root == NULL) return 0;
	else
	{
		DeepL = DepthTree(root->lchild);
		DeepR = DepthTree(root->rchild);
		return max(DeepL, DeepR) + 1;
	}
}

