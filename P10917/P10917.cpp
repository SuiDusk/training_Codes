/*
写在开头:
主要就是传送门只能传送到传送门的终点,这个终点并不是事实意义上的终点

到了这个终点之后你仍然可以接着走,
所以对于任意一个点,最近的路径一定是经过某次传送之后再加上一段路径
所以可以先求出来每个位置到最近的传送入口的距离,也就是d1数组
整理之后得到经过i次传送之后需要的最短长度,也就是d2数组
第二次bfs搜索使用优先队列对起点和所有传送门终点进行搜索,
这样能保证所有的点一定是经过i次传送之后再搜索一遍得到的最短路径长度.
从第一次开始搜的时候路径长度就会不断变长,直到和经过i+1次传送之后的代价相等的时候,从传送终点之后继续搜索.

 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;
struct Position
{
    ll x, y;
    Position(ll x = 0, ll y = 0) : x(x), y(y) {};
} Entrance[MAXN], Exit[MAXN];
struct que
{
    ll x, y, w;
    que(ll x = 0, ll y = 0, ll w = 0) : x(x), y(y), w(w) {}
    bool operator<(const que t) const
    {
        return w > t.w;
    }
};
ll opt, n, m, a[MAXN], b[MAXN];
ll in, out;
ll tx, ty;
ll d1[1005][1005]; // 每个位置到传送入口
ll d2[MAXN];       // 使用了i次传送的最短距离
ll d3[1005][1005]; // 最终答案
bool vis[1005][1005];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
char mp[1005][1005];
void bfs1();
void bfs2();
int main()
{
    cin >> opt >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }
    cin >> Exit[0].x >> Exit[0].y >> in >> out;
    if (opt == 1)
        cin >> tx >> ty;
    for (int i = 1; i <= in; i++)
    {
        cin >> Entrance[i].x >> Entrance[i].y;
    }
    for (int i = 1; i <= out; i++)
    {
        cin >> Exit[i].x >> Exit[i].y;
    }
    bfs1();
    for (int i = 1; i <= out; i++)
    {
        d2[i] = d2[i - 1] + d1[Exit[i - 1].x][Exit[i - 1].y];
        if (d2[i] >= 1e18)
        {
            for (int j = i; j <= out; j++)
                d2[j] = 1e18;
            break;
        }
    }
    bfs2();
    if (opt == 1)
    {
        if (d3[tx][ty] < 1e18)
            cout << d3[tx][ty] << endl;
        else
            cout << -1 << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (d3[i][j] < 1e18)
                    cout << d3[i][j] << " ";
                else
                    cout << -1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
void bfs1()
{
    queue<que> q;
    memset(vis, 0, sizeof(vis));
    memset(d1, 0x3f, sizeof(d1));
    for (int i = 1; i <= in; i++)
    {
        q.push(que(Entrance[i].x, Entrance[i].y, 0));
        vis[Entrance[i].x][Entrance[i].y] = 1;
        d1[Entrance[i].x][Entrance[i].y] = 0;
    }
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if (mp[nx][ny] == '#')
                continue;
            if (vis[nx][ny])
                continue;
            vis[nx][ny] = 1;
            d1[nx][ny] = d1[x][y] + 1;
            q.push(que(nx, ny, d1[x][y] + 1));
        }
    }
    return;
}
void bfs2()
{
    priority_queue<que> q;
    memset(vis, 0, sizeof(vis));
    memset(d3, 0x3f, sizeof(d3));
    for (int i = 0; i <= out; i++)
    {
        q.push(que(Exit[i].x, Exit[i].y, d2[i]));
        d3[Exit[i].x][Exit[i].y] = d2[i];
    }
    while (!q.empty())
    {
        int x = q.top().x, y = q.top().y;
        q.pop();
        if (vis[x][y])
            continue;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if (mp[nx][ny] == '#')
                continue;
            if (d3[x][y] + 1 < d3[nx][ny])
            {
                d3[nx][ny] = d3[x][y] + 1;
                q.push(que(nx, ny, d3[x][y] + 1));
            }
        }
    }
}