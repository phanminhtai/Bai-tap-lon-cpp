# Bài tập lớn c++
Open source ở trong folder source nhé: https://github.com/phanminhtai/Bai-tap-lon-cpp/tree/main/source. 
Hiện tại vì không kịp deadline nên phải nộp luôn, mới xử lý được bài 2 và bài 5, nhưng mình sẽ tiếp tục làm tiếp các bài còn lại và update lên đây liên tục.
## Demo
![alt text](https://i.imgur.com/M0Gk6I1.png)

## Đề bài
https://drive.google.com/file/d/1rfphbgb-4dUXSsHGGMjgubeIBrEn9uuM/view

## Giải thích bài 2
Đề bài là tính biểu thức trung tố, ví dụ: `s = 9.898+8.22*(7.64-(8.2654+9.11)-2.65)*89+655.66`

Để dễ hiểu thì ta sẽ làm với ví dụ chỉ có một chữ số trước: `s = 9+8*(7-(8+9)-2)*8+6`

### Ý tưởng tính biểu thức trung tố:
#### Mình sẽ phân ra làm 4 loại ký tự trong một biểu thức trung tố:
- Các con số
- Các toán tử (+ - * /)
- Dấu mở ngoặc
- Dấu đóng ngoặc
#### Tiếp theo mình phân độ ưu tiên giữa các toán tử:
- (* /) có độ ưu tiên là 2
- (+ -) có độ ưu tiên là 1
- Nếu không phải thì trả lại là 0
#### Bắt đầu làm:
1) Khai báo hai stack s1 và s2
~~~ cpp
std::stack <std::string> s1;
std::stack <char> s2;
~~~
2) Dùng một vòng for duyệt hết chuỗi
~~~ cpp
for(int i = 0; i < n; i++){ // Duyệt hết chuỗi
~~~
3) Nếu s[i] là số thì ta cho vào stack s1
~~~ cpp
if(check){ // Nếu có giá trị là số được trả về
    s1.push(a);
}
~~~
4) Nếu s[i] là một dấu mở ngoặc thì cho vào stack 2
~~~ cpp
if(b == '(') // Gặp dấu mở ngoặc thì cho vào stack s2
    s2.push(b);
~~~
5) Nếu s[i] là một toán tử thì:
  - Kiểm tra xem stack 2 có rỗng không, nếu rỗng thì thêm s[i] vào stack 2
  - Nếu không rỗng thì so sánh độ ưu tiên giữa s[i] và phần tử ở đỉnh stack 2
    - Dùng một vòng lặp while true
    - Nếu độ ưu tiên của s[i] nhỏ hơn hoặc bằng độ ưu tiên của toán tử ở đỉnh stack 2 thì lấy 2 phần tử ở đỉnh stack 1 ra tính toán với toán tử ở đỉnh stack 2 (Sau khi tính toán thì nhớ xóa 2 phần tử ở stack 1 và 1 phần tử ở stack 2)
    - Nếu độ ưu tiên của s[i] lớn hơn độ ưu tiên của toán tử ở đỉnh stack 2 thì thoát khỏi vòng while
    - Tiếp theo thêm s[i] vào stack 2
    ~~~ cpp
    if(!s2.empty()){ // Nếu stack s2 không rỗng
        while(true){
            if(s2.empty()) break; // Nếu s2 rỗng thì thoát khỏi vòng lặp while
            if(toantu(b) > toantu(s2.top()) || toantu(b) == 0){ 
                break;
            }
            else{ // Nếu toán tử đang xét có độ ưu tiên nhỏ hơn hoặc bằng toán tử ở đỉnh s2
                instack();
                ThreadBai2::truyenslot();
            }
        }
    }
    s2.push(b); // Thêm b vào stack s2
    ~~~
6) Nếu s[i] là một dấu đóng ngoặc thì lấy tất cả toán tử bên trong stack 2 ra tính toán với các số bên trong stack 1 cho đến khi gặp dấu mở ngoặc thì dừng lại. Sau đó xóa dấu mở ngoặc ra khỏi stack 2
~~~ cpp
if(b == ')'){ // Nếu gặp dấu đóng ngoặc
    while(true){
        if(s2.top() == '('){ // Nếu gặp dấu mở ngoặc
            s2.pop(); // Thêm vào stack 2
            break; // Thoát khỏi vòng lặp
        }
        else{
        ... // Tính toán
        }
    }
}
~~~
7) Nếu đã xét hết chuỗi thì lấy tất cả toán tử bên trong stack 2 ra tính toán với các số bên trong stack 1 và cho ra kết quả
~~~ cpp
while(!s2.empty()){
    ... // Tính toán
}
~~~
Vậy là đã xử lý được biểu thức `s = 9+8*(7-(8+9)-2)*8+6`

Còn với biểu thức `s = 9.898+8.22*(7.64-(8.2654+9.11)-2.65)*89+655.66` thì ta cần phải làm thêm vài bước
### Tính toán biểu thức trung tố với số thập phân tùy ý:
#### Ý tưởng:
Mình sẽ dùng một xâu trung gian để nối các phần tử của số thập phân lại, khi gặp các toán tử hoặc dấu ngoặc thì sẽ đưa xâu vào stack 1. Và sau khi xâu được truyền vào stack s1 thì sẽ gán xâu bằng rỗng
#### Thực hành:
1) Khai báo xâu trung gian (ở đây mình dùng sstream)
~~~ cpp
std::stringstream ss; // Dùng để nối số thập phân
~~~
2) Ở trong vòng for như trên, mình sẽ cho một câu điều kiện rằng: nếu không phải là chữ số và dẫu chấm thì sẽ kiểm tra xem xâu ss có rỗng không, nếu rỗng thì gán b bằng ký tự đang xét rồi truyền 1 tín hiệu là có ký tự b. Nếu không rỗng thì sẽ cho a bằng ss và truyền tín hiệu là có số a
~~~ cpp
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
~~~
3) Nếu là chữ số hoặc dấu chấm thì đơn giản là nối s[i] đang xét vào ss. Và khi mà duyệt hết chuỗi thì đưa a bằng ss
~~~ cpp
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
~~~
## Giải thích bài 5
Đối với bài 5 này mình chỉ cần duyệt và gọi hàm, sau đó thay thế là xong. Còn để áp dụng thuật toán thì hiện tại mình chưa tìm ra cái nào để áp dụng cả.
Vậy nên mình tìm ra được cách tối ưu hơn thì sẽ update nhé.

Trước tiên thì mình có hàm encode (Mã hóa):
~~~ cpp
std::string encode(char x) {
    if(x == 'a'|| x == 'A')
        return ".-";
    if(x == 'b'|| x == 'B')
        return "-...";
    ...
    ...
    ...
    return "#";
}
~~~
Sau đó là hàm decode (Giải mã):
~~~ cpp
char decode(std::string x) {
    if(x == ".-")
        return 'a';
    if(x == "-...")
        return 'b';
    ...
    ...
    ...
    return '#';
}
~~~
Đối với hàm encode, mình duyệt một vòng for xét từng ký tự được đưa vào và chuyển sang mã morse:
~~~ cpp
for (int i = 0; s[i]; i++){
  if(encode(s[i]) == "#"){
      break;
  }
  kq += encode(s[i]) + " ";
}
~~~
Đối với hàm decode, mình dùng một xâu trung gian sau đó duyệt một vòng for xét từng ký tự được đưa vào, nếu gặp dấu cách thì đưa xâu trung gian ra rồi decode(), nếu không thì nối phần tử với xâu:
~~~ cpp
for (int i = 0; i <= n - luu; i++)
{
    if(s[i] == ' ' || i == n){
        ss >> tg;
        if(decode(tg) == '#'){
            break;
        }
        kq += decode(tg);
    }
    else{
      ss << s[i];
    }
}
~~~

Oke good luck!
