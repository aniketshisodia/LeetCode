/** jai shree ram


******************************************
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *****************************************************************/
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL ;
        ListNode*slow = head ;
        ListNode*PrevSlow = NULL ;
        ListNode*fast = head ;
        while(fast&&fast->next){
           PrevSlow = slow ;
           slow = slow -> next ;
           fast = fast -> next -> next ;
        }

        ListNode*curr = head ;
        while(curr){
            if(curr->next == slow && slow  != NULL){
                curr->next = slow -> next;
            }
            curr = curr -> next ;
        }
        return head;

    }
};
        // ListNode*after = slow -> next  ;
        // ListNode*node = head ;
        // ListNode*ans = node ;
        //  if(slow -> next !=NULL)
        // PrevSlow -> next = slow -> next -> next ;
        // PrevSlow = PrevSlow -> next ;
        // while(node!=PrevSlow) node = node -> next;
        // while(PrevSlow!=NULL){
        //     PrevSlow = PrevSlow -> next ;
        // }
