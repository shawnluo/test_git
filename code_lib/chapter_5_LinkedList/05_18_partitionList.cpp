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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) {
            return nullptr;
        }
        ListNode* bigNum = head;
        ListNode* smallNum = head;

        while(bigNum != nullptr && smallNum != nullptr) {
            while(bigNum != nullptr && bigNum->val < x) {
                bigNum = bigNum->next;
            }
            if(bigNum == nullptr) {
                return head;
            }
            smallNum = bigNum->next;
            while(smallNum != nullptr && smallNum->val >= x) {
                smallNum = smallNum->next;
            }
            if(smallNum != nullptr) {
                int tmp = smallNum->val;
                smallNum->val = bigNum->val;
                bigNum->val = tmp;
            } else {
                return head;
            }
        }
        return head;
    }
};