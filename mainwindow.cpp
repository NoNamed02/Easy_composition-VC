#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hard_coding.h"

#include <QApplication>

int code_rule(int code);
int extra_rule(int code);
char make_chord(int code);
int s_move_for_first(char code);

bool is_chord = false; // 중복 선택용 변수
bool is_melody = false;

int currentMelodyIndex;
int chordIndex;

int code[32];
char Code[8];

char melody[32];
char chord[8];


////////////////////////////////////////////////////////////////////

QMediaPlayer * v1 = new QMediaPlayer();
QMediaPlayer * v2 = new QMediaPlayer();
QMediaPlayer * v3 = new QMediaPlayer();

QMediaPlayer * v1_1 = new QMediaPlayer();
QMediaPlayer * v1_2 = new QMediaPlayer();
QMediaPlayer * v2_1 = new QMediaPlayer();
QMediaPlayer * v3_1 = new QMediaPlayer();


QAudioOutput *a1 = new QAudioOutput();
QAudioOutput *a2 = new QAudioOutput();
QAudioOutput *a3 = new QAudioOutput();

QAudioOutput *a1_1 = new QAudioOutput();
QAudioOutput *a1_2 = new QAudioOutput();
QAudioOutput *a2_1 = new QAudioOutput();
QAudioOutput *a3_1 = new QAudioOutput();

QMediaPlayer * out = new QMediaPlayer();
QAudioOutput * Aout = new QAudioOutput();

QMediaPlayer * p_start = new QMediaPlayer();
QAudioOutput * Sout = new QAudioOutput();


QMediaPlayer * p_voice = new QMediaPlayer();
QAudioOutput * voice_OUT = new QAudioOutput();


QMediaPlayer * p_chord = new QMediaPlayer();
QAudioOutput * chord_OUT = new QAudioOutput();


/////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand((unsigned)time(NULL));
    ui->setupUi(this);
    QPixmap sdmiku("C:/Users/Yukari/Desktop/ezc/sdmiku.png");
    QPixmap score("C:/Users/Yukari/Desktop/ezc/c5.png");
    QPixmap s("C:/Users/Yukari/Desktop/ezc/s2_1.png");
    QPixmap mikulogo("C:/Users/Yukari/Documents/EASY_Composition/mikulogo.png");

    //////////////////음악 관련/////////////////////////////
    //QMediaPlayer * music = new QMediaPlayer();
    //music->setSource(QUrl("C:/Users/Yukari/Downloads/rabinin.mp3"));

    v1->setSource((QUrl("qrc:/sounds/v1.wav")));
    v1->setAudioOutput(a1);
    v2->setSource((QUrl("qrc:/sounds/v2.wav")));
    v2->setAudioOutput(a2);
    v3->setSource((QUrl("qrc:/sounds/v3.wav")));
    v3->setAudioOutput(a3);

    v1_1->setSource((QUrl("qrc:/sounds/v1_1.wav")));
    v1_1->setAudioOutput(a1_1);
    v2_1->setSource((QUrl("qrc:/sounds/v2_1.wav")));
    v2_1->setAudioOutput(a2_1);
    v3_1->setSource((QUrl("qrc:/sounds/v3_1.wav")));
    v3_1->setAudioOutput(a3_1);

    v1_2->setSource((QUrl("qrc:/sounds/v1_2.wav")));
    v1_2->setAudioOutput(a1_2);



    out->setSource((QUrl("qrc:/sounds/out.wav")));
    out->setAudioOutput(Aout);

    //p_start->setSource((QUrl("qrc:/sounds/voice/C.wav")));
    p_start->setSource((QUrl("qrc:/sounds/start.wav")));
    p_start->setAudioOutput(Sout);


    //voice->setSource((QUrl("qrc:/voice/C.wav")));
    //p_voice->setSource((QUrl("‪qrc:/sounds/voice/C.wav")));
    p_voice->setAudioOutput(voice_OUT);
    voice_OUT->setVolume(0.6);

    p_chord->setAudioOutput(chord_OUT);
    chord_OUT->setVolume(0.6);

    //music->setAudioOutput(Aout);
    a1->setVolume(0.6);
    a2->setVolume(0.6);
    a3->setVolume(0.6);

    a1_1->setVolume(0.6);
    a2_1->setVolume(0.6);
    a3_1->setVolume(0.6);

    a1_2->setVolume(0.6);

    Aout->setVolume(0.6);
    Sout->setVolume(0.6);

    //music->play();
    //////////////////////////////////////////////////////

    ui->sd_miku->setPixmap(sdmiku.scaled(200,200,Qt::KeepAspectRatio));
    ui->label_3->setPixmap(mikulogo.scaled(180,60));
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

    ui->s1_1->setVisible(false);
    ui->s1_2->setVisible(false);
    ui->s1_3->setVisible(false);
    ui->s1_4->setVisible(false);

    ui->s2_1->setVisible(false);
    ui->s2_2->setVisible(false);
    ui->s2_3->setVisible(false);
    ui->s2_4->setVisible(false);

    ui->s3_1->setVisible(false);
    ui->s3_2->setVisible(false);
    ui->s3_3->setVisible(false);
    ui->s3_4->setVisible(false);

    ui->s4_1->setVisible(false);
    ui->s4_2->setVisible(false);
    ui->s4_3->setVisible(false);
    ui->s4_4->setVisible(false);

    ui->s5_1->setVisible(false);
    ui->s5_2->setVisible(false);
    ui->s5_3->setVisible(false);
    ui->s5_4->setVisible(false);

    ui->s6_1->setVisible(false);
    ui->s6_2->setVisible(false);
    ui->s6_3->setVisible(false);
    ui->s6_4->setVisible(false);

    ui->s7_1->setVisible(false);
    ui->s7_2->setVisible(false);
    ui->s7_3->setVisible(false);
    ui->s7_4->setVisible(false);

    ui->s8_1->setVisible(false);
    ui->s8_2->setVisible(false);
    ui->s8_3->setVisible(false);
    ui->s8_4->setVisible(false);
    //
    QString disabledStyle = "QPushButton:disabled { background-color: lightgray; color: darkgray; }";
    ui->pushButton_2->setStyleSheet(disabledStyle);
    ui->pushButton_3->setStyleSheet(disabledStyle);
    ui->voice->setStyleSheet(disabledStyle);
    ui->voice_2->setStyleSheet(disabledStyle);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);

    ui->voice->setEnabled(false);
    ui->voice_2->setEnabled(false);
    p_start->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() // 화음
{
    if(is_chord == false && is_melody == false)
        v1->play();
    else if(is_chord == true && is_melody == false)
        v1_2->play();
    else if(is_chord == true && is_melody == true)
        v1_1->play();
    //[0]->play();
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
        B2_copy();
    if(is_melody)
        B3_copy();
}

void MainWindow::on_pushButton_2_clicked() // 배경 코드
{
    if(is_chord == false ||(is_chord == true && is_melody == false))
        v2->play();
    else if(is_chord == true && is_melody == true)
        v2_1->play();
    is_chord = true;
    ui->pushButton_3->setEnabled(true);
    ui->voice_2->setEnabled(true);

    Code[0] = make_chord(code[0]);
    Code[1] = make_chord(code[1]);
    Code[2] = make_chord(code[2]);
    Code[3] = make_chord(code[3]);
    Code[4] = make_chord(code[4]);
    Code[5] = make_chord(code[5]);
    Code[6] = make_chord(code[6]);
    Code[7] = make_chord(code[7]);
    ui->C0->setText("코드 : "+QString(Code[0]));
    ui->C1->setText("코드 : "+QString(Code[1]));
    ui->C2->setText("코드 : "+QString(Code[2]));
    ui->C3->setText("코드 : "+QString(Code[3]));
    ui->C4->setText("코드 : "+QString(Code[4]));
    ui->C5->setText("코드 : "+QString(Code[5]));
    ui->C6->setText("코드 : "+QString(Code[6]));
    ui->C7->setText("코드 : "+QString(Code[7]));
    if(is_melody)
        B3_copy();
}

void MainWindow::on_pushButton_3_clicked() // 멜로디
{
    if(is_melody == false)
        v3->play();
    else if(is_melody == true)
        v3_1->play();
    is_melody = true;
    ui->voice->setEnabled(true);
    ui->s1_1->setVisible(true);
    ui->s1_2->setVisible(true);
    ui->s1_3->setVisible(true);
    ui->s1_4->setVisible(true);

    ui->s2_1->setVisible(true);
    ui->s2_2->setVisible(true);
    ui->s2_3->setVisible(true);
    ui->s2_4->setVisible(true);

    ui->s3_1->setVisible(true);
    ui->s3_2->setVisible(true);
    ui->s3_3->setVisible(true);
    ui->s3_4->setVisible(true);

    ui->s4_1->setVisible(true);
    ui->s4_2->setVisible(true);
    ui->s4_3->setVisible(true);
    ui->s4_4->setVisible(true);

    ui->s5_1->setVisible(true);
    ui->s5_2->setVisible(true);
    ui->s5_3->setVisible(true);
    ui->s5_4->setVisible(true);

    ui->s6_1->setVisible(true);
    ui->s6_2->setVisible(true);
    ui->s6_3->setVisible(true);
    ui->s6_4->setVisible(true);

    ui->s7_1->setVisible(true);
    ui->s7_2->setVisible(true);
    ui->s7_3->setVisible(true);
    ui->s7_4->setVisible(true);

    ui->s8_1->setVisible(true);
    ui->s8_2->setVisible(true);
    ui->s8_3->setVisible(true);
    ui->s8_4->setVisible(true);

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


void MainWindow::B2_copy(){
    Code[0] = make_chord(code[0]);
    Code[1] = make_chord(code[1]);
    Code[2] = make_chord(code[2]);
    Code[3] = make_chord(code[3]);
    Code[4] = make_chord(code[4]);
    Code[5] = make_chord(code[5]);
    Code[6] = make_chord(code[6]);
    Code[7] = make_chord(code[7]);
    ui->C0->setText("코드 : "+QString(Code[0]));
    ui->C1->setText("코드 : "+QString(Code[1]));
    ui->C2->setText("코드 : "+QString(Code[2]));
    ui->C3->setText("코드 : "+QString(Code[3]));
    ui->C4->setText("코드 : "+QString(Code[4]));
    ui->C5->setText("코드 : "+QString(Code[5]));
    ui->C6->setText("코드 : "+QString(Code[6]));
    ui->C7->setText("코드 : "+QString(Code[7]));
}

void MainWindow::B3_copy(){
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
    ui->C1_3->setText(QString(melody[4]));
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

void MainWindow::on_out_btn_clicked()
{
    out->play();

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        if (out->mediaStatus() == QMediaPlayer::EndOfMedia) {
            QApplication::quit();
        }
    });
    timer->start(100);
}

/*
void MainWindow::on_voice_clicked()
{
    //p_voice->setSource((QUrl("qrc:/sounds/voice/GH.mp3")));
    //p_voice->play();

    for(int i = 0; i < 32 ; i++){
        if(melody[i] == 'C')
            p_voice->setSource((QUrl("qrc:/sounds/voice/C.wav")));
        if(melody[i] == 'D')
            p_voice->setSource((QUrl("qrc:/sounds/voice/D.wav")));
        if(melody[i] == 'E')
            p_voice->setSource((QUrl("qrc:/sounds/voice/E.wav")));
        if(melody[i] == 'F')
            p_voice->setSource((QUrl("qrc:/sounds/voice/F.wav")));
        if(melody[i] == 'G')
            p_voice->setSource((QUrl("qrc:/sounds/voice/G.wav")));
        if(melody[i] == 'A')
            p_voice->setSource((QUrl("qrc:/sounds/voice/A.wav")));
        if(melody[i] == 'B')
            p_voice->setSource((QUrl("qrc:/sounds/voice/B.mp3")));
        if(melody[i] == 'c')
            p_voice->setSource((QUrl("qrc:/sounds/voice/CH.mp3")));
        if(melody[i] == 'd')
            p_voice->setSource((QUrl("qrc:/sounds/voice/DH.mp3")));
        if(melody[i] == 'e')
            p_voice->setSource((QUrl("qrc:/sounds/voice/EH.mp3")));
        if(melody[i] == 'f')
            p_voice->setSource((QUrl("qrc:/sounds/voice/FH.mp3")));
        if(melody[i] == 'g')
            p_voice->setSource((QUrl("qrc:/sounds/voice/GH.mp3")));
        p_voice->play();

        QEventLoop loop;
        connect(p_voice, &QMediaPlayer::mediaStatusChanged, &loop, &QEventLoop::quit);
        loop.exec();

        delete p_voice;
        p_voice = new QMediaPlayer();
        p_voice->setAudioOutput(voice_OUT);
        voice_OUT->setVolume(0.6);
    }

}
*/

void MainWindow::on_voice_clicked()
{
    // 기존 연결을 해제합니다.
    disconnect(p_voice, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::handleMediaStatusChanged);

    // 새로운 연결을 설정합니다.
    connect(p_voice, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::handleMediaStatusChanged);

    // 인덱스를 초기화합니다.
    currentMelodyIndex = 0;

    // 첫 멜로디와 코드를 재생합니다.
    playNextMelody();
    //_playNextMelody();
}

void MainWindow::on_voice_2_clicked()
{

    disconnect(p_chord, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::_handleMediaStatusChanged);
    connect(p_chord, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::_handleMediaStatusChanged);
    chordIndex = 0;
    _playNextMelody();
}


void MainWindow::handleMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia)
    {
        currentMelodyIndex++;
        if (currentMelodyIndex < 32)
        {
            playNextMelody();
            /*
            if(currentMelodyIndex-1 % 4 == 0){
                _playNextMelody();
                qDebug() << "chord index:" << chordIndex;
                chordIndex++;
            }
            qDebug() << "Melody index:" << currentMelodyIndex;
        */
        }
        else
        {
            qDebug() << "Melody playback completed.";
        }
    }
}

void MainWindow::playNextMelody()
{
    if (currentMelodyIndex >= 32) return;

    switch (melody[currentMelodyIndex])
    {
    case 'C':
        p_voice->setSource(QUrl("qrc:/sounds/voice/C.wav"));
        break;
    case 'D':
        p_voice->setSource(QUrl("qrc:/sounds/voice/D.wav"));
        break;
    case 'E':
        p_voice->setSource(QUrl("qrc:/sounds/voice/E.wav"));
        break;
    case 'F':
        p_voice->setSource(QUrl("qrc:/sounds/voice/F.wav"));
        break;
    case 'G':
        p_voice->setSource(QUrl("qrc:/sounds/voice/G.wav"));
        break;
    case 'A':
        p_voice->setSource(QUrl("qrc:/sounds/voice/A.wav"));
        break;
    case 'B':
        p_voice->setSource(QUrl("qrc:/sounds/voice/B.wav"));
        break;
    case 'c':
        p_voice->setSource(QUrl("qrc:/sounds/voice/CH.wav"));
        break;
    case 'd':
        p_voice->setSource(QUrl("qrc:/sounds/voice/DH.wav"));
        break;
    case 'e':
        p_voice->setSource(QUrl("qrc:/sounds/voice/EH.wav"));
        break;
    case 'f':
        p_voice->setSource(QUrl("qrc:/sounds/voice/FH.wav"));
        break;
    case 'g':
        p_voice->setSource(QUrl("qrc:/sounds/voice/GH.wav"));
        break;
    default:
        return;
    }
    p_voice->play();
}

void MainWindow::_handleMediaStatusChanged(QMediaPlayer::MediaStatus stat)
{
    if (stat == QMediaPlayer::EndOfMedia)
    {
        chordIndex++;
        if (chordIndex < 8)
        {
            _playNextMelody();
            qDebug() << "Chord index:" << chordIndex;
        }
        else
        {
            qDebug() << "Chord playback completed.";
        }
    }
}


void MainWindow::_playNextMelody()
{
    if (chordIndex >= 8) return;

    switch (Code[chordIndex])
    {
    case 'C':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_C.wav"));
        break;
    case 'D':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_D.wav"));
        break;
    case 'E':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_E.wav"));
        break;
    case 'F':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_F.wav"));
        break;
    case 'G':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_G.wav"));
        break;
    case 'A':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_A.wav"));
        break;
    case 'B':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_B.wav"));
        break;
    case 'c':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_CH.wav"));
        break;
    case 'd':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_D.wav"));
        break;
    case 'e':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_E.wav"));
        break;
    case 'f':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_F.wav"));
        break;
    case 'g':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_G.wav"));
        break;
    default:
        return;
    }
    p_chord->play();
}


void MainWindow::playNextMelody_ex()
{
    switch (Code[chordIndex])
    {
    case 'C':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_C.wav"));
        break;
    case 'D':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_D.wav"));
        break;
    case 'E':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_E.wav"));
        break;
    case 'F':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_F.wav"));
        break;
    case 'G':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_G.wav"));
        break;
    case 'A':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_A.wav"));
        break;
    case 'B':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_B.wav"));
        break;
    case 'c':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_CH.wav"));
        break;
    case 'd':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_D.wav"));
        break;
    case 'e':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_E.wav"));
        break;
    case 'f':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_F.wav"));
        break;
    case 'g':
        p_chord->setSource(QUrl("qrc:/sounds/chord/C_G.wav"));
        break;
    default:
        return;
    }
    p_chord->play();
}
