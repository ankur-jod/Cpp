#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *link;
};
struct node* last=NULL;
void cllInsertAtBegin(int item){
 struct node* temp; 
 temp=(struct node *)malloc(sizeof(struct node));
 if(temp==NULL){
  printf("Insufficent Memory !!!");
  return ;
 } 
 temp->data=item;
 /* Node inserted as first node*/
 if(last==NULL) 
  last=temp;
 /*Node inserted as any other node*/
 else
  temp->link=last->link;
 last->link=temp;
}
void cllInsertAtEnd(item){
 struct node *temp,*ptr; 
 temp=(struct node *)malloc(sizeof(struct node));
 if(temp==NULL){
  printf("Insufficent Memory !!!");
  return ;
 } 
 temp->data=item;
 if(last==NULL)
  temp->link=temp;
  
 else{
  
  temp->link=last->link;
  last->link=temp;
 }
 last=temp;
}
void cllInsertAtAny(int item,int pos){   //item =10 pos=4

 struct node *temp,*ptr;
 int i;
   
 temp=(struct node *)malloc(sizeof(struct node));
 if(temp==NULL){
  printf("Insufficent Memory !!!");
  return ;
 } 
 temp->data=item;
 if(pos==1){ 
  /* Node inserted as first node*/
  if(last==NULL) 
   last=temp;
  /*Node inserted as any other node*/
  else
   temp->link=last->link;
  last->link=temp;
 }else{
  if(last==NULL){
   printf("Invalid position !!!");
   free(temp);
   temp=NULL;
   return ;
  } 
  ptr=last->link;
  
  for(i=1;i<=pos-2;i++){
   ptr=ptr->link;
   if(ptr==last->link){
    printf("Invalid position !!!");
    free(temp);
    temp=NULL;
    return ;
   }
  }
  temp->link=ptr->link;
  ptr->link=temp;
 }
}
void cllDeleteAtBegin(){
 struct node *ptr;
 /* If there is no node*/
 
 if(last==NULL){
  printf("No Node in Circular Linked List to Delete !!!");
  return ;
 }

 ptr=last->link;
 
 /*If there is only one node in CLL*/
 if(last==last->link)
  last=NULL; 
 else
  last->link=ptr->link; 
 free(ptr);
 ptr=NULL; 
}

/*void dllDeleteFromEnd(){
 
 struct node *ptr,*prevptr;
 /*Case #1: No Node in the Double Linked List */
/* if(start==NULL){
  printf("No Node in Double Linked List to Delete !!!");
  return ;
 }
 ptr=start;
 /* Case #2: There is exactly one node in Double Linked List*/
/* if(ptr->link==NULL)
  start=NULL; 
 /*Case #3:  There are more than one node */
/* else{
  
  while(ptr->link!=NULL){
   prevptr=ptr;
   ptr=ptr->link; 
  }
  prevptr->link=NULL;
 }
 free(ptr); 
}
void dllDeleteFromAny(int pos){
 int i;
 struct node *ptr,*prevptr;
  
 if(start==NULL){
  printf("No Node in Double Linked List to Delete");
  return;
 }
 ptr=start;
 if(pos==1){
  start=start->link;
  if(start!=NULL)
   start->prev=NULL;
 }else{
  for(i=1;i<=pos-1;i++){
   prevptr=ptr;
   ptr=ptr->link;
   if(ptr==NULL){
    printf("Invalid Position !!!");
    return ;
   }
  } 
  prevptr->link=ptr->link;
  
  if(ptr->link!=NULL)
   ptr->link->prev=prevptr; 
 }
 free(ptr);
 ptr=NULL;
}*/
void cllDisplay(){
 struct node* ptr;
 if(last==NULL){
  printf("No node in Circular Linked List to Display");
  return ;
 }
 //ptr i want to give the value that start is having.
 ptr=last->link;
 while(ptr!=last){
  printf("%d->",ptr->data);
  ptr=ptr->link;
 }
 printf("%d",ptr->data);
}
int main(void){

 
 int ch,item,pos;
 
 do{
  printf("\n\n**Circular Linked List**");
  
  printf("\n1.Create Circular Linked List by Insertion At Begin");
  printf("\n2.Create Circular Linked List by Insertion At End");
  printf("\n3.Insert at any position of Circular Linked List");
  
  printf("\n4.Delete from Begin Position of Circular Linked List");
 /* printf("\n5.Delete from End Position of Double Linked List");
  printf("\n6.Delete from Any Position of Double Linked List");*/
  
  printf("\n7.Display the Linked List");
  printf("\n8.Exit");
  
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  
  switch(ch){
   
   case 1:
     printf("Enter the item to be insert:");
     scanf("%d",&item);
     cllInsertAtBegin(item);
     break;
   case 2:
     printf("Enter the item to be insert:");
     scanf("%d",&item);
     cllInsertAtEnd(item);
     break;
   case 3:
        printf("Enter the item to be insert:");
        scanf("%d",&item);  // 100
        
        printf("Enter position of insertion >=1:");
        scanf("%d",&pos);
        
        cllInsertAtAny(item,pos);
     break;
   case 4:
     cllDeleteAtBegin();
     break;
   /*case 5:
     dllDeleteFromEnd();
     break;
   case 6:
        printf("Enter position of deletion:");
        scanf("%d",&pos);
     dllDeleteFromAny(pos);*/
     break;
    
   case 7:
     cllDisplay();
     break;
   case 8:
     exit(0); 
   default:
     printf("Wrong  Choice !!!");
  }
  
 }while(1);
}