//二叉树的主函数，文件名为bitreemain.cpp
#include<iostream>
#include<string>
#include"bitree.cpp"
using namespace std;

//char PreOrderString[]="AB#D##C##";
char PreOrderString[]="ABD#G###CE##F##";
int chCnt = 0; 

void main()
{	
    //按前序创建一棵树 p144 5-24 (AB#D##C##) 或 p141 5-20 (ABD#G###CE##F##)【第三版】
	      
    BiTree<string> bt;
                         
	BiNode<string>* root = bt.Getroot( );  //获取指向根结点的指针 

	cout<<"------前序遍历------ "<<endl;
	bt.PreOrder(root);
    cout<<endl;
    cout<<"------非递归前序遍历------ "<<endl;
	bt.fdg_PreOrder(root);
	cout<<endl<<endl;

	cout<<"------中序遍历------ "<<endl;
	bt.InOrder(root);
	cout<<endl;
	cout<<"------非递归中序遍历------ "<<endl;
	bt.fdg_InOrder(root);
	cout<<endl<<endl;

	cout<<"------后序遍历------ "<<endl;
	bt.PostOrder(root);
	cout<<endl;
    cout<<"------非递归后序遍历------ "<<endl;
	bt.fdg_PostOrder(root);
	cout<<endl<<endl;

	cout<<"------层序遍历------ "<<endl;
	bt.LevelOrder(root);
	cout<<endl;

	cout << "------在二叉树中查找X------ " << endl;
	string search;
	cout << "请输入要查找的元素" << endl;
	cin >> search;
	bt.Search(root, search);
	cout << endl;



}