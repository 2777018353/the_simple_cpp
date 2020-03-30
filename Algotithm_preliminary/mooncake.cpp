#include <iostream>
#include <algorithm>
using namespace std;

struct mooncake
{
    double store; //库存
    double sell;  //总售价
    double price; //单价
} cake[1010];

bool cmp(mooncake a, mooncake b) //单价由高到低排序
{
    return a.price > b.price;
}

int main()
{
    int n;    //月饼种类数量
    double D; //市场需求
    cin >> n >> D;
    for (int i = 0; i < n; i++)
    {
        cin >> cake[i].store;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cake[i].sell;
        cake[i].price = cake[i].sell / cake[i].store; //计算单价
    }
    sort(cake, cake + n, cmp); //单价从高到低排序
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (cake[i].store <= D)
        {
            D -= cake[i].store;
            ans += cake[i].sell;
        }
        else
        {
            ans += cake[i].price * D;
            break;
        }
    }
    printf("%.2f\n", ans);
}