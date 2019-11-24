//
// Created by rui zhou on 07/05/19.
//

//
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*slow=head,*fast=head;
        if (n==0) return head;

        while (n-->0) {
            fast=fast->next;
        }
        if (fast== nullptr)
            return head->next;
        while (fast->next) {
            slow=slow->next;
            fast=fast->next;
        }
        // slow->next to be deleted
        slow->next = slow->next->next;

//        if (slow->next==fast)
//            slow->next = nullptr;
//        else
//            slow->next = slow->next->next;

        return head;
    }
};
}