#include "shijx_widget.h"
#include "ui_shijx_widget.h"
#include "config.h"
#include "dog.h"
#include "family.h"
#include "familyreserve.h"
//#include "product.h"
#include <QDebug>

#include <QIcon> //图标
#include <QKeyEvent>  //键盘操作
#include <QCursor>  //鼠标指针
#include <QMessageBox>  //窗口
#include <QTime>  //时间操作
#include <QFile>
#include <QFileDialog>
#include <QInputDialog>
#include <QPaintEvent>
#include <QPainter>



extern int haveLoadGame;  //不加载存档不能游戏
const int CostDogFood=15,CostBonse=10,CostMedicine=5;
const int valueDogFood=5,valueBonse=3,valueMedicine=1;
QString Eggs[10];
/*
extern QVector<Product> products[3];
Product Product1("骨头",10,3.0);
products[0].append(Product1);
Product product2("狗粮",15,7.0);
products[1].append(Product2);
Product product3("药品",5,1.0);
products[2].append(Product3);
*/


ShiJX_Widget::ShiJX_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShiJX_Widget)
{
    ui->setupUi(this);

    //调用初始化场景
    initScene();



}


ShiJX_Widget::~ShiJX_Widget()
{
    delete ui;
}


//------------------------------设置游戏主题窗口数据-------------------
void ShiJX_Widget::initScene()
{
    //设置窗口尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置标题
    setWindowTitle(GAME_TITLE);

    //加载图标
    setWindowIcon(QIcon(GAME_ICON));

    //设置鼠标箭头
    QCursor *myCursor=new QCursor(QPixmap(GAME_MOUSE),-1,-1);
    this->setCursor(*myCursor);

    //设置首页面
    ui->stackedWidget->setCurrentWidget(ui->start);

    //初始化房间
    InitialHome();
    renovate();

    //载入存档
    InitialRecord();

    //初始化商店
    InitialStore();

    //初始化狗狗语录
    InitialEggs();


}

void ShiJX_Widget::InitialHome()
{

    if(haveLoadGame==0){
        ui->pushButton_save->setEnabled(false);
        ui->pushButton_gotostore->setEnabled(false);
        ui->pushButton_newmember->setEnabled(false);
        ui->pushButton_honor->setEnabled(false);
        ui->label_Wealth->setVisible(false);
        ui->label_Love->setVisible(false);
        ui->label_Time->setVisible(false);
        ui->label_Title->setVisible(false);
    }
    else{
        ui->pushButton_save->setEnabled(true);
        ui->pushButton_gotostore->setEnabled(true);
        ui->pushButton_newmember->setEnabled(true);
        ui->pushButton_honor->setEnabled(true);
        ui->label_Wealth->setVisible(true);
        ui->label_Love->setVisible(true);
        ui->label_Time->setVisible(true);
        ui->label_Title->setVisible(true);
    }

    ui->opinion->setVisible(false);
    ui->eateat->setVisible(false);

    ui->pushButton_husky->setVisible(false);
    ui->pushButton_german->setVisible(false);
    ui->pushButton_Mastiff->setVisible(false);
    ui->pushButton_beagles->setVisible(false);
    ui->pushButton_doberman->setVisible(false);
    ui->pushButton_shetland->setVisible(false);
    ui->pushButton_chihuahua->setVisible(false);
    ui->pushButton_Dalmatians->setVisible(false);
    ui->pushButton_bullTerrier->setVisible(false);
    ui->pushButton_borderCollie->setVisible(false);

    InitialFamily();
    InitInformation();
    renovate();
    InitHonor();
    Initialchoose();
}

void ShiJX_Widget::InitialFamily()
{
    QString Str;
    int x;

    if(Demo.getFamilyLove()%10 == 0 && Demo.getFamilyLove() > 0)
    {
        Demo.increaseLove();
    }

    Str=Demo.getFamilyTitle();
    Str=QString("<center>家庭名称:%1</center>").arg(Str);
    ui->label_Title->setText(Str);

    x=Demo.getFamilyWealth();
    Str=QString("<center>金币:%1</center>").arg(x);
    ui->label_Wealth->setText(Str);

    x=Demo.getFamilyLove();
    Str=QString("<center>爱心:%1</center>").arg(x);
    ui->label_Love->setText(Str);

    x=Demo.getPlayerTime();
    Str=QString("<center>时长:%1</center>").arg(x);
    ui->label_Time->setText(Str);
}

void ShiJX_Widget::renovate()
{
    QString Str;
    int x;
    if(Demo.member!=0)
    {
        if(Demo.member==1)
        {
            ui->pushButton_chihuahua->setVisible(true);
            ui->pushButton_chihuahua->setEnabled(true);
        }
        else if(Demo.member==2)
        {
            ui->pushButton_beagles->setVisible(true);
            ui->pushButton_beagles->setEnabled(true);
        }
        else if(Demo.member==3)
        {
            ui->pushButton_borderCollie->setVisible(true);
            ui->pushButton_borderCollie->setEnabled(true);
        }
        else if(Demo.member==4)
        {
            ui->pushButton_Mastiff->setVisible(true);
            ui->pushButton_Mastiff->setEnabled(true);
        }
        else if(Demo.member==5)
        {
            ui->pushButton_bullTerrier->setVisible(true);
            ui->pushButton_bullTerrier->setEnabled(true);
        }
        else if(Demo.member==6)
        {
            ui->pushButton_Dalmatians->setVisible(true);
            ui->pushButton_Dalmatians->setEnabled(true);
        }
        else if(Demo.member==7)
        {
            ui->pushButton_german->setVisible(true);
            ui->pushButton_german->setEnabled(true);
        }
        else if(Demo.member==8)
        {
            ui->pushButton_husky->setVisible(true);
            ui->pushButton_husky->setEnabled(true);
        }
        else if(Demo.member==9)
        {
            ui->pushButton_shetland->setVisible(true);
            ui->pushButton_shetland->setEnabled(true);
        }
        else if(Demo.member==10)
        {
            ui->pushButton_doberman->setVisible(true);
            ui->pushButton_doberman->setEnabled(true);
         }
         int randNum=qrand()%10;
         ui->pushButton_doberman->setToolTip(QString("<h3>%1</h3>").arg(Eggs[randNum]));
         ui->pushButton_shetland->setToolTip(QString("<h3>%1</h3>").arg(Eggs[randNum]));
         ui->pushButton_husky->setToolTip(QString("<h3>%1</h3>").arg(Eggs[randNum]));
         ui->pushButton_german->setToolTip(QString("<h3>%1</h3>").arg(Eggs[randNum]));
         ui->pushButton_Dalmatians->setToolTip(QString("<h3>%1</h3>").arg(Eggs[randNum]));
         ui->pushButton_bullTerrier->setToolTip(QString("<h3>%1</h3>").arg(Eggs[randNum]));
         ui->pushButton_Mastiff->setToolTip(QString("<h3>%1</h3>").arg(Eggs[randNum]));
         ui->pushButton_borderCollie->setToolTip(QString("<h3>%1</h3>").arg(Eggs[randNum]));
         ui->pushButton_beagles->setToolTip(QString("<h3>%1</h3>").arg(Eggs[randNum]));
         ui->pushButton_chihuahua->setToolTip(QString("<h3>%1</h3>").arg(Eggs[randNum]));
    }

/*
    for (auto it = Demo.dogs.begin(); it != Demo.dogs.end(); ++it)
    {
        Dog* dog = *it;
        if(dog->getDogState()==1)
        {
            //ui->state->setVisible(true);
        }
        else
        {
            //ui->state->setVisible(false);
        }
    }
*/
    InitInformation();

    Str=Demo.getFamilyTitle();
    Str=QString("<center>家庭名称:%1</center>").arg(Str);
    ui->label_Title->setText(Str);

    x=Demo.getFamilyWealth();
    Str=QString("<center>金币:%1</center>").arg(x);
    ui->label_Wealth->setText(Str);

    x=Demo.getFamilyLove();
    Str=QString("<center>爱心:%1</center>").arg(x);
    ui->label_Love->setText(Str);
}



//--------------------------键盘esc后退回到主页面操作------------------------
void ShiJX_Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
         ui->stackedWidget->setCurrentWidget(ui->home);
         InitialHome();
         timerKiller=startTimer(millisecondPerHour);
    }
}

//------------------页面切换跳转代码-----------------------

//欢迎页
void ShiJX_Widget::on_pushButton_start_released()
{

    //进入游戏
     ui->stackedWidget->setCurrentWidget(ui->home);
     QMessageBox::information(this,"提示",QString("<h3>要先读档才能开始游戏哦~<br>游戏结束记得存档，不然会丢失数据！！</h3>"));
     InitialHome();
     /*
     if(haveLoadGame==0){
         ui->pushButton_save->setEnabled(false);
         ui->pushButton_gotostore->setEnabled(false);
         ui->pushButton_newmember->setEnabled(false);
         ui->pushButton_honor->setEnabled(false);
     }
     else{
         ui->pushButton_save->setEnabled(true);
         ui->pushButton_gotostore->setEnabled(true);
         ui->pushButton_newmember->setEnabled(true);
         ui->pushButton_honor->setEnabled(true);
     }
     */
}

//主页
void ShiJX_Widget::on_pushButton_gotostore_released()
{
    //切换到商店页面
    if(haveLoadGame==1){
        killTimer(timerKiller);
    }
    else return;
    ui->stackedWidget->setCurrentWidget(ui->store);
    calculation();
    InitialStore();
}

void ShiJX_Widget::on_pushButton_exit_released()
{
    //关闭窗口
    close();
    timerKiller=startTimer(millisecondPerHour);
    InitialHome();
}

void ShiJX_Widget::on_pushButton_newmember_released()
{
    //切换到收养中心
    if(haveLoadGame==1){
        killTimer(timerKiller);
    }
    else return;
    ui->stackedWidget->setCurrentWidget(ui->NewMember);

}

void ShiJX_Widget::on_pushButton_help_released()
{
    //切换到帮助
    if(haveLoadGame==1){
        killTimer(timerKiller);
    }

    ui->stackedWidget->setCurrentWidget(ui->help1);
}



//跳转到读档存档
void ShiJX_Widget::on_pushButton_read_released()
{
     if(haveLoadGame==1) killTimer(timerKiller);
     ui->stackedWidget->setCurrentWidget(ui->read);
     InitialRecord();
}


void ShiJX_Widget::on_pushButton_save_released()
{
    if(haveLoadGame==0) return;
    killTimer(timerKiller);

    ui->stackedWidget->setCurrentWidget(ui->save);

    if(haveLoadGame==0){
        ui->pushButton_save->setEnabled(false);
    }
    else{
        ui->pushButton_save->setEnabled(true);
    }
}

//--------商店
void ShiJX_Widget::on_pushButton_gohome_released()
{
    //切换到回家的界面
     ui->stackedWidget->setCurrentWidget(ui->home);
     InitialHome();
     timerKiller=startTimer(millisecondPerHour);

}


//--------收养中心
void ShiJX_Widget::on_pushButton_home_released()
{
    //回家
    timerKiller=startTimer(millisecondPerHour);
    ui->stackedWidget->setCurrentWidget(ui->home);
    InitialHome();

}


//---------帮助页
//1
void ShiJX_Widget::on_pushButton_backehome_released()
{
    //回家
    timerKiller=startTimer(millisecondPerHour);
    ui->stackedWidget->setCurrentWidget(ui->home);
    InitialHome();
}

void ShiJX_Widget::on_pushButton_next1_released()
{
    //下一页
    ui->stackedWidget->setCurrentWidget(ui->help2);
}

//2
void ShiJX_Widget::on_pushButton_backhome_10_released()
{
    //回家
    timerKiller=startTimer(millisecondPerHour);
    ui->stackedWidget->setCurrentWidget(ui->home);
    InitialHome();
}

void ShiJX_Widget::on_pushButton_up_1_released()
{
    //上一页
    ui->stackedWidget->setCurrentWidget(ui->help1);
}


void ShiJX_Widget::on_pushButton_next_2_released()
{
    //下一页
    ui->stackedWidget->setCurrentWidget(ui->help3);
}

//3
void ShiJX_Widget::on_pushButton_backhome_3_released()
{
    //回家
    timerKiller=startTimer(millisecondPerHour);
    ui->stackedWidget->setCurrentWidget(ui->home);
    InitialHome();
}

void ShiJX_Widget::on_pushButton_up_2_released()
{
    //上一页
    ui->stackedWidget->setCurrentWidget(ui->help2);
}


void ShiJX_Widget::on_pushButton_next_5_released()
{
    //下一页
    ui->stackedWidget->setCurrentWidget(ui->help4);
}

//4

void ShiJX_Widget::on_pushButton_backhome__released()
{
    //回家
    timerKiller=startTimer(millisecondPerHour);
    ui->stackedWidget->setCurrentWidget(ui->home);
    InitialHome();
}

void ShiJX_Widget::on_pushButton_up_5_released()
{
    //上一页
    ui->stackedWidget->setCurrentWidget(ui->help3);
}

//读存档
void ShiJX_Widget::on_save_exit_released()
{
    ui->stackedWidget->setCurrentWidget(ui->home);
    InitialHome();

    if(haveLoadGame==0){
        ui->pushButton_save->setEnabled(false);
        ui->pushButton_buy->setEnabled(false);
    }
    else{
        ui->pushButton_save->setEnabled(true);
        timerKiller=startTimer(millisecondPerHour);
    }
}

void ShiJX_Widget::on_read_exit_released()
{
    ui->stackedWidget->setCurrentWidget(ui->home);
    InitialHome();
    if(haveLoadGame==0){
        ui->pushButton_save->setEnabled(false);
        ui->pushButton_buy->setEnabled(false);
    }
    else{
        ui->pushButton_save->setEnabled(true);
        timerKiller=startTimer(millisecondPerHour);
    }
}



//-------------------------------商店界面--------------------------------------

void ShiJX_Widget::InitialStore()
{
    int x=0;
    x=Demo.getFamilyWealth();
    ui->label_balance->setText(QString("%1").arg(x));
}

void ShiJX_Widget::calculation()
{
    int x=0;
    x+=ui->spinBox_dogfood->value()*CostDogFood;
    x+=ui->spinBox_bonse->value()*CostBonse;
    x+=ui->spinBox_medicin->value()*CostMedicine;
    if(x<=Demo.getFamilyWealth()){
        ui->label_cost->setText(QString("<center><font Color=black>%1</font></center>").arg(x));
    }
    else{
        ui->label_cost->setText(QString("<center><font Color=black>%1(余额不足)</font></center>").arg(x));
    }
}

//结算按钮的点击函数
void ShiJX_Widget::on_pushButton_buy_clicked()
{
    int sum=0,sumDogFood=0,sumBonse=0,sumMedicine=0;

    sumDogFood=ui->spinBox_dogfood->value();   //分别取各种商品的数量
    sumBonse=ui->spinBox_bonse->value();
    sumMedicine=ui->spinBox_medicin->value();

    sum=sumDogFood*CostDogFood+sumBonse*CostBonse+sumMedicine*CostMedicine;    //计算总金额

    if(sum>Demo.getFamilyWealth())  //判断金币够不够
    {
        QMessageBox::information(this,"提示",QString("<h3>金币数量不足，<br>勤劳小狗快去打工赚钱养家呀~</h3>"));
        return;
    }
    else
    {
        int ret=QMessageBox::question(this,"提示","确定下单吗?");
        if(ret==QMessageBox::No) return;
        //扣钱
        Demo.setFamilyWealth(Demo.getFamilyWealth()-sum);
        //增加食物库存
        Demo.setFamilyReserveBonse(Demo.getFamilyReserveBonse()+sumBonse);
        Demo.setFamilyReserveDogfood(Demo.getFamilyReserveDogfood()+sumDogFood);
        Demo.setFamilyReserveMedicine(Demo.getFamilyReserveMedicine()+sumMedicine);

        InitialStore();
        InitFeeding();
        QMessageBox::information(this,"提示",QString("<h3>下单成功！</h3>"));
    }
    renovate();
    calculation();
}

void ShiJX_Widget::on_spinBox_dogfood_valueChanged(int arg1)
{
    calculation();
}

void ShiJX_Widget::on_spinBox_bonse_valueChanged(int arg1)
{
    calculation();
}

void ShiJX_Widget::on_spinBox_medicin_valueChanged(int arg1)
{
    calculation();
}





//-------------------------领养中心页面---------------
//ui界面
void ShiJX_Widget::InitialNewmember()
{
    //鼠标悬停展示信息
    ui->Chihuahua->setToolTip(QString("吉娃娃聪颖、活泼、黏人，行动警惕，十分勇敢。"));
    ui->Dalmatians->setToolTip(QString("斑点狗性格很温顺，对主人忠诚，肌肉强壮，充满活力。"));
    ui->beagles->setToolTip(QString("比格犬的性格温顺，忠诚认主，头脑聪明，学习能力强。"));
    ui->boderCollie->setToolTip(QString("边牧性情很温和，容忍性好,警惕性高,热情,服从性高。"));
    ui->bullTerrier->setToolTip(QString("牛头梗看起来很凶，但对人友好，十分忠诚。"));
    ui->doberman->setToolTip(QString("杜宾犬是天生的警卫犬，性格胆大，聪明机敏，警惕坚定，忠诚且勇敢。"));
    ui->german->setToolTip(QString("德牧犬极其温顺善良，自信开朗，自控力强，敏捷，聪明好斗。"));
    ui->husky->setToolTip(QString("哈士奇好动，精力旺盛，对任何人都温顺，看家能力基本为零。"));
    ui->masstiff->setToolTip(QString("马士提夫犬性格沉稳、和善、忠实,活力充沛,具有强烈的攻击性。"));
    ui->shetland->setToolTip(QString("喜乐蒂犬聪明伶俐，活泼好动，忠于主人，但对陌生人存有戒心，警觉性高"));
}

//决定领养按钮
void ShiJX_Widget::on_pushButton_adopt_clicked()
{
    if(Demo.member!=0)
    {
        QMessageBox::information(this,"提示",QString("<h3>你已经有一个家庭成员啦，不可以领养新成员啦！</h3>"));
        return;
    }
    else
    {
        int which=0;
        which=ui->spinBox_which->value();
        if(which!=0)
        {
            if(which>10)
            {
                QMessageBox::information(this,"提示",QString("<h3>请选择正确的小狗编号！</h3>"));
                return;
            }
            else
            {
                int ret=QMessageBox::question(this,"提示","<h3>确定要收养它吗?</h3>");
                if(ret==QMessageBox::No) return;
                QMessageBox::information(this,"领养成功","<h3>一定要爱小狗哦~</h3>");
                int x;
                x=ui->spinBox_which->value();
                ui->stackedWidget->setCurrentWidget(ui->home);
                InitialDogs(which);
            }

        }
        renovate();
        timerKiller=startTimer(millisecondPerHour);
    }
}

void ShiJX_Widget::DogGrowing()
{
    for(int i=0;i<Demo.dogs.size();i++)
    {
        Demo.dogs[i]->DogGrow();
        Demo.dogs[i]->judgeDogIll();
    }
}

//按时间刷新
void ShiJX_Widget::timerEvent(QTimerEvent *)
{
    int x;
    x=Demo.getPlayerTime();
    Demo.setPlayerTime(++x);
    InitialHome();
    renovate();
    DogGrowing();
    Initialchoose();
}

void ShiJX_Widget::InitialEggs()
{
    Eggs[0]="小狗疑心大宇宙阴谋篡夺小狗的位置！";
    Eggs[1]="小狗的爱是永永远远！";
    Eggs[2]="你真的爱小狗吗？";
    Eggs[3]="这是我的地盘！";
    Eggs[4]="小狗今天吃零食的时候给你留了一块肉干哦~";
    Eggs[5]="可以带小狗出去散步吗？";
    Eggs[6]="小狗一直在家里等你哦~";
    Eggs[7]="汪汪";
    Eggs[8]="今天夸夸小狗了吗？";
    Eggs[9]="小狗今天出去玩碰到一只和我长的一模一样的狗！";
}

void ShiJX_Widget::InitialDogs(int i)
{
    if(i>0&&i<=10)
    {
        if(i>0&&i<=4)
        {
            SmallDog* dog=new SmallDog();
            QString tmp="";
            while(tmp=="")
            {
                tmp=QInputDialog::getText(this,"提示",QString("<h3>请给小狗起个响亮的名字吧：</h3>"));
            }
            dog->setDogName(tmp);
            Demo.dogs.push_back(reinterpret_cast<Dog*>(dog));
        }
        else if(i>4&&i<=10)
        {
            BigDog* dog=new BigDog();
            QString tmp="";
            while(tmp=="")
            {
                tmp=QInputDialog::getText(this,"提示",QString("<h3>请给小狗起个响亮的名字吧：</h3>"));
            }
            dog->setDogName(tmp);
            Demo.dogs.push_back(reinterpret_cast<Dog*>(dog));
        }
        Demo.addDog(i);
        InitInformation();
        renovate();
    }
    else
    {
        QMessageBox::information(this,"提示",QString("<h3>请选择正确的小狗编号！</h3>"));
        return;
    }

}


//-------------------------读档存档界面-----------------------------
//初始载入存档名称
void ShiJX_Widget::InitialRecord()
{
    QFile Fread("../PuppiesMakeAHome/database/Save1.txt");
    bool isExist=Fread.open(QIODevice::ReadOnly);
    if(isExist){
        QDataStream ds(&Fread);
        QString s;
        ds >> s;
        if(strcmp(s.toUtf8().data(),"!@#$%^")==0){
            ui->save1->setText("新建家庭");
            ui->read1->setText("新建家庭");
        }
        else
        {
            ui->save1->setText(s);
            ui->read1->setText(s);
        }
    }
    Fread.close();

    Fread.setFileName("../PuppiesMakeAHome/database/Save2.txt");
    isExist=Fread.open(QIODevice::ReadOnly);
    if(isExist){
        QDataStream ds(&Fread);
        QString s;
        ds >> s;
        if(strcmp(s.toUtf8().data(),"!@#$%^")==0){
            ui->save2->setText("新建家庭");
            ui->read2->setText("新建家庭");
        }
        else{

            ui->save2->setText(s);
            ui->read2->setText(s);
        }
    }
    Fread.close();

    Fread.setFileName("../PuppiesMakeAHome/database/Save3.txt");
    isExist=Fread.open(QIODevice::ReadOnly);
    if(isExist){
        QDataStream ds(&Fread);
        QString s;
        ds >> s;
        if(strcmp(s.toUtf8().data(),"!@#$%^")==0){
            ui->save3->setText("新建家庭");
            ui->read3->setText("新建家庭");
        }
        else{

            ui->save3->setText(s);
            ui->read3->setText(s);
        }
    }
    Fread.close();

    Fread.setFileName("../PuppiesMakeAHome/database/Save4.txt");
    isExist=Fread.open(QIODevice::ReadOnly);
    if(isExist){
        QDataStream ds(&Fread);
        QString s;
        ds >> s;
        if(strcmp(s.toUtf8().data(),"!@#$%^")==0){
            ui->save4->setText("新建家庭");
            ui->read4->setText("新建家庭");
        }
        else{

            ui->save4->setText(s);
            ui->read4->setText(s);
        }
    }
    Fread.close();

}

//重置存档
void ShiJX_Widget::ResetRecord(QString recordPath)
{
    QPushButton* pSave=ui->save1,*pRead=ui->read1;
    if(recordPath=="../PuppiesMakeAHome/database/Save1.txt"){
        pSave=ui->save1;
        pRead=ui->read1;
    }
    else if(recordPath=="../PuppiesMakeAHome/database/Save2.txt"){
        pSave=ui->save2;
        pRead=ui->read2;
    }
    else if(recordPath=="../PuppiesMakeAHome/database/Save3.txt"){
        pSave=ui->save3;
        pRead=ui->read3;
    }
    else if(recordPath==".../PuppiesMakeAHome/database/Save4.txt"){
        pSave=ui->save4;
        pRead=ui->read4;
    }


    QFile Fwrite(recordPath);
    bool isExist=Fwrite.open(QIODevice::WriteOnly);
    if(isExist){
        QDataStream ds(&Fwrite);
        QString s="!@#$%^";
        ds << QString(s);
    }

    pSave->setText("新建家庭");
    pRead->setText("新建家庭");

    Fwrite.close();

}

//读档
void ShiJX_Widget::ReadRecord(QString recordPath)
{
    int ret=QMessageBox::question(this,"提示","<h3>确定选择该存档?</h3>");
    if(ret==QMessageBox::No) return;


    QPushButton* pSave=ui->save1,*pRead=ui->read1;
    if(recordPath=="../PuppiesMakeAHome/database/Save1.txt"){
        pSave=ui->save1;
        pRead=ui->read1;
    }
    else if(recordPath=="../PuppiesMakeAHome/database/Save2.txt"){
        pSave=ui->save2;
        pRead=ui->read2;
    }
    else if(recordPath=="../PuppiesMakeAHome/database/Save3.txt"){
        pSave=ui->save3;
        pRead=ui->read3;
    }
    else if(recordPath=="../PuppiesMakeAHome/database/Save4.txt"){
        pSave=ui->save4;
        pRead=ui->read4;
    }

    QFile Fread(recordPath);
    if(pSave->text()=="新建家庭")
    {
        bool isExist=Fread.open(QIODevice::WriteOnly);
        if(isExist)
        {
            QDataStream ds(&Fread);
            QString tmp="";
            Family family;
            //初始化家庭

            Demo.Initial();
            Demo.dogs.clear();
            InitialStore();
            InitialHome();
            //家庭信息
            while(tmp=="")
            {
                tmp=QInputDialog::getText(this,"提示",QString("<h3>请给小家起个名字吧：</h3>"));
            }
            Demo.setFamilyTitle(tmp);
            ds<<Demo.getFamilyTitle();
            pSave->setText(Demo.getFamilyTitle());
            pRead->setText(Demo.getFamilyTitle());

            Demo.setFamilyWealth(30);
            ds<<QString::number(Demo.getFamilyWealth());
            Demo.setFamilyLove(5);
            ds<<QString::number(Demo.getFamilyLove());

            QMessageBox::question(this,"新建家庭成功","<h3>快去领养一只狗狗吧！</h3>");
        }
        InitInformation();
    }
    else
    {
        QMessageBox::information(this,"读档成功","快回家看看小狗吧~");
        bool isExist=Fread.open(QIODevice::ReadOnly);
        if(isExist){
            QDataStream ds(&Fread);
            QString itmp,jtmp,ktmp,stmp;

            //初始化
            Demo.Initial();
            InitialHome();

            //家庭信息
            ds>>stmp;
            Demo.setFamilyTitle(stmp.toUtf8().data());
            ds>>stmp;
            Demo.setFamilyWealth(stmp.toUtf8().toInt());
            ds>>stmp;
            Demo.setFamilyLove(stmp.toUtf8().toInt());
            ds>>stmp;
            Demo.setFamilyReserveBonse(stmp.toUtf8().toInt());
            ds>>stmp;
            Demo.setFamilyReserveDogfood(stmp.toUtf8().toInt());
            ds>>stmp;
            Demo.setFamilyReserveMedicine(stmp.toUtf8().toInt());
            ds>>stmp;
            Demo.setPlayerTime(stmp.toUtf8().toInt());
            ds>>stmp;
            Demo.member=stmp.toUtf8().toInt();

            //狗狗信息
            Dog *dogTmp;  // 在 if-else 结构之前声明

            ds >> itmp;
            for (int j = 0; j < itmp.toUtf8().toInt(); j++)
            {
                if (Demo.member > 4) {
                    dogTmp = new BigDog();  // 初始化变量
                } else {
                    dogTmp = new SmallDog();  // 初始化变量
                }

                ds>>stmp;
                dogTmp->setDogName(stmp.toUtf8().data());
                ds>>stmp;
                dogTmp->setDogAbility(stmp.toUtf8().toInt());
                ds>>stmp;
                dogTmp->setDogEnergy(stmp.toUtf8().toDouble());
                ds>>stmp;
                dogTmp->setDogIll(stmp.toUtf8().toInt());
                ds>>stmp;
                dogTmp->setDogState(stmp.toUtf8().toInt());
                ds>>stmp;
                dogTmp->setDogWorktime(stmp.toUtf8().toInt());
                Demo.dogs.push_back(dogTmp);

            }
        }
    }
    Fread.close();
    haveLoadGame=1;
    renovate();
    InitialHome();

    ui->stackedWidget->setCurrentWidget(ui->home);

    //禁用/启用按钮
    if(haveLoadGame==0){
        ui->pushButton_newmember->setEnabled(false);
        ui->pushButton_gotostore->setEnabled(false);
        ui->pushButton_honor->setEnabled(false);
    }
    else{
        ui->pushButton_save->setEnabled(true);
    }

}

//存档
void ShiJX_Widget::SaveRecord(QString recordPath)
{
    int ret=QMessageBox::question(this,"提示","确定覆盖存档?");
    if(ret==QMessageBox::No) return;

    QPushButton* pSave=ui->save1,*pRead=ui->read1;
    if(recordPath=="../PuppiesMakeAHome/database/Save1.txt"){
        pSave=ui->save1;
        pRead=ui->read1;
    }
    else if(recordPath=="../PuppiesMakeAHome/database/Save2.txt"){
        pSave=ui->save2;
        pRead=ui->read2;
    }
    else if(recordPath=="../PuppiesMakeAHome/database/Save3.txt"){
        pSave=ui->save3;
        pRead=ui->read3;
    }
    else if(recordPath=="../PuppiesMakeAHome/database/Save4.txt"){
        pSave=ui->save4;
        pRead=ui->read4;
    }


    QFile Fread(recordPath);
    bool isExist=Fread.open(QIODevice::WriteOnly);
    if(isExist)
    {
        QDataStream ds(&Fread);

        //家庭信息
        ds<<Demo.getFamilyTitle();
        pSave->setText(Demo.getFamilyTitle());
        pRead->setText(Demo.getFamilyTitle());
        ds<<QString::number(Demo.getFamilyWealth());
        ds<<QString::number(Demo.getFamilyLove());
        ds<<QString::number(Demo.getFamilyReserveBonse());
        ds<<QString::number(Demo.getFamilyReserveDogfood());
        ds<<QString::number(Demo.getFamilyReserveMedicine());
        ds<<QString::number(Demo.getPlayerTime());
        ds<<QString::number(Demo.member);

        //狗狗信息
        ds<<QString::number(Demo.dogs.size());
        for(int j=0;j<Demo.dogs.size();j++)
        {
            ds<<Demo.dogs[j]->getDogName();
            ds<<QString::number(Demo.dogs[j]->getDogAbility());
            ds<<QString::number(Demo.dogs[j]->getDogEnergy());
            ds<<QString::number(Demo.dogs[j]->getDogIll());
            ds<<QString::number(Demo.dogs[j]->getDogState());
            ds<<QString::number(Demo.dogs[j]->getDogWorktime());
        }
    }
    Fread.close();
    InitialRecord();
}



void ShiJX_Widget::on_read1_clicked()
{
    ReadRecord("../PuppiesMakeAHome/database/Save1.txt");
}

//一些按钮对应的代码
void ShiJX_Widget::on_read2_clicked()
{
    ReadRecord("../PuppiesMakeAHome/database/Save2.txt");
}

void ShiJX_Widget::on_read3_clicked()
{
    ReadRecord("../PuppiesMakeAHome/database/Save3.txt");
}

void ShiJX_Widget::on_read4_clicked()
{
    ReadRecord("../PuppiesMakeAHome/database/Save4.txt");
}

void ShiJX_Widget::on_save1_clicked()
{
    SaveRecord("../PuppiesMakeAHome/database/Save1.txt");
}

void ShiJX_Widget::on_save2_clicked()
{
    SaveRecord("../PuppiesMakeAHome/database/Save2.txt");
}

void ShiJX_Widget::on_save3_clicked()
{
    SaveRecord("../PuppiesMakeAHome/database/Save3.txt");
}

void ShiJX_Widget::on_save4_clicked()
{
    SaveRecord("../PuppiesMakeAHome/database/Save4.txt");
}


void ShiJX_Widget::on_reset1_clicked()
{
    int ret=QMessageBox::question(this,"提示","确定重置存档?");
    if(ret==QMessageBox::No) return;
    ResetRecord("../PuppiesMakeAHome/database/Save1.txt");
    InitialRecord();
}

void ShiJX_Widget::on_reset2_clicked()
{
    int ret=QMessageBox::question(this,"提示","确定重置存档?");
    if(ret==QMessageBox::No) return;
    ResetRecord("../PuppiesMakeAHome/database/Save2.txt");
    InitialRecord();
}

void ShiJX_Widget::on_reset3_clicked()
{
    int ret=QMessageBox::question(this,"提示","确定重置存档?");
    if(ret==QMessageBox::No) return;
    ResetRecord("../PuppiesMakeAHome/database/Save3.txt");
    InitialRecord();
}

void ShiJX_Widget::on_reset4_clicked()
{
    int ret=QMessageBox::question(this,"提示","确定重置存档?");
    if(ret==QMessageBox::No) return;
    ResetRecord("../PuppiesMakeAHome/database/Save4.txt");
    InitialRecord();
}

void ShiJX_Widget::on_pushButton_beagles_clicked()
{
    killTimer(timerKiller);
    ui->opinion->setVisible(true);
}

void ShiJX_Widget::on_pushButton_borderCollie_clicked()
{
    killTimer(timerKiller);
    ui->opinion->setVisible(true);
}

void ShiJX_Widget::on_pushButton_bullTerrier_clicked()
{
    killTimer(timerKiller);
    ui->opinion->setVisible(true);
}

void ShiJX_Widget::on_pushButton_Dalmatians_clicked()
{
    killTimer(timerKiller);
    ui->opinion->setVisible(true);
}

void ShiJX_Widget::on_pushButton_shetland_clicked()
{
    killTimer(timerKiller);
    ui->opinion->setVisible(true);
}

void ShiJX_Widget::on_pushButton_doberman_clicked()
{
    killTimer(timerKiller);
    ui->opinion->setVisible(true);
}

void ShiJX_Widget::on_pushButton_german_clicked()
{
    killTimer(timerKiller);
    ui->opinion->setVisible(true);
}

void ShiJX_Widget::on_pushButton_Mastiff_clicked()
{
    killTimer(timerKiller);
    ui->opinion->setVisible(true);
}

void ShiJX_Widget::on_pushButton_husky_clicked()
{
    killTimer(timerKiller);
    ui->opinion->setVisible(true);
}

void ShiJX_Widget::on_pushButton_chihuahua_clicked()
{
    killTimer(timerKiller);
    ui->opinion->setVisible(true);

}

void ShiJX_Widget::on_exit_clicked()
{
    timerKiller=startTimer(millisecondPerHour);
    ui->opinion->setVisible(false);
    ui->eateat->setVisible(false);
    InitInformation();
}

void ShiJX_Widget::on_eat_clicked()
{
    //killTimer(timerKiller);
    ui->eateat->setVisible(true);
    InitFeeding();
}

void ShiJX_Widget::on_exit_2_clicked()
{
    ui->eateat->setVisible(false);
    InitInformation();
}

//初始化投喂界面
void ShiJX_Widget::InitFeeding()
{
    int x=0,y=0,z=0;

    x=Demo.getFamilyReserveBonse();
    y=Demo.getFamilyReserveDogfood();
    z=Demo.getFamilyReserveMedicine();

    ui->label_bonse_2->setText(QString("%1").arg(x));
    ui->label_dogfood_2->setText(QString("%1").arg(y));
    ui->label_medicine_2->setText(QString("%1").arg(z));
}

void ShiJX_Widget::InitInformation()
{
    if(Demo.dogs.size()==0)
    {
        ui->label_dogname->setVisible(false);
        ui->label_energy->setVisible(false);
        ui->label_value->setVisible(false);
        ui->label_state->setVisible(false);
    }
    else
    {
        ui->label_dogname->setVisible(true);
        ui->label_energy->setVisible(true);
        ui->label_value->setVisible(true);
        ui->label_state->setVisible(true);
    }

    QString Str;
    QString State;
    double d;
    int x,t;

    for (auto it = Demo.dogs.begin(); it != Demo.dogs.end(); ++it)
    {
        Dog* dog = *it;
        Str=dog->getDogName();
        Str=QString("<center>狗狗名字：%1</center>").arg(Str);
        ui->label_dogname->setText(Str);

        d=dog->getDogEnergy();
        t=dog->getDogIll();
        Str=QString("<center>精力：%1</center>").arg(d);
        ui->label_energy->setText(Str);
        if(dog->getDogState()==1)
        {
            State="小狗正忙";
        }
        else
        {
            if(t==1)
            {
                State="小狗生病了";

            }
            else
            {
                State="小狗健康";
            }
        }
        Str=QString("<center>状态：%1</center>").arg(State);
        ui->label_state->setText(Str);
        x=dog->getDogAbility();
        Str=QString("<center>经验值：%1</center>").arg(x);
        ui->label_value->setText(Str);
    }

}

void ShiJX_Widget::Initialchoose()
{
    for (auto it = Demo.dogs.begin(); it != Demo.dogs.end(); ++it)
    {
        Dog* dog = *it;
        if(dog->getDogState()==1)
        {
            ui->eat->setEnabled(false);
            ui->dowork->setEnabled(false);
            ui->dohousework->setEnabled(false);
        }
        else
        {
            ui->eat->setEnabled(true);
            ui->dowork->setEnabled(true);
            ui->dohousework->setEnabled(true);
        }
    }
}

void ShiJX_Widget::InitHonor()
{
    QString label1="<center>未达成</center>";
    QString label2="<center>未达成</center>";
    QString label3="<center>未达成</center>";
    QString label4="<center>未达成</center>";
    QString label5="<center>未达成</center>";
    QString label6="<center>未达成</center>";

    if(Demo.getFamilyLove()>=5)
    {
        label1=QString("<center>爱心小家</center>");

        if(Demo.getFamilyLove()>=10)
        {
            label2=QString("<center>爱心大侠</center>");

            if(Demo.getFamilyLove()>=20)
            {
                label3=QString("<center>爱心超人</center>");

            }
        }
    }
    if(Demo.getFamilyWealth()>=66)
    {
        label4=QString("<center>财富初生</center>");
        if(Demo.getFamilyWealth()>=100)
        {
            label5=QString("<center>金币大亨</center>");
            if(Demo.getFamilyWealth()>=666)
            {
                label6=QString("<center>百万富翁</center>");

            }
        }
    }
    ui->label_2->setText(label1);
    ui->label_3->setText(label2);
    ui->label_4->setText(label3);
    ui->label_5->setText(label4);
    ui->label_6->setText(label5);
    ui->label_7->setText(label6);
}



//喂食
void ShiJX_Widget::on_feed_released()
{

    InitFeeding();
    int sum=0,sumDogFood=0,sumBonse=0,sumMedicine=0;

    sumDogFood=ui->dogfood->value();   //分别取各种食物的数量
    sumBonse=ui->bonse->value();
    sumMedicine=ui->medicine->value();

    sum=sumDogFood+sumBonse+sumMedicine;    //计算总量
    if(sum==0)
    {
        QMessageBox::information(this,"提示",QString("<h3>不可以用空气骗小狗！</h3>"));
        return;
    }
    else
    {
        if(sumDogFood>Demo.getFamilyReserveDogfood()||sumMedicine>Demo.getFamilyReserveMedicine()||sumBonse>Demo.getFamilyReserveBonse())  //判断
        {
            QMessageBox::information(this,"提示",
            QString("<h3>食物数量不足，<br>快去商店买一点吧！</h3>"));
            return;
        }
        else
        {
            int ret=QMessageBox::question(this,"提示","<h3>确定投喂吗?</h3>");
            if(ret==QMessageBox::No) return;
            for (auto it = Demo.dogs.begin(); it != Demo.dogs.end(); ++it)
            {
                Dog* dog = *it;
                if(dog->getDogIll()==1&&sumMedicine==0)
                {
                    if(sumMedicine==0)
                    {
                        QMessageBox::information(this,"提示",
                        QString("<h3>生病只有吃药才会好哦，<br>快给小狗喂药吧！</h3>"));
                        sumDogFood=0;
                        sumBonse=0;
                        sumMedicine=0;
                        return;
                    }

                }
                else if(dog->getDogIll()==0&&sumMedicine!=0)
                {
                    QMessageBox::information(this,"提示",
                    QString("<h3>是药三分毒，<br>药物可不能乱吃哦！</h3>"));
                    return;
                    sumDogFood=0;
                    sumBonse=0;
                    sumMedicine=0;
                }
                else
                {
                    dog->resetDogIll();
                    QMessageBox::information(this,"提示",QString("<h3>投喂成功！</h3>"));
                }
                //扣除储备
                Demo.setFamilyReserveDogfood(Demo.getFamilyReserveDogfood()-sumDogFood);
                Demo.setFamilyReserveBonse(Demo.getFamilyReserveBonse()-sumBonse);
                Demo.setFamilyReserveMedicine(Demo.getFamilyReserveMedicine()-sumMedicine);
                dog->eat(sumDogFood*valueDogFood+sumBonse*valueBonse+sumMedicine*valueMedicine);
                Demo.setFamilyLove(Demo.getFamilyLove()+1);
                if(dog->getDogIll()==0)
                {
                    ui->eateat->setVisible(false);
                }
            }
        }
    }
    Initialchoose();
    InitFeeding();
    renovate();
    InitInformation();
    timerKiller=startTimer(millisecondPerHour);
}
//狗狗打工

void ShiJX_Widget::on_dohousework_clicked()
{
    ui->eateat->setVisible(false);
    //链表中找狗狗对象
    for (auto it = Demo.dogs.begin(); it != Demo.dogs.end(); ++it)
    {
        Dog* dog = *it;
        if(dog->getDogIll()==1)
        {
            QMessageBox::information(this,"提示",QString("<h3>小狗生病需要休息，<br>快给小狗喂药吧！</h3>"));
            return;
        }
        else
        {

            if(dog->getDogEnergy() >= 2 && dog->getDogIll()==0)
            {
                dog->doHousework();
                dog->judgeDogIll();
                Demo.setFamilyLove(Demo.getFamilyLove()+1);
            }
            else
            {
               dog->doHousework();
            }

            if(dog->getDogIll()==1)
            {
                Demo.decreaseLove();
            }
            ui->opinion->setVisible(false);
        }
    }
    timerKiller=startTimer(millisecondPerHour);
    Initialchoose();
    InitInformation();
    InitialFamily();

}

void ShiJX_Widget::on_dowork_clicked()
{
    ui->eateat->setVisible(false);

    for (auto it = Demo.dogs.begin(); it != Demo.dogs.end(); ++it)
    {
        Dog* dog = *it;
        if(dog->getDogIll()==1)
        {
            QMessageBox::information(this,"提示",QString("<h3>小狗生病需要休息，<br>快给小狗喂药吧！</h3>"));
            return;
        }
        else
        {
            if (dog->getDogEnergy() >= 3.0 && dog->getDogAbility() >= 5 && dog->getDogIll()==0)
            {
                Demo.increaseWealth(10);
            }
            dog->doWork();
            dog->judgeDogIll();
            if(dog->getDogIll()==1)
            {
                Demo.decreaseLove();
            }
            ui->opinion->setVisible(false);
        }
    }
    Initialchoose();
    InitInformation();
    InitialFamily();
    timerKiller=startTimer(millisecondPerHour);
}


void ShiJX_Widget::on_pushButton_clicked()
{  
    ui->stackedWidget->setCurrentWidget(ui->home);
    InitialHome();
    timerKiller=startTimer(millisecondPerHour);
}

void ShiJX_Widget::on_pushButton_honor_clicked()
{
    if(haveLoadGame==1)
    {
        killTimer(timerKiller);
    }
    else return;
    ui->stackedWidget->setCurrentWidget(ui->honor);
    InitHonor();
}

