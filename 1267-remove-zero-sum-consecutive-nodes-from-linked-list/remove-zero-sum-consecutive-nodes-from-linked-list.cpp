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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // dummnode -> next = head ; 
        // mp 
        // mp[0] = dummyNode
        // while 
        // prefixSum += head->val;
        // map mai prefix sum present 
        // delete 
        // else insert in map 
        ListNode * dummyNode = new ListNode(0) ;
        dummyNode->next = head;

        unordered_map<int,ListNode*>mp;
        mp[0] = dummyNode;
        int prefixSum = 0;
        while(head!=NULL){
            prefixSum += head->val;
            if(mp.find(prefixSum) != mp.end()){
                // delete
                ListNode * start = mp[prefixSum];
                ListNode * temp = start;
                int pSum = prefixSum;
                while(temp!= head){

                    temp = temp->next;
                    pSum += temp->val;
                    if(temp!= head){
 mp.erase(pSum);
                    }
                   
                }

                start->next= temp->next;

            }else{
                mp[prefixSum] = head;
            }
            head=head->next;
        }
        return dummyNode->next;
     }
};