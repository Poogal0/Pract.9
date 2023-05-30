#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class QTimer;

class MainWindow : public QMainWindow {
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLabel *m_timeLabel;
    int m_seconds;
    QTimer *m_timer;

    void startTimer();
    void stopTimer();
    void updateTimer();
};

#endif // MAINWINDOW_H
