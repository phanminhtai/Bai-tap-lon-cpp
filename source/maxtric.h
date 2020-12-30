#include <iostream>

class MAXTRIC
{
    private:
        typedef float** point2;
        point2 p, q;
        int n, m;

    public:
        MAXTRIC(){};
        // Hàm tạo, để lấy giá trị string của input, khai báo mảng động và chuẩn bị full đồ cần thiết cho các hàm khác
        MAXTRIC(std::string a){
            this->n = 2;
            this->m = 3;
            p = new float*[n];
            q = new float*[10];

            for(int i = 0; i < n; i++){
                p[i] = new float[m];
            }

            for(int i = 0; i < 10; i++){
                q[i] = new float[10];
            }

            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    std::cout << "Nhap phan tu hang " << i+1 << " cot " << j+1 << ": ";
                    std::cin >> p[i][j];
                }
            }
        }
        // Hàm hủy
        ~MAXTRIC(){
            p = new float*[n];
            
            for(int i = 0; i < n; i++){
                p[i] = new float[m];
            }

            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    std::cout << "Nhap phan tu hang " << i+1 << " cot " << j+1 << ": ";
                    std::cin >> p[i][j];
                }
            }

            q = new float*[10];

            for(int i = 0; i < 10; i++){
                q[i] = new float[10];
            }
        }

        // Convert chuỗi sang số thực
        float atof(const std::string *s);

        // Check đầu vào và chuyển từ string sang array
        void validate(){

        }

        // Hàm thực hiện chuyển vị và lưu vào mảng trung gian
        float** chuyen_vi(){
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 3; j++){
                    q[j][i] = p[i][j];
                }
            }
            return q;
        }

        // Hàm xóa con trỏ và gán NULL
        void delpoint(){
            delete p;
            delete q;
            p = NULL;
            q = NULL;
        }
};
