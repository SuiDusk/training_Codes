#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 20005;

int n, q;
string op;

class Node {
public:
    long long l, r;
    Node(long long l = 0, long long r = 0) :l(l), r(r) {};

    bool operator < (Node x)
    {
        return l < x.l;
    }
};
vector<Node> pieces;

class process_Node {
public:
    long long l, r, index, point;
    process_Node(long long l, long long r, long long index, long long point) :l(l), r(r), index(index), point(point) {};
};

class process {
public:
    vector<process_Node> node;

    long long build(int length)
    {
        long long index = 0, aim_length = 0;
        //printf("分配空间前\n");
        for (int i = pieces.size() - 1; i >= 0; i--)
        {
            if (pieces[i].r == -1)
            {
                index = i; aim_length = pieces[i].l;
            }
            else
            {
                if (pieces[i].r - pieces[i].l + 1 >= length && pieces[i].r - pieces[i].l + 1 <= aim_length)
                    index = i, aim_length = pieces[i].r - pieces[i].l + 1;
            }
            //printf("pieces[%d]=%d %d\n",i, pieces[i].l, pieces[i].r);
        }
        long long ans = pieces[index].l;
        pieces[index].l += length;

        node.push_back(process_Node(pieces[index].l - length, pieces[index].l - 1, node.size() + 1, 0));
        if (pieces[index].l > pieces[index].r && pieces[index].r != -1) pieces.erase(pieces.begin() + index);
        //for (int i = 0; i < node.size(); i++)
        //{
        //	printf("node[%d].l.r=%d %d\n", i, node[i].l, node[i].r);
        //}

        //printf("分配空间后\n");
        //for (auto i : pieces)
        //	printf("pieces[]=%d %d\n", i.l, i.r);

        return ans;
    }

    long long send()
    {
        int len = node.size();
        long long sum = 0;
        for (int i = 0; i < len; i++)
        {
            //printf("node[%d].l.r.point=%d %d %d\n", i, node[i].l, node[i].r, node[i].point);
            sum += node[i].l + node[i].point;
            node[i].point++;
            if (node[i].point + node[i].l > node[i].r) node[i].point = 0;
        }
        return sum;
    }
    void delet(int index)
    {
        for (int i = index; i < node.size(); i++)
            node[i].index--;
        pieces.push_back(Node(node[index - 1].l, node[index - 1].r));
        node.erase(node.begin() + index - 1);
        sort(pieces.begin(), pieces.end());
        for (int i = 0; i < pieces.size() - 1; i++)
        {
            if (pieces[i].r == pieces[i + 1].l || pieces[i].r == pieces[i + 1].l - 1)
                pieces[i].r = pieces[i + 1].r, pieces.erase(pieces.begin() + i + 1), i--;
        }
        return;
    }
};


int main()
{
    scanf("%d %d", &n, &q);
    vector<process> pro(n + 5);
    pieces.push_back(Node(0, -1));
    while (q--)
    {
        cin >> op;
        if (op == "new")
        {
            int p, L;
            scanf("%d %d", &p, &L);
            printf("%lld\n", pro[p].build(L));
        }
        if (op == "send")
        {
            int p;
            scanf("%d", &p);
            printf("%lld\n", pro[p].send());
        }
        if (op == "delete")
        {
            int p, index;
            scanf("%d %d", &p, &index);
            pro[p].delet(index);
        }
    }
    return 0;
}
