#include <iostream>
using namespace std;

int josephus(int M, int N) {
    int result = 0;  // ��ֻʣ��1������ʱ�������0
    for (int i = 2; i <= M; ++i) {
        result = (result + N) % i;
    }
    return result;
}

int main() {
    int M, N;
    cin >> M >> N;

    // �������ʣ�µĺ��ӵı��
    int winner = josephus(M, N);

    cout << winner << endl;

    return 0;
}
