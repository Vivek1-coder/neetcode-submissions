/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        stack<ListNode*> st;
        while(slow->next){
            ListNode* temp = slow->next;
            slow->next = nullptr;
            st.push(temp);
            slow = temp;
    
        }
        ListNode* curr = head;
        while(!st.empty())
        {
            ListNode* temp = curr->next;
            curr->next = st.top();
            st.pop();
            curr = curr->next;
            curr->next = temp;
            curr = curr->next;
        }
    }
};
