#define SIZE 10000
struct lnode {
	struct lnode* next;
	struct lnode* newnext;
	unsigned int id;
	char side;
	char symbol[5];
	int quantity;
	double price;
};
struct A{
	unsigned int id;
	char side;
	char symbol[5];
	unsigned int quantity;
	double price;
};
struct X{
	int id;
	char symbol[5];
};
struct TC{
	int id;
	char symbol[5];
	int quantity;
};

struct R{
	char input;
	int id;
	char symbol[5];
	int quantity;
	double price;
};
struct lnode* hashtable[SIZE];
struct lnode* buy;
struct lnode* sell;


int hash(int);
void hasInit();
void printhash(FILE*);
struct lnode* searchNode(int);
int changeNode(struct TC);
int changePnode(struct R);
int hashAdd(struct A);
void hashDel(struct X);
