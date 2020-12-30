#ifndef THREADBAI5_H
#define THREADBAI5_H
#include <QThread>

class ThreadBai5 : public QThread
{
    Q_OBJECT
public:
    explicit ThreadBai5(QObject *parent = 0, std::string a = "", int c = 0, bool d = true, std::string e = "", std::string f = "", bool mode = true);
    void run();
    void outout(std::string);
    void xuly(std::string);
    bool validate(std::string, int);
    std::string truyeninput;
    int truyentime;
    bool checkif;
    bool truyenmode;
    std::string fileinput;
    std::string folderoutput;

signals:
    void quitrinhbai5change(std::string);
    void outputbai5(std::string);
    void baoloibai5(std::string);
    bool chayxongbai5(bool);

public slots:

};

#endif
