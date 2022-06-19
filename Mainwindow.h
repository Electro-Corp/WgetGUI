#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCore/QVariant> 
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QPushButton>


namespace Ui {
  class MainWindow;
}
 
class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *get;
    QProgressBar *progressBar;
private slots:
  void handleButton();
private:
  QPushButton *m_button;
};
#endif // MAINWINDOW_H
