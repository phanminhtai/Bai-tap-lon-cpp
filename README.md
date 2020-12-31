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
2) Dùng một vòng for duyệt hết chuỗi
3) Nếu s[i] là số thì ta cho vào stack s1
4) Nếu s[i] là một dấu mở ngoặc thì cho vào stack 2
5) Nếu s[i] là một toán tử thì:
  - Kiểm tra xem stack 2 có rỗng không, nếu rỗng thì thêm s[i] vào stack 2
  - Nếu không rỗng thì so sánh độ ưu tiên giữa s[i] và phần tử ở đỉnh stack 2
    - Dùng một vòng lặp while true
    - Nếu độ ưu tiên của s[i] nhỏ hơn hoặc bằng độ ưu tiên của toán tử ở đỉnh stack 2 thì lấy 2 phần tử ở đỉnh stack 1 ra tính toán với toán tử ở đỉnh stack 2 (Sau khi tính toán thì nhớ xóa 2 phần tử ở stack 1 và 1 phần tử ở stack 2)
    - Nếu độ ưu tiên của s[i] lớn hơn độ ưu tiên của toán tử ở đỉnh stack 2 thì thoát khỏi vòng while
    - Tiếp theo thêm s[i] vào stack 2
6) Nếu s[i] là một dấu đóng ngoặc thì lấy tất cả toán tử bên trong stack 2 ra tính toán với các số bên trong stack 1 cho đến khi gặp dấu mở ngoặc thì dừng lại. Sau đó xóa dấu mở ngoặc ra khỏi stack 2
7) Nếu đã xét hết chuỗi thì lấy tất cả toán tử bên trong stack 2 ra tính toán với các số bên trong stack 1 và cho ra kết quả
## Giải thích bài 5
Đối với bài 5 này mình chỉ cần duyệt và gọi hàm, sau đó thay thế là xong. Còn để áp dụng thuật toán thì hiện tại mình chưa tìm ra cái nào để áp dụng cả.
Vậy nên mình tìm ra được cách tối ưu hơn thì sẽ update nhé.

