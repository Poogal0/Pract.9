#include <QtWidgets>
class MainWindow : public QMainWindow {
    public:
    MainWindow();
    void startButtonClick();
   
    private:
    QLabel *timerLabel;
    QPushButton *startButton;
    QPushButton *stopButton;
};
MainWindow::MainWindow(){
    setFixedSize(900,500);
    QFont buttonFont("Time",16,QFont::Bold);
    setWindowTitle("Anim v0.1");
    timerLabel= new QLabel(this);
    timerLabel->setText("Test QLabel");
    timerLabel->setGeometry(50,100,350,120);
    timerLabel->setFont(buttonFont);
    startButton = new QPushButton("Start",this);
    startButton->setGeometry(50,220,70,30);
    startButton->setFont(buttonFont);
   
   
    connect (startButton, &QPushButton::clicked,this, &MainWindow::startButtonClick);
    }
void MainWindow::startButtonClick(){
    timerLabel->setText("Start");
}

   
int main(int argc,char *argv[]){
    QApplication app(argc,argv);
    MainWindow mainWin;
    mainWin.show();
    return app.exec();}
