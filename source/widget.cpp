#include "widget.h"
#include "./ui_widget.h"
#include <bits/stdc++.h>
#include <QMessageBox>
#include <QtCore/QCoreApplication>
#include <QFileDialog>
#include <QDebug>
#include <QMovie>
#include <QDesktopServices>


bool checkif;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Threadb2 = new ThreadBai2(this);
    Threadb5 = new ThreadBai5(this);

    connect(Threadb2, SIGNAL(quitrinhbai2change(std::string)),
            this, SLOT(quitrinhb2change(std::string)));
    connect(Threadb2, SIGNAL(outputbai2(std::string)),
            this, SLOT(outputb2(std::string)));
    connect(Threadb2, SIGNAL(baoloibai2(std::string)),
            this, SLOT(baoloib2(std::string)));
    connect(Threadb2, SIGNAL(chayxongbai2(bool)),
            this, SLOT(chayxongb2(bool)));

    connect(Threadb5, SIGNAL(quitrinhbai5change(std::string)),
            this, SLOT(quitrinhb5change(std::string)));
    connect(Threadb5, SIGNAL(outputbai5(std::string)),
            this, SLOT(outputb5(std::string)));
    connect(Threadb5, SIGNAL(baoloibai5(std::string)),
            this, SLOT(baoloib5(std::string)));
    connect(Threadb5, SIGNAL(chayxongbai5(bool)),
            this, SLOT(chayxongb5(bool)));

    QMovie *showlogo;
    showlogo = new QMovie("img/logo.gif");
    ui->logo->setMovie(showlogo);
    showlogo->start();

    QMovie *showloading;
    showloading = new QMovie("img/loader.gif");
    ui->label_12->setMovie(showloading);
    // showloading->setSpeed(200);
    showloading->start();
    ui->label_12->setVisible(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::quitrinhb2change(std::string s)
{
    QTextCursor curs(ui->quitrinh_bai2->document());
    curs.movePosition(QTextCursor::End);
    curs.insertText(QString::fromUtf8(s.c_str()));
    curs.insertText(QString::fromUtf8("\n"));
}

void Widget::outputb2(std::string s)
{
    QTextCursor curs(ui->output_bai2->document());
    curs.movePosition(QTextCursor::End);
    curs.insertText(QString::fromUtf8(s.c_str()));
    curs.insertText(QString::fromUtf8("\n"));
}

void Widget::baoloib2(std::string s)
{
    QMessageBox::warning(this, "Thông báo!", QString::fromUtf8(s.c_str()));
}

void Widget::chayxongb2(bool a)
{
    if(a)
    {
        ui->batdautinh_bai2->setEnabled(true);
        ui->chuyenchedo_bai2->setEnabled(true);
        ui->chuyenchedo_bai2_2->setEnabled(true);
        ui->label_12->setVisible(false);
        ui->main->setTabEnabled(0, true);
        ui->main->setTabEnabled(2, true);
        ui->main->setTabEnabled(3, true);
        ui->main->setTabEnabled(4, true);
    }
}


void Widget::quitrinhb5change(std::string s)
{
    QTextCursor curs(ui->quitrinh_bai5->document());
    curs.movePosition(QTextCursor::End);
    curs.insertText(QString::fromUtf8(s.c_str()));
    curs.insertText(QString::fromUtf8("\n"));
}

void Widget::outputb5(std::string s)
{
    QTextCursor curs(ui->output_bai5->document());
    curs.movePosition(QTextCursor::End);
    curs.insertText(QString::fromUtf8(s.c_str()));
    curs.insertText(QString::fromUtf8("\n"));
}

void Widget::baoloib5(std::string s)
{
    QMessageBox::warning(this, "Thông báo!", QString::fromUtf8(s.c_str()));
}

void Widget::chayxongb5(bool a)
{
    if(a)
    {
        ui->batdautinh_bai5->setEnabled(true);
        ui->batdautinh_bai5_2->setEnabled(true);
        ui->chuyenchedo_bai5->setEnabled(true);
        ui->chuyenchedo_bai2_4->setEnabled(true);
        ui->label_12->setVisible(false);
        ui->main->setTabEnabled(0, true);
        ui->main->setTabEnabled(1, true);
        ui->main->setTabEnabled(2, true);
        ui->main->setTabEnabled(3, true);
    }
}

void Widget::on_selectmode_bai1_1_clicked()
{
    ui->stacked_bai1->setCurrentIndex(0);
}

void Widget::on_selectmode_bai1_2_clicked()
{
    ui->stacked_bai1->setCurrentIndex(1);
}

void Widget::on_selectmode_bai1_3_clicked()
{
    ui->stacked_bai1->setCurrentIndex(2);
}

void Widget::on_selectmode_bai1_4_clicked()
{
    ui->stacked_bai1->setCurrentIndex(3);
}

void Widget::on_selectmode_bai1_5_clicked()
{
    ui->stacked_bai1->setCurrentIndex(4);
}

void Widget::on_selectmode_bai1_6_clicked()
{
    ui->stacked_bai1->setCurrentIndex(5);
}

void Widget::on_selectmode_bai1_7_clicked()
{
    ui->stacked_bai1->setCurrentIndex(6);
}

void Widget::on_selectmode_bai1_8_clicked()
{
    ui->stacked_bai1->setCurrentIndex(7);
}

void Widget::on_buttonbai2_1_clicked()
{
    ui->stacked_bai2->setCurrentIndex(1);
    ui->stackedbai22->setCurrentIndex(1);
    checkif = true;
}

void Widget::on_buttonbai2_2_clicked()
{
    ui->stacked_bai2->setCurrentIndex(1);
    ui->stackedbai22->setCurrentIndex(0);
    checkif = false;
}

void Widget::on_chuyenchedo_bai2_clicked()
{
    ui->stackedbai22->setCurrentIndex(0);
    checkif = false;
    ui->quitrinh_bai2->setText("");
    ui->output_bai2->setText("");
}

void Widget::on_chuyenchedo_bai2_2_clicked()
{
    ui->stackedbai22->setCurrentIndex(1);
    checkif = true;
    ui->quitrinh_bai2->setText("");
    ui->output_bai2->setText("");
}

void Widget::on_tieptucchuyenvi_clicked()
{
    /*
    QString getdata = ui->inputchuyenvi->toPlainText(); // Lấy giá trị từ input Qtext

    std::string s = getdata.toUtf8().constData(); // Chuyển từ dạng Qstring sang dạng string

    std::string delimiter = " ";

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        std::cout << ::atof(token.c_str()) << " ";
        s.erase(0, pos + delimiter.length());
    }
    std::cout << s << std::endl;

    QString str = QString::fromUtf8(s.c_str()); // Chuyển từ dạng string sang dạng Qstring

    ui->label_7->setText(str); // Hiển thị kết quả

    int n = 2 , m = 3;

    std::ostringstream output_bai1_chuyenvi;

    MAXTRIC M{n, m};

    typedef float** point2;
    point2 p;
    p = new float*[10];
    for(int i = 0; i < n; i++){
        p[i] = new float[10];
    }

    p = M.chuyen_vi();

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            output_bai1_chuyenvi << p[i][j] << "\t";
        }
        output_bai1_chuyenvi << "\n";
    }

    std::string outout(output_bai1_chuyenvi.str());

    M.delpoint();

    delete p;
    p = NULL;
    */
}

void Widget::on_batdautinh_bai2_clicked()
{
    ui->batdautinh_bai2->setEnabled(false);
    ui->chuyenchedo_bai2->setEnabled(false);
    ui->chuyenchedo_bai2_2->setEnabled(false);
    ui->main->setTabEnabled(0, false);
    ui->main->setTabEnabled(2, false);
    ui->main->setTabEnabled(3, false);
    ui->main->setTabEnabled(4, false);

    QString getdata = ui->input_bai2->toPlainText();

    std::string s = getdata.toUtf8().constData();

    ui->quitrinh_bai2->setText("");
    ui->output_bai2->setText("");

    int t = ui->spinBox_bai2->value();
    int w = ui->spinBox_bai2_2->value();

    Threadb2->truyeninput = s;
    Threadb2->truyendauphay = t;
    Threadb2->truyentime = w;
    Threadb2->checkif = checkif;

    Threadb2->start();
    ui->label_12->setVisible(true);
}

void Widget::on_buttonbai2_5_clicked()
{
    QString linkfile = QFileDialog::getOpenFileName(this);
    ui->textBrowser_24->setText(linkfile);
    Threadb2->fileinput = linkfile.toUtf8().constData();
}

void Widget::on_buttonbai2_6_clicked()
{
    QString linkfile = QFileDialog::getExistingDirectory(this);
    ui->textBrowser_5->setText(linkfile);
    Threadb2->folderoutput = linkfile.toUtf8().constData();
}

void Widget::on_buttonbai5_3_clicked()
{
    ui->stacked_bai5->setCurrentIndex(1);
    ui->stackedbai22_2->setCurrentIndex(1);
    checkif = true;
}

void Widget::on_buttonbai5_4_clicked()
{
    ui->stacked_bai5->setCurrentIndex(1);
    ui->stackedbai22_2->setCurrentIndex(0);
    checkif = false;
}

void Widget::on_chuyenchedo_bai2_4_clicked()
{
    ui->stackedbai22_2->setCurrentIndex(0);
    checkif = false;
    ui->quitrinh_bai5->setText("");
    ui->output_bai5->setText("");
}

void Widget::thucthib5(){
    ui->batdautinh_bai5->setEnabled(false);
    ui->chuyenchedo_bai5->setEnabled(false);
    ui->chuyenchedo_bai2_4->setEnabled(false);
    ui->batdautinh_bai5_2->setEnabled(false);

    QString getdata = ui->input_bai5->toPlainText();

    std::string s = getdata.toUtf8().constData();

    ui->quitrinh_bai5->setText("");
    ui->output_bai5->setText("");

    int w = ui->spinBox_bai5_2->value();

    Threadb5->truyeninput = s;
    Threadb5->truyentime = w;
    Threadb5->checkif = checkif;

    Threadb5->start();
    ui->label_12->setVisible(true);
    ui->main->setTabEnabled(0, false);
    ui->main->setTabEnabled(1, false);
    ui->main->setTabEnabled(2, false);
    ui->main->setTabEnabled(3, false);
}

void Widget::on_batdautinh_bai5_clicked()
{
    Threadb5->truyenmode = true;
    Widget::thucthib5();
}

void Widget::on_batdautinh_bai5_2_clicked()
{
    Threadb5->truyenmode = false;
    Widget::thucthib5();
}

void Widget::on_chuyenchedo_bai5_clicked()
{
    ui->stackedbai22_2->setCurrentIndex(1);
    checkif = true;
    ui->quitrinh_bai5->setText("");
    ui->output_bai5->setText("");
}

void Widget::on_buttonbai5_clicked()
{
    QString linkfile = QFileDialog::getOpenFileName(this);
    ui->textBrowser_25->setText(linkfile);
    Threadb5->fileinput = linkfile.toUtf8().constData();
}

void Widget::on_buttonbai5_2_clicked()
{
    QString linkfile = QFileDialog::getExistingDirectory(this);
    ui->textBrowser_6->setText(linkfile);
    Threadb5->folderoutput = linkfile.toUtf8().constData();
}

void Widget::on_source_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/phanminhtai/Bai-tap-lon-cpp"));
}

void Widget::on_source_4_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/phanminhtai"));
}

void Widget::on_source_5_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.facebook.com/GrouSrlpPrsc"));
}

void Widget::on_source_2_clicked()
{
    QDesktopServices::openUrl(QUrl("https://sharescript.net"));
}

void Widget::on_source_3_clicked()
{
    QDesktopServices::openUrl(QUrl("https://taipm.net"));
}
