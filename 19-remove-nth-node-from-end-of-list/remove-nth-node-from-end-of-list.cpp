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
    int getLength(ListNode * head ){
        int len =0;
        while(head){
            len++;
            head = head->next;
        }

        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // n th node form end is len - 
        if(head->next == NULL && n ==1){
            head = NULL;
            return head;
        }
        int size = getLength(head);
        int pos = size - n; //pos form start if we sttart from 1
        ListNode * temp = head;
        ListNode * prev= NULL;
        while(pos && temp){
            prev= temp;
            temp = temp->next;
            pos--;
        }

        // now prev and temp at correct location 
        if(temp){
        if(prev == NULL){
            head = head->next;
            return head;
        }
        prev->next = temp->next;
        temp->next = NULL;
        delete temp;

        }
       
        return head;

    }
};