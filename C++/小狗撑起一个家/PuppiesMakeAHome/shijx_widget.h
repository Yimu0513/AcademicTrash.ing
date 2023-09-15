#ifndef SHIJX_WIDGET_H
#define SHIJX_WIDGET_H

#include <QWidget>

#include "family.h"
#include "dog.h"
#include "config.h"
#include "familyreserve.h"
#include "product.h"

//#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QMouseEvent>


namespace Ui {
class ShiJX_Widget;
}

class ShiJX_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit ShiJX_Widget(QWidget *parent = nullptr);
    ~ShiJX_Widget() override;

    int millisecondPerHour=10000;//游戏速率

    int timerKiller;
    void timerEvent(QTimerEvent *e);  //计时器事件

    //初始化界面
    void initScene();

    //键盘操作
    void keyPressEvent(QKeyEvent *event) override;

private slots:

    //这里是使用图形化ui自动生成的按钮跳转代码

    void on_pushButton_gotostore_released();

    void on_pushButton_exit_released();

    void on_pushButton_gohome_released();

    void on_pushButton_newmember_released();

    void on_pushButton_home_released();

    void on_pushButton_backehome_released();

    void on_pushButton_next1_released();

    void on_pushButton_backhome_10_released();

    void on_pushButton_up_1_released();

    void on_pushButton_next_2_released();

    void on_pushButton_backhome_3_released();

    void on_pushButton_up_2_released();

    void on_pushButton_next_5_released();

    void on_pushButton_backhome__released();

    void on_pushButton_up_5_released();

    void on_pushButton_start_released();

    void on_pushButton_buy_clicked();

    void on_pushButton_adopt_clicked();

    void on_read1_clicked();

    void on_read2_clicked();

    void on_read3_clicked();

    void on_read4_clicked();

    void on_save1_clicked();

    void on_save2_clicked();

    void on_save3_clicked();

    void on_save4_clicked();

    void on_pushButton_read_released();

    void on_pushButton_save_released();

    void on_save_exit_released();

    void on_read_exit_released();

    void on_reset1_clicked();

    void on_reset2_clicked();

    void on_reset3_clicked();

    void on_reset4_clicked();

    void on_pushButton_help_released();

    void on_spinBox_dogfood_valueChanged(int arg1);

    void on_spinBox_bonse_valueChanged(int arg1);

    void on_spinBox_medicin_valueChanged(int arg1);

    void on_pushButton_beagles_clicked();

    void on_pushButton_borderCollie_clicked();

    void on_pushButton_bullTerrier_clicked();

    void on_pushButton_Dalmatians_clicked();

    void on_pushButton_shetland_clicked();

    void on_pushButton_doberman_clicked();

    void on_pushButton_german_clicked();

    void on_pushButton_Mastiff_clicked();

    void on_pushButton_husky_clicked();

    void on_pushButton_chihuahua_clicked();

    void on_exit_clicked();

    void on_eat_clicked();

    void on_exit_2_clicked();

    void on_feed_released();

    void on_dowork_clicked();

    void on_dohousework_clicked();

    void on_pushButton_clicked();

    void on_pushButton_honor_clicked();

private:
    Ui::ShiJX_Widget *ui;

    Family Demo;

    void InitialHome();
    void InitialFamily();
    void renovate();  //首页设置，并用于实时刷新数据

    void InitialRecord();//初始载入存档名称
    void ResetRecord(QString recordPath);//初始化存档
    void ReadRecord(QString recordPath);//读文件
    void SaveRecord(QString recordPath);//写文件

    void InitialStore();//初始化商店
    void calculation();//计算价格

    void InitialNewmember();  //初始化领养中心

    void DogGrowing();  //模拟精力减少

    void InitialEggs(); //初始化狗狗语录
    void InitialDogs(int i=0);   //初始化狗狗

    void InitFeeding();  //初始化投喂界面
    void InitInformation(); //初始化狗狗信息
    void Initialchoose();  //初始化狗狗活动

    void InitHonor(); //初始化荣誉

//    void mouseMoveEvent(QMouseEvent *event);


};

#endif // SHIJX_WIDGET_H
