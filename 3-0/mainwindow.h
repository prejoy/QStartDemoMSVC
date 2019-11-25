#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWizardPage>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QErrorMessage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButtonCreateDialog_clicked();

    void on_pushButtoncolordialog_clicked();

    void on_pushButtonfiledialog_clicked();

    void on_pushButtonFontDialog_clicked();

    void on_pushButtoninputdialog_clicked();

    void on_pushButtonmessagebox_clicked();

    void on_pushButtonprocessdialog_clicked();

    void on_pushButtonerrormessage_clicked();

    void on_pushButtonwizardpage_clicked();

public slots:
    void mytempslotfuntion();
private:
    Ui::MainWindow *ui;
    QErrorMessage *errorDialog;
    QWizardPage *createPage1();     //new add
    QWizardPage *createPage2();     //指针函数,返回指针
    QWizardPage *createPage3();     //返回 QWizardPage类对象
};
#endif // MAINWINDOW_H
