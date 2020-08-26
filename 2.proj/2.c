/*
 * ============================================================================
 *
 *       Filename:  2.c
 *
 *    Description: https://leetcode-cn.com/problems/add-two-numbers
 *
 *        Version:  1.0
 *        Created:  10/08/19 10:10:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * ============================================================================
 */
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL;
    struct ListNode* parent = NULL;
    int carry = 0;
    do {
        struct ListNode* node =
            (struct ListNode*)malloc(sizeof(struct ListNode));
        int l1val = l1 != NULL ? l1->val : 0;
        int l2val = l2 != NULL ? l2->val : 0;
        node->val = (l1val + l2val + carry) % 10;
        node->next = NULL;
        if (parent != NULL) {
            parent->next = node;
            parent = node;
        } else {
            parent = node;
            head = node;
        }
        carry = (l1val + l2val + carry) / 10;
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    } while (l1 != NULL || l2 != NULL);

    if (carry != 0) {
        struct ListNode* node =
            (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = carry;
        node->next = NULL;
        parent->next = node;
    }
    return head;
}

int main(int argc, char** argv) {
    struct ListNode* l1;
    struct ListNode* l2;

    struct ListNode* result = addTwoNumbers(l1, l2);

    while (result != NULL) {
        printf("%d", result->val);

        if (result != NULL) {
            struct ListNOde* tmp = result->next;
            free(result);
            result = tmp;
        }
    }
}
