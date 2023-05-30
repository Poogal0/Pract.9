#include "mainwindow.h"
<<<<<<< Updated upstream
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
=======

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), m_label(new QLabel(this)), m_timer(new QTimer(this)),
      m_x(0), m_y(0), m_directionX(1), m_directionY(1)
{
    
    m_label->setText("Move me!");
    m_label->move(0, 0);

    
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(new QVBoxLayout);
    centralWidget->layout()->addWidget(m_label);

 
    connect(m_timer, &QTimer::timeout, this, &MainWindow::moveHorizontally);

   QPushButton *horizButton = new QPushButton("Horiz", centralWidget);
    connect(horizButton, &QPushButton::clicked, m_timer, [this]() {
        m_timer->start(10);
        m_directionX = 1;
    });

    QPushButton *vertButton = new QPushButton("Vert", centralWidget);
    connect(vertButton, &QPushButton::clicked, this, &MainWindow::moveVertically);

    centralWidget->layout()->addWidget(horizButton);
    centralWidget->layout()->addWidget(vertButton);

    resize(400, 300);
>>>>>>> Stashed changes
}

MainWindow::~MainWindow()
{
<<<<<<< Updated upstream
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
=======
}

void MainWindow::moveHorizontally()
{
    m_x += m_directionX;

  if (m_x > centralWidget()->width() - m_label->width() || m_x < 0) {
        m_directionX = -m_directionX;
    }

    m_label->move(m_x, m_y);
}

void MainWindow::moveVertically()
{
    m_y += m_directionY;

if (m_y > centralWidget()->height() - m_label->height() || m_y < 0) {
        m_directionY = -m_directionY;
    }

    m_label->move(m_x, m_y);
>>>>>>> Stashed changes
}
