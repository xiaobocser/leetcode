#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


    ListNode *process(ListNode *head){
        if(head->val != head->next->val)
            return head;
        ListNode *front = head;
        ListNode *middle = front->next;
        ListNode *back = middle->next;
        cout << front->val << endl;
        cout << middle->val << endl;
        cout << back->val << endl;
        while( back != NULL && !(front->val != middle->val && middle->val != back->val) ){
            front = middle;
            middle = back;
            back = back->next;
            cout << front->val << endl;
            cout << middle->val << endl;

        }
        if(back == NULL && front->val == middle->val)
            return NULL;
        return middle;
    }

    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;

        head = process(head);

        cout << head->val;

        if(head == NULL || head->next == NULL)
            return head;

        ListNode *front = head;
        ListNode *back = front->next;

        bool flag = false;
        while(back->next != NULL){
            if(back->val != back->next->val){
                if(flag){
                    if(back->next->next == NULL){
                        front->next = back;
                        break;
                    }else{
                        if(back->next->val != back->next->next->val){
                             front->next = back->next;
                             front = back->next;
                             flag = false;
                        }
                    }
                }
                back = back->next;
            }else{
                back = back->next;
                flag = true;
            }
        }
        if(flag){
            front->next = NULL;
        }
        return head;
    }


int main(){
    ListNode l1(1);ListNode l2(1);ListNode l3(2);
    ListNode *head = &l1;
    head->next = &l2;head->next->next = &l3;head->next->next->next = NULL;
    deleteDuplicates(head);
}
