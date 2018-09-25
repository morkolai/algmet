
#include <iostream>

int const N = 4;
int const LEN = N + 1;
int pos[LEN];
int ant = 0;


void dronning(int x);
bool sjekkPoss(int x, int y);
void display();

int main() {

	dronning(1);
	display();

	return 0;
}

void dronning(int x) {
	if (x == N) {
		display();
		ant++;
	}
	for (int i = 1; i <= N; i++) {
		if (sjekkPoss(x, i)) {
			pos[x] = i;
			dronning(x + 1);
			pos[x] = -1;
		}
	}
}

bool sjekkPoss(int x, int y) {

	for (int i = 1; i < LEN; i++) {					   //sjekker y-pos/kolonne
		if (pos[i] = y) {
			return false;
		}
	}

	int yn = y, yo = y;						   //setter øvre og nedre diagonal

	for (--x; x > 0; x--) {						  //går til venstre på brettet
		
		yn--;									//øvre og nedre diagonal sin y
		yo++;

		if (yn <= 0)				  //sikrer at det ikke går utenfor brettet
			yn = 0;
		if (yo <= 0)
			yo = 0;

		if (pos[x] == yn || pos[x] == yo)					//sjekker diagonal
			return false;
	}

	return true;
}

void display() {
	for (int i = 1; i < LEN; i++) {
		std::cout << '(' << i << ", " << pos[i] << ')' << std::endl;
	}
}