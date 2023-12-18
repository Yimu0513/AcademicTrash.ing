//声明类BiTree及定义结构BiNode,文件名为bitree.h
#ifndef BITREE_H
#define BITREE_H

const int ASize = 20;
//"AB#D##C##";
//"ABD#G###CE##F##";
extern char PreOrderString[ASize];
extern int chCnt;
extern int Count;
extern int DeepL;
extern int DeepR;

template <class T>
struct BiNode   //二叉树的结点结构
{
  T data;       
  BiNode<T> *lchild, *rchild;
};

template <class T>
class BiTree
{
public:
             
	BiTree(int flag );     //改进输入的构造
    ~BiTree(void);         //析构函数，释放二叉链表中各结点的存储空间
	BiNode<T>* Getroot();  //获得指向根结点的指针
    void PreOrder(BiNode<T> *root);     //前序遍历二叉树
    void InOrder(BiNode<T> *root);      //中序遍历二叉树
    void PostOrder(BiNode<T> *root);    //后序遍历二叉树
    void LevelOrder(BiNode<T> *root);   //层序遍历二叉树
    void CountNode(BiNode<T>* root);    //计算叶子节点
    void PrintLeafNode(BiNode<T>* root); //按照前序顺序打印叶子节点
    int DepthTree(BiNode<T>* root); //计算二叉树深度

private:
    BiNode<T> *root;         //指向根结点的头指针
    BiNode<T> *Creat( );     //有参构造函数调用
	BiNode<T> *Creat1( );    //改进输入
    void Release(BiNode<T> *root);   //析构函数调用 
};
#endif