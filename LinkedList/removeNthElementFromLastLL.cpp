#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

int kthLastElement(node *head, int k){
    //Complete this function to return kth last element
    
    int i=1;
    node *fast,*slow;
    fast = slow = head;
    
    while(i<= k-1){
        fast = fast->next;
        i++;
    }
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
    
}