#include <stdio.h>
#include <conio.h>     
#include <string.h>    
#include <windows.h> 

//定义学生信息结构体
struct Stu{  
	char name[20];
	int id;
	double phonenumber;	
};

struct Stu student[50];      //定义结构体，容纳50名同学



int sum;        //定义全局变量，用于记录总共添加的学生数
void AddInformation();       //添加学生信息
void DelInformation();       //删除学生信息
void ChangeInformation();    //修改学生信息
void SelectInformation();      //查看单个学生信息
void PrintInformation();     //显示学生信息
void ShowHomePage();     //登录页面
void HomePage();       //主页功能
void ShowMainMune();    //功能菜单页面
void ShowSelect();      //查询页面
void idSelect();      //学号查询功能
void nameSelect();    //姓名查询功能
void ShowDel();     //确认删除小弹窗



void ShowHomePage()
{
    system("cls");
    printf("    ********************************************\n");
    printf("    *            欢迎使用通讯录系统              *\n");
    printf("    ********************************************\n");
    printf("    *                请您先登陆                 *\n");
    printf("    ********************************************\n");
}
//学生管理系统主菜单
void ShowMainMenu()
{
    system("cls");
    printf("    ********************************************\n");
    printf("    *            欢迎使用管理员功能              *\n");
    printf("    ********************************************\n");
    printf("    *            以下为本系统功能菜单            *\n");
    printf("    *            1.增加同学信息                 *\n");
    printf("    *            2.删除同学信息                 *\n");
    printf("    *            3.修改同学信息                 *\n");
    printf("    *            4.查询同学信息                 *\n");
	printf("    *            5.显示同学信息                 *\n");
    printf("    *            0.退出系统                     *\n");
    printf("    ********************************************\n");
    printf("\n");  
    printf("请输入您要使用的功能：");
} 


void ShowSelect()
{
    system("cls");
    printf("    ********************************************\n");
    printf("    *            欢迎使用管理员功能              *\n");
    printf("    ********************************************\n");
    printf("    *            请选择您的查询方式              *\n");
    printf("    *                1.学号                     *\n");
    printf("    *                2.姓名                     *\n");
    printf("    ********************************************\n");
    printf("\n");  
    printf("请输入您要使用的功能：");

}

void ShowDel()
{
    system("cls");
    printf("    ********************************************\n");
    printf("    *               这是一个弹窗                *\n");
    printf("    ********************************************\n");
    printf("    *       请确认是否要删除该学生的全部信息      *\n");
    printf("    *                1.确认删除                 *\n");
    printf("    *                2.再考虑一下               *\n");
    printf("    ********************************************\n");
    printf("\n");  
    printf("请输入您的选择：");

}


//主函数
int main()
{
    char ch;
    char username[10],password[10];
    ShowHomePage();
    char true_password[20]="123456";
    printf("请输入您的帐号：");
    gets(username);
    int judge=1;
	int try=3;
    while(judge==1){
        int i=0;
        printf("请输入密码:");
        while(i<10)
        {
            ch = getch();
            if(ch == '\r')
            {
                printf("\n");
                break;
            }
            else
            {  
                password[i] = ch;
                printf("*");
                i++;
            }
        }
        if(strcmp(password,true_password)==0)
        {
            judge=0;
        }
        else
        {
            printf("密码输入错误！\n");
			try--;
            judge=1;
        }
		if(try==0)
		{
			printf("您已输入密码错误三次！系统即将关闭！\n");
			Sleep(2000);
			return 0;
		}
    }
    printf("登陆成功！请等待系统缓冲\n");
    Sleep(2000);
    HomePage();

    return 0;
}


void HomePage()
{
	int flag;
	ShowMainMenu();  
	scanf("%d", &flag); 
	while (flag)
	{
		switch (flag)
		{
		case 1:
			AddInformation();
			break;
		case 2:
			DelInformation();
			break;
		case 3:
			ChangeInformation();
			break;
        case 4:
            SelectInformation();
			break;
		case 5:
            PrintInformation();
            break;
		default:
			printf("请输入正确的数字！\n程序将于2秒后跳转到主菜单");
			Sleep(2000);
		}
		ShowMainMenu();
		scanf("%d", &flag);
	}
}

//增加信息
void AddInformation()
{
	int n,i,m;
loop:
    system("cls");
	int flag=1;
	printf("请输入要添加的学号!\n");
	scanf("%d",&n);
	for(i=0;i<sum;i++)
	{
		if(n == student[i].id)
		{
			printf("该学号已存在!\n");
			printf("是否要继续添加？\n是(1)\n否(2)");
			scanf("%d",&flag);
			if(flag==1)
			{
				goto loop;
			}
			else
			{
				printf("系统将于两秒后跳回主菜单！\n");
                Sleep(2000);
			    return;
			}
            
		}
	}
	student[sum].id = n;
    
	printf("请输入要添加的学生姓名!\n");
	scanf("%s",student[sum].name);
	printf("请输入要添加的学生电话!\n");
	scanf("%lf",&student[sum].phonenumber);
	sum++;
	printf("该学生信息添加成功!\n");
	printf("是否要继续添加？\n是(1)\n否(2)将返回主菜单\n");
	scanf("%d",&m);
	if(m == 1)
	{
		goto loop;  //回到指定代码行
	}

}

//删除信息
void DelInformation()
{	
	int n,p;
	int i,j;
	int flag=0;
loop2:
    system("cls");
	printf("请输入要删除学生的学号!\n");
	scanf("%d",&n);
    ShowDel();
	scanf("%d",&p);
	if(p == 1)
	{
		for(i=0;i<sum;i++)
		{
			if(n == student[i].id)
			{
				for(j=i;j<sum-1;j++)
				{
					student[j]=student[j+1];
				}
				sum--;
			}
		}
		
		printf("删除成功！\n");
		printf("是否要继续删除信息？\n是(1)\n否(2)将返回主菜单");
		scanf("%d",&flag);
		if(flag==1)
		{
			goto loop2;
		}
		else{
			system("cls");
			printf("系统将于两秒后跳回主菜单！\n");
            Sleep(2000);
		}

	}
	else if(p == 2)
	{
		printf("是否要继续删除信息？\n是(1)\n否(2)将返回主菜单");
		scanf("%d",&flag);
		if(flag==1)
		{
			goto loop2;
		}
	}
	
}
//修改学生信息
void ChangeInformation()
{
	int n,i;
loop3:
    system("cls");
	int flag=0;
	int f=0;
	printf("请输入要修改学生的学号!\n");
	scanf("%d",&n);
	for(i=0;i<sum;i++)
	{
		if(n == student[i].id)
		{
			f=1;
            printf("请输入要修改的信息：\n");
			printf("请输入修改后学生的姓名!\n");
			scanf("%s",student[i].name);
			printf("请输入修改后学生的电话!\n");
			scanf("%lf",&student[i].phonenumber);
		}
	}
	if(f==0)
	{
		printf("查无此人！\n");
	}
	printf("是否要继续修改信息？\n是(1)\n否(2)将返回主菜单");
	scanf("%d",&flag);
	if(flag==1)
	{
		goto loop3;
	}
}

//显示信息
void PrintInformation()
{
	int i;
	system("cls");
	printf("\n");
	printf("\t学号\t姓名\t电话\n");
	for(i=0;i<sum;i++)
	{
	    printf("\t%d\t%s\t%.0f\n",student[i].id,student[i].name,student[i].phonenumber);
	}
	printf("|按任意键返回鸭|\n");
	getchar();
	getchar();
}


//查询子函数--------------------------------------------------------
void SelectInformation()
{
	int iItem = 0;
	ShowSelect();

	
	
	int flag=1;

    while(flag==1)
    {
		scanf("%d", &iItem);
	    switch (iItem)
	    {
	    case 1:
		    idSelect();
		    break;
	    case 2:
		    nameSelect();
		    break;
	    default:
		    printf("\t\t请输入正确的数字！\n\t\t");
	    }
		printf("是否要继续查询信息？\n是(1)\n否(2)将返回主菜单");
	    scanf("%d",&flag);
		ShowSelect();

	}
	ShowSelect();

}

//学号查询
void idSelect()
{
    int n,i;
    int flag=0;
    printf("请输入要查看学生的学号!\n");
	scanf("%d",&n);
	for(i=0;i<sum;i++)
	{
		if(n == student[i].id)
		{
			flag = 1;
			printf("该学生信息为：\n");
			printf("学号\t姓名\t电话\n");
			printf("%d\t%s\t%.0f\n",student[i].id,student[i].name,student[i].phonenumber);	
		}
	}
    if(flag == 0)
	{
		printf("查无此人！\n");
	}
}
//姓名查询
void nameSelect()
{
    printf("请输入要查看学生的姓名!\n");
    char str[20]={0};
    int i;
    int flag=0;
	scanf("%s",str);
	for(i=0;i<sum;i++)
	{
		if(0 == strcmp(str,student[i].name))
		{
			flag = 1;
			printf("该学生信息为：\n");
			printf("学号\t姓名\t电话\n");
			printf("%d\t%s\t%.0f\n",student[i].id,student[i].name,student[i].phonenumber);	
		}
	}
    if(flag == 0)
	{
		printf("查无此人,返回主菜单！\n");
	}
}