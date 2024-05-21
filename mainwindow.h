#ifndef MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QPixmap>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
namespace Ui { class MainWindow; }
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void B2_copy();

    void B3_copy();

    void on_out_btn_clicked();

    void on_voice_clicked();

    void handleMediaStatusChanged(QMediaPlayer::MediaStatus status);

    void playNextMelody();

    void _handleMediaStatusChanged(QMediaPlayer::MediaStatus status);

    void _playNextMelody();

    void playNextMelody_ex();


    void on_voice_2_clicked();

private:
    Ui::MainWindow *ui;
    //QMediaPlayer *p_voice;
    //int currentMelodyIndex;
    //const char* _melody;
};
#endif // MAINWINDOW_H
