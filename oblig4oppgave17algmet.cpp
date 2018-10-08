#include <iostream>
#include <fstream>
typedef char itemType;
typedef int infoType;
const infoType infoNIL = NULL;
const itemType itemMAX = 91;
const itemType OPPGAVE17[] = "OPPG_17.TXT";
class Dict
{
private:
	struct node
	{
		itemType key; infoType info;
		struct node *next;
		node(itemType k, infoType i, struct node *n)
		{
			key = k; info = i; next = n;
		};
	};
	struct node *head, *z;
public:
	Dict(int max)
	{
		z = new node(itemMAX, infoNIL, 0);
		head = new node(0, 0, z);
	}
	//~Dict();
	infoType search(itemType v);
	void insert(itemType v, infoType info);
};

infoType Dict::search(itemType v) // Sorted list
{
	struct node *t = head;
	while (v > t->key) t = t->next;
	return (v = t->key) ? t->info : z->info;
}

void Dict::insert(itemType v, infoType info)
{
	struct node *x, *t = head;
	while (v > t->next->key) t = t->next;
	x = new node(v, info, t->next);
	t->next = x;
}

// leser inn 2 og 2 bokstaver fra fil med format AA BB CC ...
void lesFraFil() {
	itemType ord[1];
	std::ifstream inn(OPPGAVE17);
	if (inn) {
		while (inn >> ord) {
			LeggTilToBokstaverITraer(*ord);			// legger til bokstavduoen
		}
	}
	else { // Feilmelding
		std::cout << "Finner ikke filen " << OPPGAVE17 << ". Husk at du trenger filen for aa kjore programmet.\n";
	}
}

void LeggTilToBokstaverITraer(itemType bokstaver) {

}

int main() {

	return 0;
}