#include "mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), m_seconds(0)
{
    setWindowTitle("Timer Example");

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QLabel *label = new QLabel("Elapsed Time:", centralWidget);
    layout->addWidget(label);

    m_timeLabel = new QLabel("0", centralWidget);
    m_timeLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    layout->addWidget(m_timeLabel);

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &MainWindow::updateTimer);
    m_timer->start(1000); // 1 second interval
}

MainWindow::~MainWindow()
{
    delete m_timer;
}

void MainWindow::startTimer() {
    m_timer->start(1000);
}

void MainWindow::stopTimer() {
    m_timer->stop();
}

void MainWindow::updateTimer() {
    m_seconds++;
    m_timeLabel->setText(QString::number(m_seconds));
}
