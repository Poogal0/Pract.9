#ifndef MAINWINDOW_H
#define MAINWINDOW_H
<<<<<<< Updated upstream

#include <QMainWindow>

class QLabel;
class QTimer;

class MainWindow : public QMainWindow {
=======
#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

>>>>>>> Stashed changes
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
<<<<<<< Updated upstream
    QLabel *m_timeLabel;
    int m_seconds;
    QTimer *m_timer;

    void startTimer();
    void stopTimer();
    void updateTimer();
=======
    QLabel *m_label;
    QTimer *m_timer;
    int m_x;
    int m_y;
    int m_directionX;
    int m_directionY;

private slots:
    void moveHorizontally();
    void moveVertically();
>>>>>>> Stashed changes
};

#endif // MAINWINDOW_H
