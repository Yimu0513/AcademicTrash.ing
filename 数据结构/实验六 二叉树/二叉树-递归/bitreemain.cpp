//二叉树的主函数，文件名为bitreemain.cpp
#include<iostream>
#include<string>
#include"bitree.cpp"
using namespace std;

//char PreOrderString[]="AB#D##C##";
char PreOrderString[]="ABD##EH###CF#I##G##";
int chCnt = 0;
int Count = 0;
int DeepL = 0, DeepR = 0;


int main()
{	
    //按前序创建一棵树 p144 5-24 (AB#D##C##) 或 p141 5-20 (ABD#G###CE##F##)【第三版】

	//BiTree<string> bt(1); //----键盘输入-------       
    BiTree<string> bt(0); //-----用PreOrderString, 自动输入-----
       
	BiNode<string>* root = bt.Getroot( );  //获取指向根结点的指针 

	cout<<"------前序遍历------ "<<endl;
	bt.PreOrder(root);
    cout<<endl;
   

	cout<<"------中序遍历------ "<<endl;
	bt.InOrder(root);
	cout<<endl;


	cout<<"------后序遍历------ "<<endl;
	bt.PostOrder(root);
	cout<<endl;
   

	cout<<"------层序遍历------ "<<endl;
	bt.LevelOrder(root);
	cout<<endl;

	cout << "------算法设计部分------ " << endl;
	cout << "------计算结点个数------ " << endl;
	bt.CountNode(root);
	cout << "此二叉树中共有" << Count << "个结点" << endl;

	cout << "------前序次序打印叶子节点------ " << endl;
	bt.PrintLeafNode(root);
	cout << endl;

	cout << "------计算二叉树深度------ " << endl;
	cout << "二叉树深度为" << bt.DepthTree(root) << endl;



	return 0;
}