#ifndef THREADBAI2_H
#define THREADBAI2_H
#include <QThread>

class ThreadBai2 : public QThread
{
    Q_OBJECT
public:
    explicit ThreadBai2(QObject *parent = 0, std::string a = "", int b = 0, int c = 0, bool d = true, std::string e = "", std::string f = "");
    void run();
    void truyenslot();
    void xuly();
    std::string truyeninput;
    int truyendauphay;
    int truyentime;
    bool checkif;
    std::string fileinput;
    std::string folderoutput;

signals:
    void quitrinhbai2change(std::string);
    void outputbai2(std::string);
    void baoloibai2(std::string);
    bool chayxongbai2(bool);

public slots:

};

#endif
