#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Choosepic_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.png *.jpg *.jpeg *.bmp)"));

    if (QString::compare(filename,QString()) != 0)
    {
        QImage image;
        bool valid = image.load(filename);

        if(valid)
        {
           ui->LabSetpicture->setPixmap(QPixmap::fromImage(image));
        }else{
            //Error loading
        }
    }

}
