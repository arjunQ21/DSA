#include <iostream>

using namespace std ;

#define SIZE 4

class CircularQueue{
	int insertAt, deleteFrom, arr[ SIZE ] ;
	public:
		CircularQueue(){
			insertAt = deleteFrom = 0 ;
		}
		int isFull(){
			return ((insertAt - deleteFrom ) == SIZE) ;
		}
		int isEmpty(){
			return ( insertAt == deleteFrom ) ;
		}
		void insert(int num){
			if(isFull()){
				cout << "\nQueue Overflow. Cant insert more items." ;
			}else{
				arr[insertAt % SIZE] = num ;
				cout << "\n Inserted " << num << " to queue." ;
				insertAt ++ ;
			}
			display() ;
		}
		void remove(){
			if(isEmpty()){
				cout << "\nQueue Underflow. Cant remove when there are no items." ;
			}else{
				cout << "\nRemoved " << arr[deleteFrom++ % SIZE ] << " from queue." ;
			}
			display() ;
		}
		void display(){
			cout << endl << endl << "Queue Status: " << endl << endl 
			<< "insertAt: " << insertAt << ", deleteFrom: " << deleteFrom << ", Full: " << (isFull()? "Yes": "No" )<< ", Empty: " << (isEmpty()?"Yes" : "No" )<<endl ;
			int i ;
			for( i = deleteFrom ; i < insertAt ; i++){
				cout << "\n[" 
				<< i % SIZE << "] => " << arr[ i % SIZE ] ;
			}
		}
};

main(){
	CircularQueue queue;
	cout << "\n Demo of queue operations for queue of size " << SIZE << endl << endl;
	char choice ;
	int input ;
	
	do{
//		system("CLS") ;
//		queue.display();
		cout << "\n\n\nEnter your choice" ;
		cout << "\nPress: \n" 
				<< "a => " << "add item to queue" <<endl 
				<< "b => " << "remove item from queue" << endl 
				<< "c => " << "Display queue" << endl
				<< "x => " << "Exit " << endl ;
		cin >> choice ;
		switch(choice){
			case 'a':
				cout << "\nEnter a number to add to queue: " ;
				cin >> input ;
				queue.insert(input) ;
				break ;
			case 'b':
				queue.remove() ;
				break ;
			case 'c':
				queue.display() ;
				break ;
			case 'x':
				break ;
			default:
				cout << "\nInvalid choice." ;	
		}
		
	}while( choice != 'x') ;
	cout << "\nFinished.." ;
}






