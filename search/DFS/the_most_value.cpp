#include <iostream>
using namespace std;

const int maxn = 30;
int n; //the number of object
int V; //the capcity of bag
int maxValue;

int w[maxn]; //the weight of each object
int c[maxn]; //the value of each object

/*
输入: index为当前处理物品编号, sumW和sumC分别为当前总重量和当前总价值
*/
void DFS(int index, int sumW, int sumC)
{
    if (index == n) //已完成对n件物品的选择(死胡同)
    {
        if (sumW <= V && sumC > maxValue) //不超过背包容量时更新最大价值maxValue
        {
            maxValue = sumC;
        }
        return;
    }

    //岔道口
    DFS(index + 1, sumW, sumC);                       //不选择第index件物品
    DFS(index + 1, sumW + w[index], sumC + c[index]); //选择第index件物品
}

void DFS_v2(int index, int sumW, int sumC)
{
    if (index == n)
        return;
    DFS(index + 1, sumW, sumC); //不选第index件物品

    if (sumW + w[index] <= V) //剪枝, 当加入第index件物品未超过V, 继续
    {
        if (sumC + c[index] > maxValue)
        {
            maxValue = sumC + c[index];
        }
        DFS_v2(index + 1, sumW + w[index], sumC + c[index]); //选index
    }
}

int main()
{
    cin >> n >> V;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    DFS_v2(0, 0, 0);
    cout << maxValue;
}