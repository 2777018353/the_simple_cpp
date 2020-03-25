#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 100;
struct node
{
    int x, y; //坐标(x, y)
    int step; //最少步数
} S, T, Node; //S起点, T终点, Node临时节点

int n, m;                       //n * m的矩阵
char maze[maxn][maxn];          //迷宫
bool inq[maxn][maxn] = {false}; //记录坐标(x, y)是否入队
int X[4] = {0, 0, 1, -1};       //增量数组
int Y[4] = {1, -1, 0, 0};

//判断坐标(x, y)
bool test(int x, int y)
{
    if (x >= n || x < 0 || y >= m || y < 0) //边界
        return false;
    if (maze[x][y] == '*') //墙壁
        return false;
    if (inq[x][y] == true) //已入队
        return false;
    return true; //有效位置
}

int BFS()
{
    queue<node> q;
    q.push(S);
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        if (top.x == T.x && top.y == T.y)
        {
            return top.step; //终点, 直接返回最少步数
        }
        for (int i = 0; i < 4; i++)
        {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (test(newX, newY)) //坐标(x, y)有效
            {
                Node.x = newX, Node.y = newY;
                Node.step = top.step + 1;
                q.push(Node);
                inq[newX][newY] = true;
            }
        }
    }
    return -1; //无法到达终点T时返回-1
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
        }
    }
    cin >> S.x >> S.y >> T.x >> T.y;
    S.step = 0;
    cout << BFS();
    return 0;
}