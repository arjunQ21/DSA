#include <iostream>

using namespace std ;

//adt of type NaturalNumber
class NaturalNumber{
	int number ;
	public:
		//constructors
		NaturalNumber(){
			number = 1 ;
			cout << "\nInitialized a natural number to 1." ;
		}
		NaturalNumber(int a){
			if(a > 0){
				number = a ;
				cout << "\nInitialized a natural number to " << a<< "." ;
			}else{
				number = 1 ;
				cout << "\nCant initialize a natural number to "<< a << " so, initialized it to 1.";
			}
		}
		//methods
		int increment(){
			return ++number ;
		}
		int decrement(){
			if(number > 1){
				return --number ;
			}else{
				cout << "\nCannot decrement below 1." ;
				return 1 ;
			}
		}
};
main(){
	NaturalNumber a ;
	NaturalNumber b(-89) ;
	NaturalNumber c(0) ;
	NaturalNumber d(45) ;
}
