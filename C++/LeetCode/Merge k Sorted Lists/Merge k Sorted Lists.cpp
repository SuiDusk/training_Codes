#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        int si = lists.size();
        int cnt[20005] = {0};
        ListNode *cur;
        for (int i = 0; i < si; i++)
        {
            cur = lists[i];
            while (cur != nullptr)
            {
                cnt[cur->val + 10000]++;
                cur = cur->next;
            }
        }
        ListNode *res = nullptr, *tail = nullptr;
        for (int i = 0; i <= 20000; ++i)
        {
            while (cnt[i]--)
            {
                ListNode *node = new ListNode(i - 10000);
                if (!res)
                {
                    res = tail = node;
                }
                else
                {
                    tail->next = node;
                    tail = node;
                }
            }
        }
        return res;
    }
};
int main()
{
    return 0;
}