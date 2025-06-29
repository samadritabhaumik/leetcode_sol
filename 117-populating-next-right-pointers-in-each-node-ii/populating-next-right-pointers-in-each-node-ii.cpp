class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        Node* curr = root;
        Node* dummy = new Node(0); 
        while (curr) {
            Node* temp = dummy;
            while (curr) {
            if (curr->left) {
            temp->next = curr->left;
            temp = temp->next;
                }
            if (curr->right) {
            temp->next = curr->right;
            temp = temp->next;}
                curr = curr->next;
            }
            curr = dummy->next;
            dummy->next=NULL; 
        }
        return root;
    }
};
