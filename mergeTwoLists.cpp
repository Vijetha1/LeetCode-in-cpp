#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

void print(ListNode* dummyL){
    if (dummyL == NULL)
    {
        cout << "pointing to NULL"<<endl;
    }
    // ListNode* dummyL = l;
    while(dummyL != NULL){
        cout << dummyL->val << "  ";
        dummyL = dummyL->next;
    }
    cout << endl;
}
ListNode* mergeTwoLists(ListNode* ref, ListNode* check) {
    // - lets say:
    //      list1: 1->2->3
    //      list2: 1->3->5->6->7
    // - keep one list as the reference list, and add nodes from the other lists. 
    print(ref);
    print(check);
    if (ref==NULL)
        return check;
    if (check==NULL)
        return ref;
    // ListNode* ref = l1;
    // ListNode* check = l2;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    ListNode* head = NULL;
    while(ref != NULL && check != NULL){
        if(ref->val <= check-> val){
            if(head==NULL)
                head=ref;
            prev = ref;
            ref = ref->next;
        }
        else{
            if(head==NULL)
                head = check;
            if(prev != NULL)
                prev->next = check;
            next = check->next;
            check->next = ref;
            prev = check;
            check = next;
        }
    }
    if(ref == NULL){
        prev->next = check;
    }
    print(head);
    return head;
}

int main(){
    cout << "Hello World  !" << endl;
    ListNode l1(1);
    ListNode l2(2);
    l1.next = &l2;
    ListNode l3(3);
    l2.next = &l3;
    ListNode l4(2);
    ListNode l5(3);
    ListNode l6(4);
    ListNode l7(5);
    ListNode l8(6);
    l4.next = &l5;
    l5.next = &l6;
    l6.next = &l7;
    l7.next = &l8;
    ListNode* dummy = NULL;
    mergeTwoLists(&l1, &l4);

    return 0;
}