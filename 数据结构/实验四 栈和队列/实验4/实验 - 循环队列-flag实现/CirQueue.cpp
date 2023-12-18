//CirQueue.cpp
#include <string>
using namespace std;
#include "CirQueue.h"

/*
 * 前置条件：队列不存在
 * 输    入：无
 * 功    能：初始化队列
 * 输    出：无
 * 后置条件：创建一个空队列
 */

template <class T>
CirQueue<T>::CirQueue( ) 
{
    //=========学生完成：修改初始化（现在无需费一个空间），初始化 flag================
	front=rear=0;
    flag = false; // 初始化flag为false
} 

/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：销毁队列
 * 输    出：无
 * 后置条件：释放队列所占用的存储空间
 */

template <class T>
CirQueue<T>::~CirQueue( )
{

}

/*
 * 前置条件：队列已存在
 * 输    入：元素值x
 * 功    能：在队尾插入一个元素
 * 输    出：如果插入不成功，抛出异常
 * 后置条件：如果插入成功，队尾增加了一个元素
 */

template <class T> 
void CirQueue<T>::EnQueue(T x)
{
    //=========学生完成：改成flag实现，判断队满=================
    //if ((rear+1) % QueueSize ==front) throw string("队满异常");
    if (flag)
    {
        throw string("队满异常");
    }
    else
    {
        rear = (rear + 1) % QueueSize;   //队尾指针在循环意义下加1
        data[rear] = x;                //在队尾处插入元素
        if (rear == front) 
        {
            flag = true;    // 设置flag为true，表示队列已满
        }
    }
   

    //=========学生完成：检查是否要改flag及怎么改===============

}

/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：删除队头元素
 * 输    出：如果删除成功，返回被删元素值，否则，抛出删除异常
 * 后置条件：如果删除成功，队头减少了一个元素
 */

template <class T> 
T CirQueue<T>::DeQueue( )
{
    //=========学生完成：改成flag实现，判断队空==================
    if (rear == front)
    {
        throw string("队空异常");
    }
    else 
    {
        front = (front + 1) % QueueSize;    //队头指针在循环意义下加1
        if (flag)
        {
            flag = false;   // 队列非满状态
        }
    }
    

    //=========学生完成：检查是否要改flag及怎么改==================

    return data[front];             //读取并返回出队前的队头元素，注意队头指针
}

/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：读取队头元素
 * 输    出：若队列不空，返回队头元素
 * 后置条件：队列不变
 */

template <class T>
T CirQueue<T>::GetQueue( )
{   
    //=========学生完成：改成flag实现，判断队空==================
    if (rear == front)
    {
        throw string("队空异常");
    }
    else
    {
        int i;
        i = (front + 1) % QueueSize;  //注意不要给队头指针赋值
        return data[i];
    }
    
}

/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：判断队列是否为空
 * 输    出：如果队列为空，返回1，否则，返回0
 * 后置条件：队列不变
 */

template <class T> 
bool CirQueue<T>::Empty( ) 
{
    //=========学生完成：改成flag实现，判断队空==================
    if (front==rear) 
		return 1; 
	else 
		return 0;
}

/*
*前置条件：队列已存在
* 输    入：无
* 功    能：判断队列是否满
* 输    出：如果队列满，返回 true，否则，返回 false
* 后置条件：队列不变
*/

template <class T>
bool CirQueue<T>::Full()
{
    // 判断队列是否满
    if ((rear + 1) % QueueSize == front) {
        return true; // 队列满
    }
    else {
        return false; // 队列不满
    }
}
