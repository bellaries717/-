#include<iostream>
#include<cmath>
#include<set>
#include<string>
#include<sstream>//stringstream �������ǽ����������ַ�������ַ���������
                 //���������׼���������һ��������ʹ�� << �� >> �����������������������ڴ��е��ַ���

#include<iomanip>//setw(width)����������ֶεĿ�ȣ���ʾ��������������� width ���ַ���ȡ�
                 //setfill(ch)����������ַ���Ĭ������ַ��ǿո񣬿���ָ�������ַ����� '0'�������հס�

using namespace std;

//�ж��Ƿ�Ϊ����
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

//�������ڣ����ж��Ƿ�Ϊ������
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
                string date = ss.str();//ss.str() �� stringstream ���һ����Ա���������������Ǵ� stringstream ��������ȡ����ǰ�����������ݲ�����һ�� string ����

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