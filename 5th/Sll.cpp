#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Node{
public:
		int data;
		Node* next;

		Node(int x){
		this->data=x;
		this->next=NULL;
       }
};
class li{
public:
Node* head;
li(){
head=NULL;
}
void iab(int k){
	Node* temp=new Node(k);
    temp->next=head;
	head=temp;
	
	}
void iae(int a){
	Node* temp=new Node(a);
   if(head==NULL){
	head=temp;
	return;
}
	Node* curr=head;
	while(curr->next!=NULL)
	curr=curr->next;
	curr->next=temp;

	}

void display(){
	Node* temp=head;
	int cnt=0;
	while(temp!=NULL)
	{
	cout<<temp->data<<" ";
	temp=temp->next;
	cnt++;
	}
	cout<<endl;
	cout<<"no of element in the linked list:"<<cnt<<endl;
}
void del(int x){
	
	
	if(head->data==x){
	cout<<head->data<<"is removed from the linkedlist"<<endl;
	head=head->next;
	return;
	}
	Node* temp=head;
	while(temp->next->data!=x)
	temp=temp->next;
	Node* curr=temp->next;
	temp->next=temp->next->next;
	
	cout<<curr->data<<"is removed from the linkedlist"<<endl;
	delete(curr);
	
}

	
};

int main(){
li l;
int ch;
int fl=1;
while(fl){
	cout<<"\t\t press 1 for insert:"<<endl;
	cout<<"\t\t press 2 for display:"<<endl;
    cout<<"\t\t press 3 for delete:"<<endl;	
	cout<<"\t\t press 4 for exit:"<<endl;
	cin>>ch;
	switch(ch){
		case 1:
				cout<<"\t\t press 1 for insert at beginning:"<<endl;
				cout<<"\t\t press 2 for insert at end:"<<endl;
					int k;
					cin>>k;
				cout<<"enter the data to be entered:"<<endl;
				int x;
				cin>>x;
				if(k==1)
				l.iab(x);
				else
				l.iae(x);
				break;
		case 2:
				l.display();
				break;
		case 3:	
				cout<<"enter the element to be delete from the list:"<<endl;
				int t;
				cin>>t;
				l.del(t);
				break;
		case 4:
				fl=0;
				break;
		default:
				cout<<"press any valid key!!"<<endl;
	}
}
return 0;
}
