#include <iostream>
#include <vector>
using namespace std;

int N, M;  // ��ͼ������������
vector<string> map;  // �洢��ͼ
vector<vector<bool>> visited;  // ���ʱ������

// �ĸ����򣬷ֱ�Ϊ��������
int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = { 0, 0, -1, 1 };

// �жϵ�ǰλ���Ƿ�����Ч��Χ��
bool inBounds(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

// �ݹ�DFSɨ�赺��
void dfs(int x, int y, bool& hasTreasure) {
    visited[x][y] = true;

    // ��鵱ǰ�����Ƿ��Ǳ���
    if (map[x][y] >= '2' && map[x][y] <= '9') {
        hasTreasure = true;
    }

    // ��չ�ĸ�����
    for (int i = 0; i < 4; ++i) {
        int nx = x + dirX[i];
        int ny = y + dirY[i];

        if (inBounds(nx, ny) && !visited[nx][ny] && (map[nx][ny] == '1' || map[nx][ny] >= '2')) {
            dfs(nx, ny, hasTreasure);
        }
    }
}

int main() {
    cin >> N >> M;
    map.resize(N);
    visited.resize(N, vector<bool>(M, false));

    // �����ͼ����
    for (int i = 0; i < N; ++i) {
        cin >> map[i];
    }

    int totalIslands = 0;
    int islandsWithTreasure = 0;

    // �������и���
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // ֻ��δ���ʹ���½�ػ��߱��زŻᴥ�� DFS
            if ((map[i][j] == '1' || map[i][j] >= '2') && !visited[i][j]) {
                bool hasTreasure = false;
                dfs(i, j, hasTreasure);  // ���õݹ�DFS
                totalIslands++;
                if (hasTreasure) {
                    islandsWithTreasure++;
                }
            }
        }
    }

    cout << totalIslands << " " << islandsWithTreasure << endl;

    return 0;
}
