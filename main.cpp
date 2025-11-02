#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    pair<int,int> twoSumLinkedList(ListNode* head, int target) {
        unordered_map<int,int> mp; // value -> index
        ListNode* cur = head;
        int idx = 0;

        while(cur != NULL) {
            int need = target - cur->val;
            if(mp.count(need)) {
                return { mp[need], idx }; // return indices
            }
            mp[cur->val] = idx;
            cur = cur->next;
            idx++;
        }
        return {-1, -1}; // not found
    }
};

int main() {
    // Create Linked List: 2 -> 7 -> 11 -> 15
    ListNode* head = new ListNode(2);
    head->next = new ListNode(7);
    head->next->next = new ListNode(11);
    head->next->next->next = new ListNode(15);

    int target = 9;

    Solution s;
    pair<int,int> ans = s.twoSumLinkedList(head, target);

    if(ans.first != -1)
        cout << "Indices: " << ans.first << ", " << ans.second;
    else
        cout << "No pair found";

    return 0;
}
