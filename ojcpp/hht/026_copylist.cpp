//
// Created by rui zhou on 2019-11-29.
//

// 复制复杂链表，需要额外空间，可以考虑bfs的做法

#include <codech/codech_def.h>
using namespace std;

struct ComplexListNode {
    int value;
    ComplexListNode *next;
    ComplexListNode *sibling;
    ComplexListNode(int v) {value = v;next = nullptr,sibling = nullptr;}
    //ComplexListNode() {}
};

namespace {
    // O(n) space

    class Solution {
    public:
        unordered_map<ComplexListNode*,ComplexListNode*> m; // mapping

        //unordered_set<ComplexListNode*> uset;

        ComplexListNode* clonelist(ComplexListNode *node) {
            ComplexListNode dummy(0);
            ComplexListNode*prev = &dummy;

            ComplexListNode *head = node;

            while (head) {
                ComplexListNode* clone = new ComplexListNode(head->value);
                prev->next = clone;
                //clone->value = head->value;

                m[head] = clone;
                prev = prev->next;
                head = head->next;
            }

            head = node;

            while (head) {
                auto sib = head->sibling;
                auto clone_head = m[head];

                if (sib) {
                    ComplexListNode* clone_sib = m[sib];
                    clone_head->sibling = clone_sib;
                }

                head = head->next;
            }
            return dummy.next;
        }
    };
}

void print_complexlist(ComplexListNode*node) {
    ComplexListNode *head = node;
    while (head) {
        cout << head->value << "-->";
        head = head->next;
    }
    cout <<endl;
    head = node;
    while (head) {
        if (head->sibling) {
            cout << head->value << " sibling:" << head->sibling->value << endl;
        }
        head = head->next;
    }

}

DEFINE_CODE_TEST(jump_polish_notation)
{
    Solution obj;
    {
        // a- b -c -d -e
        // a-c,b-e,d-b
        ComplexListNode *pa=new ComplexListNode(0);
        ComplexListNode *pb=new ComplexListNode(1);
        ComplexListNode *pc=new ComplexListNode(2);
        ComplexListNode *pd=new ComplexListNode(3);
        ComplexListNode *pe=new ComplexListNode(4);
        pa->next = pb;pb->next = pc;pc->next = pd;pd->next = pe;
        pa->sibling = pc;pd->sibling = pb;pb->sibling = pe;
        ComplexListNode *newhead = obj.clonelist(pa);
        print_complexlist(newhead);

    }

}