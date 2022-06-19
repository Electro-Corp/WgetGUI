#include <QtWidgets/QApplication>

//#include "ui_installernew.h"
#include "Mainwindow.h"

/*int main(int argc, char *argv[]){
	QApplication app(argc, argv);
    QDialog widget;
    Ui::Form ui;
    ui.setupUi(&widget);
    widget.show();
    return app.exec();
}
*/
//#include "mainwindow.h"

 
 
int main(int argc, char *argv[]) 
{
  QApplication app(argc, argv);
  MainWindow mainWindow;
  mainWindow.showMaximized();
  return app.exec();
}