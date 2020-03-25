#include <iostream>
#include <queue>
using namespace std;

const int maxn = 100;
struct node
{
    int x, y;
} Node;

int n, m;                       //矩阵大小为n * m
int matrix[maxn][maxn];         //01矩阵
bool inq[maxn][maxn] = {false}; //记录(x, y)是否已经入过队(为减少空间使用可直接在原矩阵将已经被visit的元素置零)
int X[4] = {0, 0, 1, -1};       //增量数组
int Y[4] = {1, -1, 0, 0};

//判断坐标(x, y)是否是块的一部分
bool judge(int x, int y)
{
    //越界返回flase
    if (x >= n || x < 0 || y >= m || y < 0)
        return false;
    //当前元素为0, 或(x, y)已经入过队, 返回false
    if (matrix[x][y] == 0 || inq[x][y] == true)
        return false;
    //都不满足
    return true;
}

//BFS函数访问坐标(x, y)所在的块, 将该块中所有的"1"的inq都设置为true
void BFS(int x, int y)
{
    queue<node> Q;
    Node.x = x, Node.y = y;
    Q.push(Node);
    inq[x][y] = true;
    while (!Q.empty())
    {
        node top = Q.front();       //取出队首元素
        Q.pop();                    //出队
        for (int i = 0; i < 4; i++) //4个相邻位置
        {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (judge(newX, newY)) //如果属于块
            {
                Node.x = newX, Node.y = newY; //新节点
                Q.push(Node);                 //入队
                inq[newX][newY] = true;       //已访问过
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++)
            cin >> matrix[x][y];

    int ans = 0;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            if (matrix[x][y] == 1 && inq[x][y] == false)
            {
                ans++;     //块数+1
                BFS(x, y); //访问整个块. 将所有的"1"的inq标记为true
            }
        }
    }
    cout << ans;
    return 0;
}