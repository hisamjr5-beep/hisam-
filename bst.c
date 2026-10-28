#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *lchild,*rchild;
};
void main()
{
int ch,data;
struct node *search(struct node*,int);
struct node *insert(struct node*,int);
void inorder(struct node*);
struct node *delete(struct node*,int);
//null BST
struct node *root=0;
struct node *temp;
while (1)
    {
        printf("\n1.Insert\n2.Search\n3.Inorder\n4.Delete\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Enter data to search: ");
                scanf("%d", &data);
                temp = search(root, data);

                if (temp != 0)
                    printf("Data found");
                else
                    printf("Data not found");
                break;
           case 3:
                printf("Inorder: ");
                inorder(root);
                break;

          case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;

          case 5:
                exit(0);
   }
   }
}
//function to search a node
struct node *search(struct node *root,int data)
{
 while(root!=0 && root->data!=data)
 { 
  if(data<root->data)
   root=root->lchild;
  else
   root=root->rchild;
 }
return root;
}
//function to insert an item
struct node *insert(struct node *root, int data)
{
 struct node *t, *par = 0, *t1;
 t = (struct node*)malloc(sizeof(struct node));
 t->data = data;
 t->lchild = t->rchild = 0;
 if (root == 0)
 {
  root = t;
 }
  else if (search(root,data) != NULL)
  {
   printf("%d is Duplicate data",data);
  }
  else
  {
   t1 = root;
   while (t1 != 0)
   {
    par = t1;
    if (data < t1->data)
    t1 = t1->lchild;
    else
    t1 = t1->rchild;
   }
   if (data < par->data)
     par->lchild = t;
   else
     par->rchild = t;
 }
return root;
}
//function to traverse BST in inorder
void inorder(struct node *root)
{
if(root!=0)
{
 inorder(root->lchild);
 printf("%d,",root->data);
 inorder(root->rchild);
}
}
//function to delete a node
struct node *delete(struct node *root,int data)
{
 struct node *t=root,*par=0 ,*suc,*sucpar;
 while(t!=0 && t->data!=data)
 {
  par=t;
  if(data<t->data)
   t=t->lchild;
  else
   t=t->rchild;
  }
  if(t==0)
   printf("%d not found",data);
   //case of leaf node
  else
  {
   if(t->lchild==0 &&t->rchild ==0)
  {
  if(par==0)
   root=0;
  else if(data<par->data)
    par->lchild=0;
  else
   par->rchild=0;
 }
 //case of one child
else if(t->lchild==0 || t->rchild==0)
{
 if(par==0)
   root=root->lchild==0?root->rchild:root->lchild;
 else if(data<par->data)
   par->lchild=t->lchild==0?t->rchild:t->lchild;
 else
    par->rchild=t->lchild==0?t->rchild:t->lchild;
}
//case of two child
else
{
  sucpar=t;
  suc=t->rchild;
//finding inorder successor
  while(suc->lchild!=0)
  {
   sucpar=suc;
   suc=suc->lchild;
  }
 t->data=suc->data;
//delete inorder successor
if(suc->data<sucpar->data)
{
 sucpar->lchild=suc->rchild;
 }
else
 sucpar->rchild=suc->rchild;
t=suc;
}
free(t);
}
return root;
}


 
 
  
   
