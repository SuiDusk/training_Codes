#include <iostream>
#include <cstdio>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode Head;
        Head.next = head;
        ListNode *pre = &Head;
        while (true)
        {
            ListNode *end = pre;
            for (int i = 0; i < k; i++)
            {
                end = end->next;
                if (!end)
                    return Head.next;
            }
            ListNode *nextGroup = end->next;
            end->next = nullptr;
            ListNode *cur = pre->next;
            ListNode *prev = nullptr;
            while (cur)
            {
                ListNode *tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            }
            ListNode *groupTail = pre->next;
            pre->next = prev;
            groupTail->next = nextGroup;
            pre = groupTail;
        }
    }
};
int main()
{
    int n = 0, k = 0;
    cin >> n;
    ListNode *head = nullptr, *tail = nullptr;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ListNode *newNode = new ListNode(x);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    cin >> k;
    Solution s;
    ListNode *rev = s.reverseKGroup(head, k);
    ListNode *cur = rev;
    while (cur != nullptr)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    return 0;
}