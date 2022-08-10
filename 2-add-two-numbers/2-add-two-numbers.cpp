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
    ListNode * solve(ListNode* l1, ListNode* l2){
//         select the longer list as l1 
          
        ListNode * curr1 = l1 ;
        ListNode * next1 = l1->next ;
        ListNode * curr2 = l2 ;
        ListNode * add1 = new ListNode(0);// will use if last has zero 
        
        int carry = 0;
        while(curr1 != NULL  && curr2 != NULL ){
            
        
            if(curr1 ->val + curr2 -> val >=10 ){
               if(next1 == NULL){
                next1 = add1;
                curr1->next = add1;
            }
                next1 ->val +=1;
            }
            
            curr1 ->val = (curr1->val + curr2->val )%10;
            curr1 = curr1->next ;
            curr2 = curr2->next ;
            if(next1 != NULL){
                next1 = next1 ->next ; 
            }
            

        }
        
        while(curr1!=NULL){
            if(curr1->val >=10){
                curr1->val = (curr1 -> val)%10;
            if(next1 == NULL){
                next1 = add1;
                curr1->next = add1;
            }
                next1 ->val +=1;
            }
            curr1 = curr1->next ;
            
            if(next1 != NULL){
                next1 = next1 ->next ; 
            }
            
        }
      
        return l1;
        
        
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
     int len1 = 0 ;
    int len2 = 0 ;
        
        ListNode * curr1 = l1 ;
        ListNode * curr2 = l2;
        
        while(curr1 != NULL){
            len1++;
            curr1 = curr1->next;
        }
    while(curr2 != NULL){
            len2++;
            curr2 = curr2->next;
        }
        
      
        
        if(len1>=len2){
            return solve(l1,l2);
        }else{
            return solve(l2,l1);
        }
        
        
        
            
            
    }
};