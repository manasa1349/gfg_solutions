/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {

        // code here
        if(!head) return head;
        Node *temp=head;
        Node *dummy=new Node(-1);
        dummy->next=temp;
        Node *st=temp;
        while(temp && temp->next){
            if(temp->next->data==temp->data){
                while(temp->next && temp->next->data==temp->data){
                    temp=temp->next;
                }
                st->next=temp->next;
            }
            st=st->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};