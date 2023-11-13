#include<stdio.h> 
#include<stdlib.h> 
struct node{ 
 int data; 
 struct node* link; 
}; 
struct node* start=NULL; 
void sllInsertAtBegin(int item){ 
 struct node* temp;  
 temp=(struct node *)malloc(sizeof(struct node)); 
 if(temp==NULL){ 
  printf("Insufficent Memory !!!"); 
  return ; 
 }  
 temp->data=item; 
 temp->link=start; 
 start=temp; 
} 
void sllInsertAtEnd(item){ 
 struct node *temp,*ptr;  
 temp=(struct node *)malloc(sizeof(struct node)); 
 if(temp==NULL){ 
  printf("Insufficent Memory !!!"); 
  return ; 
 }  
 temp->data=item; 
 temp->link=NULL; 
  
 if(start==NULL) 
  start=temp; 
 else{ 
   
  ptr=start; 
  while(ptr->link!=NULL) 
   ptr=ptr->link; 
  ptr->link=temp; 
 } 
} 
void sllInsertAtAny(int item,int pos){  
 
 struct node *temp,*ptr; 
 int i; 
    
 temp=(struct node *)malloc(sizeof(struct node)); 
 if(temp==NULL){ 
  printf("Insufficent Memory !!!"); 
  return ; 
 }  
 temp->data=item; 
  
 if(pos==1){  
  temp->link=start; 
  start=temp;  
 } 
 else{ 
  ptr=start; 
  for(i=1;i<=pos-2 && ptr!=NULL;i++){ 
   ptr=ptr->link;   
  } 
  if(ptr==NULL){ 
   printf("Invalid Position !!!"); 
   free(temp); 
   return;  
  } 
  temp->link=ptr->link; 
  ptr->link=temp;  
 } 
} 
void sllDeleteAtBegin(){ 
 struct node *ptr; 
 if(start==NULL){ 
  printf("No Node in Single Linked List to Delete !!!"); 
  return ; 
 } 
 ptr=start; 
 start=start->link; 
 free(ptr); 
} 
void sllDeleteFromEnd(){ 
  
 struct node *ptr,*prevptr; 
 /*Case #1: No Node in the Single Linked List */ 
 if(start==NULL){ 
  printf("No Node in Single Linked List to Delete !!!"); 
  return ; 
 } 
 ptr=start; 
 /* Case #2: There is exactly one node in Single Linked List*/ 
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
void sllDisplay(){ 
 struct node* ptr; 
 if(start==NULL){ 
  printf("No node in Single Linked List to Display"); 
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
  printf("\n\n**Single Linked List**"); 
   
  printf("\n1.Create Single Linked List by Insertion At Begin"); 
  printf("\n2.Create Single Linked List by Insertion At End"); 
  printf("\n3.Insert at any position of Single Linked List"); 
  printf("\n4.Delete from Begin Position of Single Linked List"); 
  printf("\n5.Delete from End Position of Single Linked List"); 
   
  printf("\n6.Display the Linked List"); 
  printf("\n7.Exit"); 
   
  printf("\nEnter your choice:"); 
  scanf("%d",&ch); 
   
  switch(ch){ 
    
   case 1: 
     printf("Enter the item to be insert:"); 
     scanf("%d",&item); 
     sllInsertAtBegin(item); 
     break; 
   case 2: 
     printf("Enter the item to be insert:"); 
     scanf("%d",&item); 
     sllInsertAtEnd(item); 
     break; 
   case 3: 
        printf("Enter the item to be insert:"); 
        scanf("%d",&item);  // 100 
         
        printf("Enter position of insertion >=1:"); 
        scanf("%d",&pos); 
         
        sllInsertAtAny(item,pos); 
     break; 
   case 4: 
     sllDeleteAtBegin(); 
     break; 
   case 5: 
     sllDeleteFromEnd(); 
     break; 
   case 6: 
     sllDisplay(); 
     break; 
   case 7: 
     break; 
      
   default: 
     printf("Wrong  Choice !!!"); 
  } 
   
 }while(1); 
}