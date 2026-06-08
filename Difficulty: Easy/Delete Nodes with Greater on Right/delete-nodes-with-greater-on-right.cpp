/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *compute(Node *head) {
        // code here
        // arr[0] < arr[1]
        //remove arr[0];
        stack<int>st;
        Node* temp=head;
        while(temp){
            while(!st.empty() && st.top()<temp->data){
                st.pop();
            }
            st.push(temp->data);
            temp=temp->next;
        }
        if(st.empty()) return nullptr;
        Node *nxt=new Node(st.top());
        st.pop();
        while(!st.empty()){
            Node *node=new Node(st.top());
            st.pop();
            node->next=nxt;
            nxt=node;
        }
        return nxt;
    }
};