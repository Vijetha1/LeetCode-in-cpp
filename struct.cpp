#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

struct Node{
    int val;
    Node* next;
    // Node(int x, Node* n) : val(x), next(n) {}
};

int main(){
    // Node n={1, NULL};
    Node n;
    Node* head = &n;
    head->val = 10;
    head->next = NULL;
    // n.val=10;
    // int i;
    // cout << typeid(i).name() << endl;;
    // n.val = 10;
    cout << head->val << endl;
    cout << head->next << endl;
    Node* p = head;
    cout << p->val << endl;
    cout << p->next << endl;
    cout << head << endl;
    cout << p << endl;

    Node* q = p;
    cout << p << endl;
    cout << p->next <<endl;
    Node* r = q;
    cout << p << endl;
    cout << p->next <<endl;
    // cout << p->val << endl;
    // cout << p->next << endl;
    // cout << head << endl;
    // cout << p << endl;
    // n.val = 1;
    // n.next = NULL;
    // cout << n.val << endl;
    // cout << n.next << endl;
    // cout << n.val << endl;
    // cout << n.next << endl;
    cout << "Hello World!";
}