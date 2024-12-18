#include <iostream>
using namespace std;

int josephus(int M, int N) {
    int result = 0;  // 当只剩下1个猴子时，编号是0
    for (int i = 2; i <= M; ++i) {
        result = (result + N) % i;
    }
    return result;
}

int main() {
    int M, N;
    cin >> M >> N;

    // 计算最后剩下的猴子的编号
    int winner = josephus(M, N);

    cout << winner << endl;

    return 0;
}
