//
// Created by rui zhou on 2019-11-22.
//

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
    class Solution {
    public:
        ListNode* deletenode(ListNode *head, ListNode *node) {
            ListNode dummy(0);
            dummy.next = head;
            ListNode *prev = &dummy;

            while (head) {
                if (head == node) {
                    prev->next=head->next;
                    break;
                } else {
                    prev = head;
                    head = head->next;
                }
            }
            return dummy.next;
        }

    };
}

DEFINE_CODE_TEST(013_deletenode)
{
    Solution obj;
    {
        ListNode*head = CREATE_LIST(10);
        ListNode *node=FIND_LISTNODE(head,5);
        ListNode *newhead = obj.deletenode(head,node);
        VERIFY_CASE(PRINT_LIST(newhead),"1 2 3 4 6 7 8 9 10");
    }
}