#include <QtWidgets>

class MainWindow : public QMainWindow {
	public:
	MainWindow();
	private:
	QLabel *timerLabel;
};

MainWindow::MainWindow(){
	setFixedSize(900,500);
	QFont buttonFont("Courier",16,QFont::Bold);
	setWindowTitle("Anim v0.1");
	timerLabel= new QLabel(this);
	timerLabel->setText("Test QLabel");
	timerLabel->setGeometry(50,100,350,120);
	timerLabel->setFont(buttonFont);
}

int main(int argc,char *argv[]){
	QApplication app(argc,argv);
	MainWindow mainWin;
	mainWin.show();
	return app.exec();
}
