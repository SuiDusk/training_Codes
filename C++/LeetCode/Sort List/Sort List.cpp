#include <iostream>
#include <cstdio>
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
    ListNode *sortList(ListNode *head)
    {
        int cnt[200005];
        if (head == nullptr)
            return head;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            cnt[cur->val + 100000]++;
            cur = cur->next;
        }
        cur = head;
        for (int i = 0; i <= 200000; i++)
        {
            while (cnt[i] != 0 && cur != nullptr)
            {
                cur->val = i - 100000;
                cnt[i]--;
                cur = cur->next;
            }
            if (cur == nullptr)
                break;
        }
        return head;
    }
};
int main()
{
    return 0;
}