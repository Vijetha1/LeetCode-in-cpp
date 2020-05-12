#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int v, Node* n):val(v), next(n){}
};

class LinkedList{
    private:
    Node* head=NULL;
    int size=0;
    public:
        void insertNodeAtHead(int v){
            Node* newnode = new Node(v, NULL);
            newnode->next = head;
            head = newnode;
            size+=1;
        }
        
        void insertNodeAtTail(int v){
            Node* n = head;
            Node* prev = NULL;
            while(n!=NULL){
                prev=n;
                n=n->next;
            }
            Node* newnode = new Node(v, NULL);
            if (prev!=NULL)
                prev->next = newnode;
            else
                head = newnode;
            size+=1;
        }

        void insertNodeAtIndex(int v, int idx){
            // 0->1->2->NULL
            // idx = 4
            if(idx > size){
                cout << "Index is too large to insert" << endl;
                return;
            }
            int i = 0;//0
            Node* n = head;//0
            Node* prev = NULL;//0
            while( i<idx){//<3
                prev=n;//2
                n=n->next;//NULL
                i++;//3
            }
            Node* newnode = new Node(v, NULL);
            prev->next = newnode;
            newnode->next = n;
            size+=1;
        }

        void deleteNodeAtHead(){
            if(size==0)
                {
                    cout << "Trying to delete from an empty LinkedList" << endl;
                    return;
                }
            Node* newhead = head->next;
            head = newhead;
            size-=1;
        }

        void deleteNodeAtTail(){
            if(size==0)
                {
                    cout << "Trying to delete from an empty LinkedList" << endl;
                    return;
                }
            Node* n = head;
            Node* prev = NULL;
            while(n->next!=NULL){
                prev=n;
                n=n->next;
            }
            if (prev!=NULL)     
                prev->next = NULL;
            else head=NULL;
            size-=1;
        }
        void deleteNodeAtIndex(int idx){
            if(size < idx)
                {
                    cout << "Index is too large to delete" << endl;
                    return;
                }
            Node* n = head;
            Node* prev = NULL;
            int i=1;
            while(i<idx){
                prev = n;
                n=n->next;
                i++;
            }
            if (prev !=NULL)
                prev->next = n->next;
            else
                head=NULL;
            size-=1;
        }
        void print(){
            Node* n = head;
            cout << "LinkedList:  ";
            while(n!=NULL){
                cout << n->val << "  ";
                n=n->next;
            }
            cout << endl;
        }

        void reverseLinkedList(){
            if (head==NULL || head->next == NULL)
                return;
            Node* n = head;
            Node* prev = NULL;
            Node* next = n->next;
            while(next != NULL){
                prev = n;
                n = next;
                next = n->next;
                n->next = prev;
            }
            head->next = NULL;
            head = n;
        }
};

int main(){
    LinkedList* ll = new LinkedList();
    ll->print();
    ll->insertNodeAtHead(0);
    ll->insertNodeAtTail(1);
    ll->insertNodeAtTail(2);
    ll->insertNodeAtTail(3);
    ll->insertNodeAtTail(4);
    ll->insertNodeAtTail(5);
    ll->print();
    ll->insertNodeAtHead(0);
    ll->print();
    ll->insertNodeAtIndex(1, 8);
    ll->print();
    ll->deleteNodeAtHead();
    ll->print();
    ll->deleteNodeAtTail();
    ll->print();
    ll->deleteNodeAtIndex(5);
    ll->print();
    ll->reverseLinkedList();
    ll->print();
}