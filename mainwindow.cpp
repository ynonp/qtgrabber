#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui/QtGui>
#include <QtWidgets/QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(changeLocation()));
    QObject::connect(ui->lineEdit, SIGNAL(editingFinished()), this, SLOT(changeLocation()));

    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(captureWebsite()));
    QUrl google("http://www.google.com");
    ui->webView->load(google);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeLocation()
{
    QString t_url = ui->lineEdit->text();
    QUrl url(t_url);

    ui->webView->load( url );
}

void MainWindow::captureWebsite()
{
    QString filename =  QFileDialog::getSaveFileName(this, "Save as", "Choose a filename", "PNG(*.png);; TIFF(*.tiff *.tif);; JPEG(*.jpg *.jpeg)");


    // this works for Qt4
/*
    if(!QPixmap::grabWindow(ui->webView->effectiveWinId()).save(filename))
    {
        QMessageBox::warning(this, "File could not be saved", "ok", QMessageBox::Ok);
    }
  */

    // this one for Qt5
    if(!ui->webView->grab().save(filename))
    {
        QMessageBox::warning(this, "File could not be saved", "ok", QMessageBox::Ok);
    }
}
