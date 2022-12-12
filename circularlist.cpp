//Circular Linked List
#include <iostream>
using namespace std;
class cllnode
{
	public:
  int data;
  cllnode* next;
  
  cllnode (int a)
  {
  	data=a;
  	next=NULL;
  }	
    friend class cllist;	
};

 class cllist
{
	public:
	cllnode* tail;
	cllist()
	{
		tail=NULL;
	}
	
	bool isEmpty()
	{
		return (tail==NULL);
	}
	
	void addatstart(int x)
	{
		if (isEmpty())
		{
			tail=new cllnode(x);
			tail->next=tail;
		}
		else
		{
			cllnode* newnode=new cllnode(x);
			newnode->next=tail->next;
			tail->next=newnode;
		}
	}
	
	void addatend(int x)
	{
		if (isEmpty())
		{
			tail=new cllnode(x);
			tail->next=tail;
		}
		else
		{
			cllnode* newnode=new cllnode(x);
			newnode->next=tail->next;
			tail->next=newnode;
			tail=newnode;
		}
	}
	
	void addatposition(int x,int i)
	{
		if (isEmpty())
		{
			tail=new cllnode(x);
			tail->next=tail;
		}
		
	     if(i==1)
		{
		   addatstart(x);
		   return;	
		}
		else
		{
			cllnode* newnode=new cllnode(x);
			cllnode*temp =tail->next;
		//	cllnode*temp1=tail->next;
			
			int a=1;
			while(a<i-1) 
			{
			   temp=temp->next;
			   a++;
			}
			newnode->next=temp->next;
			temp->next=newnode; 	
		}
	}
	
	void deleteatstart()
	{
		if(isEmpty())
		{
			cout<<"Cannot delete the empty list"<<endl;
		}
		
		if(tail->next==tail)
		{
			delete tail;
		}
		
		else
		{
			cllnode* temp=tail->next;
			tail->next=temp->next;
			temp->next=NULL;
			delete temp;
		}
	}
	
	void deleteatend()
	{
		if(isEmpty())
		{
			cout<<"Cannot delete the empty list"<<endl;
		}
		if(tail->next==tail)
		{
			delete tail;
		}
		else
		{
			cllnode* temp=tail->next;
			cllnode* temp1=tail;
			while(temp->next !=tail)
			{
				temp=temp->next;
			}
			temp->next=temp1->next;
			temp1->next=NULL;
			tail=temp;
			delete temp1;
		}
	}
	
	void deleteatposition(int i)
	{
		if(isEmpty())
		{
			cout<<"Cannot delete the empty list"<<endl;
		}
		else if(tail->next==tail)
		{
			delete tail;
		}
		else
		{
		    cllnode* temp=tail->next;
		    
			int a=1;
			while(a < i-1)
			{
				temp=temp->next;
				a++;
			}
			cllnode* temp1=temp->next;
			temp->next=temp1->next;
			temp1->next=NULL;
			delete temp1;
		}
	}
	
	void search(int key)
	{
		if(isEmpty())
		{
			cout<<"Empty list"<<endl;
		}
		else
		{
			
			cllnode* temp1=tail->next;
			while( temp1!=tail)
			{
		    	if(temp1->data==key)
					{
					   cout<<"Found at position: "<<temp1<<endl;
					   break;	
					}
			
				
					temp1=temp1->next;
				     
			}
			if(temp1==tail && temp1->data ==key)
			{
				cout<<"Found at position: "<<temp1<< endl;
			}
			if(temp1==tail && temp1->data !=key)
			{
				cout<<"Not found"<<endl;
			}	
		}
	}
	 void concatenate(cllist obj1,cllist obj2)
	 {
	     cllnode* t1=obj1.tail;
	     cllnode* t2=obj2.tail;
	     
	     cllnode* temp=t1->next;
	     t1->next=t2->next;
	     t2->next=temp;
	     
	     tail=t2;
	 }
	 
	 void reverse()
	 {
	 	cllnode* temp=tail->next;
		cllnode* previous=tail;
		cllnode* current;
		
	while(current != tail->next )
		{
			current=temp->next;
			temp->next=previous;
			previous=temp;
			temp=current;
		 } 
		 
		  tail=current;
	 }
	void display()
	{
		cllnode* temp= tail;
		
		if(temp->next==temp)
		{
		    cout<<temp->data;
		    return;
		
		}
		
		cllnode* temp2=tail->next;
		while(temp2 != temp)
		{
			cout<<temp2->data<<" ";
			temp2=temp2->next;
		}
		if(temp2==tail)
		{
			cout<<temp2->data<<endl;
		}
		cout<<endl;
	}	
};
int main()
{
	int choice ,choice1,choice2,i,e,x,n1,n2;
	cllist ob,ob1,ob2;
	char c='y',ch1='y',ch2='y';
	do
	{
		cout<<"circular linked list operations "<<endl;
		cout<<"1:add"<<endl<<"2:delete"<<endl<<"3:rev"<<endl<<"4:concatinATE"<<endl<<"5:exit"<<endl<<"enter your choice";
		cin>>choice;
		switch(choice)
		{
			case 1 :
				do{
					cout<<"1:add at begin"<<endl<<"2:add at end"<<endl<<"3:add at pos i"<<endl<<"4:exit"<<endl;
					cout<<"enter your choice";
					cin>>choice1;
					switch(choice1)
					{
						case 1 :
							ch1='y';
							cout<<"enter element to add :";
							cin>>x;
							ob.addatstart(x);
							ob.display();
							break;
						case 2 :
							ch1='y';
							cout<<"enter element to add :";
							cin>>x;
							ob.addatend(x);
							ob.display();
							break;
						case 3 :
							ch1='y';
							cout<<"enter element to add :";
							cin>>x;
							cout<<"enter i :";
							cin>>i;
							ob.addatposition(x,i);
							ob.display();
							break;
						case 4 :
							ch1='n';
							break;
						default :
							cout<<"you have entered wrong choice"<<endl;
						
					}
				}
				while(ch1=='y');
				break;
			case 2 :
				do{
					cout<<"1:delete at begin"<<endl<<"2:delete at end"<<endl<<"3:delete at pos i"<<endl<<"4:exit"<<endl;
					cout<<"enter your choice";
					cin>>choice2;
					switch(choice2)
					{
						case 1 :
							ch2='y';
							ob.deleteatstart();
							ob.display();
							break;
						case 2 :
							ch2='y';
							ob.deleteatend();
							ob.display();
							break;
						case 3 :
							ch2='y';
							cout<<"enter i :";
							cin>>i;
							ob.deleteatposition(i);
							ob.display();
							break;
						case 4 :
							ch2='n';
							break;
						default :
							cout<<"you have entered wrong choice"<<endl;
						
					}
				}
				while(ch2=='y');
				break;
			case 3 :
				
				ob.reverse();
				ob.display();
				break;
			case 4 :
				cout<<"no of elements in list 1";
				cin>>n1;
				cout<<"no of elements in list 2";
				cin>>n2;
				cout<<"enter list 1"<<endl;
				for(int j=0;j<n1;j++)
				{
					cin>>x;
					ob1.addatstart(x);
				}
				ob1.reverse();
				cout<<"first list";
				ob1.display();
				cout<<"enter list 2"<<endl;
				for(int j=0;j<n2;j++)
				{
					cin>>x;
					ob2.addatstart(x);
				}
				ob2.reverse();
				cout<<"second list";
				ob2.display();
				ob.concatenate(ob1,ob2);
				ob.display();
				break;
			case 5 :
				c='n';
				break;	
			default :
				cout<<"wrong choice entred";
		}
	}
	while(c=='y');

   return 0;
}
