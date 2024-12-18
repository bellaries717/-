#include <iostream>
#include <vector>
using namespace std;

int N, M;  // 地图的行数和列数
vector<string> map;  // 存储地图
vector<vector<bool>> visited;  // 访问标记数组

// 四个方向，分别为上下左右
int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = { 0, 0, -1, 1 };

// 判断当前位置是否在有效范围内
bool inBounds(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

// 递归DFS扫描岛屿
void dfs(int x, int y, bool& hasTreasure) {
    visited[x][y] = true;

    // 检查当前格子是否是宝藏
    if (map[x][y] >= '2' && map[x][y] <= '9') {
        hasTreasure = true;
    }

    // 扩展四个方向
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

    // 输入地图数据
    for (int i = 0; i < N; ++i) {
        cin >> map[i];
    }

    int totalIslands = 0;
    int islandsWithTreasure = 0;

    // 遍历所有格子
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // 只有未访问过的陆地或者宝藏才会触发 DFS
            if ((map[i][j] == '1' || map[i][j] >= '2') && !visited[i][j]) {
                bool hasTreasure = false;
                dfs(i, j, hasTreasure);  // 调用递归DFS
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
