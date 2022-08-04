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
    private:
    int getlength(ListNode *head){
        int len = 0;
        while(head != NULL){
            len++;
            head= head ->next;
            
        }
        return len;
    }
public:
    ListNode* middleNode(ListNode* head) {
        
        int len = getlength(head);
        
        int mid = (len/2 );
        ListNode * temp = head;
        
        while(mid--){
            temp = temp->next;
        }
        return temp;
    }
};