#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hard_coding.h"
#include <QPixmap>

int code_rule(int code);
int extra_rule(int code);
char make_chord(int code);
int s_move_for_first(char code);

bool is_chord = false; // 중복 선택용 변수
bool is_melody = false;

int code[32];

char melody[32];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand((unsigned)time(NULL));
    ui->setupUi(this);
    QPixmap sdmiku("C:/Users/Yukari/Desktop/ezc/sdmiku.png");
    QPixmap score("C:/Users/Yukari/Desktop/ezc/c5.png");
    QPixmap s("C:/Users/Yukari/Desktop/ezc/s2.png");

    ui->sd_miku->setPixmap(sdmiku.scaled(200,200,Qt::KeepAspectRatio));
    ui->score1->setPixmap(score);
    ui->score2->setPixmap(score);

    /*
    음계 기록용 라인임
    y좌표 기준
    1번 5선보

    220 미
    */
    ui->s1_1->setPixmap(s.scaled(25,17));
    ui->s1_2->setPixmap(s.scaled(25,17));
    ui->s1_3->setPixmap(s.scaled(25,17));
    ui->s1_4->setPixmap(s.scaled(25,17));

    ui->s2_1->setPixmap(s.scaled(25,17));
    ui->s2_2->setPixmap(s.scaled(25,17));
    ui->s2_3->setPixmap(s.scaled(25,17));
    ui->s2_4->setPixmap(s.scaled(25,17));

    ui->s3_1->setPixmap(s.scaled(25,17));
    ui->s3_2->setPixmap(s.scaled(25,17));
    ui->s3_3->setPixmap(s.scaled(25,17));
    ui->s3_4->setPixmap(s.scaled(25,17));

    ui->s4_1->setPixmap(s.scaled(25,17));
    ui->s4_2->setPixmap(s.scaled(25,17));
    ui->s4_3->setPixmap(s.scaled(25,17));
    ui->s4_4->setPixmap(s.scaled(25,17));

    ui->s5_1->setPixmap(s.scaled(25,17));
    ui->s5_2->setPixmap(s.scaled(25,17));
    ui->s5_3->setPixmap(s.scaled(25,17));
    ui->s5_4->setPixmap(s.scaled(25,17));

    ui->s6_1->setPixmap(s.scaled(25,17));
    ui->s6_2->setPixmap(s.scaled(25,17));
    ui->s6_3->setPixmap(s.scaled(25,17));
    ui->s6_4->setPixmap(s.scaled(25,17));

    ui->s7_1->setPixmap(s.scaled(25,17));
    ui->s7_2->setPixmap(s.scaled(25,17));
    ui->s7_3->setPixmap(s.scaled(25,17));
    ui->s7_4->setPixmap(s.scaled(25,17));

    ui->s8_1->setPixmap(s.scaled(25,17));
    ui->s8_2->setPixmap(s.scaled(25,17));
    ui->s8_3->setPixmap(s.scaled(25,17));
    ui->s8_4->setPixmap(s.scaled(25,17));
    //

    ui->C0_1->setAlignment(Qt::AlignCenter);
    ui->C0_2->setAlignment(Qt::AlignCenter);
    ui->C0_3->setAlignment(Qt::AlignCenter);
    ui->C0_4->setAlignment(Qt::AlignCenter);

    ui->C1_1->setAlignment(Qt::AlignCenter);
    ui->C1_2->setAlignment(Qt::AlignCenter);
    ui->C1_3->setAlignment(Qt::AlignCenter);
    ui->C1_4->setAlignment(Qt::AlignCenter);

    ui->C2_1->setAlignment(Qt::AlignCenter);
    ui->C2_2->setAlignment(Qt::AlignCenter);
    ui->C2_3->setAlignment(Qt::AlignCenter);
    ui->C2_4->setAlignment(Qt::AlignCenter);

    ui->C3_1->setAlignment(Qt::AlignCenter);
    ui->C3_2->setAlignment(Qt::AlignCenter);
    ui->C3_3->setAlignment(Qt::AlignCenter);
    ui->C3_4->setAlignment(Qt::AlignCenter);

    ui->C4_1->setAlignment(Qt::AlignCenter);
    ui->C4_2->setAlignment(Qt::AlignCenter);
    ui->C4_3->setAlignment(Qt::AlignCenter);
    ui->C4_4->setAlignment(Qt::AlignCenter);

    ui->C5_1->setAlignment(Qt::AlignCenter);
    ui->C5_2->setAlignment(Qt::AlignCenter);
    ui->C5_3->setAlignment(Qt::AlignCenter);
    ui->C5_4->setAlignment(Qt::AlignCenter);

    ui->C6_1->setAlignment(Qt::AlignCenter);
    ui->C6_2->setAlignment(Qt::AlignCenter);
    ui->C6_3->setAlignment(Qt::AlignCenter);
    ui->C6_4->setAlignment(Qt::AlignCenter);

    ui->C7_1->setAlignment(Qt::AlignCenter);
    ui->C7_2->setAlignment(Qt::AlignCenter);
    ui->C7_3->setAlignment(Qt::AlignCenter);
    ui->C7_4->setAlignment(Qt::AlignCenter);

    ui->pushButton_2->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->pushButton_3->setAttribute(Qt::WA_TranslucentBackground, true);
    QString disabledStyle = "QPushButton:disabled { background-color: lightgray; color: darkgray; }";
    ui->pushButton_2->setStyleSheet(disabledStyle);
    ui->pushButton_3->setStyleSheet(disabledStyle);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() // 화음
{
    code[0] = 1;
    code[1] = code_rule(code[0]);
    code[2] = extra_rule(code[1]);
    code[3] = 5;
    code[4] = 1;
    code[5] = extra_rule(code[4]);
    code[6] = 5;
    code[7] = 1;
    ui->pushButton_2->setEnabled(true);

    ui->code0->setText(QString::number(code[0])+"도 화음");
    ui->code1->setText(QString::number(code[1])+"도 화음");
    ui->code2->setText(QString::number(code[2])+"도 화음");
    ui->code3->setText(QString::number(code[3])+"도 화음");
    ui->code4->setText(QString::number(code[4])+"도 화음");
    ui->code5->setText(QString::number(code[5])+"도 화음");
    ui->code6->setText(QString::number(code[6])+"도 화음");
    ui->code7->setText(QString::number(code[7])+"도 화음");
    if(is_chord)
        on_pushButton_2_clicked();
    if(is_melody)
        on_pushButton_3_clicked();
}

void MainWindow::on_pushButton_2_clicked() // 배경 코드
{
    is_chord = true;
    ui->pushButton_3->setEnabled(true);
    ui->C0->setText("코드 : "+QString(make_chord(code[0])));
    ui->C1->setText("코드 : "+QString(make_chord(code[1])));
    ui->C2->setText("코드 : "+QString(make_chord(code[2])));
    ui->C3->setText("코드 : "+QString(make_chord(code[3])));
    ui->C4->setText("코드 : "+QString(make_chord(code[4])));
    ui->C5->setText("코드 : "+QString(make_chord(code[5])));
    ui->C6->setText("코드 : "+QString(make_chord(code[6])));
    ui->C7->setText("코드 : "+QString(make_chord(code[7])));
    if(is_melody == true){
        on_pushButton_3_clicked();
    }
}

void MainWindow::on_pushButton_3_clicked() // 멜로디
{
    srand((unsigned)time(NULL));
    is_melody = true;

    float B = 0.5;
    melody[0] = make_chord(code[0]);
    melody[1] = make_chord(code[0]);
    melody[2] = make_chord(code[0]);
    melody[3] = make_chord(code[0]);

    melody[4] = make_chord(code[1]);
    melody[5] = make_chord(code[1]);
    melody[6] = make_chord(code[1]);
    melody[7] = make_chord(code[1]);

    melody[8] = make_chord(code[2]);
    melody[9] = make_chord(code[2]);
    melody[10] = make_chord(code[2]);
    melody[11] = make_chord(code[2]);

    melody[12] = make_chord(code[3]);
    melody[13] = make_chord(code[3]);
    melody[14] = make_chord(code[3]);
    melody[15] = make_chord(code[3]);

    melody[16] = make_chord(code[4]);
    melody[17] = make_chord(code[4]);
    melody[18] = make_chord(code[4]);
    melody[19] = make_chord(code[4]);

    melody[20] = make_chord(code[5]);
    melody[21] = make_chord(code[5]);
    melody[22] = make_chord(code[5]);
    melody[23] = make_chord(code[5]);

    melody[24] = make_chord(code[6]);
    melody[25] = make_chord(code[6]);
    melody[26] = make_chord(code[6]);
    melody[27] = make_chord(code[6]);


    melody[28] = make_chord(code[7]);
    melody[29] = make_chord(code[7]);
    melody[30] = make_chord(code[7]);
    melody[31] = make_chord(code[7]);

    ui->C0_1->setText(QString(melody[0]));
    ui->C0_2->setText(QString(melody[1]));
    ui->C0_3->setText(QString(melody[2]));
    ui->C0_4->setText(QString(melody[3]));
    ui->s1_1->move(50,s_move_for_first(melody[0])+B);
    ui->s1_2->move(80,s_move_for_first(melody[1])+B);
    ui->s1_3->move(110,s_move_for_first(melody[2])+B);
    ui->s1_4->move(140,s_move_for_first(melody[3])+B);
    //
    ui->C1_1->setText(QString(melody[4]));
    ui->C1_2->setText(QString(melody[5]));
    ui->C1_3->setText(QString(melody[6]));
    ui->C1_4->setText(QString(melody[7]));
    ui->s2_1->move(200,s_move_for_first(melody[4])+B);
    ui->s2_2->move(230,s_move_for_first(melody[5])+B);
    ui->s2_3->move(260,s_move_for_first(melody[6])+B);
    ui->s2_4->move(290,s_move_for_first(melody[7])+B);
    //
    ui->C2_1->setText(QString(melody[8]));
    ui->C2_2->setText(QString(melody[9]));
    ui->C2_3->setText(QString(melody[10]));
    ui->C2_4->setText(QString(melody[11]));
    ui->s3_1->move(350,s_move_for_first(melody[8])+B);
    ui->s3_2->move(380,s_move_for_first(melody[9])+B);
    ui->s3_3->move(410,s_move_for_first(melody[10])+B);
    ui->s3_4->move(440,s_move_for_first(melody[11])+B);
    //
    ui->C3_1->setText(QString(melody[12]));
    ui->C3_2->setText(QString(melody[13]));
    ui->C3_3->setText(QString(melody[14]));
    ui->C3_4->setText(QString(melody[15]));
    ui->s4_1->move(500,s_move_for_first(melody[12])+B);
    ui->s4_2->move(530,s_move_for_first(melody[13])+B);
    ui->s4_3->move(560,s_move_for_first(melody[14])+B);
    ui->s4_4->move(590,s_move_for_first(melody[15])+B);
    //
//////////////////////////////////////////////////////////////////////
    float A = 250.5; // 보정값
    ui->C4_1->setText(QString(melody[16]));
    ui->C4_2->setText(QString(melody[17]));
    ui->C4_3->setText(QString(melody[18]));
    ui->C4_4->setText(QString(melody[19]));
    ui->s5_1->move(50,s_move_for_first(melody[16])+A);
    ui->s5_2->move(80,s_move_for_first(melody[17])+A);
    ui->s5_3->move(110,s_move_for_first(melody[18])+A);
    ui->s5_4->move(140,s_move_for_first(melody[19])+A);
    //
    ui->C5_1->setText(QString(melody[20]));
    ui->C5_2->setText(QString(melody[21]));
    ui->C5_3->setText(QString(melody[22]));
    ui->C5_4->setText(QString(melody[23]));
    ui->s6_1->move(200,s_move_for_first(melody[20])+A);
    ui->s6_2->move(230,s_move_for_first(melody[21])+A);
    ui->s6_3->move(260,s_move_for_first(melody[22])+A);
    ui->s6_4->move(290,s_move_for_first(melody[23])+A);
    //
    ui->C6_1->setText(QString(melody[24]));
    ui->C6_2->setText(QString(melody[25]));
    ui->C6_3->setText(QString(melody[26]));
    ui->C6_4->setText(QString(melody[27]));
    ui->s7_1->move(350,s_move_for_first(melody[24])+A);
    ui->s7_2->move(380,s_move_for_first(melody[25])+A);
    ui->s7_3->move(410,s_move_for_first(melody[26])+A);
    ui->s7_4->move(440,s_move_for_first(melody[27])+A);
    //
    ui->C7_1->setText(QString(melody[28]));
    ui->C7_2->setText(QString(melody[29]));
    ui->C7_3->setText(QString(melody[30]));
    ui->C7_4->setText(QString(melody[31]));
    ui->s8_1->move(500,s_move_for_first(melody[28])+A);
    ui->s8_2->move(530,s_move_for_first(melody[29])+A);
    ui->s8_3->move(560,s_move_for_first(melody[30])+A);
    ui->s8_4->move(590,s_move_for_first(melody[31])+A);
}

