#include <iostream>
#include <fstream>
typedef char itemType;
typedef int infoType;

// GLOBALE VARIABLE
const infoType infoNIL = NULL;
const itemType itemMAX = 91;
const itemType OPPGAVE17[] = "OPPG_17.TXT";

// Roten av tre1
Dict Tre(itemMAX);

// KLASSE
class Dict
{
private:
	
	struct node
	{
		itemType key; infoType info;
		struct node *next;
		union TreAnt {                 //  UNION:
			int ant;                             //    Antall to-bokstavs-forekomster
			struct node* tre;                           //    ELLER peker til hodet i 2.treet.
		};
		node(itemType k, infoType i, struct node *n,int tretype)
		{
			key = k; info = i; next = n;
			TreAnt tA;
			if (tretype == 1)  tA.tre = new node(itemMAX, 0, 0, 2);  //  Nytt 2.tre.
			else           tA.ant = 0;         //    Initierer antall kombinasjoner.
		};
	};
	struct node *head, *z;
	
public:
	Dict(int max)
	{
		z = new node(itemMAX, infoNIL, 0,1);
		head = new node(0, 0, z,1);
		
	}
	//~Dict();
	infoType search(itemType v);
	void insert(itemType v, infoType info,int tretype);
};
 // MEDLEMSFUNKSJONER
infoType Dict::search(itemType v) // Sorted list
{
	struct node *t = head;
	while (v > t->key) t = t->next;
	return (v = t->key) ? t->info : z->info;
}

void Dict::insert(itemType v, infoType info,int tretype)
{
	struct node *x, *t = head;
	while (v > t->next->key) t = t->next;
	x = new node(v, info, t->next, tretype);
	t->next = x;
}

// DEKLARASJON AV FUNKSJONER:
void lesFraFil();
void LeggTilToBokstaverITre(itemType bokstaver);
// leser inn 2 og 2 bokstaver fra fil med format AA BB CC ...
void lesFraFil() {
	itemType ord[1];
	std::ifstream inn(OPPGAVE17);
	if (inn) {
		while (inn >> ord) {
			LeggTilToBokstaverITre(*ord);			// legger til bokstavduoen
		}
	}
	else { // Feilmelding
		std::cout << "Finner ikke filen " << OPPGAVE17 << ". Husk at du trenger filen for aa kjore programmet.\n";
	}
}

void LeggTilToBokstaverITre(itemType bokstaver) {
	// TODO:søke etter bokstav 1 i 1.tre
			// TODO: Hvis funnet søk etter bokstav 2 i 2.tre
				// TODO: Hvis funnet ++ant
				// TODO: Hvis ikke funnet insert i 2.tre
			// TODO: Hvis ikke funnet insert bokstav 1 i 1.tre
				// TODO: Søk etter bokstav 2 i 2.tre
					// TODO: Hvis funnet ++ant
					// TODO: Hvis ikke funnet insert i 2.tre
}

int main() {
	lesFraFil();
	return 0;
}