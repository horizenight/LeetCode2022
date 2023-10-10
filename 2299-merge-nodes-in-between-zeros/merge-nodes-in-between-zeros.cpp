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
    ListNode* mergeNodes(ListNode* head) {
        ListNode * temp = head;
        ListNode * mHead = NULL;
        ListNode * mTail = mHead;

        int ans = 0;
        while(temp != NULL){
            if(temp->next != NULL && temp->next->val != 0){
                ans += temp->next->val;
            }else{
                if(ans != 0){
                ListNode * newNode = new ListNode(ans);
                if(mHead==NULL){
                    mHead = newNode;
                    mTail = mHead;
                }else{
                    mTail->next = newNode;
                    mTail = newNode;
                }
                }
               
                ans=0;
            }
            temp = temp->next;
        }

        return mHead;
    }
};