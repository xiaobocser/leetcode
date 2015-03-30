#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;


// speed O(n^2) space O(1) exceed time
ListNode *mergeKLists1(vector<ListNode *> &lists) {
    bool empty = true;
    int min, minPos, i;
    ListNode *tmp, *pre, *head;
    //find pre, head
    min = INT_MAX;
    minPos = -1;
    for(i=0; i<lists.size(); i++) {
        if(lists[i] != NULL) {
            if(min > lists[i]->val){
                min = lists[i]->val;
                minPos = i;
            }
        }
    }
    if(minPos != -1){
        pre = lists[minPos];
        head = pre;
        lists[minPos] = lists[minPos]->next;
    }
    else
        return NULL;
    //construct list
    while(empty) {
        min = INT_MAX;
        empty = false;
        minPos = -1;
        for(i=0; i<lists.size(); i++) {
            if(lists[i] != NULL) {
                empty = true;
                if(min > lists[i]->val){
                    min = lists[i]->val;
                    minPos = i;
                }
            }
        }
        if(minPos != -1){
            pre->next = lists[minPos];
            pre = lists[minPos];
            lists[minPos] = lists[minPos]->next;
        }
    }
    return head;
}

// speed O(n + nlogn) space O(2n)  in time
ListNode *mergeKLists2(vector<ListNode *> &lists) {
    if(lists.size() == 0)
        return NULL;

    bool empty = false;
    int i;
    ListNode *tmp, *pre, *head;

    for(i=0; i<lists.size(); i++) {
        if(lists[i] != NULL)
            empty = true;
    }
    if(!empty)
        return false;

    vector<int> trans;
    for(i=0; i<lists.size(); i++) {
        tmp = lists[i];
        while(tmp != NULL){
            trans.push_back(tmp->val);
            tmp = tmp->next;
        }
    }
    sort(trans.begin(), trans.end());

    pre = new ListNode(trans[0]);
    head = pre;
    for(i=1; i<trans.size(); i++) {
        tmp = new ListNode(trans[i]);
        pre->next = tmp;
        pre = tmp;
    }
    pre->next = NULL;

    return head;
}

int main() {

}
