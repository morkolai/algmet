#include <iostream>

bool isVowel(char a);

int main() {



	return 0;
}


bool isVowel(char a) {
	a = toupper(a);
	char vowels[] = "AEIOU";
	for (int i = 0; i < 5; i++) {
		if (a == vowels[i]) {
			return true;
		}
	}
	return false;
}