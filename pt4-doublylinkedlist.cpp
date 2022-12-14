


#include <iostream>
using namespace std;
class dllnode
{
	public:
   int data;
   dllnode* previous;
   dllnode* next;
   dllnode( int x)
   {
   	data=x;
   	previous=NULL;
   	next=NULL;
  }	
  friend class dllist;
};
class dllist
{
	public:
	dllnode* head;
	dllnode* tail;
	 
	dllist()
	{
		head=tail=0;
	}
	
	
	bool isEmpty()
	{
		return(head==NULL);	
	}
	
    void addatstart(int x)
    {
    	
    	if(isEmpty())
    	{
    		head=tail=new dllnode(x);
				
		}
		else
		{
			dllnode* newnode=new dllnode(x);
		    newnode->next=head;
		    head->previous=newnode;
		    head=newnode;
		     
		}
    	
	}
	
	void addatend(int x)
	{
		if(isEmpty())
		{
			head=tail=new dllnode(x);
		}
		else
		{
			dllnode* newnode=new dllnode(x);
		     tail->next=newnode;
		     newnode->previous=tail;
		     tail=newnode;
	}
}
	void addatposition(int x,int i)
	{
		if(i==1)
		{
			addatstart(x);
			return;
		}
		else
		{
			dllnode* newnode=new dllnode(x);
			dllnode* temp1=head;
			dllnode* temp2=head;
			int a=1;
			while(a<i)
			{
		     	temp1=temp1->next;
		     	temp2=temp1->previous;
		     	a++;
			}
			newnode->next=temp1;
			newnode->previous=temp2;
			temp1->previous=newnode;
			temp2->next=newnode;	
		}
		
	}
	
	void deleteatstart()
	{
		if(isEmpty())
		{
			cout<<"!!!!!List is empty ,cannot delete!!!!"<<endl;
		}
		else
		{
		      dllnode*temp=head;
		      head=head->next;
		      head->previous=NULL;
		      delete temp;
		}
	}
  
    void deleteatend()
    {
    	if(isEmpty())
    	{
    		cout<<"!!!!!!LIST IS EMPTY CANNOT DELETE!!!!!!!"<<endl;
		}
		else
		{
			dllnode* temp=tail;
			tail=tail->previous;
			tail->next=NULL;
			delete (temp);
		}
	}
	
	void deleteatposition(int i)
	{
		if(i==1)
		{
			deleteatstart();
			return;
		}
		
		else
		{
			dllnode* temp=head;
			int a=1;
			while(a<i)
			{
				temp=temp->next;
				a++;
			}
			dllnode* temp1=temp->previous;
			dllnode* temp2=temp->next;
			temp1->next=temp2;
			temp2->previous=temp1;
			delete (temp);
		}
		
		
	}
	
	void reverse()
{
	dllnode* temp=head;
	  while	(temp!=NULL)
	  {
	  	dllnode* t1= temp->next;
	  	temp->next=temp->previous;
	  	temp->previous=t1;
	  	temp=t1;	
	  }
	   dllnode*temp1=head;
	   head=tail;
	   tail=temp1;
}

    void search(int key)
    {
         dllnode* temp=head;
		 while(temp != NULL)
		 {
		 	if(key==temp->data)
		 	{
		 		cout<<"Found at position:  "<<temp<<endl;
		 		break;
			}
			
		      temp=temp->next;	  	
		 }
		 if(temp==NULL)
		 {
		 	cout<<"Not found"<<endl;
			 }		
	}
	
	void concatenate(dllist obj1,dllist obj2)
	{
		dllnode* tail1=obj1.tail;
		dllnode* head2=obj2.head;
		
		tail1->next=head2;
		head2->previous=tail1;
		
		head=obj1.head;
		tail=obj2.tail;
	}
	
    dllnode* merge(dllnode* head1,dllnode* head2)
    {
    	dllnode* h1=head1;
    	dllnode* h2=head2;
    	dllnode* dummy=new dllnode(-3);
    	dllnode* h3=dummy;
    	
    	while(h1!= NULL &&  h2!=NULL)
    	{
    		if(h1->data < h2->data)
    		{
    			h3->next=h1;
    			h1->previous=h3;
    			h1=h1->next;
			}
			else
			{
				h3->next=h2;
				h2->previous=h3;
				h2=h2->next;
			}
    		
    		h3=h3->next;
		}
		
		while(h1 !=NULL)
		{
		   h3->next=h1;
		   h1->previous=h3;
		   h1=h1->next;
		   h3=h3->next;	
		}
		
		while(h2!=NULL)
		{
		        h3->next=h2;
				h2->previous=h3;
				h2=h2->next;
				h3=h3->next;	
		}
    	head=dummy->next;
    	tail=h3;
    	
	}
	void display()
	{ 
	   dllnode* temp=head;
		while(temp != NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	
	
		
	 dllnode* findMid(dllnode* h1)
	 {
	 	dllnode* fast=h1->next;
	 	dllnode* slow=h1;
          while(head!= NULL && head->next!= NULL)
		  {
		  	fast=fast->next->next;
		  	slow=slow->next;
		  }
		  return slow;	 	
	 }
	 
	 
		dllnode* mergesort(dllnode* h1)
	{
		if(h1==NULL || h1-> next==NULL)
		{
			return h1;
		}
		
		dllnode* mid=findMid(h1);
		
		dllnode* left=h1;
		dllnode* right=mid->next;
		
		mid->next=NULL;
		right->previous =NULL;
		
		 left=mergesort(left);
		 right=mergesort(right);
		 
		 
		dllnode*result= merge(left,right); 
		}	
	
};
	
	

int main()
{
	int choice ,choice1,choice2,i,e,x,n1,n2;
	dllist ob,ob1,ob2;
	char c='y',ch1='y',ch2='y';
	do
	{
		cout<<" doubly linked list operations "<<endl;
		cout<<"1:add"<<endl<<"2:delete"<<endl<<"3:rev"<<endl<<"4:concatinATE"<<endl<<"5:merge"<<endl<<"6:exit"<<endl<<"enter your choice";
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
				ob.merge(ob1.head,ob2.head);
				ob.display();
				break;
				break;
			case 6 :
				c='n';
				break;	
			default :
				cout<<"wrong choice entred";
		}
	}
	while(c=='y');
	return 0;
}
