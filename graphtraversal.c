#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// Structure to represent vertex and edge
struct node
{
    int data;
    int status;
    struct node *next, *point;
};

// Structure to represent topological sort
struct topsort
{
    int n;
    struct topsort *next;
};

// Queue declaration
struct node *q[10];            //to maintain queue
int front = 0, rear = 0;      //queue handling points
struct node *g = 0;          //to store graph
struct topsort *tsort = 0;  //to store topological sort order

// Function to add a vertex
void addvertex(int n)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = n;
    t->status=0;
    t->point = 0;
    t->next = g;
    g = t;
}

// Function to find vertex node address
struct node *find(int n)
{
    struct node *t = g;
    while (t != 0 && t->data != n)
      t = t->next;
    return t;
}

// Function to add an edge
void addedge(int u, int v)
{
    struct node *v1, *v2, *t;
    v1 = find(u);
    v2 = find(v);
    t = (struct node *)malloc(sizeof(struct node));
    t->next = v1->point;
    v1->point = t;
    t->point = v2;
    return;
}

// Function to print a graph
void printgraph()
{
    struct node *t1, *t2, *t3;
    printf("\nVertex\tEdge List\n");
    t1 = g;
    while (t1 != 0)
    {
        printf("\n%d\t", t1->data);
        t2 = t1->point;
        while (t2 != 0)
        {
            t3 = t2->point;
            printf("%d ", t3->data);
            t2 = t2->next;
        }
        t1 = t1->next;
    }
}

// Function to insert nodes in topological order list
void toposorting(int n)
{
    struct topsort *z =(struct topsort *)malloc(sizeof(struct topsort));
    z->n = n;
    z->next = tsort;
    tsort = z;
}

// Printing topological order list
void topsortout()
{
    while (tsort != 0)
    {
        printf("%d ", tsort->n);
        tsort = tsort->next;
    }
}

// DFS visit
void dfs_visit(struct node *u)
{
    struct node *t, *t1;
    u->status = 1;         //visit vertex
    printf("%d ", u->data);
    t = u->point;
    while (t != 0)
    {
        t1 = t->point;
        if (t1->status == 0)  //if not visited
            dfs_visit(t1);
        t = t->next;
    }
    toposorting(u->data);  //store the node topological sort list
    return;
}

// DFS search
void dfs(struct node *g1)
{
    struct node *t = g;
    while (t != 0)
    {
        t->status = 0;   //set as not visited
        t = t->next;
    }
    dfs_visit(g1);
}

// Enqueue operation
void enqueue(struct node *s)
{
    int r1=rear;
    r1 = (r1 + 1) % SIZE;
    if (front == r1)
    {
        printf("Q full");
        exit(1);
    }
    rear = r1;
    q[rear] = s;
}

// Check whether queue is empty
int emptyq()
{
    if (front == rear)
        return 1;
    else
        return 0;
}

// Dequeue operation
struct node *dequeue()
{
    if (emptyq())
    {
        printf("empty Q");
        exit(2);
    }
    front = (front + 1) % SIZE;
    return q[front];
}

// BFS
void bfs(struct node *s)
{
    struct node *t=g, *t1, *u;
    while (t != 0)
    {
        t->status = 0;    //set all vertices as not visited
        t = t->next;
    }
    s->status = 1;       //visit start vertex
    printf("%d ", s->data);
    enqueue(s);
    while (!emptyq())
    {
        u = dequeue();
        t = u->point;
        while (t != 0)
        {
            t1 = t->point;
            if (t1->status == 0)
            {
                printf("%d ", t1->data);
                t1->status = 1;
                enqueue(t1);
            }
            t = t->next;
        }
    }
}

// Main function to demonstrate graph search and topological sort
int main()
{
    addvertex(1);
    addvertex(2);
    addvertex(3);
    addvertex(4);
    addvertex(5);

    addedge(1, 2);
    addedge(1, 4);
    addedge(2, 3);
    addedge(2, 4);
    addedge(4, 3);
    addedge(4, 5);

    printf("\nThe graph is:\n");
    printgraph();
    printf("\n\nDFS traverse:\n");
    dfs(find(1));
    printf("\n\nBFS traverse:\n");
    bfs(find(1));
    printf("\n\nTopological sort order is:\n");
    topsortout();
    return 0;
}
 

