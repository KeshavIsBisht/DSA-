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
    ListNode* reverseList(ListNode* head) {
    
        if (head == NULL || head->next == NULL)
    return head;

        ListNode* temp1=head->next;
        if (head->next->next==NULL){
            temp1->next=head;
            head->next = NULL;
            head=temp1;
            return head;
        }

        ListNode* temp2=head->next->next;
        int count=0;

        while (temp1!=NULL){
            temp1->next=head;
            if (count==0){
                 head->next = NULL;
                 count++;
            }
            head=temp1;
            temp1=temp2;
            if(temp2!=NULL){
                temp2=temp2->next;
            }
        }
        return head;
    }
};