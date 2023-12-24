#include <stdio.h>
#include <stdlib.h>
struct node
{
	int exp;
	int coeff;
	struct node *link;
};
struct node *ptr1, *ptr, *ptr2, *ptr3, *head, *head1, *new;
int i, t1, e, c;
struct node *readpoly()
{
	head = NULL;
	printf("Enter the no.of terms of polynomial\n");
	scanf("%d", &t1);
	for (i = 1; i <= t1; i++)
	{
		new = (struct node *)malloc(sizeof(struct node));
		printf("Enter the coefficient of %d term : ", i);
		scanf("%d", &c);
		printf("Enter the exponent of %d term : ", i);
		scanf("%d", &e);
		new->exp = e;
		new->coeff = c;
		new->link = NULL;
		if (head == NULL)
		{
			head = new;
			ptr = new;
		}
		else
		{
			ptr->link = new;
			ptr = new;
		}
	}
	return head;
}
struct node *addpoly(struct node *p, struct node *q)
{
	struct node *head1 = NULL;
	ptr1 = p;
	ptr2 = q;
	ptr3 = head1;
	while (ptr1 != NULL && ptr2 != NULL)
	{
		new = (struct node *)malloc(sizeof(struct node));
		new->link = NULL;
		if (ptr1->exp == ptr2->exp)
		{
			new->coeff = ptr1->coeff + ptr2->coeff;
			new->exp = ptr1->exp;
			ptr1 = ptr1->link;
			ptr2 = ptr2->link;
		}
		else if (ptr1->exp > ptr2->exp)
		{
			new->coeff = ptr1->coeff;
			new->exp = ptr1->exp;
			ptr1 = ptr1->link;
		}
		else
		{
			new->coeff = ptr2->coeff;
			new->exp = ptr2->exp;
			ptr2 = ptr2->link;
		}
		if (head1 == NULL)
		{
			head1 = new;
			ptr3 = new;
		}
		else
		{
			ptr3->link = new;
			ptr3 = new;
		}
	}
	while (ptr1 != NULL)
	{
		new = (struct node *)malloc(sizeof(struct node));
		new->link = NULL;
		new->coeff = ptr1->coeff;
		new->exp = ptr1->exp;
		ptr1 = ptr1->link;
		ptr3->link = new;
		ptr3 = new;
	}
	while (ptr2 != NULL)
	{
		new = (struct node *)malloc(sizeof(struct node));
		new->link = NULL;
		new->coeff = ptr2->coeff;
		new->exp = ptr2->exp;
		ptr2 = ptr2->link;
		ptr3->link = new;
		ptr3 = new;
	}
	return head1;
}
void display(struct node *head1)
{
	if (head1 != NULL)
	{
		printf("Polynomial is:");
		ptr = head1;
		while (ptr->link != NULL)
		{
			if (ptr->exp == 0)
				printf("%d ", ptr->coeff);
			else if (ptr->exp == 1)
				printf("%dX ", ptr->coeff);
			else
				printf("%dX^%d", ptr->coeff, ptr->exp);
			printf(" + ");
			ptr = ptr->link;
		}
		if (ptr->exp == 0)
			printf("%d ", ptr->coeff);
		else if (ptr->exp == 1)
			printf("%dX ", ptr->coeff);
		else
			printf("%dX^%d", ptr->coeff, ptr->exp);
	}
	printf("\n");
}
void main()
{
	struct node *p, *q, *r;
	p = readpoly();
	display(p);
	q = readpoly();
	display(q);
	r = addpoly(p, q);
	printf("Resultant ");
	display(r);
}