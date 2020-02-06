#include <iostream>

#define SIZE 5

using namespace std ;

class Queue{
	int insertAt , deleteFrom , arr[SIZE] ;
	public:
		Queue(){
			deleteFrom = 0 ;
			insertAt = 0 ;
		}
		void insert(int a){
			if(insertAt < SIZE ){
				arr[insertAt] = a ;
				insertAt ++ ;
				cout << "\nInserted " << a << " to queue." ;
			}else{
				cout << "\nQueue full. cant insert " << a ;
			}
		}
		void remove(){
			if(insertAt == 0){
				cout << "\nCant remove, no items in queue." ;
			}else{
				if(deleteFrom < SIZE){
					deleteFrom++ ;
					cout << "\nRemoved " << arr[deleteFrom - 1] << " from queue ";
				}else{
					if(deleteFrom == insertAt){
						deleteFrom = insertAt = 0 ;
						cout << "\nQueue Reset.";
					}
				}
			}
		}
};

main(){
	Queue queue ;
	queue.insert(1);
	queue.insert(2);
	queue.insert(3);
	queue.remove();
	queue.remove();
	queue.remove();
	queue.remove();
	queue.remove();
	queue.remove();
	queue.remove();
	queue.remove();
	queue.insert(4);
	queue.insert(5);
	queue.insert(6);
}
