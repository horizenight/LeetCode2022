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
    void insert( ListNode * &head , ListNode * &tail ,int val ){
        
        ListNode * temp = new ListNode(val);
        
        if(head->next == NULL){
            head->next = temp;
            tail = temp;
        }
        else{
            tail->next  = temp;
            tail = temp;
        }
//         this inserts 
        
        
    }
public:
    
    ListNode* oddEvenList(ListNode* head) {
//       form two dummy node 
        ListNode * oddHead = new ListNode(-1);
        ListNode * oddTail = oddHead;
        ListNode * evenHead = new ListNode(-1);
        ListNode * evenTail = evenHead;
        
        ListNode * curr = head ;
        int len =1 ;
        while(curr!= NULL){
            
            if(len&1){
                //odd
                
                
                  insert(oddHead , oddTail , curr->val );
                
            }else{
//                 even
              insert(evenHead , evenTail , curr->val);
            }
            
            curr = curr->next ;
            len++;
            
        }
        
        
//         merge odd and even 
        
        oddTail ->next = evenHead->next;
        oddHead = oddHead->next;
        
        return oddHead;
        
    }
};