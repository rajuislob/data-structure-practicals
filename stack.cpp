#include <iostream>
using namespace std;
template <class t>
class snode
{
	public :
		t element;
		snode<t> *next;
		snode(t val=0,snode* p=NULL)
		{
			element=val;
			next=p;
		}
};

template <class t>
class stack
{
	
		public :
		snode<t>* head;
		stack()
		{
			head=NULL;
		}
		bool empty()
		{
			return(head==NULL);
		}
		int size()
		{
			snode<t> *q;
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
		void push(t x)
		{
			if(empty())
			{
				head=new snode<t>(x);
			}
			else
			{
				snode<t> *p,*q;
				p=new snode<t>(x);
				q=head;
				while(q->next !=NULL)
				{
					q=q->next;
				}
				q->next=p;
			}
		}
		void pop()
		{
			if(empty())
			{
				cout<<"error list is already empty";
				return;
			}
			else
			{
				if(size()==1)
				{
					snode<t> *p=head;
					head=NULL;
					delete(p);
				}
				else
				{
					snode<t> *p,*r;
					p=head;
					while(p->next != NULL)
					{
						r=p;
						p=p->next;
					}
					r->next=NULL;
					delete(p);
				}
			}
		}
		t tos()
		{
			snode<t> *p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			return p->element;
		}
	};
	
	int main()
	{
		stack<int> ob;
		int co;
		bool t=true;
		int x;
		do
		{
			cout<<" 1: push \n 2: pop \n 3: size \n 4: tos \n 5: exit \n enter your choice";
			cin>>co;
			switch(co)
			{
				case 1 :
					cout<<"enter elemengt to push into stack \n";
					cin>>x;
					ob.push(x);
					cout<<endl;
					break;
				case 2 :
					ob.pop();
					cout<<endl;
					break;
				case 3 :
					cout<<ob.size();
					cout<<endl;
					break;
				case 4 :
					cout<<ob.tos();
					cout<<endl;
					break;
				case 5 :
					t=false;
					break;
				default :
					cout<<"wrong choice entered \n";
					cout<<endl;
			}
		}
		while(t);
		return 0;
	}
	
	
	
	
