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
    ListNode* merge(ListNode* a,ListNode* b){
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        while(a && b){
            if(a->val <= b->val){
                temp->next = a;
                a = a->next;   
            }
            else{
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
            temp->next = nullptr;
        }
        while(a){
            temp->next = a;
            a = a->next;   
            temp = temp->next;
            temp->next = nullptr;
        }
        while(b){
            temp->next = b;
            b = b->next;   
            temp = temp->next;
            temp->next = nullptr;
        }
        temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode* head = lists[0];
        for(int i = 1;i<lists.size();i++){
            head = merge(head,lists[i]);
        }
        return head;
    }
};
