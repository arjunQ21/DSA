#include <iostream>
#include <conio.h>

#define SIZE 5

using namespace std ;

class CircularQueue{
	//Usually, rear and front are used. insertAt and deleteFrom are more readable. so,
	int insertAt , deleteFrom , arr[SIZE] ;
	public:
		CircularQueue(){
			deleteFrom = 0 ;
			insertAt = 0 ;
			cout << "\nQueue initialized." ;
			show() ;
		}
		int isFull(){
			return ((insertAt - deleteFrom) ==  SIZE) ;
		}
		int isEmpty(){
			return (insertAt == deleteFrom) ;
		}
		void insert(int a){				
			if(!isFull()){
				arr[ (insertAt++ % SIZE) ] = a ;
				cout << "\nInserted " << a << " to queue." ;
			}else{
				cout << "\nQueue full. cant insert " << a ;
			}
			show() ;
		}
		
		void remove(){
			if(!isEmpty()){
				cout << "\nRemoved " << arr[(deleteFrom++ % SIZE)] << " from queue.";
			}else{
				cout << "\nCant remove, no items in queue." ;
			}
			show() ;
		}
		void show(){
			cout << "\nCurrent Queue Status: " ;
			cout << "\n\tdeleteFrom: " << deleteFrom << ", insertAt: " << insertAt  ;
			if(!isEmpty()){
				for(int i = deleteFrom; i < insertAt; i++){
					cout << "\n\t[" << i%SIZE << "] = " << arr[i % SIZE] ;
				}
				cout << "\n" ;
			}else{
				cout << "\n\tQueue Empty.\n" ;
			}
		}
};

main(){
	CircularQueue queue ;
	//for exams, you can just show these
	queue.insert(1);
	queue.insert(23);
	queue.insert(3);
	queue.remove();
	queue.remove();
	queue.remove();
	queue.remove();
	queue.remove();
	queue.insert(4);
	queue.insert(5);
	queue.insert(6);
	queue.remove();
	queue.remove();
	queue.remove();
	queue.insert(6);	
	
	//For Testing nicely in console screen
	char choice = 1 ;
	do{
		cout << "\n\nCicular Queue Demo. Press given numbers for respective functions: ";
		cout << "\n1\tInsert item into queue."
			<< "\n2\tRemove item from queue."
			<< "\n3\tShow Queue Status."
			<< "\n0\tExit."<< endl;
		choice = getche() ;
		switch(choice){
			case '1':
				cout << "\nEnter a number to add to queue: " ;
				int a ;
				cin >> a ;
				queue.insert(a) ;
				break ;
			case '2':
				queue.remove() ;
				break ;
			case '3':
				queue.show() ;
				break ;
			default:
				cout << "\nInvalid Choice. choose again." ;
		}
	}while(choice != '0');
}
