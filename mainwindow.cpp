#include "Mainwindow.h"
#include <QtCore/QVariant> 
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QMainWindow>
#include <QDesktopWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QPushButton>
#include <iostream>
#include <cstdlib> 
#include <cstring>
#include <memory>
#include <stdexcept>
#include <array>
#include <QMessageBox>
#define WINDOW_WIDTH 270
#define WINDOW_HEIGHT 100
using namespace std;
MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  
	
	if (this->objectName().isEmpty())
            this->setObjectName(QString::fromUtf8("Form"));
        //this->resize(286, 103);
		//this->resize(50, 50);
		//this->resize(QDesktopWidget().availableGeometry(this).size() * 0.3);
		this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
		this->setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);
        label = new QLabel(this);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 81, 16));
        label_2 = new QLabel(this);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 131, 16));
        lineEdit = new QLineEdit(this);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 10, 113, 24));
        lineEdit_2 = new QLineEdit(this);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 40, 113, 24));
		get = new QPushButton(this);
        get->setObjectName(QString::fromUtf8("get"));
        get->setGeometry(QRect(190, 70, 81, 24));
        progressBar = new QProgressBar(this);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 70, 118, 23));
        progressBar->setValue(0);
		//name
		this->setWindowTitle(QCoreApplication::translate("Form", "Wget GUI 1.0", nullptr));
        label->setText(QCoreApplication::translate("Form", "Web Source:", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "Download Location:", nullptr));
        get->setText(QCoreApplication::translate("Form", "Get", nullptr));

        QMetaObject::connectSlotsByName(this);
 
  // Connect button signal to appropriate slot
  connect(get, &QPushButton::released, this, &MainWindow::handleButton);
}
string GetStdoutFromCommand(string cmd) {

  std::string data;
  FILE * stream;
  const int max_buffer = 256;
  char buffer[max_buffer];
  cmd.append(" 2>&1");

  stream = popen(cmd.c_str(), "r");

  if (stream) {
    while (!feof(stream))
      if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
    pclose(stream);
  }
  return data;
}

void MainWindow::handleButton()
{
	get->setText(QCoreApplication::translate("Form", "Please wait..", nullptr));
	progressBar->setValue(0);
	std::string wget = "wget ";
	std::string cd = "cd ";
	std::string end = " ;";
	std::string source = lineEdit->text().toStdString();
	std::string output = lineEdit_2->text().toStdString();
	cd = cd+output+end;
	wget = cd+wget+source;
	char *cwget = new char[wget.length()+1];
	strcpy(cwget, wget.c_str());
	//std::system(cwget);
	std::string system = GetStdoutFromCommand(cwget);
	QMessageBox msgBox;
	char *systemchar = new char[system.length()+1];
	strcpy(systemchar, system.c_str());
	msgBox.setText(systemchar);
	msgBox.exec();
	//ill make this actully show the pace of the download
	 progressBar->setValue(100);
	get->setText(QCoreApplication::translate("Form", "Get", nullptr));

}
