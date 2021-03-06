//Circular Linked list insertion
#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* createNode(int data){
	try{
		Node *node = new Node;
		node->data = data;
		node->next = NULL;
		return node;
	}
	catch(int e){
		cout<<" Mem error";
		exit(0);
	}
}

void insertBegin(Node** head,int data){
	Node *node = createNode(data);

	//check for empty list
	if(*head == NULL){
		*head = node;
		node->next = node;
		return;
	}

	Node* last = *head;
	while(last->next!= *head)
		last = last->next;
	node->next = *head;
	last->next = node;
	*head = node;
}

void insertEnd(Node** head,int data){
	Node *node = createNode(data);

	if(*head == NULL){
		*head = node;
		node->next = node;
		return;
	}

	Node *last = *head;
	while(last->next != *head){
		last = last->next;
	}
	node->next = *head;
	last->next = node;
}

void disp(Node* head){
	Node *temp =head;
	while(head->next != temp){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<head->data<<" ";
	cout<<endl;
}
main(){
	Node* head = NULL;
	insertBegin(&head,1);
	insertBegin(&head,2);
	insertBegin(&head,3);
	disp(head);
	insertBegin(&head,22);
	insertBegin(&head,11);
	disp(head);
}
