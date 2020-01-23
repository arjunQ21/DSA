#include <iostream>

using namespace std ;

#define SIZE 4

class CircularQueue{
	int front, rear, arr[ SIZE ] ;
	public:
		CircularQueue(){
			front = rear = 0 ;
		}
		int isFull(){
			return (front == (rear + 1) % SIZE) ;
		}
		int isEmpty(){
			return ( front == rear ) ;
		}
		void insert(int num){
			if(isFull()){
				cout << "\nQueue Overflow. Cant insert more items." ;
			}else{
				arr[rear % SIZE] = num ;
				cout << "\n Inserted " << num << " to queue." ;
				rear ++ ;
			}
			display() ;
		}
		void remove(){
			if(isEmpty()){
				cout << "\nQueue Underflow. Cant remove when there are no items." ;
			}else{
				front ++ ;
				cout << "\nRemoved " << arr[front - 1] << " from queue." ;
				front = front % SIZE ;
				if(front == rear){
					front = rear = 0 ;
				}
			}
			display() ;
		}
		void display(){
			cout << endl << "Queue: " << endl 
			<< "Front: " << front << ", Rear: " << rear << ", Full: " << (isFull()? "Yes": "No" )<< ", Empty: " << (isEmpty()?"Yes" : "No" )<<endl ;
			int i ;
			for( i = front ; i < rear ; i++){
				cout << "\n[" 
//				<< i<<", " 
				<< i % SIZE << "] => " << arr[ i % SIZE ] ;
//				if(front == i % SIZE ) break ;
			}
		}
};

main(){
	CircularQueue queue;
	cout << "\n Demo of queue operations for queue of size " << SIZE ;
	char choice ;
	int input ;
	
	do{
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






