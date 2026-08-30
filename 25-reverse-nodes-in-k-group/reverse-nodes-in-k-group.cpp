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
   ListNode* reverseLinkedList(ListNode* head) {

    ListNode* prev = NULL;
    ListNode* temp = head;

    while (temp != NULL) {
        ListNode* next = temp->next;

        temp->next = prev;

        prev = temp;
        temp = next;
    }

    return prev;
}

    ListNode* kth (ListNode* head, int k){
        ListNode* temp=head;
        for (int i=0;i<k-1;i++){
            temp=temp->next;
            if (temp==NULL) return NULL;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp=head;
        ListNode* prev=NULL;

        while (temp!=NULL){
            
            ListNode* kthnode=kth(temp,k);

            if (kthnode==NULL){
               if (prev) prev->next=temp;
                break;
            }

            ListNode* nextnode=kthnode->next;
            kthnode->next=NULL;
            reverseLinkedList(temp);
            if (head==temp){
                head=kthnode;
            }else{
                prev->next=kthnode;
            }
            prev=temp;
            temp=nextnode;
        }
        return head;
    }
};