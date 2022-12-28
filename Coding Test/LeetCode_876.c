// LeetCode 876. Middle of the Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {

    struct ListNode* first = head;
    struct ListNode* second = head;

    while (first && first->next)
    {
        second = second->next;
        first = first->next->next;
    }

    return second;
}