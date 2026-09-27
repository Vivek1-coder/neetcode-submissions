/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        if(slow == null || slow.next == null) return false;
        do{
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast) return true;
        }while(fast != null && fast.next != null);

        return false;

    }
}
