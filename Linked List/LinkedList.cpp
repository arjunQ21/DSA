#include <iostream>

using namespace std ;

struct Node{
	int data ;
	struct Node * next ;
};

class LinkedList{
	struct Node * start ;
	public:
		LinkedList(){
			start = NULL ;
			cout << "\nInitialized linked list." ;
		}
		struct Node* createNode()
		{
			return new struct Node();
		}
		void insertAtFirst(int d){
			
			struct Node *newNode = createNode();
			if(!newNode)
			{
				return;
			}
			newNode->next = start;
			newNode->data = d;
			start = newNode;
			cout << "\nAdded " << d << " at fist of list." ;
		}
		void insertAtLast(int d)
		{
			struct Node * newNode = createNode();
			if(!newNode)
			{
				return;
			}
			newNode->data = d;
			newNode->next = NULL;
			if(start == NULL){
				start = newNode;
				cout << "\nAdded " << newNode->data << " at last of list" ;
				return ;
			}
			struct Node *temp = start;
			while(temp->next != NULL){
				temp = temp->next ;
			}
			temp->next = newNode ;
			cout << "\nAdded " << newNode->data << " at last of list" ;
		}
		void display(){
			cout << "\nShowing Linked List." ;
			int c = 0 ;
			struct Node * temp = start ;
			if(temp){
				while(1){
					cout << "\n[" << c++ << "] => address = "<< temp << ", data = " << temp->data << " , next = " << temp->next  ; 
					temp = temp->next ;
					if(temp == NULL) break ;
				}
			}else{
				cout << "\nNo items in linked list.";
			}
		}
};

main(){
	LinkedList l ;
	l.insertAtLast(5);
	l.insertAtLast(8);
	l.insertAtFirst(9) ;
	l.display();
}
