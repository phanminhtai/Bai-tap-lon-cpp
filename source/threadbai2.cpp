#include "threadbai2.h"
#include <QDebug>
#include <bits/stdc++.h>
#include <string>

Q_DECLARE_METATYPE(std::string)

ThreadBai2::ThreadBai2(QObject *parent, std::string a, int b, int c, bool d, std::string e, std::string f) :
    QThread(parent), truyeninput(a), truyendauphay(b), truyentime(c), checkif(d), fileinput(e), folderoutput(f)
{
}

int n, dem = 0; // n là số phần tử của mảng input, mongoac và dongngoac để lưu lại có bao nhiêu dấu mở ngoặc đóng ngoặc
std::string test, allkq;
std::stack <std::string> s1;
std::stack <char> s2;
std::string tg, tg2, error, quitrinh; // Dùng để lưu lại số thập phân để xài
std::stringstream ssquitrinh;
bool checkbreak = false;

void ThreadBai2::truyenslot(){
    emit quitrinhbai2change(quitrinh);
    this->msleep(this->truyentime*100);
}

int toantu(char c){
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

bool chuso(char c){
    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
        return true;
    return false;
}

std::string tinhtoan(std::string a, std::string b, char c){
    float x, y, s;
    x = std::atof(a.c_str());
    y = std::atof(b.c_str());
    if(c == '+') s = x + y;
    if(c == '-') s = y - x;
    if(c == '*') s = x * y;
    if(c == '/') s = y / x;
    a = std::to_string(s);
    return a;
}

void instack(){
    std::string a;
    tg = s1.top(); // Lấy phần tử của đỉnh stack s1
    s1.pop(); // Xóa phần tử của đỉnh stack s1
    tg2 = s1.top(); // Lấy phần tử của đỉnh stack s1 lần 2
    s1.pop(); // Xóa phần tử của đỉnh stack s1 lần 2
    a = tinhtoan(tg, tg2, s2.top());
    s1.push(a); // Chèn vào đỉnh stack s1: tg + - * / tg2

    quitrinh = "Lấy " + tg2 + " " + s2.top() + " " + tg + " = " + a;
    s2.pop(); // Xóa phần tử của đỉnh stack s2
}

std::string errorlog(){
    return error;
}

std::string lamtron(std::string a, int n){

    std::stringstream ss;

    int pos = a.find('.');

    if(n == 0){
        for(int i = 0 ; i < pos; i ++){
            ss << a[i];
        }
    }
    else{
        for(int i = 0 ; i <= pos + n; i ++){
            ss << a[i];
        }
    }

    ss >> a;

    return a;
}

bool validate(int dem){
    int mongoac = 0, dongngoac = 0;
    bool check1;
    /* Validate:
    Ở giữa:
    - Hai toán tử ko được gần nhau như này: *+
    - Ngoặc vs số ko được gần nhau như này: 5(, )5
    - Hai ngoặc không được như này: (), )(
    - Dấu chấm phải nằm giữa 2 số: 9.6
    - Số ngoặc mở phải bằng số ngoặc đóng và phải có ngoặc mở trước
    - Ngoặc mở phải được thấy trước ngoặc đóng
    - Toán tử phải nằm giữa 2 số hoặc nằm sau dấu ), nằm trước dấu (

    Ở đầu:
    - Chỉ có số và dấu mở ngoặc được phép

    Ở cuối:
    - Chỉ có số và dấu đóng ngoặc được phép
    */

    // Kiểm tra xem ký tự đầu tiên có phải là dấu mở ngoặc hoặc là 1 số không
    if(test[0] != '(' && !chuso(test[0])){
        error = "Dòng " + std::to_string(dem) + ": Bạn đã viết sai cú pháp, ký tự đầu tiên phải là số hoặc dấu mở ngoặc!";
        return false;
    }
    else{
        if(test[0] == '('){
            mongoac ++;
        }
        // Kiểm tra xem ký tự cuối cùng có phải là dấu đóng ngoặc hoặc là 1 số không
        if(test[n-1] != ')' &&  !chuso(test[n-1])){
            error = "Dòng " + std::to_string(dem) + ": Bạn đã viết sai cú pháp, ký tự cuối cùng phải là số hoặc dấu đóng ngoặc!";
            return false;
        }
        else{
            check1 = false;

            for(int i = 1; i < n; i++){

                // Kiểm tra xem phần tử mình duyệt có chứa các ký tự khác không được phép không
                if(toantu(test[i]) == 0 && test[i] != '(' && test[i] != ')' && test[i] != '.' && !chuso(test[i])){
                    error = "Dòng " + std::to_string(dem) + ": Dường như bạn đã nhập sai, những ký tự được hỗ trợ gồm + - * / ( ) . dấu cách và 0 đến 9!";
                    return false;
                }

                // Dấu . phải nằm giữa 2 số
                if(test[i] == '.'){
                    if(!chuso(test[i - 1]) || !chuso(test[i + 1])){
                        error = "Dòng " + std::to_string(dem) + ": Dường như bạn đã viết sai số thập phân, xem lại nhé!";
                        return false;
                    }
                }

                // Hai toán tử không được gần nhau
                if(toantu(test[i]) != 0){
                    if(toantu(test[i - 1]) != 0 || toantu(test[i + 1]) != 0){
                        error = "Dòng " + std::to_string(dem) + ": Dường như bạn đã viết toán tử liền kề nhau, xem lại nhé!";
                        return false;
                    }
                }

                // Kiểm tra xem có các kiểu cấu trúc dạng này không: 5(, (), )( và tăng giá trị của dấu mở ngoặc lên 1
                if(test[i] == '('){
                    mongoac ++;
                    if(test[i - 1] == ')' || test[i + 1] == ')' || chuso(test[i - 1])){
                        error = "Dòng " + std::to_string(dem) + ": Bạn đã viết sai một trong số các cú pháp sau: 5(, (), )(";
                        return false;
                    }
                }

                // Toán tử nằm giữa 2 số hoặc nằm sau dấu ), nằm trước dấu (
                if(toantu(test[i]) != 0){
                    if(test[i - 1] != ')' && !chuso(test[i - 1])){
                        error = "Dòng " + std::to_string(dem) + ": Dường như bạn đã đặt sai chỗ toán tử, xem lại nhé!";
                        return false;
                    }
                    if(test[i + 1] != '(' && !chuso(test[i + 1])){
                        error = "Dòng " + std::to_string(dem) + ": Dường như bạn đã đặt sai chỗ toán tử, xem lại nhé!";
                        return false;
                    }
                }

                // Kiểm tra xem có các kiểu cấu trúc dạng này không: )5, (), )( và tăng giá trị của dấu đóng ngoặc lên 1
                if(test[i] == ')'){
                    dongngoac ++;
                    if(test[i - 1] == '(' || test[i + 1] == '(' || chuso(test[i + 1])){
                        error = "Dòng " + std::to_string(dem) + ": Bạn đã viết sai một trong số các cú pháp sau: (5, (), )(";
                        return false;
                    }

                    // Kiểm tra xem dấu đóng ngoặc có xuất hiện trước dấu mở ngoặc không
                    if(dongngoac > mongoac){
                        error = "Dòng " + std::to_string(dem) + ": Có vấn đề với dấu đóng ngoặc, hãy chắc chắn rằng bạn đã nhập đúng!";
                        return false;
                        check1 = true;
                    }
                }
            }
            // Sau khi duyệt hết phần tử, so sánh dấu đóng và mở ngoặc xem có bằng nhau không
            if(dongngoac != mongoac && check1 == false){
                error = "Dòng " + std::to_string(dem) + ": Có vấn đề với dấu mở đóng ngoặc, số dấu mở ngoặc khác số dấu đóng ngoặc!";
                return false;
            }
        }
    }
    return true;
}

void ThreadBai2::xuly(){
    dem ++;
    n = test.length();

    if(validate(dem)){
        std::stringstream ss; // Dùng để nối số thập phân
        std::string a;
        char b; // Dùng để lưu lại toán tử và dấu đóng mở ngoặc để xài
        bool check, check2; // Check để kiểm tra xem số thập phân có tồn tại không, check2 để kiểm tra toán tử có tồn tại không
        ss.str("");
        ss.clear();

        check2 = true;
        for(int i = 0; i < n; i++){ // Duyệt hết chuỗi

            if(!chuso(test[i]) && test[i] != '.'){ // Nếu không phải là chữ số và dấu .
                if(ss.rdbuf()->in_avail() == 0){ // Kiểm tra ss có chứa số không
                    b = test[i]; // b là toán tử hoặc dấu ngoặc
                }
                else{
                    b = test[i]; // b là toán tử hoặc dấu ngoặc
                    check = true;
                    ss >> a; // a sẽ chứa số thập phân
                    ss.str(""); // Clear ss
                    ss.clear();
                }
            }
            else{ // Nếu là toán tử hoặc dấu ngoặc
                if(chuso(test[i]) || test[i] == '.'){ // Nếu là chữ số hoặc dấu .
                    ss << test[i]; // Truyền vào ss
                }

                if(chuso(test[n - 1]) && i == (n - 1)){
                    check = true;
                    check2 = false;
                    ss >> a;
                    ss.str("");
                    ss.clear();
                }
                else{
                    continue;
                }
            }

            if(check){ // Nếu có giá trị số float được trả về
                s1.push(a);
            }

            if(check2 == true){ // Nếu có giá trị char được trả về
                if(b == '(') // Gặp dấu mở ngoặc thì cho vào stack s2
                    s2.push(b);

                if(toantu(b) != 0){ // Nếu b là toán tử + - * /
                    if(!s2.empty()){ // Nếu stack s2 không rỗng
                        while(true){
                            if(s2.empty()) break;
                            if(toantu(b) > toantu(s2.top()) || toantu(b) == 0){ // Nếu toán tử đang xét có độ ưu tiên nhỏ hơn hoặc bằng toán tử ở đỉnh s2
                                break;
                            }
                            else{
                                instack();
                                ThreadBai2::truyenslot();
                            }
                        }
                    }
                    s2.push(b); // Thêm b vào stack s2
                }

                if(b == ')'){
                    while(true){
                        if(s2.top() == '('){
                            s2.pop();
                            break;
                        }
                        else{
                            instack();
                            ThreadBai2::truyenslot();
                        }
                    }
                }
            }

            check = false;
        }

        while(!s2.empty()){
            instack();
            ThreadBai2::truyenslot();
        }
        emit outputbai2(lamtron(s1.top(), this->truyendauphay));
        allkq += lamtron(s1.top(), this->truyendauphay) + "\n";
    }
    else{
        emit baoloibai2(errorlog());
        checkbreak = true;
    }
    quitrinh = "-----------";
    ThreadBai2::truyenslot();
}

void ThreadBai2::run()
{
    qRegisterMetaType<std::string>("std::string");
    dem = 0;
    allkq = "";
    checkbreak = false;

    if(this->checkif){
        std::istringstream f(this->truyeninput);
        while (std::getline(f, test)) {
            xuly();
            if(checkbreak)
                break;
        }
    }
    else{
        if(this->fileinput == "" || this->folderoutput == ""){
            emit baoloibai2("Vui lòng nhập đủ thông tin!");
        }
        else{
            std::ifstream f(this->fileinput);
            while (std::getline(f, test)) {
                if(checkbreak)
                    break;
                xuly();
            }
            f.close();
            if(!checkbreak){
                std::ofstream outfile(this->folderoutput + "/output.out");
                outfile << allkq;
                outfile.close();
                emit baoloibai2("Đã ghi kết quả vào đường dẫn " + this->folderoutput + "/output.out");
            }
        }
    }
    emit chayxongbai2(true);
}
