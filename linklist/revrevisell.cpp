ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* newHead=reverseList(head->next);

        head->next->next=head;//ye dekh lena ku kiya hai
        head->next=NULL;

        return newHead;
    }