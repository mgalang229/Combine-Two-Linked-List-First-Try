#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
		int data;
		Node* next;
};

void Print(Node* head) {
	Node* tmp = head;
	while (tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << '\n';
}

void Combine(Node* head, Node* head2) {
	Node* connect = head;
	if (head == NULL || head2 == NULL) {
		return;
	}
	while (connect->next != NULL) {
		connect = connect->next;
	}
	connect->next = head2;
}

void BubbleSort(Node* head) {
	bool checker = false;
	Node* ptr;
	Node* lptr = NULL;
	if (head == NULL) {
		return;
	}
	do {
		checker = false;
		ptr = head;
		while (ptr->next != lptr) {
			if (ptr->data > ptr->next->data) {
				int tmp = ptr->data;
				ptr->data = ptr->next->data;
				ptr->next->data = tmp;
				checker = true;
			}
			ptr = ptr->next;
		}
		lptr = ptr;
	} while(checker);
}

int main() {
	// create 1st linked list from 10 to 20
	Node* head = NULL;
	Node* tmp = new Node();
	tmp->data = 10;
	tmp->next = NULL;
	Node* trav;
	head = trav = tmp;
	for (int i = 11; i <= 20; i++) {
		tmp = new Node();
		tmp->data = i;
		tmp->next = NULL;
		trav->next = tmp;
		trav = trav->next;
	}
	// print 1st linked list
	Print(head);
	// create 2nd linked list from 1 to 10
	Node* head2 = NULL;
	tmp = new Node();
	tmp->data = 1;
	tmp->next = NULL;
	head2 = trav = tmp;
	for (int i = 2; i <= 10; i++) {
		tmp = new Node();
		tmp->data = i;
		tmp->next = NULL;
		trav->next = tmp;
		trav = trav->next;
	}
	// print 2nd linked list
	Print(head2);
	// combine 1st and 2nd linked list
	Combine(head, head2);
	// print newly-combined linked list
	Print(head);
	// sort the newly-combined linked list using bubble-sort
	BubbleSort(head);
	// print the sorted linked list
	Print(head);
	return 0;
}
