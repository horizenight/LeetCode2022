/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
//         hare tortoise algorithm 
        
        ListNode * fast = head;
        ListNode * slow = head;
        int flag = false;
        while(fast != NULL && slow !=NULL && fast->next !=NULL){
            fast = fast ->next ->next ;
            slow = slow ->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
        
        
        
    }
};