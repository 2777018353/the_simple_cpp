#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 110;
struct Inteval //开区间左右端点
{
    int x;
    int y;
} I[maxn];
//先按左端点从大到小排序, 左端点相同的从小到大排序
bool cmp(Inteval a, Inteval b)
{
    if (a.x != b.x)
    {
        return a.x > b.x;
    }
    else
    {
        return a.y < b.y;
    }
}

int main()
{
    int n;
    while (cin >> n, n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> I[i].x >> I[i].y;
        }
        sort(I, I + n, cmp);

        int ans = 1;        //记录不相交区间个数
        int lastX = I[0].x; //记录上一个被选中区间的左端点
        for (int i = 1; i < n; i++)
        {
            if (I[i].y <= lastX)
            {
                lastX = I[i].x;
                ans++;
            }
        }
        cout << ans;
    }
}