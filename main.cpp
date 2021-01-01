#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

class Node {
	public:
		int data;
		Node* next;
};

void print(Node* head) {
	Node* tmp=head;
	while(tmp!=NULL) {
		cout << tmp->data << " ";
		tmp=tmp->next;
	}
	cout << "\n";
}

void combine(Node* head, Node* head2) {
	Node* con=head;
	if(head==NULL||head2==NULL)
		return;
	while(con->next!=NULL)
		con=con->next;
	con->next=head2;
}

void sort(Node* head) {
	bool ok=0;
	Node* ptr;
	Node* lptr=NULL;
	if(head==NULL)
		return;
	do {
		ok=0;
		ptr=head;
		while(ptr->next!=lptr) {
			if(ptr->data>ptr->next->data) {
				int tmp=ptr->data;
				ptr->data=ptr->next->data;
				ptr->next->data=tmp;
				ok=1;
			}
			ptr=ptr->next;
		}
		lptr=ptr;
	} while(ok);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//create first linked list from 10->20
	Node* head=NULL;
	Node* tmp = new Node();
	tmp->data=10;
	tmp->next=NULL;
	Node* trav;
	head=trav=tmp;
	for(int i=11; i<=20; ++i) {
		tmp = new Node();
		tmp->data=i;
		tmp->next=NULL;
		trav->next=tmp;
		trav=trav->next;
	}
	//print first linked list
	print(head);
	//create second linked list 1->10
	Node* head2=NULL;
	tmp = new Node();
	tmp->data=1;
	tmp->next=NULL;
	head2=trav=tmp;
	for(int i=2; i<=10; ++i) {
		tmp = new Node();
		tmp->data=i;
		tmp->next=NULL;
		trav->next=tmp;
		trav=trav->next;
	}
	//print second linked list
	print(head2);
	//combine first and second linked list
	combine(head, head2);
	// print the newly-created linked list
	print(head);
	//sort the newly-created linked list using bubble-sort
	sort(head);
	//print the sorted linked list
	print(head); 
}
