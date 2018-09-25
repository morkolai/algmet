//Algmet, IMT2021, oppg9
//Contributors: morkolai, Torkjellr, owren, thanssveen
//This program figures out where to place N chess queens on a N*N chess board
//without standing in each others target zones.

#include <iostream>

int const N = 6;								  //number og rows and columns
int const LEN = N + 1;										 //length of array
int pos[LEN];						      //array with coordinates (index = x)
int ant = 0;											 //number of solutions


void dronning(int x);
bool sjekkPoss(int x, int y);	 
void display();								

int main() {
	dronning(1);
	std::cout << ant << std::endl;
	return 0;
}

//places the queens
void dronning(int x) {	
	
	if (x == LEN) {											   //when finished
		display();
		ant++;
	}
	for (int i = 1; i <= N; i++) {				              //for each value
		if (sjekkPoss(x, i)) {						     //if the pos is legal
			pos[x] = i;
			dronning(x + 1);							         //next column
			pos[x] = -1;								     //wipes the array
		}
	}
}

//checks if the position is legal
bool sjekkPoss(int x, int y) {

	for (int i = 1; i < LEN; i++) {					 //checks y-values/columns
		if (pos[i] == y) {
			return false;
		}
	}

	int yn = y, yo = y;						        //upper and lower diagonal

	for (--x; x > 0; x--) {				      //moves to the left on the board
		
		yn--;							
		yo++;

		if (yn <= 0)									 //secures safe values
			yn = 0;
		if (yo <= 0)
			yo = 0;

		if (pos[x] == yn || pos[x] == yo)			    //checks the diagonals
			return false;
	}

	return true;
}

//displays the solutions
void display() {
	for (int i = 1; i < LEN; i++) {
		std::cout << '(' << i << ", " << pos[i] << ")\n";
	}
	std::cout << std::endl;
}