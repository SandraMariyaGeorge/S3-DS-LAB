#include <stdio.h>
#include <stdlib.h>
#define max 50
void bfs_traversal(int v);
void dfs_traversal(int v);
void enqueue(int a);
int dequeue();
int search(int visit[],int u);
void insert(int visit[],int u);
int pop();
void push(int data);
struct node
{
    int data;
    struct node *link;
};
struct node *head[100], *new, *ptr;
int startNode,n,i,visit[max],front,rear,qs[max],top,b;
int main()
{
    int d,ch;
    printf("Enter number of nodes\n");
    scanf("%d", &n);
    int i,j,c;
    for (i = 1; i <= n; i++)
    {
        head[i] = (struct node *)malloc(sizeof(struct node));
        head[i]->data = i;
        head[i]->link = NULL;
        ptr = head[i];
        printf("enter no of neighbours of %d: \n",i);
        scanf("%d",&d);
        printf("Enter all adjacent nodes to vertex %d:\n",i);
        for(j=0;j<d;j++)
        {
            scanf("%d", &c);    
            new = (struct node *)malloc(sizeof(struct node));
            new->data = c;
            new->link = NULL;
            ptr->link = new;
            ptr = new;
        }
    }
    printf("The Adjacency list is:\n");
    for(i = 1; i <= n; i++)
    {
        ptr=head[i];
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
    }
    do
    {
        printf("Enter your choice: \n1--BFS\t\t2--DFS\t\t3--EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                front=rear=-1;
                b=1;
                for(i=0;i<max;i++)
                {
                    visit[i]=0;
                    qs[i]=0;
                }
                printf("\nEnter the start vertex\n");
                scanf("%d", &startNode);
                bfs_traversal(startNode);
                break;
            case 2:
                top=-1;
                b=1;
                for(i=0;i<max;i++)
                {
                    visit[i]=0;
                    qs[i]=0;
                }
                printf("\nEnter the start vertex\n");
                scanf("%d", &startNode);
                dfs_traversal(startNode);
                break;
            case 3:break;
            default:printf("Enter a valid Option\n");
        }
    } while (ch!=3);
}

void bfs_traversal(int v)
{
    int u,sc;
    if (head[v]==NULL)
    {
        printf("Graph is empty\n");
    }
    else
    {
        u=v;
        enqueue(u);
        do
        {
            u=dequeue();
            sc=search(visit,u);
            if(sc==0)//u not in visit
            {
                insert(visit,u);
                ptr=head[u]->link;
                while(ptr!=NULL)
                {
                    enqueue(ptr->data);
                    ptr=ptr->link;
                }
            }
        }while(front!=-1);
    }
    printf("The BFS Traversal is:\n");
    for(i=1;i<=n;i++)
    {
        printf("%d ",visit[i]);
    }
    printf("\n");
}

void enqueue(int a)
{
     if (rear == max - 1)
        return;
    if (front == -1)
        ++front;
    qs[++rear] = a;
}

int dequeue()
{
    if (front==-1)
        return -1;
    int deleted = qs[front];
    if (rear == front)
        front = rear = -1;
    else
        front++;
    return deleted;
}

int search(int visit[],int u)
{
    for(i=1;i<=n;i++)
    {
        if(visit[i]==u)
        {
            return 1;
        }
    }
    return 0;
}

void insert(int visit[],int u)
{
    visit[b]=u;
    b++;
}

void dfs_traversal(int v)
{
    int u,sc;
    if (head==NULL)
    {
        printf("Graph is empty\n");
    }
    else
    {
        u=v;
        push(u);
        while(top!=-1)
        {
            u=pop();
            sc=search(visit,u);
            if(sc==0)//u not in visit
            {
                insert(visit,u);
                ptr=head[u]->link;
                while(ptr!=NULL)
                {
                    push(ptr->data);
                    ptr=ptr->link;
                }
            }
        }
    }
    printf("The DFS Traversal is:\n");
    for(i=1;i<=n;i++)
    {
        printf("%d ",visit[i]);
    }
    printf("\n");
}
int pop()
{
    if (top==-1)
        return -1;
    return qs[top--];
}
void push(int data)
{
    if (top == max - 1)
        return;
    qs[++top] = data;
}