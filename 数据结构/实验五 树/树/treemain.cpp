//有关树的实现的主函数，文件名为treemain.cpp
#include <iostream>
#include <string>
#include"tree.cpp"
using namespace std;

void main() 
{
    Tree<string> t; //创建一棵树
    /*
       例如对教材P130 图5-3 (a) 可按如下方式输入：
	   A
	   A B
	   C G   //有意输入错误
	   
	   B D
	   B E
	   B F

       C G   //有意输入错误
	   
	   A C
	   C G
	   C H
	   E I
      */
	/*
		选用例1
		
	*/

	TNode<string>* p = t.Getroot( );  //获取指向根结点的指针 
	cout<<"------前序遍历------ "<<endl;
	t.PreOrder(p);
	cout<<endl;
	cout<<"------后序遍历------ "<<endl;
	t.PostOrder(p);
	cout<<endl;
	cout<<"------层序遍历------ "<<endl;
	t.LevelOrder(p);
	cout<<endl;
}