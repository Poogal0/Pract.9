#include <QtWidgets>

class MainWindow : public QMainWindow {
	public:
	MainWindow();
	void startButtonClick();
	void stopButtonClick();
	void runClock();
	private:
	QLabel *timerLabelSeconds;
	QLabel *timerLabelMinutes;
	QPushButton *startButton;
	QPushButton *stopButton;
	QTimer *timer;
	int seconds,minutes;
};

MainWindow::MainWindow(){
	setFixedSize(900,500);
	QFont buttonFont("Time",16,QFont::Bold);
	setWindowTitle("Anim v0.1");
	timerLabelSeconds= new QLabel(this);
	timerLabelSeconds->setText("Test QLabel");
	timerLabelSeconds->setGeometry(100,100,350,120);
	timerLabelSeconds->setFont(buttonFont);
	
	timerLabelMinutes= new QLabel(this);
	timerLabelMinutes->setText("00");
	timerLabelMinutes->setGeometry(70,100,350,120);
	timerLabelMinutes->setFont(buttonFont);
	
	timer = new QTimer(this);
	timer->setInterval(100);
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
	timer->start();
}
void MainWindow::stopButtonClick(){
	timer->stop();
}
void MainWindow::runClock(){
	seconds++;
	if (seconds<10){
	QString strSeconds = "0"+ QString::number(seconds);
	timerLabelSeconds -> setText(strSeconds);}
	else{
    QString strSeconds = QString::number(seconds);
	timerLabelSeconds -> setText(strSeconds);}
	if (seconds==60){
		minutes++;
		seconds=0;
		QString strMinutes = QString::number(minutes);
		timerLabelMinutes -> setText(strMinutes);}
	
}

int main(int argc,char *argv[]){
	QApplication app(argc,argv);
	MainWindow mainWin;
	mainWin.show();
	return app.exec();
}
