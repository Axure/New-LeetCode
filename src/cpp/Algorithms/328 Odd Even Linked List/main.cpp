#include "Solution.hpp"

int main() {
  auto listNode = new ListNode(1);
  listNode->next = new ListNode(2);
  listNode->next->next = new ListNode(3);
//  listNode->next->next->next = new ListNode(4);
//  listNode->next->next->next->next = new ListNode(5);
//  listNode->next->next->next->next->next = new ListNode(6);
  auto solution = Solution();
  solution.oddEvenList(listNode);

  return 0;
}