#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *sp = NULL;
struct node *push(struct node *, int);
struct node *pop(struct node *, int *);
void display(struct node *);
int search(struct node *, int);
int main()
{
int opt, data, found;
for (;;){
printf("\n1. Push \n2. Pop \n3. Display \n4. Search \n5. Exit");
printf("\nEnter your choice: ");
scanf("%d", &opt);
switch (opt)
{
case 1:
printf("Enter element to insert: ");
scanf("%d", &data);
sp = push(sp, data);
break;
case 2:
if (sp == NULL)
{
printf("Stack is empty!\n");
}
else
{
sp = pop(sp, &data);
printf("Popped element is: %d\n", data);
}
break;
case 3:
display(sp);
break;
case 4:
printf("Enter the element to be searched: ");
scanf("%d", &data);
found = search(sp, data);
if (found != 0)
{
printf("The element %d is present.\n", data);
}
else
{
printf("%d not found.\n", data);
}
break;
case 5:
exit(0);
default:
printf("Invalid choice!\n");
}
}
return 0;
}
/* Push an element into the stack */
struct node *push(struct node *sp, int data)
{
struct node *temp;
temp = (struct node *)malloc(sizeof(struct node));
if (temp == NULL)
{
printf("Memory allocation failed!\n");
 return sp;
}
temp->data = data;
temp->next = sp;
sp = temp;
return sp;
}
/* Pop an element from the stack */
struct node *pop(struct node *sp, int *x)
{
struct node *temp;
if (sp != NULL)
{
temp = sp;
*x = sp->data;
sp = sp->next;
free(temp);
}
 return sp;
}
/* Display the elements of the stack */
void display(struct node *sp)
{
if (sp == NULL)
{
printf("Stack is empty!\n");
return;
}
 printf("Stack elements are:\n");
while (sp != NULL)
    {
printf("%d\n", sp->data);
sp = sp->next;
    }
}
/* Search for an element in the stack */
int search(struct node *sp, int data)
{
while (sp != NULL)
 {
 if (sp->data == data)
{
return 1;
}
sp = sp->next;
}
 return 0;
}
