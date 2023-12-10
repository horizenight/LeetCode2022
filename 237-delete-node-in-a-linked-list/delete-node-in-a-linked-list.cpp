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
    void deleteNode(ListNode* node) {
      // logic copy the next poiuinter to this pointer 
      node->val = node->next->val;
      ListNode * temp = node -> next;
      node->next = node ->next->next;
      temp->next= NULL;
      delete temp;
    }
};