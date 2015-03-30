#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *reverseKGroup(ListNode *head, int k) {
    if(k == 0 || k == 1)
        return head;
    int pos = 0;
    vector<ListNode *> ListsHead;
    vector<ListNode *> ListsTail;
    ListNode *scan = head, *pre = head, *vot, *cons, *tmp, *votHead;
    while(scan != NULL) {
        if(++pos == k){
            pos = 0;
            ListsHead.push_back(pre);
            scan = scan->next;
            votHead = pre;//cout<<"scan"<<scan->val<<endl;
            vot = scan;//cout<<"vot"<<vot->val<<endl;
            cons = pre;cout<<"pre"<<cons->val<<endl;
            while(cons != vot){
                tmp = cons->next;
                cons->next = pre;
                pre = cons;
                cons = tmp;
            }
            ListsTail.push_back(pre);
            votHead->next = vot;

            pre=vot;
        }else
            scan = scan->next;
    }
    if(ListsTail.size() != 0)
        head = ListsTail[0];
    cout << "head" << head->val << endl;
    for(int i=1; i<ListsTail.size(); i++){
        ListsHead[i-1]->next = ListsTail[i];
        cout << "head" << ListsHead[i-1]->val << "tail" <<ListsTail[i]->val << endl;
    }

    return head;
}


int main() {
    ListNode *t1 = new ListNode(1);
    ListNode *t2 = new ListNode(2);
    ListNode *t3 = new ListNode(3);
    ListNode *t4 = new ListNode(4);
    t1->next = t2; t2->next = t3; t3->next = t4; t4->next = NULL;
    t2 = reverseKGroup(t1,2);
    while(t2 != NULL){
        cout << t2->val << " ";
        t2 = t2->next;
    }
}
