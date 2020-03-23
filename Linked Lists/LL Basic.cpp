#include<iostream>
using namespace std;

class node{
	public:
		int data = -1;
		node *next = NULL;
	
		node(int data){
			this->data = data;
			this->next = NULL;
		}
};

void insertAtHead(node *&head, int value){ //NOTE: passing head by reference
	if(head == NULL){
		head = new node(value);
		return;
	}
	node *newNode = new node(value);
	newNode->next = head;
	head = newNode;	
}

void insertAtTail(node *&head, int value){
	if(head == NULL)
		return insertAtHead(head, value); //return is important 
	node *newNode = new node(value);
	node *temp = head;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = newNode;
}

void insertInMiddle(node *&head, int value, int position){
	if(position == 0)
		return insertAtHead(head, value);
	int count = 0;
	node *temp = head;
	while(temp->next!=NULL && count<position-1){ //if position is greater than size of LL, insert at tail
		temp = temp->next;
		count++;
	}
	node *next_node = temp->next; //storing next value before updating next
	node *new_node = new node(value);
	temp->next = new_node;
	new_node->next = next_node;
}

void printList(node *head){ //No modifications to value of head
	if(head==NULL){
		cout<<"\n";
		return;
	}		
	cout<<head->data<<" ";
	printList(head->next);
}

int main(){
	node *head = NULL;
	insertAtTail(head, 3);
	insertAtHead(head, 1);
	insertAtHead(head, 2);
	insertAtTail(head, 0);
	insertInMiddle(head, 5, 2);
	printList(head);
	insertInMiddle(head, 4, 0);
	insertInMiddle(head, 6, 6);
	insertInMiddle(head, 10, 9); //edge case
	printList(head);
}