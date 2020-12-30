#include "threadbai5.h"
#include <QDebug>
#include <bits/stdc++.h>
#include <string>

Q_DECLARE_METATYPE(std::string)

ThreadBai5::ThreadBai5(QObject *parent, std::string a, int c, bool d, std::string e, std::string f, bool mode) :
    QThread(parent), truyeninput(a), truyentime(c), checkif(d), truyenmode(mode), fileinput(e), folderoutput(f)
{
}

bool checkbreakb5 = false;
std::string allkqb5;

std::string encode(char x) {
    if(x == 'a'|| x == 'A')
        return ".-";
    if(x == 'b'|| x == 'B')
        return "-...";
    if(x == 'c'|| x == 'C')
        return "-.-.";
    if(x == 'd'|| x == 'D')
        return "-..";
    if(x == 'e'|| x == 'E')
        return ".";
    if(x == 'f'|| x == 'F')
        return "..-.";
    if(x == 'g'|| x == 'G')
        return "--.";
    if(x == 'h'|| x == 'H')
        return "....";
    if(x == 'i'|| x == 'I')
        return "..";
    if(x == 'j'|| x == 'J')
        return ".---";
    if(x == 'k'|| x == 'K')
        return "-.-";
    if(x == 'l'|| x == 'L')
        return ".-..";
    if(x == 'm'|| x == 'M')
        return "--";
    if(x == 'n'|| x == 'N')
        return "-.";
    if(x == 'o'|| x == 'O')
        return "---";
    if(x == 'p'|| x == 'P')
        return ".--.";
    if(x == 'q'|| x == 'Q')
        return "--.-";
    if(x == 'r'|| x == 'R')
        return ".-.";
    if(x == 's'|| x == 'S')
        return "...";
    if(x == 't'|| x == 'T')
        return "-";
    if(x == 'u'|| x == 'U')
        return "..-";
    if(x == 'v'|| x == 'V')
        return "...-";
    if(x == 'w'|| x == 'W')
        return ".--";
    if(x == 'x'|| x == 'X')
        return "-..-";
    if(x == 'y'|| x == 'Y')
        return "-.--";
    if(x == 'z'|| x == 'Z')
        return "--..";
    if(x == '0')
        return "-----";
    if(x == '1')
        return ".----";
    if(x == '2')
        return "..---";
    if(x == '3')
        return "...--";
    if(x == '4')
        return "....-";
    if(x == '5')
        return ".....";
    if(x == '6')
        return "-....";
    if(x == '7')
        return "--...";
    if(x == '8')
        return "---..";
    if(x == '9')
        return "----.";
    if(x == '\'')
        return "--..--";
    if(x == '.')
        return ".-.-.-";
    if(x == '?')
        return "..--..";
    if(x == ';')
        return "-.-.-";
    if(x == ')')
        return "---...";
    if(x == '/')
        return "-..-.";
    if(x == '+')
        return ".-.-.";
    if(x == '-')
        return "-....-";
    if(x == '=')
        return "-...-";
    if(x == '(')
        return "-.--.";
    if(x == ')')
        return "-.--.-";
    if(x == '"')
        return ".-..-.";
    if(x == ' ')
        return "/";
    return "#";
}

char decode(std::string x) {
    if(x == ".-")
        return 'a';
    if(x == "-...")
        return 'b';
    if(x == "-.-.")
        return 'c';
    if(x == "-..")
        return 'd';
    if(x == ".")
        return 'e';
    if(x == "..-.")
        return 'f';
    if(x == "--.")
        return 'g';
    if(x == "....")
        return 'h';
    if(x == "..")
        return 'i';
    if(x == ".---")
        return 'j';
    if(x == "-.-")
        return 'k';
    if(x == ".-..")
        return 'l';
    if(x == "--")
        return 'm';
    if(x == "-.")
        return 'n';
    if(x == "---")
        return 'o';
    if(x == ".--.")
        return 'p';
    if(x == "--.-")
        return 'q';
    if(x == ".-.")
        return 'r';
    if(x == "...")
        return 's';
    if(x == "-")
        return 't';
    if(x == "..-")
        return 'u';
    if(x == "...-")
        return 'v';
    if(x == ".--")
        return 'w';
    if(x == "-..-")
        return 'x';
    if(x == "-.--")
        return 'y';
    if(x == "--..")
        return 'z';
    if(x == "-----")
        return '0';
    if(x == ".----")
        return '1';
    if(x == "..---")
        return '2';
    if(x == "...--")
        return '3';
    if(x == "....-")
        return '4';
    if(x == ".....")
        return '5';
    if(x == "-....")
        return '6';
    if(x == "--...")
        return '7';
    if(x == "---..")
        return '8';
    if(x == "----.")
        return '9';
    if(x == "--..--")
        return '\'';
    if(x == ".-.-.-")
        return '.';
    if(x == "..--..")
        return '?';
    if(x == "-.-.-")
        return ';';
    if(x == "---...")
        return ')';
    if(x == "-..-.")
        return '/';
    if(x == ".-.-.")
        return '+';
    if(x == "-....-")
        return '-';
    if(x == "-...-")
        return '=';
    if(x == "-.--.")
        return '(';
    if(x == "-.--.-")
        return ')';
    if(x == ".-..-.")
        return '"';
    if(x == "/")
        return ' ';
    return '#';
}

void ThreadBai5::outout(std::string quitrinhb5){
    emit quitrinhbai5change(quitrinhb5);
    this->msleep(this->truyentime*100);
}

void ThreadBai5::xuly(std::string s){
  std::string tg, kq = "", quitrinhb5;
  std::stringstream ss;
  int n = s.length();

  if(this->truyenmode)
  {
      for (int i = 0; s[i]; i++){
          if(encode(s[i]) == "#"){
              emit baoloibai5("Bạn đã nhập ký tự sai hoặc không được hỗ trợ, vui lòng xem lại!");
              checkbreakb5 = true;
              break;
          }
          kq += encode(s[i]) + " ";
          std::string s1(1, s[i]);
          quitrinhb5 = "Chuyển '" + s1 + "' thành " + encode(s[i]);
          ThreadBai5::outout(quitrinhb5);
      }
  }
  else{
    int boqua = n - 1, luu = 0;
    while (s[boqua] == ' ') {
        boqua --;
        luu ++;
    }
    for (int i = 0; i <= n - luu; i++)
    {
        if(s[i] == ' ' || i == n){
            ss >> tg;
            if(decode(tg) == '#'){
                emit baoloibai5("Bạn đã nhập mã morse sai hoặc không được hỗ trợ, vui lòng xem lại!");
                checkbreakb5 = true;
                break;
            }
            kq += decode(tg);
            ss.str("");
            ss.clear();
            std::string s2(1, decode(tg));
            quitrinhb5 = "Chuyển " + tg + " thành '" + s2 + "'";
            ThreadBai5::outout(quitrinhb5);
        }
        else{
          ss << s[i];
        }
    }
  }
  emit outputbai5(kq);
  emit quitrinhbai5change("-----------");
  allkqb5 += kq + "\n";
}

void ThreadBai5::run()
{
    qRegisterMetaType<std::string>("std::string");

    std::string test;
    allkqb5 = "";
    checkbreakb5 = false;

    if(this->checkif){
        std::istringstream f(this->truyeninput);
        while (std::getline(f, test)) {
            if(checkbreakb5)
                break;
            xuly(test);
        }
    }
    else{
        if(this->fileinput == "" || this->folderoutput == ""){
            emit baoloibai5("Vui lòng nhập đủ thông tin!");
        }
        else{
            std::ifstream f(this->fileinput);
            while (std::getline(f, test)) {
                if(checkbreakb5)
                    break;
                xuly(test);
            }
            f.close();
            if(!checkbreakb5){
                std::ofstream outfile(this->folderoutput + "/output.out");
                outfile << allkqb5;
                outfile.close();
                emit baoloibai5("Đã ghi kết quả vào đường dẫn " + this->folderoutput + "/output.out");
            }
        }
    }
    emit chayxongbai5(true);
}
