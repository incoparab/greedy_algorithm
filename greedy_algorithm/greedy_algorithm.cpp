//带有限期的作业排序算法
#include <iostream>
using namespace std;
struct Work
{
    int d; //期限值
    int p; //收益
    int m;
    Work()
    {
        d = 0;
        p = 0;
    }
};

void Sort(Work *w, int n)
{
    //使收益按照非递增排序
    for (int i = 2; i < n; i++)
        for (int j = 1; j < i; j++)
        {
            if (w[i].p > w[j].p)
            {
                Work temp = w[i];
                w[i] = w[j];
                w[j] = temp;
            }
        }
}

int main()
{
    int n;
    cout << "请输入作业的数量:" << endl;
    cin >> n;
    Work *w = new Work[n + 1];
    Work *j = new Work[n + 1];
    cout << "请在接下来的一行输入各作业的期限值：" << endl;
    for (int i = 1; i < n + 1; i++)
        cin >> w[i].d;
    cout << "请在接下来的一行输入各作业的收益:" << endl;
    for (int i = 1; i < n + 1; i++)
        cin >> w[i].p;
    for (int i = 1; i < n + 1; i++)
        w[i].m = i;

    Sort(w, n + 1);

    j[1] = w[1];
    int k = 1;
    for (int i = 2; i < n + 1; i++)
    {
        int r = k;
        while (j[r].d > w[i].d && j[r].d != r)
            r--;
        if (j[r].d <= w[i].d && w[i].d > r)
        {
            for (int i = k; i >= r + 1; i--)
                j[i + 1] = j[i];
            j[r + 1] = w[i];
            k++;
        }
    }

    //输出
    for (int i = 1; j[i].d != 0; i++)
        cout << j[i].m;
    cout << endl;
    system("pause");
    return 0;
}