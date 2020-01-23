#include <iostream>
using namespace std ;

#define SIZE 10

class Stack{
	int arr[ SIZE ], top ;
	public:
		Stack(){
			top = 0 ;
		}
		int isEmpty(){
			if(top > 0){
				return 0 ;
			}else{
				return 1 ;
			}
		}
		int isFull(){
			if(top >= SIZE ){
				return 1 ;
			}else{
				return 0 ;
			}
		}
		void show(){
			cout << "\nStack Contents:" ;
			int i ;
			for(i = top -1 ; i >= 0 ; i-- ){
				cout << "\n\t[ " << i << " ] => " <<  arr[i] ;
			}
			cout << endl ;
		}
		void push(int number){
			if(isFull()){
				cout << "\n Cannot Push " << number << " to stack because stack is full." ;
			}else{
				arr[top] = number ;
				top ++ ;
				cout << "\nPushed " << number << " to stack." ;
			}
		}
		int pop(){
			if(isEmpty()){
				cout << "\n Cannot Pop from stack because stack is empty." ;
				return -1 ;
			}else{
				cout << "\nPopped " << arr[top - 1] << " from stack." ;
				return arr[ top--]  ;
			}
		}
};
main(){
	Stack stack ;
	cout << "\n Demo of stack operations for stack of size " << SIZE ;
	char choice ;
	int input ;
	
	do{
		cout << "\n\n\nEnter your choice" ;
		cout << "\nPress: \n" 
				<< "a => " << "Push item to stack" <<endl 
				<< "b => " << "Pop from stack" << endl 
				<< "c => " << "Display Stack" << endl
				<< "x => " << "Exit " << endl ;
		cin >> choice ;
		switch(choice){
			case 'a':
				cout << "\nEnter a number to push to stack: " ;
				cin >> input ;
				stack.push(input) ;
				break ;
			case 'b':
				stack.pop() ;
				break ;
			case 'c':
				stack.show() ;
				break ;
			case 'x':
				break ;
			default:
				cout << "\nInvalid choice." ;	
		}
		
	}while( choice != 'x') ;
	cout << "\nFinished.." ;
}











