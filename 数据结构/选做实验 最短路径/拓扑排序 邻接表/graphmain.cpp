//graphmain.cpp
#include <iostream>
#include <string>
#include "graph.cpp"
using namespace std;
int visited[MaxSize];
int MyFlag=0;

void main( )
{
	int which;
	int pos1,pos2;
	int j;
	string name;
	int choose=1;
//	string a[6] = {"A","B","C","D","E","F"};   //教材ver2,P174 图6-35
	string a[6] = {"v0","v1","v2","v3","v4","v5"};   //教材ver3 P202 图6-27
	ALGraph<string> algraphTest( a, 6, 0);        //构造图 注意是有向图
	while ( choose==1 )                                      //控制
	{ cout<<"===================================="<<endl;
	  cout << "需要输出顶点信息请按0" << endl;		         //输入所要进行的操作的序号
	  cout << "需要输出任意一个顶点信息请按1" << endl;
      cout << "需要插入顶点请按2" << endl;
      cout << "需要修改顶点请按3" << endl;
      cout << "需要删除顶点请按4" << endl;      	  
	  cout << "需要深度优先遍历请按5" << endl;
	  cout << "需要广度优先遍历请按6" << endl;
	  cout << "需要删除边请按7" << endl;
	  cout << "需要插入边请按8" << endl;
      cout << "基于 广度  优先遍历的判定两点是否存在通路 请按 9" << endl;
	  cout << "基于 深度  优先遍历的判定两点是否存在通路 请按 10" << endl;
	  cout << "拓扑排序请按11" << endl;
	  cout << "需要退出请按12" << endl;
	  cout<<"===================================="<<endl;
      cin >> which;
      switch( which )                                        //功能选择
	  {
		 case 0:
			 for(j=0;j<6;j++ )
				cout<<algraphTest.GetVex(j)<<" ";              //输出顶点
			 cout<<endl; 
			 break;
		 case 1:
			int i;
			cout<<"请输入顶点："<<endl;
			cin>>i;
			try
			{
				cout<<algraphTest.GetVex(i)<<endl;              //输出i顶点的数据域
			}
		    catch(char* s)
			{
			  cout<<s<<endl;
			}
		    break;
	    case 2:                                               //在图中的i位置插入一顶点值为name
		   cout<<"请输入顶点及名字："<<endl;
		   cin>>i>>name;
		   try
		   {
			  algraphTest.InsertVex(i, name);					              
                        
		   }
		   catch(char* s)
		   {
			  cout<<s<<endl;
		   }
		   break;
		case 3:                                               //修改图中一顶点的值
		   cout<<"请输入顶点及名字："<<endl;
		   cin>>i>>name;
		   try
		   {
			   algraphTest.PutVex(i, name);					              
		   }
		   catch(char* s)
		   {
				cout<<s<<endl;
		   }
		   break;
		case 4:                                               //删除图中一顶点的值
		   cout<<"请输入顶点："<<endl;
		   cin>>i;
		   try
		   {
			    algraphTest.DeleteVex(i);					              
		   }
		   catch(char* s)
		   {
				cout<<s<<endl;
		   }
		   break;
		case 5:                                               //图的深度优先搜索
		   cout<<"请输入顶点："<<endl;
		   cin>>i;
		   cout<<endl<<"从第"<<i<<"个顶点深度优先遍历图"<<endl;
		   try
		   {
				for (int ii=0; ii<MaxSize; ii++) visited[ii] = 0;
	            algraphTest.DFSTraverse(i); 
				cout<<endl;
		   }
		   catch(char* s)
		   {
				cout<<s<<endl;
		   }
		   break;
		case 6:                                               //图的广度优先搜索
		   cout<<"请输入顶点："<<endl;
		   cin>>i;
		   cout<<endl<<"从第"<<i<<"个顶点广度优先遍历图"<<endl;
		   try
		   {
				for (int ii=0; ii<MaxSize; ii++) visited[ii] = 0;
				algraphTest.BFSTraverse(i);					              
		   }
		   catch(char*s)
		   {
				cout<<s<<endl;
		   }
		   break;
	  case 7:                      //删除边       
			  cout<<"请输入两顶点："<<"\n";
			 
			  cin>>pos1>>pos2;
			  try
			  {
				 algraphTest.DeleteArc(pos1,pos2); 
			  }
			   catch(char* s)
			   {
				cout<<s<<endl;
			   }
          
				break;

       case 8:                   //插入一条边         
	      cout<<"请输入两顶点："<<"\n";
		  cin>>pos1>>pos2;
		  
		  try
		  {
			 algraphTest.InsertArc(pos1,pos2);
		  }
		   catch(char* s)
		   {
				cout<<s<<endl;
		   }
          
	        break;

      case 9:
		   cout<<"---------------------------------------"<<endl;
		   cout<<"基于广度优先遍历的判定两点是否存在通路"<<endl;
		   cout<<"---------------------------------------"<<endl;
		   cout<<"请输入两顶点："<<"\n";
		   cin>>pos1>>pos2;
		   //基于广度优先遍历的判定两点是否存在通路 1:存在，0:不存在
		   for ( j=0; j<MaxSize; j++) 
			   visited[j] = 0;
           if ( algraphTest.BFSTconJudge( pos1,pos2 )>0 ) 
			   cout<<"存在通路!"<<endl;
		   else
              cout<<"不连通!"<<endl;
		    cout<<"---------------------------------------"<<endl;
				
		   break;
	case 10:
		 cout<<"---------------------------------------"<<endl;
		   cout<<"基于深度优先遍历的判定两点是否存在通路"<<endl;
		  cout<<"---------------------------------------"<<endl;	
	    	cout<<"请输入两顶点："<<"\n";
		   cin>>pos1>>pos2;
		   //基于深度优先遍历的判定两点是否存在通路 1:存在，0:不存在
		   for ( j=0; j<MaxSize; j++) 
			   visited[j] = 0;
		   MyFlag=0; //全局标记变量
           algraphTest.DFSTconJudge( pos1,pos2 );
           if (MyFlag >0 ) 
			   cout<<"存在通路!"<<endl;
		   else
              cout<<"不连通!"<<endl;
		   cout<<"---------------------------------------"<<endl;
				
		   break;

	 case 11:
           algraphTest.TopSort();
		   break;
     case 12:                                             //退出
		   choose=0;
           break;
	  }
   }
}
 