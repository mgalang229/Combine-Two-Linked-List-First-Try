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
	Node* tmp = head;
	while(tmp!=NULL) {
		cout << tmp->data << " ";
		tmp=tmp->next;
	}
	cout << "\n";
}

void combine(Node* head, Node* head2) {
	Node* link;
	link=head;
	while(link->next!=NULL)
		link=link->next;
	link->next=head2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	Node* head=NULL;
	Node* tmp = new Node();
	tmp->data=1;
	tmp->next=NULL;
	Node* trav;
	head=trav=tmp;
	for(int i=2; i<=10; ++i) {
		tmp = new Node();
		tmp->data=i;
		tmp->next=NULL;
		trav->next=tmp;
		trav=trav->next;
	}
	print(head);
	Node* head2=NULL;
	tmp = new Node();
	tmp->data=10;
	tmp->next=NULL;
	head2=trav=tmp;
	for(int i=11; i<=20; ++i) {
		tmp = new Node();
		tmp->data=i;
		tmp->next=NULL;
		trav->next=tmp;
		trav=trav->next;
	}
	print(head2);
	combine(head, head2);
	print(head);
}
