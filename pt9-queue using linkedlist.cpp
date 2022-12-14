#include <iostream>
using namespace std;
template <class t>
class llnode
{
	public :
		t element;
		llnode<t> *next;
		llnode(t val=0,llnode* p=NULL)
		{
			element=val;
			next=p;
		}
};
template <class t>
class llist
{
	
		public :
		llnode<t>* head;
		llist()
		{
			head=NULL;
		}
		bool empty()
		{
			return(head==NULL);
		}
		int size()
		{
			llnode<t> *q;
			if(head ==NULL)
			{
				return 0;
			}
			q=head;
			int j=1;
			while(q->next !=NULL)
			{
				j++;
				q=q->next;
			}
			return j;
		}
		void enqueue(t x)
		{
			if(empty())
			{
				head=new llnode<t>(x);
			}
			else
			{
				llnode<t> *p,*q;
				p=new llnode<t>(x);
				q=head;
				while(q->next !=NULL)
				{
					q=q->next;
				}
				q->next=p;
			}
		}
		void dequeue()
		{
			if(empty())
			{
				cout<<"error";
				return;
			}
			else
			{
				llnode<t> *p=head;
				head=head->next;
				delete(p);
			}
		}
		t front()
		{
			llnode<t> *p=head;
			return p->element;
		}
		t rear()
		{
			llnode<t> *p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			return p->element;
		}
};
int main()
{
	llist<int> ob;
		int co;
		bool t=true;
		int x;
		do
		{
			cout<<" 1: enqueue \n 2: dequeue \n 3: size \n 4: front \n 5: rear \n 6: exit \n enter your choice";
			cin>>co;
			switch(co)
			{
				case 1 :
					cout<<"enter elemengt to enqueue \n";
					cin>>x;
					ob.enqueue(x);
					break;
				case 2 :
					ob.dequeue();
					break;
				case 3 :
					cout<<ob.size()<<endl;
					break;
				case 4 :
					cout<<ob.front()<<endl;
					break;
				case 5 :
					cout<<ob.rear()<<endl;
					break;
				case 6 :
					t=false;
					break;
				default :
					cout<<"wrong choice entered \n";
			}
		}
		while(t);
		return 0;
}
