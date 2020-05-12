#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x, Node* n) : val(x), next(n) {};
};

int lenOfLL(Node* head){
    int len=0;
    Node* n = head;
    while(n!=NULL){
        n=n->next;
        len+=1;
    }
    return len;
}

Node* reverseLinkedList(Node* p){
    Node* n = p;
    Node* next= NULL;
    Node* prev=NULL;
    while(n!= NULL){
        next = n->next;
        n->next = prev;
        prev = n;
        n = next;
    }
    p->next = NULL;
    return prev;
}

bool isPalin(Node* head){
    int len = lenOfLL(head);
    Node* secondList;
    if(len == 0 || len == 1)
        return true; 
    Node* n = head;//1 -> 2 -> 3 -> NULL
    int l = 0;
    while(l < len/2){//0<1
        n=n->next;//2
        l+=1;//1
    }
    secondList = reverseLinkedList(n);
    Node* p1 = head;
    Node* p2 = secondList;
    l=0;
    while(l < len/2){
        if(p1->val != p2->val)
            return false;
        p1=p1->next;
        p2=p2->next;
        l+=1;
    }
    return true;
}

void print(Node* n){
    while(n!=NULL){
        cout << n->val;
        if(n->next !=NULL)
            cout <<"  ->  ";
        n=n->next;
    }
    cout << endl;
}
int main(){
    cout << boolalpha;
    cout << "Hello World!"<<endl;
    Node* l1 = new Node(1, NULL);
    Node* l2 = new Node(2, l1);
    Node* l3 = new Node(1, l2);
    print(l3);
    cout << "is this a palindrome? "<<isPalin(l3)<<endl;
}