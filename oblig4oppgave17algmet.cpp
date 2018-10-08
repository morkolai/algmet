#include <iostream>
#include <ostream>
typedef char itemType;
typedef int infoType;
const infoType infoNIL = NULL;
const itemType itemMAX = 91;
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
int main() {
	return 0;
}