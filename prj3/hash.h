#define SIZE 10000
struct lnode {
	struct lnode* next;
	struct lnode* newnext;
	long id;
	char side;
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
int searchNode(int);
int changeNode(int, int);
int changePnode(int, int, double);
int hashAdd(int, char, char*, int, double);
void hashDel(int);
