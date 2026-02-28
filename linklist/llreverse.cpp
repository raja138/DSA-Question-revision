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

//ListNode* newHead = reverseList(head->next);

// Chalo ise dry run se samjhte hain.
//  Example lete hain:
// Linked List:
// 1 → 2 → 3 → NULL
// Hum call karte hain:
// reverseList(1)
//  Step-by-step Recursion Flow
//  Call 1:
// reverseList(1)
// Ye line execute hogi:
// newHead = reverseList(2)
//  Call 2:
// reverseList(2)
// Ye line execute hogi:
// newHead = reverseList(3)
//  Call 3:
// reverseList(3)
// Yaha base case hit hoga:
// head->next == NULL
// Return 3.
// So:
// newHead = 3
//  Ab Stack Unwind Hota Hai
// Ab recursion wapas upar aata hai.
//  Back to Call 2 (head = 2)
// Ab:
// newHead = 3
// Ab hum ye karte hain:
// head->next->next = head;
// Matlab:
// 3->next = 2
// Ab list ban gayi:
// 3 → 2
// Phir:
// head->next = NULL;
// Matlab:
// 2->next = NULL
// Return newHead (3)
// 🔙 Back to Call 1 (head = 1)
// Ab:
// newHead = 3
// Again:
// head->next->next = head;
// Matlab:
// 2->next = 1
// Now:
// 3 → 2 → 1
// Phir:
// 1->next = NULL
// Return newHead (3)
//  Final Answer
// 3 → 2 → 1
//  Important Samajhne Wali Baat
// Ye line:
// ListNode* newHead = reverseList(head->next);
// Ka matlab hai:
// "Baaki poori list ko pehle reverse karo…
// phir mujhe us reversed list ke end me jod dena."
//  Mental Model
// Recursive version me:
// Neeche tak jao
// Last node ko new head banao
// Wapas aate hue links ulto
// Agar chaho to main iska ek stack diagram bhi bana ke samjha sakta hoon.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* newHead=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
};