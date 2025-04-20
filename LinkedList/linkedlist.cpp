#include <iostream>
using namespace std;


class Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void TraverseList(Node* head){
    if (head == NULL) return;
    cout<<head->data<<" ";
    TraverseList(head->next);
}

Node* InsertAtHead(Node* head, int data) {
    Node *node = new Node(data);
    node->next = head;
    head = node;
    return head;
}
int main(){
    #ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#endif
    Node* first,*last = NULL;
    Node* head = new Node(1);
    first = last = head;
    Node * node = new Node(2);
    last->next = node;
    last = node;
    node = new Node(3);
    last->next = node;
    last = node;
    head =  InsertAtHead(head, 0);
    TraverseList(head);

}