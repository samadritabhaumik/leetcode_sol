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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }
        return prev;}
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        ListNode* curr = head;
        int maxi = curr->val;
        ListNode* prev = curr;
        curr = curr->next;
        while (curr) {
            if (curr->val < maxi) {
                prev->next = curr->next;
                curr = curr->next;
            } else {
                maxi = curr->val;
                prev = curr;
                curr = curr->next;
            }}
        return reverseList(head);
    }
};
