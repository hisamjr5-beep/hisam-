#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};
struct node*sp=NULL;
struct node*push(struct node*,int);
struct node*pop(struct node*,int*);
void display(struct node*);
int search(struct node*,int);
int main()
{
int opt,data,found;
for(;;)
{
printf("\n1.push\n2.pop\n3.display\n4.search\n5.exit\n");
printf("enter your choice: ");
scanf("%d;&opt");
switch(opt)
{
case 1:
printf("enter elements to insert: ");
scanf("%d",&data);
sp=push(sp,data);
break;
case 2:
if(sp==NULL)
{
printf("stack is empty !\n")
}
else
{
sp=pop(sp,&data);
printf("popped element is:%d\n",data);
}
break;
case 3:
display(sp);
break;
case 4:
printf("enter the element to be searched: ");
scanf("%d",&data);
if(found!=0)
printf("the element is found at position %d\n"data.found);
else
printf("not found\n");
break;
case 5:
exit(0);
break;
}}
return 0;
}
struct node*push(struct node*sp,int data)
{
struct node*temp;
temp=(struct node*)malloc(size of(struct node));
temp->data=data;
temp->next=sp;
sp=temp;
return sp;
}
struct node*pop(srruct node*sp,int*x)
{
struct node*temp;
if(sp!=NULL)
{
temp=-sp;
*x=sp->data
sp=sp->next
free(temp);
}
return sp;
}
void display (struct node*sp)
{
if (sp==NULL)
{
printf("stack is empty:\n");
return;
}
printf("stack elements are:\n");
while(sp!=NULL)
{
printf("%d\n",sp->data);
sp=sp->next;
}}
int search(struct node*sp,int data)
{
int pos=1;
while (sp!=NULL)
{
if(sp->data==data)
return pos;
sp=sp->next;
pos++;}
return 0;
}		
