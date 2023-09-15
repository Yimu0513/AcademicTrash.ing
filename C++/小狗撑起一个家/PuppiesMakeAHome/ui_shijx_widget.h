/********************************************************************************
** Form generated from reading UI file 'shijx_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHIJX_WIDGET_H
#define UI_SHIJX_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShiJX_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *start;
    QPushButton *pushButton_start;
    QWidget *honor;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *home;
    QPushButton *pushButton_gotostore;
    QPushButton *pushButton_exit;
    QPushButton *pushButton_newmember;
    QPushButton *pushButton_help;
    QPushButton *pushButton_read;
    QPushButton *pushButton_save;
    QLabel *label_Title;
    QLabel *label_Wealth;
    QLabel *label_Love;
    QPushButton *pushButton_beagles;
    QPushButton *pushButton_chihuahua;
    QPushButton *pushButton_Dalmatians;
    QPushButton *pushButton_Mastiff;
    QPushButton *pushButton_borderCollie;
    QPushButton *pushButton_bullTerrier;
    QPushButton *pushButton_doberman;
    QPushButton *pushButton_german;
    QPushButton *pushButton_husky;
    QPushButton *pushButton_shetland;
    QWidget *opinion;
    QPushButton *dowork;
    QPushButton *dohousework;
    QPushButton *eat;
    QPushButton *exit;
    QWidget *eateat;
    QSpinBox *dogfood;
    QSpinBox *bonse;
    QSpinBox *medicine;
    QLabel *label_dogfood_2;
    QLabel *label_bonse_2;
    QLabel *label_medicine_2;
    QPushButton *feed;
    QPushButton *exit_2;
    QLabel *label_dogname;
    QLabel *label_energy;
    QLabel *label_value;
    QLabel *label_state;
    QPushButton *pushButton_honor;
    QLabel *label_Time;
    QWidget *store;
    QPushButton *pushButton_gohome;
    QSpinBox *spinBox_dogfood;
    QSpinBox *spinBox_bonse;
    QSpinBox *spinBox_medicin;
    QLabel *label_cost;
    QPushButton *pushButton_buy;
    QLabel *label_bonse;
    QLabel *label_dogfood;
    QLabel *label_medicine;
    QLabel *label_balance;
    QWidget *NewMember;
    QPushButton *pushButton_home;
    QLabel *Chihuahua;
    QLabel *beagles;
    QLabel *boderCollie;
    QLabel *masstiff;
    QLabel *bullTerrier;
    QLabel *Dalmatians;
    QLabel *german;
    QLabel *husky;
    QLabel *shetland;
    QLabel *doberman;
    QPushButton *pushButton_adopt;
    QSpinBox *spinBox_which;
    QLabel *label;
    QWidget *help1;
    QPushButton *pushButton_backehome;
    QPushButton *pushButton_next1;
    QWidget *help2;
    QPushButton *pushButton_backhome_10;
    QPushButton *pushButton_next_2;
    QPushButton *pushButton_up_1;
    QWidget *help3;
    QPushButton *pushButton_backhome_3;
    QPushButton *pushButton_next_5;
    QPushButton *pushButton_up_2;
    QWidget *help4;
    QPushButton *pushButton_backhome_;
    QPushButton *pushButton_up_5;
    QWidget *save;
    QPushButton *save1;
    QPushButton *save2;
    QPushButton *save3;
    QPushButton *save4;
    QPushButton *save_exit;
    QWidget *read;
    QPushButton *read1;
    QPushButton *reset1;
    QPushButton *reset2;
    QPushButton *reset3;
    QPushButton *reset4;
    QPushButton *read2;
    QPushButton *read3;
    QPushButton *read4;
    QPushButton *read_exit;

    void setupUi(QWidget *ShiJX_Widget)
    {
        if (ShiJX_Widget->objectName().isEmpty())
            ShiJX_Widget->setObjectName(QString::fromUtf8("ShiJX_Widget"));
        ShiJX_Widget->resize(1282, 792);
        ShiJX_Widget->setStyleSheet(QString::fromUtf8("QStackedWidget#stackedWidget QPushButton:hover\n"
"{\n"
"	background-color: rgb(234, 195, 182);\n"
"}\n"
"border-color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(ShiJX_Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(ShiJX_Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setToolTipDuration(0);
        stackedWidget->setStyleSheet(QString::fromUtf8("background-image:url(:/saveandread/img/read.png);"));
        start = new QWidget();
        start->setObjectName(QString::fromUtf8("start"));
        start->setStyleSheet(QString::fromUtf8("background-image: url(:/welcome/img/welcome.png);"));
        pushButton_start = new QPushButton(start);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(530, 620, 230, 61));
        pushButton_start->setStyleSheet(QString::fromUtf8("font: 24pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(4, 48, 92);\n"
"border-color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(start);
        honor = new QWidget();
        honor->setObjectName(QString::fromUtf8("honor"));
        honor->setStyleSheet(QString::fromUtf8("background-image: url(:/honor/img/honorback.png);"));
        label_2 = new QLabel(honor);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 400, 201, 51));
        label_2->setStyleSheet(QString::fromUtf8("background-image: url(:/honor/img/honor2.png);\n"
"color: rgb(227, 125, 63);\n"
"font: 14pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        label_3 = new QLabel(honor);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(550, 400, 201, 51));
        label_3->setStyleSheet(QString::fromUtf8("background-image: url(:/honor/img/honor2.png);\n"
"color: rgb(227, 125, 63);\n"
"font: 14pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        label_4 = new QLabel(honor);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(840, 400, 201, 51));
        label_4->setStyleSheet(QString::fromUtf8("background-image: url(:/honor/img/honor2.png);\n"
"color: rgb(227, 125, 63);\n"
"font: 14pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        label_5 = new QLabel(honor);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(250, 700, 201, 51));
        label_5->setStyleSheet(QString::fromUtf8("background-image: url(:/honor/img/honor2.png);\n"
"color: rgb(227, 125, 63);\n"
"font: 14pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        label_6 = new QLabel(honor);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(550, 700, 201, 51));
        label_6->setStyleSheet(QString::fromUtf8("background-image: url(:/honor/img/honor2.png);\n"
"color: rgb(227, 125, 63);\n"
"font: 14pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        label_7 = new QLabel(honor);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(840, 700, 201, 51));
        label_7->setStyleSheet(QString::fromUtf8("background-image: url(:/honor/img/honor2.png);\n"
"color: rgb(227, 125, 63);\n"
"font: 14pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        pushButton = new QPushButton(honor);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 30, 201, 61));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 211, 160);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"background-image: url(:/main/img/store.png);\n"
"color:white;"));
        label_8 = new QLabel(honor);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(240, 200, 231, 191));
        label_8->setToolTipDuration(0);
        label_8->setStyleSheet(QString::fromUtf8("background: transparent; "));
        label_9 = new QLabel(honor);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(530, 200, 231, 191));
        label_9->setToolTipDuration(0);
        label_9->setStyleSheet(QString::fromUtf8("background: transparent; "));
        label_10 = new QLabel(honor);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(830, 200, 231, 191));
        label_10->setStyleSheet(QString::fromUtf8("background: transparent; "));
        label_11 = new QLabel(honor);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(240, 500, 231, 191));
        label_11->setToolTipDuration(0);
        label_11->setStyleSheet(QString::fromUtf8("background: transparent; "));
        label_12 = new QLabel(honor);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(530, 500, 231, 191));
        label_12->setToolTipDuration(0);
        label_12->setStyleSheet(QString::fromUtf8("background: transparent; "));
        label_13 = new QLabel(honor);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(820, 500, 231, 191));
        label_13->setToolTipDuration(0);
        label_13->setStyleSheet(QString::fromUtf8("background: transparent; "));
        stackedWidget->addWidget(honor);
        home = new QWidget();
        home->setObjectName(QString::fromUtf8("home"));
        home->setStyleSheet(QString::fromUtf8("background-image: url(:/main/img/background.png);"));
        pushButton_gotostore = new QPushButton(home);
        pushButton_gotostore->setObjectName(QString::fromUtf8("pushButton_gotostore"));
        pushButton_gotostore->setGeometry(QRect(1030, 30, 211, 51));
        pushButton_gotostore->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 211, 160);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"background-image: url(:/main/img/store.png);\n"
"color:white;"));
        pushButton_exit = new QPushButton(home);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(30, 30, 211, 51));
        pushButton_exit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 211, 160);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"background-image: url(:/main/img/store.png);\n"
"color:white;"));
        pushButton_newmember = new QPushButton(home);
        pushButton_newmember->setObjectName(QString::fromUtf8("pushButton_newmember"));
        pushButton_newmember->setGeometry(QRect(1030, 100, 211, 51));
        pushButton_newmember->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 211, 160);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"background-image: url(:/main/img/store.png);\n"
"color:white;"));
        pushButton_help = new QPushButton(home);
        pushButton_help->setObjectName(QString::fromUtf8("pushButton_help"));
        pushButton_help->setGeometry(QRect(30, 240, 211, 51));
        pushButton_help->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 211, 160);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"background-image: url(:/main/img/store.png);\n"
"color:white;"));
        pushButton_read = new QPushButton(home);
        pushButton_read->setObjectName(QString::fromUtf8("pushButton_read"));
        pushButton_read->setGeometry(QRect(30, 100, 211, 51));
        pushButton_read->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 211, 160);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"background-image: url(:/main/img/store.png);\n"
"color:white;"));
        pushButton_save = new QPushButton(home);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(30, 170, 211, 51));
        pushButton_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 211, 160);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"background-image: url(:/main/img/store.png);\n"
"color:white;"));
        label_Title = new QLabel(home);
        label_Title->setObjectName(QString::fromUtf8("label_Title"));
        label_Title->setGeometry(QRect(300, 40, 201, 41));
        label_Title->setStyleSheet(QString::fromUtf8("background-image: url(:/main/img/homeshow.png);\n"
"color: rgb(227, 125, 63);\n"
"font: 14pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        label_Wealth = new QLabel(home);
        label_Wealth->setObjectName(QString::fromUtf8("label_Wealth"));
        label_Wealth->setGeometry(QRect(520, 40, 161, 41));
        label_Wealth->setStyleSheet(QString::fromUtf8("background-image: url(:/main/img/homeshow.png);\n"
"color: rgb(227, 125, 63);\n"
"font: 14pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        label_Love = new QLabel(home);
        label_Love->setObjectName(QString::fromUtf8("label_Love"));
        label_Love->setGeometry(QRect(690, 40, 131, 41));
        label_Love->setStyleSheet(QString::fromUtf8("background-image: url(:/main/img/homeshow.png);\n"
"color: rgb(227, 125, 63);\n"
"font: 14pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        pushButton_beagles = new QPushButton(home);
        pushButton_beagles->setObjectName(QString::fromUtf8("pushButton_beagles"));
        pushButton_beagles->setGeometry(QRect(550, 430, 131, 241));
        pushButton_beagles->setToolTipDuration(0);
        pushButton_beagles->setStyleSheet(QString::fromUtf8("background-image: url(:/dog/img/Beagles.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        pushButton_chihuahua = new QPushButton(home);
        pushButton_chihuahua->setObjectName(QString::fromUtf8("pushButton_chihuahua"));
        pushButton_chihuahua->setGeometry(QRect(560, 460, 131, 181));
        pushButton_chihuahua->setToolTipDuration(0);
        pushButton_chihuahua->setStyleSheet(QString::fromUtf8("background-image: url(:/dog/img/Chihuahua.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        pushButton_Dalmatians = new QPushButton(home);
        pushButton_Dalmatians->setObjectName(QString::fromUtf8("pushButton_Dalmatians"));
        pushButton_Dalmatians->setGeometry(QRect(550, 350, 151, 301));
        pushButton_Dalmatians->setToolTipDuration(0);
        pushButton_Dalmatians->setStyleSheet(QString::fromUtf8("background-image: url(:/dog/img/Dalmatians.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        pushButton_Mastiff = new QPushButton(home);
        pushButton_Mastiff->setObjectName(QString::fromUtf8("pushButton_Mastiff"));
        pushButton_Mastiff->setGeometry(QRect(530, 370, 171, 281));
        pushButton_Mastiff->setToolTipDuration(0);
        pushButton_Mastiff->setStyleSheet(QString::fromUtf8("background-image: url(:/dog/img/Mastiff.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        pushButton_borderCollie = new QPushButton(home);
        pushButton_borderCollie->setObjectName(QString::fromUtf8("pushButton_borderCollie"));
        pushButton_borderCollie->setGeometry(QRect(560, 400, 131, 241));
        pushButton_borderCollie->setToolTipDuration(0);
        pushButton_borderCollie->setStyleSheet(QString::fromUtf8("background-image: url(:/dog/img/borderCollie.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        pushButton_bullTerrier = new QPushButton(home);
        pushButton_bullTerrier->setObjectName(QString::fromUtf8("pushButton_bullTerrier"));
        pushButton_bullTerrier->setGeometry(QRect(540, 390, 151, 251));
        pushButton_bullTerrier->setToolTipDuration(0);
        pushButton_bullTerrier->setStyleSheet(QString::fromUtf8("background-image: url(:/dog/img/bullTerrier.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        pushButton_doberman = new QPushButton(home);
        pushButton_doberman->setObjectName(QString::fromUtf8("pushButton_doberman"));
        pushButton_doberman->setGeometry(QRect(550, 290, 146, 361));
        pushButton_doberman->setToolTipDuration(0);
        pushButton_doberman->setStyleSheet(QString::fromUtf8("background-image: url(:/dog/img/doberman.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        pushButton_german = new QPushButton(home);
        pushButton_german->setObjectName(QString::fromUtf8("pushButton_german"));
        pushButton_german->setGeometry(QRect(550, 330, 128, 311));
        pushButton_german->setToolTipDuration(0);
        pushButton_german->setStyleSheet(QString::fromUtf8("background-image: url(:/dog/img/german.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        pushButton_husky = new QPushButton(home);
        pushButton_husky->setObjectName(QString::fromUtf8("pushButton_husky"));
        pushButton_husky->setGeometry(QRect(540, 400, 131, 241));
        pushButton_husky->setToolTipDuration(0);
        pushButton_husky->setStyleSheet(QString::fromUtf8("background-image: url(:/dog/img/husky.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        pushButton_shetland = new QPushButton(home);
        pushButton_shetland->setObjectName(QString::fromUtf8("pushButton_shetland"));
        pushButton_shetland->setGeometry(QRect(550, 340, 141, 301));
        pushButton_shetland->setToolTipDuration(0);
        pushButton_shetland->setStyleSheet(QString::fromUtf8("background-image: url(:/dog/img/shetland.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        opinion = new QWidget(home);
        opinion->setObjectName(QString::fromUtf8("opinion"));
        opinion->setGeometry(QRect(740, 250, 371, 411));
        opinion->setStyleSheet(QString::fromUtf8("background-image: url(:/main/img/opinions.png);"));
        dowork = new QPushButton(opinion);
        dowork->setObjectName(QString::fromUtf8("dowork"));
        dowork->setGeometry(QRect(50, 90, 271, 71));
        dowork->setToolTipDuration(0);
        dowork->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color: rgb(208, 146, 98);\n"
"background-color: rgb(254, 234, 209);\n"
"background-image: url(:/main/img/opinions_background.png);"));
        dohousework = new QPushButton(opinion);
        dohousework->setObjectName(QString::fromUtf8("dohousework"));
        dohousework->setGeometry(QRect(50, 188, 271, 71));
        dohousework->setToolTipDuration(0);
        dohousework->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color: rgb(208, 146, 98);\n"
"background-color: rgb(254, 234, 209);\n"
"background-image: url(:/main/img/opinions_background.png);"));
        eat = new QPushButton(opinion);
        eat->setObjectName(QString::fromUtf8("eat"));
        eat->setGeometry(QRect(50, 280, 271, 71));
        eat->setToolTipDuration(0);
        eat->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color: rgb(208, 146, 98);\n"
"background-color: rgb(254, 234, 209);\n"
"background-image: url(:/main/img/opinions_background.png);"));
        exit = new QPushButton(opinion);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(140, 13, 91, 31));
        exit->setToolTipDuration(0);
        exit->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color: rgb(53, 53, 53);\n"
"background-color: rgb(254, 234, 209);\n"
"background-image: url(:/main/img/opinions_background.png);"));
        eateat = new QWidget(home);
        eateat->setObjectName(QString::fromUtf8("eateat"));
        eateat->setGeometry(QRect(180, 400, 331, 261));
        eateat->setStyleSheet(QString::fromUtf8("background-image: url(:/main/img/eat_opinion.png);"));
        dogfood = new QSpinBox(eateat);
        dogfood->setObjectName(QString::fromUtf8("dogfood"));
        dogfood->setGeometry(QRect(120, 60, 91, 41));
        bonse = new QSpinBox(eateat);
        bonse->setObjectName(QString::fromUtf8("bonse"));
        bonse->setGeometry(QRect(120, 127, 91, 41));
        medicine = new QSpinBox(eateat);
        medicine->setObjectName(QString::fromUtf8("medicine"));
        medicine->setGeometry(QRect(120, 190, 91, 41));
        label_dogfood_2 = new QLabel(eateat);
        label_dogfood_2->setObjectName(QString::fromUtf8("label_dogfood_2"));
        label_dogfood_2->setGeometry(QRect(230, 60, 71, 41));
        label_dogfood_2->setStyleSheet(QString::fromUtf8("background-image: url(:/main/img/opinions_background.png);\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color: rgb(255, 255, 255);"));
        label_bonse_2 = new QLabel(eateat);
        label_bonse_2->setObjectName(QString::fromUtf8("label_bonse_2"));
        label_bonse_2->setGeometry(QRect(230, 128, 71, 41));
        label_bonse_2->setStyleSheet(QString::fromUtf8("background-image: url(:/main/img/opinions_background.png);\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color: rgb(255, 255, 255);"));
        label_medicine_2 = new QLabel(eateat);
        label_medicine_2->setObjectName(QString::fromUtf8("label_medicine_2"));
        label_medicine_2->setGeometry(QRect(230, 190, 71, 41));
        label_medicine_2->setStyleSheet(QString::fromUtf8("background-image: url(:/main/img/opinions_background.png);\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color: rgb(255, 255, 255);"));
        feed = new QPushButton(eateat);
        feed->setObjectName(QString::fromUtf8("feed"));
        feed->setGeometry(QRect(120, 7, 91, 31));
        feed->setToolTipDuration(0);
        feed->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color: rgb(53, 53, 53);\n"
"background-color: rgb(254, 234, 209);\n"
"background-image: url(:/main/img/opinions_background.png);"));
        exit_2 = new QPushButton(eateat);
        exit_2->setObjectName(QString::fromUtf8("exit_2"));
        exit_2->setGeometry(QRect(10, 7, 93, 31));
        exit_2->setToolTipDuration(0);
        exit_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color: rgb(53, 53, 53);\n"
"background-color: rgb(254, 234, 209);\n"
"background-image: url(:/main/img/opinions_background.png);"));
        bonse->raise();
        medicine->raise();
        feed->raise();
        exit_2->raise();
        label_dogfood_2->raise();
        label_bonse_2->raise();
        label_medicine_2->raise();
        dogfood->raise();
        label_dogname = new QLabel(home);
        label_dogname->setObjectName(QString::fromUtf8("label_dogname"));
        label_dogname->setGeometry(QRect(250, 700, 251, 41));
        label_dogname->setStyleSheet(QString::fromUtf8("background-image: url(:/main/img/homeshow.png);\n"
"color: rgb(227, 125, 63);\n"
"font: 14pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        label_energy = new QLabel(home);
        label_energy->setObjectName(QString::fromUtf8("label_energy"));
        label_energy->setGeometry(QRect(510, 700, 151, 41));
        label_energy->setStyleSheet(QString::fromUtf8("background-image: url(:/main/img/homeshow.png);\n"
"color: rgb(227, 125, 63);\n"
"font: 14pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        label_value = new QLabel(home);
        label_value->setObjectName(QString::fromUtf8("label_value"));
        label_value->setGeometry(QRect(680, 700, 161, 41));
        label_value->setStyleSheet(QString::fromUtf8("background-image: url(:/main/img/homeshow.png);\n"
"color: rgb(227, 125, 63);\n"
"font: 14pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        label_state = new QLabel(home);
        label_state->setObjectName(QString::fromUtf8("label_state"));
        label_state->setGeometry(QRect(850, 700, 181, 41));
        label_state->setStyleSheet(QString::fromUtf8("background-image: url(:/main/img/homeshow.png);\n"
"color: rgb(227, 125, 63);\n"
"font: 14pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        pushButton_honor = new QPushButton(home);
        pushButton_honor->setObjectName(QString::fromUtf8("pushButton_honor"));
        pushButton_honor->setGeometry(QRect(1030, 170, 211, 51));
        pushButton_honor->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 211, 160);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"background-image: url(:/main/img/store.png);\n"
"color:white;"));
        label_Time = new QLabel(home);
        label_Time->setObjectName(QString::fromUtf8("label_Time"));
        label_Time->setGeometry(QRect(840, 40, 131, 41));
        label_Time->setStyleSheet(QString::fromUtf8("background-image: url(:/main/img/homeshow.png);\n"
"color: rgb(227, 125, 63);\n"
"font: 14pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        stackedWidget->addWidget(home);
        store = new QWidget();
        store->setObjectName(QString::fromUtf8("store"));
        store->setStyleSheet(QString::fromUtf8("background-image: url(:/main/img/shopping.png);\n"
"\n"
""));
        pushButton_gohome = new QPushButton(store);
        pushButton_gohome->setObjectName(QString::fromUtf8("pushButton_gohome"));
        pushButton_gohome->setGeometry(QRect(20, 60, 111, 51));
        pushButton_gohome->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 211, 160);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"background-image: url(:/main/img/store.png);\n"
"color:white;"));
        spinBox_dogfood = new QSpinBox(store);
        spinBox_dogfood->setObjectName(QString::fromUtf8("spinBox_dogfood"));
        spinBox_dogfood->setGeometry(QRect(1130, 280, 101, 31));
        spinBox_bonse = new QSpinBox(store);
        spinBox_bonse->setObjectName(QString::fromUtf8("spinBox_bonse"));
        spinBox_bonse->setGeometry(QRect(1130, 340, 101, 31));
        spinBox_medicin = new QSpinBox(store);
        spinBox_medicin->setObjectName(QString::fromUtf8("spinBox_medicin"));
        spinBox_medicin->setGeometry(QRect(1130, 400, 101, 31));
        label_cost = new QLabel(store);
        label_cost->setObjectName(QString::fromUtf8("label_cost"));
        label_cost->setGeometry(QRect(1131, 484, 101, 31));
        label_cost->setTextFormat(Qt::AutoText);
        pushButton_buy = new QPushButton(store);
        pushButton_buy->setObjectName(QString::fromUtf8("pushButton_buy"));
        pushButton_buy->setGeometry(QRect(1070, 60, 111, 51));
        pushButton_buy->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 211, 160);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"background-image: url(:/main/img/store.png);\n"
"color:white;"));
        label_bonse = new QLabel(store);
        label_bonse->setObjectName(QString::fromUtf8("label_bonse"));
        label_bonse->setGeometry(QRect(162, 353, 323, 101));
        label_bonse->setToolTipDuration(5000);
        label_bonse->setStyleSheet(QString::fromUtf8("background-image: url(:/store/img/bonse.png);"));
        label_bonse->setLineWidth(0);
        label_dogfood = new QLabel(store);
        label_dogfood->setObjectName(QString::fromUtf8("label_dogfood"));
        label_dogfood->setGeometry(QRect(518, 293, 407, 215));
        label_dogfood->setToolTipDuration(5000);
        label_dogfood->setStyleSheet(QString::fromUtf8("background-image: url(:/store/img/dogfood.png);"));
        label_dogfood->setLineWidth(0);
        label_medicine = new QLabel(store);
        label_medicine->setObjectName(QString::fromUtf8("label_medicine"));
        label_medicine->setGeometry(QRect(513, 527, 411, 154));
        label_medicine->setToolTipDuration(5000);
        label_medicine->setAutoFillBackground(false);
        label_medicine->setStyleSheet(QString::fromUtf8("background-image: url(:/store/img/medicine .png);"));
        label_medicine->setLineWidth(0);
        label_balance = new QLabel(store);
        label_balance->setObjectName(QString::fromUtf8("label_balance"));
        label_balance->setGeometry(QRect(1140, 635, 111, 31));
        label_balance->setStyleSheet(QString::fromUtf8("color: rgb(244, 147, 53);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        stackedWidget->addWidget(store);
        NewMember = new QWidget();
        NewMember->setObjectName(QString::fromUtf8("NewMember"));
        NewMember->setStyleSheet(QString::fromUtf8("background-image: url(:/dog/img/newmember.png);"));
        pushButton_home = new QPushButton(NewMember);
        pushButton_home->setObjectName(QString::fromUtf8("pushButton_home"));
        pushButton_home->setGeometry(QRect(70, 40, 131, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\347\220\245\347\217\200"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        pushButton_home->setFont(font);
        pushButton_home->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 211, 160);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"background-image: url(:/main/img/store.png);\n"
"color:white;"));
        Chihuahua = new QLabel(NewMember);
        Chihuahua->setObjectName(QString::fromUtf8("Chihuahua"));
        Chihuahua->setGeometry(QRect(80, 370, 111, 31));
        Chihuahua->setToolTipDuration(5000);
        Chihuahua->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color:black;"));
        Chihuahua->setTextInteractionFlags(Qt::NoTextInteraction);
        beagles = new QLabel(NewMember);
        beagles->setObjectName(QString::fromUtf8("beagles"));
        beagles->setGeometry(QRect(260, 370, 121, 31));
        beagles->setToolTipDuration(5000);
        beagles->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color:black;"));
        boderCollie = new QLabel(NewMember);
        boderCollie->setObjectName(QString::fromUtf8("boderCollie"));
        boderCollie->setGeometry(QRect(440, 370, 161, 31));
        boderCollie->setToolTipDuration(5000);
        boderCollie->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color:black;"));
        masstiff = new QLabel(NewMember);
        masstiff->setObjectName(QString::fromUtf8("masstiff"));
        masstiff->setGeometry(QRect(650, 370, 171, 41));
        masstiff->setToolTipDuration(5000);
        masstiff->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color:black;"));
        bullTerrier = new QLabel(NewMember);
        bullTerrier->setObjectName(QString::fromUtf8("bullTerrier"));
        bullTerrier->setGeometry(QRect(110, 730, 111, 31));
        bullTerrier->setToolTipDuration(5000);
        bullTerrier->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color:black;"));
        Dalmatians = new QLabel(NewMember);
        Dalmatians->setObjectName(QString::fromUtf8("Dalmatians"));
        Dalmatians->setGeometry(QRect(270, 730, 111, 31));
        Dalmatians->setToolTipDuration(5000);
        Dalmatians->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color:black;"));
        german = new QLabel(NewMember);
        german->setObjectName(QString::fromUtf8("german"));
        german->setGeometry(QRect(450, 730, 161, 31));
        german->setToolTipDuration(5000);
        german->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color:black;"));
        husky = new QLabel(NewMember);
        husky->setObjectName(QString::fromUtf8("husky"));
        husky->setGeometry(QRect(700, 730, 111, 31));
        husky->setToolTipDuration(5000);
        husky->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color:black;"));
        shetland = new QLabel(NewMember);
        shetland->setObjectName(QString::fromUtf8("shetland"));
        shetland->setGeometry(QRect(860, 730, 191, 41));
        shetland->setToolTipDuration(5000);
        shetland->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color:black;"));
        doberman = new QLabel(NewMember);
        doberman->setObjectName(QString::fromUtf8("doberman"));
        doberman->setGeometry(QRect(1100, 730, 131, 41));
        doberman->setToolTipDuration(5000);
        doberman->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color:black;"));
        pushButton_adopt = new QPushButton(NewMember);
        pushButton_adopt->setObjectName(QString::fromUtf8("pushButton_adopt"));
        pushButton_adopt->setGeometry(QRect(1100, 30, 131, 51));
        pushButton_adopt->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 211, 160);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"background-image: url(:/main/img/store.png);\n"
"color:white;"));
        spinBox_which = new QSpinBox(NewMember);
        spinBox_which->setObjectName(QString::fromUtf8("spinBox_which"));
        spinBox_which->setGeometry(QRect(970, 34, 121, 51));
        label = new QLabel(NewMember);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(851, 34, 111, 51));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 211, 160);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"background-image: url(:/main/img/store.png);\n"
"color:white;"));
        stackedWidget->addWidget(NewMember);
        help1 = new QWidget();
        help1->setObjectName(QString::fromUtf8("help1"));
        help1->setStyleSheet(QString::fromUtf8("background-image: url(:/help/img/love.png);"));
        pushButton_backehome = new QPushButton(help1);
        pushButton_backehome->setObjectName(QString::fromUtf8("pushButton_backehome"));
        pushButton_backehome->setGeometry(QRect(30, 30, 151, 61));
        pushButton_backehome->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        pushButton_next1 = new QPushButton(help1);
        pushButton_next1->setObjectName(QString::fromUtf8("pushButton_next1"));
        pushButton_next1->setGeometry(QRect(1080, 690, 151, 51));
        pushButton_next1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        stackedWidget->addWidget(help1);
        help2 = new QWidget();
        help2->setObjectName(QString::fromUtf8("help2"));
        help2->setStyleSheet(QString::fromUtf8("background-image: url(:/help/img/balance.png);"));
        pushButton_backhome_10 = new QPushButton(help2);
        pushButton_backhome_10->setObjectName(QString::fromUtf8("pushButton_backhome_10"));
        pushButton_backhome_10->setGeometry(QRect(30, 30, 151, 61));
        pushButton_backhome_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        pushButton_next_2 = new QPushButton(help2);
        pushButton_next_2->setObjectName(QString::fromUtf8("pushButton_next_2"));
        pushButton_next_2->setGeometry(QRect(1080, 690, 151, 51));
        pushButton_next_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        pushButton_up_1 = new QPushButton(help2);
        pushButton_up_1->setObjectName(QString::fromUtf8("pushButton_up_1"));
        pushButton_up_1->setGeometry(QRect(30, 690, 151, 51));
        pushButton_up_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        stackedWidget->addWidget(help2);
        help3 = new QWidget();
        help3->setObjectName(QString::fromUtf8("help3"));
        help3->setStyleSheet(QString::fromUtf8("background-image: url(:/help/img/energy.png);"));
        pushButton_backhome_3 = new QPushButton(help3);
        pushButton_backhome_3->setObjectName(QString::fromUtf8("pushButton_backhome_3"));
        pushButton_backhome_3->setGeometry(QRect(30, 30, 151, 61));
        pushButton_backhome_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        pushButton_next_5 = new QPushButton(help3);
        pushButton_next_5->setObjectName(QString::fromUtf8("pushButton_next_5"));
        pushButton_next_5->setGeometry(QRect(1080, 690, 151, 51));
        pushButton_next_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        pushButton_up_2 = new QPushButton(help3);
        pushButton_up_2->setObjectName(QString::fromUtf8("pushButton_up_2"));
        pushButton_up_2->setGeometry(QRect(30, 690, 151, 51));
        pushButton_up_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        stackedWidget->addWidget(help3);
        help4 = new QWidget();
        help4->setObjectName(QString::fromUtf8("help4"));
        help4->setStyleSheet(QString::fromUtf8("background-image: url(:/help/img/newnew.png);"));
        pushButton_backhome_ = new QPushButton(help4);
        pushButton_backhome_->setObjectName(QString::fromUtf8("pushButton_backhome_"));
        pushButton_backhome_->setGeometry(QRect(30, 30, 151, 61));
        pushButton_backhome_->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        pushButton_up_5 = new QPushButton(help4);
        pushButton_up_5->setObjectName(QString::fromUtf8("pushButton_up_5"));
        pushButton_up_5->setGeometry(QRect(30, 690, 151, 51));
        pushButton_up_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        stackedWidget->addWidget(help4);
        save = new QWidget();
        save->setObjectName(QString::fromUtf8("save"));
        save->setStyleSheet(QString::fromUtf8("background-image: url(:/saveandread/img/save.png);"));
        save1 = new QPushButton(save);
        save1->setObjectName(QString::fromUtf8("save1"));
        save1->setGeometry(QRect(520, 180, 311, 61));
        save2 = new QPushButton(save);
        save2->setObjectName(QString::fromUtf8("save2"));
        save2->setGeometry(QRect(520, 333, 311, 61));
        save3 = new QPushButton(save);
        save3->setObjectName(QString::fromUtf8("save3"));
        save3->setGeometry(QRect(520, 485, 311, 61));
        save4 = new QPushButton(save);
        save4->setObjectName(QString::fromUtf8("save4"));
        save4->setGeometry(QRect(520, 637, 311, 61));
        save_exit = new QPushButton(save);
        save_exit->setObjectName(QString::fromUtf8("save_exit"));
        save_exit->setGeometry(QRect(20, 20, 131, 51));
        save_exit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 211, 160);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"background-image: url(:/main/img/store.png);\n"
"color:white;"));
        stackedWidget->addWidget(save);
        read = new QWidget();
        read->setObjectName(QString::fromUtf8("read"));
        read->setStyleSheet(QString::fromUtf8("background-image: url(:/saveandread/img/read.png);"));
        read1 = new QPushButton(read);
        read1->setObjectName(QString::fromUtf8("read1"));
        read1->setGeometry(QRect(460, 170, 311, 61));
        reset1 = new QPushButton(read);
        reset1->setObjectName(QString::fromUtf8("reset1"));
        reset1->setGeometry(QRect(820, 160, 85, 85));
        reset1->setStyleSheet(QString::fromUtf8("background-image: url(:/saveandread/img/restart.png);"));
        reset2 = new QPushButton(read);
        reset2->setObjectName(QString::fromUtf8("reset2"));
        reset2->setGeometry(QRect(820, 310, 85, 85));
        reset2->setStyleSheet(QString::fromUtf8("background-image: url(:/saveandread/img/restart.png);"));
        reset3 = new QPushButton(read);
        reset3->setObjectName(QString::fromUtf8("reset3"));
        reset3->setGeometry(QRect(820, 460, 85, 85));
        reset3->setStyleSheet(QString::fromUtf8("background-image: url(:/saveandread/img/restart.png);"));
        reset4 = new QPushButton(read);
        reset4->setObjectName(QString::fromUtf8("reset4"));
        reset4->setGeometry(QRect(820, 615, 85, 85));
        reset4->setStyleSheet(QString::fromUtf8("background-image: url(:/saveandread/img/restart.png);"));
        read2 = new QPushButton(read);
        read2->setObjectName(QString::fromUtf8("read2"));
        read2->setGeometry(QRect(460, 322, 311, 61));
        read3 = new QPushButton(read);
        read3->setObjectName(QString::fromUtf8("read3"));
        read3->setGeometry(QRect(460, 474, 311, 61));
        read4 = new QPushButton(read);
        read4->setObjectName(QString::fromUtf8("read4"));
        read4->setGeometry(QRect(460, 628, 311, 61));
        read_exit = new QPushButton(read);
        read_exit->setObjectName(QString::fromUtf8("read_exit"));
        read_exit->setGeometry(QRect(30, 20, 131, 51));
        read_exit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 211, 160);\n"
"font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"background-image: url(:/main/img/store.png);\n"
"color:white;"));
        stackedWidget->addWidget(read);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(ShiJX_Widget);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(ShiJX_Widget);
    } // setupUi

    void retranslateUi(QWidget *ShiJX_Widget)
    {
        ShiJX_Widget->setWindowTitle(QApplication::translate("ShiJX_Widget", "ShiJX_Widget", nullptr));
        pushButton_start->setText(QApplication::translate("ShiJX_Widget", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        pushButton->setText(QApplication::translate("ShiJX_Widget", "\345\233\236\345\256\266", nullptr));
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QApplication::translate("ShiJX_Widget", "\347\210\261\345\277\203\346\225\260\351\207\217\350\276\276\345\210\2601\357\274\214\345\217\257\350\216\267\345\276\227\347\247\260\345\217\267\342\200\234\347\210\261\345\277\203\345\256\266\345\272\255\342\200\235", nullptr));
#endif // QT_NO_TOOLTIP
        label_8->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_9->setToolTip(QApplication::translate("ShiJX_Widget", "\347\210\261\345\277\203\346\225\260\351\207\217\350\276\276\345\210\26010\357\274\214\345\217\257\350\216\267\347\247\260\345\217\267\342\200\234\347\210\261\345\277\203\345\244\247\344\276\240\342\200\235", nullptr));
#endif // QT_NO_TOOLTIP
        label_9->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_10->setToolTip(QApplication::translate("ShiJX_Widget", "\347\210\261\345\277\203\346\225\260\351\207\217\350\276\276\345\210\26020\357\274\214\345\217\257\350\216\267\345\276\227\347\247\260\345\217\267\342\200\235\347\210\261\345\277\203\350\266\205\344\272\272\342\200\234", nullptr));
#endif // QT_NO_TOOLTIP
        label_10->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_11->setToolTip(QApplication::translate("ShiJX_Widget", "\351\207\221\345\270\201\346\225\260\350\276\276\345\210\26066\357\274\214\345\217\257\345\276\227\347\247\260\345\217\267\342\200\235\350\264\242\345\257\214\345\210\235\347\224\237\342\200\234", nullptr));
#endif // QT_NO_TOOLTIP
        label_11->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_12->setToolTip(QApplication::translate("ShiJX_Widget", "\351\207\221\345\270\201\346\225\260\351\207\217\345\210\260\350\276\276100\357\274\214\345\217\257\350\216\267\345\276\227\347\247\260\345\217\267\342\200\235\351\207\221\345\270\201\345\244\247\344\272\250\342\200\234", nullptr));
#endif // QT_NO_TOOLTIP
        label_12->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_13->setToolTip(QApplication::translate("ShiJX_Widget", "\351\207\221\345\270\201\346\225\260\351\207\217\350\276\276\345\210\260666\357\274\214\345\217\257\350\216\267\345\276\227\347\247\260\345\217\267\342\200\235\347\231\276\344\270\207\345\257\214\347\277\201\342\200\234", nullptr));
#endif // QT_NO_TOOLTIP
        label_13->setText(QString());
        pushButton_gotostore->setText(QApplication::translate("ShiJX_Widget", "\345\216\273\345\225\206\345\272\227", nullptr));
        pushButton_exit->setText(QApplication::translate("ShiJX_Widget", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
        pushButton_newmember->setText(QApplication::translate("ShiJX_Widget", "\351\242\206\345\205\273\346\226\260\346\210\220\345\221\230", nullptr));
        pushButton_help->setText(QApplication::translate("ShiJX_Widget", "\345\270\256\345\212\251", nullptr));
        pushButton_read->setText(QApplication::translate("ShiJX_Widget", "\350\257\273\346\241\243", nullptr));
        pushButton_save->setText(QApplication::translate("ShiJX_Widget", "\345\255\230\346\241\243", nullptr));
        label_Title->setText(QString());
        label_Wealth->setText(QString());
        label_Love->setText(QString());
        pushButton_beagles->setText(QString());
        pushButton_chihuahua->setText(QString());
        pushButton_Dalmatians->setText(QString());
        pushButton_Mastiff->setText(QString());
        pushButton_borderCollie->setText(QString());
        pushButton_bullTerrier->setText(QString());
        pushButton_doberman->setText(QString());
        pushButton_german->setText(QString());
        pushButton_husky->setText(QString());
        pushButton_shetland->setText(QString());
        dowork->setText(QApplication::translate("ShiJX_Widget", "\345\244\226\345\207\272\346\211\223\345\267\245", nullptr));
        dohousework->setText(QApplication::translate("ShiJX_Widget", "\345\201\232\345\256\266\345\212\241", nullptr));
        eat->setText(QApplication::translate("ShiJX_Widget", "\350\241\245\345\205\205\350\203\275\351\207\217", nullptr));
        exit->setText(QApplication::translate("ShiJX_Widget", "\345\205\263\351\227\255", nullptr));
        label_dogfood_2->setText(QString());
        label_bonse_2->setText(QString());
        label_medicine_2->setText(QString());
        feed->setText(QApplication::translate("ShiJX_Widget", "\346\212\225\345\226\202", nullptr));
        exit_2->setText(QApplication::translate("ShiJX_Widget", "\345\205\263\351\227\255", nullptr));
        label_dogname->setText(QString());
        label_energy->setText(QString());
        label_value->setText(QString());
        label_state->setText(QString());
        pushButton_honor->setText(QApplication::translate("ShiJX_Widget", "\350\215\243\350\252\211", nullptr));
        label_Time->setText(QString());
        pushButton_gohome->setText(QApplication::translate("ShiJX_Widget", "\345\233\236\345\256\266", nullptr));
        label_cost->setText(QApplication::translate("ShiJX_Widget", "0", nullptr));
        pushButton_buy->setText(QApplication::translate("ShiJX_Widget", "\347\273\223\347\256\227", nullptr));
#ifndef QT_NO_TOOLTIP
        label_bonse->setToolTip(QApplication::translate("ShiJX_Widget", "\345\260\217\351\233\266\351\243\237\351\252\250\345\244\264\357\274\214\346\257\217\344\273\275\346\217\220\344\276\2333\347\202\271\350\203\275\351\207\217\343\200\202", nullptr));
#endif // QT_NO_TOOLTIP
        label_bonse->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_dogfood->setToolTip(QApplication::translate("ShiJX_Widget", "\344\270\273\351\243\237\347\213\227\347\262\256\357\274\214\346\257\217\344\273\275\346\217\220\344\276\2335\347\202\271\350\203\275\351\207\217\343\200\202", nullptr));
#endif // QT_NO_TOOLTIP
        label_dogfood->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_medicine->setToolTip(QApplication::translate("ShiJX_Widget", "\350\215\257\347\211\251\357\274\214\347\224\237\347\227\205\345\277\205\345\244\207\343\200\202\346\257\217\344\273\275\346\217\220\344\276\2331\347\202\271\350\203\275\351\207\217", nullptr));
#endif // QT_NO_TOOLTIP
        label_medicine->setText(QString());
        label_balance->setText(QString());
        pushButton_home->setText(QApplication::translate("ShiJX_Widget", "\345\233\236\345\256\266", nullptr));
#ifndef QT_NO_TOOLTIP
        Chihuahua->setToolTip(QApplication::translate("ShiJX_Widget", "\345\220\211\345\250\203\345\250\203\350\201\252\351\242\226\343\200\201\346\264\273\346\263\274\343\200\201\351\273\217\344\272\272\357\274\214\350\241\214\345\212\250\350\255\246\346\203\225\357\274\214\345\215\201\345\210\206\345\213\207\346\225\242\343\200\202", nullptr));
#endif // QT_NO_TOOLTIP
        Chihuahua->setText(QApplication::translate("ShiJX_Widget", "1-\345\220\211\345\250\203\345\250\203", nullptr));
#ifndef QT_NO_TOOLTIP
        beagles->setToolTip(QApplication::translate("ShiJX_Widget", "\346\257\224\346\240\274\347\212\254\347\232\204\346\200\247\346\240\274\346\270\251\351\241\272\357\274\214\345\277\240\350\257\232\350\256\244\344\270\273\357\274\214\345\244\264\350\204\221\350\201\252\346\230\216\357\274\214\345\255\246\344\271\240\350\203\275\345\212\233\345\274\272\343\200\202", nullptr));
#endif // QT_NO_TOOLTIP
        beagles->setText(QApplication::translate("ShiJX_Widget", "2-\346\257\224\346\240\274\347\212\254", nullptr));
#ifndef QT_NO_TOOLTIP
        boderCollie->setToolTip(QApplication::translate("ShiJX_Widget", "\350\276\271\347\211\247\346\200\247\346\203\205\345\276\210\346\270\251\345\222\214\357\274\214\345\256\271\345\277\215\346\200\247\345\245\275,\350\255\246\346\203\225\346\200\247\351\253\230,\347\203\255\346\203\205,\346\234\215\344\273\216\346\200\247\351\253\230\343\200\202", nullptr));
#endif // QT_NO_TOOLTIP
        boderCollie->setText(QApplication::translate("ShiJX_Widget", "3-\350\276\271\345\242\203\347\211\247\347\276\212\347\212\254", nullptr));
#ifndef QT_NO_TOOLTIP
        masstiff->setToolTip(QApplication::translate("ShiJX_Widget", "\351\251\254\345\243\253\346\217\220\345\244\253\347\212\254\346\200\247\346\240\274\346\262\211\347\250\263\343\200\201\345\222\214\345\226\204\343\200\201\345\277\240\345\256\236,\346\264\273\345\212\233\345\205\205\346\262\233,\345\205\267\346\234\211\345\274\272\347\203\210\347\232\204\346\224\273\345\207\273\346\200\247\343\200\202", nullptr));
#endif // QT_NO_TOOLTIP
        masstiff->setText(QApplication::translate("ShiJX_Widget", "4-\351\251\254\345\243\253\346\217\220\345\244\253\347\212\254", nullptr));
#ifndef QT_NO_TOOLTIP
        bullTerrier->setToolTip(QApplication::translate("ShiJX_Widget", "\347\211\233\345\244\264\346\242\227\347\234\213\350\265\267\346\235\245\345\276\210\345\207\266\357\274\214\344\275\206\345\257\271\344\272\272\345\217\213\345\245\275\357\274\214\345\215\201\345\210\206\345\277\240\350\257\232\343\200\202", nullptr));
#endif // QT_NO_TOOLTIP
        bullTerrier->setText(QApplication::translate("ShiJX_Widget", "5-\347\211\233\345\244\264\346\242\227", nullptr));
#ifndef QT_NO_TOOLTIP
        Dalmatians->setToolTip(QApplication::translate("ShiJX_Widget", "\346\226\221\347\202\271\347\213\227\346\200\247\346\240\274\345\276\210\346\270\251\351\241\272\357\274\214\345\257\271\344\270\273\344\272\272\345\277\240\350\257\232\357\274\214\350\202\214\350\202\211\345\274\272\345\243\256\357\274\214\345\205\205\346\273\241\346\264\273\345\212\233\343\200\202", nullptr));
#endif // QT_NO_TOOLTIP
        Dalmatians->setText(QApplication::translate("ShiJX_Widget", "6-\346\226\221\347\202\271\347\213\227", nullptr));
#ifndef QT_NO_TOOLTIP
        german->setToolTip(QApplication::translate("ShiJX_Widget", "\345\276\267\347\211\247\347\212\254\346\236\201\345\205\266\346\270\251\351\241\272\345\226\204\350\211\257\357\274\214\350\207\252\344\277\241\345\274\200\346\234\227\357\274\214\350\207\252\346\216\247\345\212\233\345\274\272\357\274\214\346\225\217\346\215\267\357\274\214\350\201\252\346\230\216\345\245\275\346\226\227\343\200\202", nullptr));
#endif // QT_NO_TOOLTIP
        german->setText(QApplication::translate("ShiJX_Widget", "7-\345\276\267\345\233\275\347\211\247\347\276\212\347\212\254", nullptr));
#ifndef QT_NO_TOOLTIP
        husky->setToolTip(QApplication::translate("ShiJX_Widget", "\345\223\210\345\243\253\345\245\207\345\245\275\345\212\250\357\274\214\347\262\276\345\212\233\346\227\272\347\233\233\357\274\214\345\257\271\344\273\273\344\275\225\344\272\272\351\203\275\346\270\251\351\241\272\357\274\214\347\234\213\345\256\266\350\203\275\345\212\233\345\237\272\346\234\254\344\270\272\351\233\266\343\200\202", nullptr));
#endif // QT_NO_TOOLTIP
        husky->setText(QApplication::translate("ShiJX_Widget", "8-\345\223\210\345\243\253\345\245\207", nullptr));
#ifndef QT_NO_TOOLTIP
        shetland->setToolTip(QApplication::translate("ShiJX_Widget", "\345\226\234\344\271\220\350\222\202\347\212\254\350\201\252\346\230\216\344\274\266\344\277\220\357\274\214\346\264\273\346\263\274\345\245\275\345\212\250\357\274\214\345\277\240\344\272\216\344\270\273\344\272\272\357\274\214\344\275\206\345\257\271\351\231\214\347\224\237\344\272\272\345\255\230\346\234\211\346\210\222\345\277\203\357\274\214\350\255\246\350\247\211\346\200\247\351\253\230", nullptr));
#endif // QT_NO_TOOLTIP
        shetland->setText(QApplication::translate("ShiJX_Widget", "9-\345\226\234\344\271\220\350\222\202\347\211\247\347\276\212\347\212\254", nullptr));
#ifndef QT_NO_TOOLTIP
        doberman->setToolTip(QApplication::translate("ShiJX_Widget", "\346\235\234\345\256\276\347\212\254\346\230\257\345\244\251\347\224\237\347\232\204\350\255\246\345\215\253\347\212\254\357\274\214\346\200\247\346\240\274\350\203\206\345\244\247\357\274\214\350\201\252\346\230\216\346\234\272\346\225\217\357\274\214\350\255\246\346\203\225\345\235\232\345\256\232\357\274\214\345\277\240\350\257\232\344\270\224\345\213\207\346\225\242\343\200\202", nullptr));
#endif // QT_NO_TOOLTIP
        doberman->setText(QApplication::translate("ShiJX_Widget", "10-\346\235\234\345\256\276\347\212\254", nullptr));
        pushButton_adopt->setText(QApplication::translate("ShiJX_Widget", "\345\260\261\345\256\203\344\272\206", nullptr));
        label->setText(QApplication::translate("ShiJX_Widget", "\351\200\211\346\213\251\347\274\226\345\217\267", nullptr));
        pushButton_backehome->setText(QApplication::translate("ShiJX_Widget", "\345\233\236\345\210\260\346\270\270\346\210\217", nullptr));
        pushButton_next1->setText(QApplication::translate("ShiJX_Widget", "\344\270\213\344\270\200\351\241\265", nullptr));
        pushButton_backhome_10->setText(QApplication::translate("ShiJX_Widget", "\345\233\236\345\210\260\346\270\270\346\210\217", nullptr));
        pushButton_next_2->setText(QApplication::translate("ShiJX_Widget", "\344\270\213\344\270\200\351\241\265", nullptr));
        pushButton_up_1->setText(QApplication::translate("ShiJX_Widget", "\344\270\212\344\270\200\351\241\265", nullptr));
        pushButton_backhome_3->setText(QApplication::translate("ShiJX_Widget", "\345\233\236\345\210\260\346\270\270\346\210\217", nullptr));
        pushButton_next_5->setText(QApplication::translate("ShiJX_Widget", "\344\270\213\344\270\200\351\241\265", nullptr));
        pushButton_up_2->setText(QApplication::translate("ShiJX_Widget", "\344\270\212\344\270\200\351\241\265", nullptr));
        pushButton_backhome_->setText(QApplication::translate("ShiJX_Widget", "\345\233\236\345\210\260\346\270\270\346\210\217", nullptr));
        pushButton_up_5->setText(QApplication::translate("ShiJX_Widget", "\344\270\212\344\270\200\351\241\265", nullptr));
        save1->setText(QString());
        save2->setText(QString());
        save3->setText(QString());
        save4->setText(QString());
        save_exit->setText(QApplication::translate("ShiJX_Widget", "\345\233\236\345\256\266", nullptr));
        read1->setText(QString());
        reset1->setText(QString());
        reset2->setText(QString());
        reset3->setText(QString());
        reset4->setText(QString());
        read2->setText(QString());
        read3->setText(QString());
        read4->setText(QString());
        read_exit->setText(QApplication::translate("ShiJX_Widget", "\345\233\236\345\256\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShiJX_Widget: public Ui_ShiJX_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHIJX_WIDGET_H
