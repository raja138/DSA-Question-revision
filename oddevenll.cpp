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
    ListNode* oddEvenList(ListNode* head) {
        //0/1 node → kuch change nahi.
        if(!head || !head->next)
        {
            return head;
        }

        ListNode* odd=head;//// 1st node (odd position)

        ListNode* even=head->next;// 2nd node (even position)
        ListNode* firstEven=head->next;//// even list ka head (baad mein jodne ke liye odd aur even list ko )


//Jab tak next odd & even available hain:
// odd->next  = odd->next->next;   // odd → next odd
// even->next = even->next->next;  // even → next even
// odd  = odd->next;               // odd aage
// even = even->next;              // even aage
//  Isse:
// odd nodes aapas mein judte jaate hain
// even nodes aapas mein judte jaate hain

        while(even && even->next)
        {
            odd->next=odd->next->next;//
            even->next=even->next->next;//
            odd=odd->next;//oddd ko aage bdhane k liye
            even=even->next;//even ko aage bdhane k liye
        }

//Dono lists ko jodna
// odd->next = firstEven;
// Odd list ke end pe even list attach.
        odd->next=firstEven;
        return head;
    }
};