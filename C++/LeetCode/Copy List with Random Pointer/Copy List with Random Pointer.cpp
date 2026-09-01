#include <iostream>
#include <cstdio>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        Node *cur = head;
        while (cur != nullptr)
        {
            Node *tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
        cur = head;
        while (cur != nullptr)
        {
            if (cur->random != nullptr)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        cur = head->next;
        Node *pre = head, *res = head->next;
        while (cur->next != nullptr)
        {
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = nullptr;
        return res;
    }
};
int main()
{
    return 0;
}