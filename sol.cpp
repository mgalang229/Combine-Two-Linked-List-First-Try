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
	while (connect-> next != NULL) {
		connect = connect->next;
	}
	connect->next = head2;
}

void BubbleSort(Node* head) {
	int swapped = 0;
	Node* ptr;
	Node* lptr = NULL;
	if (head == NULL) {
		return;
	}
	do {
		swapped = 0;
		ptr = head;
		while (ptr->next != lptr) {
			if (ptr->data > ptr->next->data) {
				int tmp = ptr->data;
				ptr->data = ptr->next->data;
				ptr->next->data = tmp;
				swapped = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;
	} while(swapped);
}

int main() {
	// create first linked list from 10 to 20
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
	// print first linked list
	Print(head);
	// create second linked list from 1 to 10
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
	// print second linked list
	Print(head2);
	// combine first and second linked list
	Combine(head, head2);
	// print the combined linked list
	Print(head);
	// sort the linked list using bubble-sort
	BubbleSort(head);
	// print the linked list
	Print(head);
	return 0;	
}
