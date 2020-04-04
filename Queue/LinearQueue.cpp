#include <iostream>

#define SIZE 5

using namespace std ;

class Queue{
	int insertAt , deleteFrom , arr[SIZE] ;
	public:
		Queue(){
			deleteFrom = 0 ;
			insertAt = 0 ;
			cout << "\nQueue initialized." ;
			show() ;
		}
		int isFull(){
			return (insertAt == SIZE) ;
		}
		int isEmpty(){
			return (insertAt == deleteFrom) ;
		}
		void insert(int a){				
			if(!isFull()){
				arr[ insertAt++ ] = a ;
				cout << "\nInserted " << a << " to queue." ;
			}else{
				cout << "\nQueue full. cant insert " << a ;
			}
			show() ;
		}
		
		void remove(){
			if(!isEmpty()){
				cout << "\nRemoved " << arr[deleteFrom++] << " from queue.";
			}else{
				cout << "\nCant remove, no items in queue." ;
				reset() ;
			}
			show() ;
		}
		void reset(){
			deleteFrom = insertAt = 0 ;
			cout << "\nQueue Reset." ;
		}
		void show(){
			cout << "\nCurrent Queue Status: " ;
			if(!isEmpty()){
				for(int i = deleteFrom; i < insertAt; i++){
					cout << "\n\t[" << i << "] = " << arr[i] ;
				}
				cout << "\n" ;
			}else{
				cout << "\n\tQueue Empty.\n" ;
			}
		}
};

main(){
	Queue queue ;
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
}
