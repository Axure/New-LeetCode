#include <cstddef>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) { }
};
// TODO: write a set of data structures that specifically fits into LeetCode. (i.e. val, next interfaces, etc.)
class Solution {
 public:
  ListNode *oddEvenList(ListNode *head) {
    bool nextEven = true;
    ListNode *pEven, *pOdd, *pInitOdd, *pInitEven;
    pOdd = head;
    pInitOdd = pOdd;
    if (pOdd != NULL) {
      pEven = pOdd->next;
      pInitEven = pEven;
      if (pEven != NULL && pEven->next != NULL) {
        /**
         * Detach and reattach
         */
        pOdd->next = pEven->next;
        pOdd = pOdd->next;
        /**
         * Loop.
         */
        while (pOdd->next != NULL && pEven->next != NULL) {
          /**
           * If the next is even
           */
          if (nextEven) {
            pEven->next = pOdd->next;
            pEven = pEven->next;
            nextEven = false;
          } else {
            pOdd->next = pEven->next;
            pOdd = pOdd->next;
            nextEven = true;
          }
        }
        pEven->next = NULL;
      }
      pOdd->next = pInitEven;
    }
    return pInitOdd;
  }
};