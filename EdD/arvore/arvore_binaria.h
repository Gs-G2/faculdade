
typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
} Node;

void inserir(Node **node, int data);
int buscar(Node *node, int data);
void in_order(Node *node);
void pre_order(Node *node);
void post_order(Node *node);
void remover(Node **node, int data);