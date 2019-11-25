#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QDialog>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QErrorMessage>
#include <QWizard>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    errorDialog = new QErrorMessage(this);
//    QDialog *myDialog = new QDialog(this);  //由于建立的Dialog继承自父窗口，可以不同delete来显式释放该对象！！！
//    myDialog->setModal(true);             //可以将show显式的对话框设置为模态的
//    myDialog->show();                       //创建了窗口但不阻塞父窗口
//    myDialog->exec();         //阻塞住父窗口，直到该Dialog退出

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mytempslotfuntion()
{
    qDebug(__FUNCTION__);
}


void MainWindow::on_pushButtonCreateDialog_clicked()
{
    QDialog *myDialog = new QDialog(this);
    myDialog->show();
}

void MainWindow::on_pushButtoncolordialog_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red,this,tr("color dialog"),QColorDialog::ShowAlphaChannel);
    qDebug()<<"color : "<<color;
}

void MainWindow::on_pushButtonfiledialog_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"get file name","..","*.txt;;*.jpg,*.bmp,*.png");
    qDebug()<<"file name : "<<filename;

//    QString directoryname = QFileDialog::getExistingDirectory(this,"get directory name","D:");
//        qDebug()<<"directory name : "<<directoryname;
}



void MainWindow::on_pushButtonFontDialog_clicked()
{
    bool okFlag = false;
    QFont userFont = QFontDialog::getFont(&okFlag,this);
    if(okFlag == true) ui->pushButtonFontDialog->setFont(userFont);
    else qDebug()<<"no config font";
}

void MainWindow::on_pushButtoninputdialog_clicked()
{
    //输入部分大都有默认值选项，如果用户输入值和默认值相同，就要铜鼓okFlag来判断是不是用户输入的值。
    bool okFlag = false;
    QString userInput = QInputDialog::getText(this,"plz input something","the label",QLineEdit::Normal,"default string",&okFlag);
    qDebug()<<"get user Text input :"<<userInput;

    int userInt = QInputDialog::getInt(this,"this is title","this is label",100,-1000,1000,10,&okFlag);
    //默认值设了100，如果用户输入值也是100，就要通过okFlag来判断是否是用户输入的100
    qDebug()<<"get user Int input :"<<userInt;

    QStringList listitems;
    listitems.append("listitem1");
    listitems.append("listitem2");
    QString userItem = QInputDialog::getItem(this,"it is title","it is label",listitems,1,true,&okFlag);
    qDebug()<<"get user Item input :"<<userItem;
}



void MainWindow::on_pushButtonmessagebox_clicked()
{
    int ret1 = QMessageBox::question(this,"this is title","this is prompt text",QMessageBox::Cancel,QMessageBox::Ok);
    int ret2 = QMessageBox::warning(this,"title","prompt",QMessageBox::Ok,QMessageBox::Cancel);
    qDebug()<<"ret1 is "<<ret1<<endl<<"ret2 is "<<ret2;
    //QMessageBox::information()
    //QMessageBox::about()
}



void MainWindow::on_pushButtonprocessdialog_clicked()
{
    QProgressDialog userProcess("File Copy Process","Cancel",0,50000,this);
    userProcess.setWindowTitle("this is window title");
    userProcess.setWindowModality(Qt::WindowModal);         //设置了模态，非模态需要定时器等帮助
    userProcess.show();
//    userProcess.exec();                //除非进度条的进度值是异步的，否则会卡死。可能异步IO设备会使用
    for (int i = 0; i < 50000; ++i) {
        userProcess.setValue(i);
        QCoreApplication::processEvents();      //每次刷新，否则一闪而过，进度条得不到刷新
        if(userProcess.wasCanceled())           //途中取消，立即结束
            break;
    }
    userProcess.setValue(50000);
    qDebug()<<"process end";
}

void MainWindow::on_pushButtonerrormessage_clicked()
{
    errorDialog->setWindowTitle("this is error message dialog");
    errorDialog->showMessage("Error Message");
}


QWizardPage *MainWindow::createPage1()
{
    QWizardPage *page = new QWizardPage();
    page->setTitle("intraduction page");
    return page;
}

QWizardPage *MainWindow::createPage2()
{
    QWizardPage *page = new QWizardPage();
    page->setTitle("choose message page");
    return page;
}

QWizardPage *MainWindow::createPage3()
{
    QWizardPage *page = new QWizardPage();
    page->setTitle("end page");
    return page;
}

void MainWindow::on_pushButtonwizardpage_clicked()
{
    QWizard wizard(this);    //注意此处为QWizard，不是QWizardPage
    wizard.setWindowTitle("this is titlle");
    wizard.addPage(createPage1());  //加入三个页面
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.exec();          //进入wizard流程,必须使用exec
}
