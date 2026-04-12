#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for linked list
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode *mergeKLists_Brute(vector<ListNode *> &lists)
    {
        vector<int> result;
        for (auto head : lists)
        {
            while (head)
            {
                result.push_back(head->val);
                head = head->next;
            }
        }
        sort(result.begin(), result.end());
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;
        for (auto a : result)
        {
            dummy->next = new ListNode(a);
            dummy = dummy->next;
        }

        return head->next;
    }
    struct comp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists_Optimal(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, comp> pt;
        for (auto head : lists)
        {
            if (head)
                pt.push(head);
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        while (!pt.empty())
        {
            ListNode *curr = pt.top();
            pt.pop();

            tail->next = curr;
            tail = curr;
            if (curr->next)
            {
                pt.push(curr->next);
            }
        }
        return dummy->next;
    }
};

int main()
{

    vector<ListNode *> lists;

    Solution obj;

    // Call any approach
    ListNode *result = obj.mergeKLists_Optimal(lists);

    return 0;
}