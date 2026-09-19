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
    ListNode* reverse(ListNode* st,ListNode* end){
        ListNode* temp = st;
        ListNode* prev = end;
        while(temp != end){
            ListNode* t = temp->next;
            temp->next = prev;
            prev = temp;
            temp = t;
        }
        ListNode* t = temp->next;
        temp->next = prev;
        prev = temp;
        temp = t;
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode* st = head;
        ListNode* end = head;
        ListNode* prev = head;
        for(int i = 0;i<k;i++){
            if(!end) return head;
            prev = end;
            end = end->next;
        }

        end = reverseKGroup(end,k);
        ListNode* t = reverse(st,prev);
        st->next = end;
        return t;
    }
};
