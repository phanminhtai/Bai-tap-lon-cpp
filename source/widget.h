#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "threadbai2.h"
#include "threadbai5.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    ThreadBai2 *Threadb2;
    ThreadBai5 *Threadb5;

public slots:
    void quitrinhb2change(std::string);
    void outputb2(std::string);
    void baoloib2(std::string);
    void chayxongb2(bool);

    void quitrinhb5change(std::string);
    void outputb5(std::string);
    void baoloib5(std::string);
    void chayxongb5(bool);

private slots:

    void on_selectmode_bai1_1_clicked();

    void on_selectmode_bai1_2_clicked();

    void on_selectmode_bai1_3_clicked();

    void on_selectmode_bai1_4_clicked();

    void on_selectmode_bai1_5_clicked();

    void on_selectmode_bai1_6_clicked();

    void on_selectmode_bai1_7_clicked();

    void on_selectmode_bai1_8_clicked();

    void on_buttonbai2_1_clicked();

    void on_buttonbai2_2_clicked();

    void on_tieptucchuyenvi_clicked();

    void on_batdautinh_bai2_clicked();

    void on_chuyenchedo_bai2_clicked();

    void on_chuyenchedo_bai2_2_clicked();

    void on_buttonbai2_5_clicked();

    void on_buttonbai2_6_clicked();

    void on_buttonbai5_3_clicked();

    void on_buttonbai5_4_clicked();

    void on_chuyenchedo_bai2_4_clicked();

    void on_batdautinh_bai5_clicked();

    void on_chuyenchedo_bai5_clicked();

    void on_buttonbai5_clicked();

    void on_buttonbai5_2_clicked();

    void on_batdautinh_bai5_2_clicked();

    void thucthib5();

    void on_source_clicked();

    void on_source_4_clicked();

    void on_source_5_clicked();

    void on_source_2_clicked();

    void on_source_3_clicked();

private:
    Ui::Widget *ui;
};
#endif
