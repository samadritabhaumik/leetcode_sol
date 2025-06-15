class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* curr = head;
        while (curr) {
            stk.push(curr);
            curr = curr->next;
        }
        int carry = 0;
        while (!stk.empty()) {
            curr = stk.top();
            stk.pop();
            int val = curr->val * 2 + carry;
            curr->val = val % 10;
            carry = val / 10;}
        if (carry) {
            ListNode* newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;}
        return head;
    }
};
