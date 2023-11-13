#include<stdio.h> 
#include<stdlib.h> 
struct node{ 
 struct node *prev; 
 int data; 
 struct node *link; 
}; 
struct node* start=NULL; 
void dllInsertAtBegin(int item){ 
 struct node* temp;  
 temp=(struct node *)malloc(sizeof(struct node)); 
 if(temp==NULL){ 
  printf("Insufficent Memory !!!"); 
  return ; 
 }  
 temp->data=item; 
 temp->prev=NULL; 
 temp->link=start; 
 if(start!=NULL) 
  start->prev=temp; 
 start=temp; 
} 
void dllInsertAtEnd(item){ 
 struct node *temp,*ptr;  
 temp=(struct node *)malloc(sizeof(struct node)); 
 if(temp==NULL){ 
  printf("Insufficent Memory !!!"); 
  return ; 
 }  
 temp->data=item; 
 temp->link=NULL; 
  
 if(start==NULL){ 
  temp->prev=NULL; 
  start=temp; 
 } 
 else{  
  ptr=start; 
  while(ptr->link!=NULL) 
   ptr=ptr->link; 
  ptr->link=temp; 
  temp->prev=ptr; 
 } 
} 
void dllInsertAtAny(int item,int pos){  
 
 struct node *temp,*ptr; 
 int i; 
    
 temp=(struct node *)malloc(sizeof(struct node)); 
 if(temp==NULL){ 
  printf("Insufficent Memory !!!"); 
  return ; 
 }  
 temp->data=item; 
 if(pos==1){  
  temp->prev=NULL; 
  temp->link=start; 
  if(start!=NULL) 
   start->prev=temp; 
  start=temp; 
 }else{ 
  ptr=start; 
  for(i=1;i<=pos-2 && ptr!=NULL;i++){ 
   ptr=ptr->link;  
  } 
  if(ptr==NULL){ 
   printf("Invalid Position !!!"); 
   free(temp); 
   return ; 
  } 
  temp->link=ptr->link; 
   
  if(ptr->link!=NULL) 
   ptr->link->prev=temp; 
  ptr->link=temp; 
  temp->prev=ptr; 
 } 
} 
void dllDeleteAtBegin(){ 
 struct node *ptr; 
 if(start==NULL){ 
  printf("No Node in Double Linked List to Delete !!!"); 
  return ; 
 } 
 ptr=start; 
 start=start->link; 
 if(start!=NULL) 
  start->prev=NULL;  
 free(ptr); 
} 
void dllDeleteFromEnd(){ 
  
 struct node *ptr,*prevptr; 
 /*Case #1: No Node in the Double Linked List */ 
 if(start==NULL){ 
  printf("No Node in Double Linked List to Delete !!!"); 
  return ; 
 } 
 ptr=start; 
 /* Case #2: There is exactly one node in Double Linked List*/ 
 if(ptr->link==NULL) 
  start=NULL;  
 /*Case #3:  There are more than one node */ 
 else{ 
   
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
} 
void dllDisplay(){ 
 struct node* ptr; 
 if(start==NULL){ 
  printf("No node in Double Linked List to Display"); 
  return ; 
 } 
 //ptr i want to give the value that start is having. 
 ptr=start; 
 printf("Start -> "); 
 while(ptr!=NULL){ 
  printf("%d->",ptr->data); 
  ptr=ptr->link; 
 } 
 printf("NULL"); 
} 
int main(void){ 
 
  
 int ch,item,pos; 
  
 do{ 
  printf("\n\n**Double Linked List**"); 
   
  printf("\n1.Create Double Linked List by Insertion At Begin"); 
  printf("\n2.Create Double Linked List by Insertion At End"); 
  printf("\n3.Insert at any position of Double Linked List"); 
   
  printf("\n4.Delete from Begin Position of Double Linked List"); 
  printf("\n5.Delete from End Position of Double Linked List"); 
  printf("\n6.Delete from Any Position of Double Linked List"); 
   
  printf("\n7.Display the Linked List"); 
  printf("\n8.Exit"); 
   
  printf("\nEnter your choice:"); 
  scanf("%d",&ch); 
   
  switch(ch){ 
    
   case 1: 
     printf("Enter the item to be insert:"); 
     scanf("%d",&item); 
     dllInsertAtBegin(item); 
     break; 
   case 2:
   printf("Enter the item to be insert:"); 
     scanf("%d",&item); 
     dllInsertAtEnd(item); 
     break; 
   case 3: 
        printf("Enter the item to be insert:"); 
        scanf("%d",&item);  // 100 
         
        printf("Enter position of insertion >=1:"); 
        scanf("%d",&pos); 
         
        dllInsertAtAny(item,pos); 
     break; 
   case 4: 
     dllDeleteAtBegin(); 
     break; 
   case 5: 
     dllDeleteFromEnd(); 
     break; 
   case 6: 
        printf("Enter position of deletion:"); 
        scanf("%d",&pos); 
     dllDeleteFromAny(pos); 
     break; 
   case 7: 
     dllDisplay(); 
     break; 
   case 8: 
     exit(0);  
   default: 
     printf("Wrong  Choice !!!"); 
  } 
   
 }while(1); 
}
