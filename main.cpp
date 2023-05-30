#include <QtWidgets>

class MainWindow : public QMainWindow {
	public:
	MainWindow();
	void startButtonClick();
	void stopButtonClick();
	void runClock();
	private:
	QLabel *timerLabel;
	QPushButton *startButton;
	QPushButton *stopButton;
	QTimer *timer;
	int seconds;
};

MainWindow::MainWindow(){
	setFixedSize(900,500);
	QFont buttonFont("Time",16,QFont::Bold);
	setWindowTitle("Anim v0.1");
	timerLabel= new QLabel(this);
	timerLabel->setText("Test QLabel");
	timerLabel->setGeometry(50,100,350,120);
	timerLabel->setFont(buttonFont);
	timer = new QTimer(this);
	timer->setInterval(1000);
	seconds=0;
	
	startButton = new QPushButton("Start",this);
	startButton->setGeometry(50,220,70,30);
	startButton->setFont(buttonFont);
	stopButton = new QPushButton("Stop",this);
	stopButton->setGeometry(150,220,70,30);
	stopButton->setFont(buttonFont);
	

	connect (startButton, &QPushButton::clicked,this, &MainWindow::startButtonClick);
	connect (stopButton, &QPushButton::clicked,this, &MainWindow::stopButtonClick);
	connect (timer, &QTimer::timeout,this,&MainWindow::runClock);}

void MainWindow::startButtonClick(){
	timerLabel->setText("Start");
	timer->start();
}
void MainWindow::stopButtonClick(){
	timerLabel->setText("Stop");
	timer->stop();
}
void MainWindow::runClock(){
	seconds++;
	QString strSeconds =  QString::number(seconds);
	timerLabel -> setText(strSeconds);
}
int main(int argc,char *argv[]){
	QApplication app(argc,argv);
	MainWindow mainWin;
	mainWin.show();
	return app.exec();
}
