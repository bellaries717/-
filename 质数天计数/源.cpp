#include<iostream>
#include<cmath>
#include<set>
#include<string>
#include<sstream>//stringstream 允许我们将数据流入字符串或从字符串流出。
                 //它可以像标准输入输出流一样工作（使用 << 和 >> 操作符），但它操作的是内存中的字符串

#include<iomanip>//setw(width)：设置输出字段的宽度，表示输出的内容至少有 width 个字符宽度。
                 //setfill(ch)：设置填充字符。默认填充字符是空格，可以指定其他字符（如 '0'）来填充空白。

using namespace std;

//判断是否为质数
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

//生成日期，并判断是否为质数天
int count_prime_days() {
    int count = 0;
    for (int year = 2000; year <= 2999; ++year) {
        for (int month = 1; month <= 12; ++month) {
            int day_in_month ;
            if (month == 2) {
                if (year % 4 == 0) {
                    if (year % 100 != 0 || year % 400 == 0) day_in_month = 29;
                    else day_in_month = 28;
                }
                else day_in_month = 28;
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11) {
                day_in_month = 30;
            }
            else {
                day_in_month = 31;
            }

            for (int day = 1; day <= day_in_month; ++day) {
                stringstream ss;
                ss << setw(4) << setfill('0') << year;
                ss << setw(2) << setfill('0') << month;
                ss << setw(2) << setfill('0') << day;
                string date = ss.str();//ss.str() 是 stringstream 类的一个成员函数，它的作用是从 stringstream 对象中提取出当前缓冲区的内容并返回一个 string 对象。

                for (int i = 0; i < date.size(); ++i) {
                    string sub_str = date.substr(i);
                    int number = stoi(sub_str);
                    if (!is_prime(number)) {
                        break;
                    }
                    else
                        ++count;
                }
            }
        }
    }
    return count;
}

int main() {
    cout << count_prime_days() << endl;
    return 0;
}