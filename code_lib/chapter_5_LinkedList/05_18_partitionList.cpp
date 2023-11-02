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


// Given a linked list and a value x, 
// partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.

// 这道题要求我们划分链表，把所有小于给定值的节点都移到前面，大于该值的节点顺序不变，相当于一个局部排序的问题。
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

// 此题还有一种解法，就是将所有小于给定值的节点取出组成一个新的链表，
// 此时原链表中剩余的节点的值都大于或等于给定值，只要将原链表直接接在新链表后即可，代码如下：

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *newDummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy, *p = newDummy;
        while (cur->next) {
            if (cur->next->val < x) {
                p->next = cur->next;
                p = p->next;
                cur->next = cur->next->next;
                p->next = NULL;
            } else {
                cur = cur->next;
            }
        }
        p->next = dummy->next;
        return newDummy->next;
    }
};