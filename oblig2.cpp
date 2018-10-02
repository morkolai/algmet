#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <iostream>
#include <cstring>

const int LEN = 15;

char txt[];

bool isVowel(char a);
bool check(char a[]);
void swap(char & x, char & y);
void rotateLeft(char a[], int i);
void perm(int i);
void display(char a[]);


int main() {

	char temp[LEN];
	std::cin >> temp;
	char * txt = new char[strlen(temp)+1];
	strcpy(txt, temp);
	
	perm(0);                             
										
	std::cout << '\n';
	display(txt);                        
	std::cout << "\n\n";                      
	return 0;
}

//true if a is a vowel, elseway false
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

//checks a set of rules set by the task description
bool check(char a[]) {
	for (int i = 1; i < LEN; i++) {
		if (a[i] == a[i - 1] && isVowel(a[i]) && isVowel(a[i - 1])) {
			return false;
		}
	}

	for (int i = 2; i < LEN; i++) {
		if (isVowel(a[i]) && isVowel(a[i - 1]) && isVowel(a[i - 2])) {
			return false;
		}

		if (a[i] == a[i - 1] == a[i - 2] && !isVowel(a[i]) &&
			!isVowel(a[i - 1]) && !isVowel(a[i - 2])) {
			return false;
		}
	}

	for (int i = 3; i < LEN; i++) {
		if (!isVowel(a[i]) && !isVowel(a[i - 1]) && !isVowel(a[i - 2])
			&& !isVowel(a[i - 3])) {
			return false;
		}
	}

	if (a[0] == a[1]) {
		return false;
	}

	return true;
}

void swap(char & x, char & y) {
	char temp = x;
	x = y;
	y = temp;
}

void rotateLeft(char a[], int i) {   
	int x, k;
	x = a[i];                           
	for (k = i + 1; k < LEN; k++)          
		a[k - 1] = a[k];
	a[LEN - 1] = x; 
}

void perm(int i) {
	int t;
	if (i == LEN - 1)                       
		display(txt);                    
	else {                              
		perm(i + 1);                       
											
		for (t = i + 1; t < LEN; t++) {
			swap(txt[i], txt[t]);         
										  
			perm(i + 1);                 
		}                                
		rotateLeft(txt, i);            
	}
}

void display(char a[]) {
	std::cout << "\n";
	for (int i = 0; i < LEN; i++)
		std::cout << a[i] << ' ';
}

