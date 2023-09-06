/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node * &head , Node * &tail , int d ){
        Node * newNode = new Node(d);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail ->next = newNode;
            tail = newNode;
        }
    }
    Node* copyRandomList(Node* head) {
        Node * cloneHead = NULL;
        Node * cloneTail = NULL;    

        // make a clone list 
        Node * temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp = temp->next;
        }

        // intialise clone node in between  
        Node * originalNode = head;
        Node * cloneNode = cloneHead;

        while(originalNode != NULL && cloneNode != NULL){
            Node * next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;

            next = cloneNode->next;
            cloneNode -> next = originalNode;
            cloneNode = next;
        }
        temp = head;

        while(temp != NULL){
            if(temp->next != NULL){

            temp->next->random = temp->random ? temp->random->next : temp->random;
                  temp = temp->next->next;
            }
      
        }

        originalNode = head;
        cloneNode = cloneHead;

         while(originalNode != NULL && cloneNode != NULL){
             originalNode->next = cloneNode->next;
             originalNode = originalNode ->next;

             if(originalNode != NULL){
                 cloneNode->next = originalNode->next;
                 cloneNode = cloneNode->next;
             }
         }
      

    return cloneHead;

    }
};