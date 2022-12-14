#include <iostream>
using namespace std;
class llnode
{
	public :
		int element;
		llnode *next;
		llnode(int val=0,llnode* p=NULL)
		{
			element=val;
			next=p;
		}
		friend class llist;
};

// p=new llnode()
class llist
{
	
		public :
		llnode* head;
		llist()
		{
			head=NULL;
		}
		bool empty()
		{
			return(head==NULL);
		}
		int noofnodes()
		{
			llnode *q;
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
		void disll()
		{
			llnode *p;
			p=head;
			if(noofnodes()==0)
			{
				cout<<"list is empty";
				return;
			}
			else if(noofnodes()==1)
			{
				cout<<p->element<<"->NULL"<<endl;
			}
			else
			{
				while(p->next !=NULL)
				{
					cout<<p->element<<"->";
					p=p->next;
				}
				cout<<p->element<<"->NULL"<<endl;
			}
		}
		void addatbegin(int x)
		{
			if(empty())
			{
				head=new llnode(x);
			}
			else
			{
				llnode *p;
				p=new llnode(x);
				p->next=head;
				head=p;
			}
		}
		void addatend(int x)
		{
			if(empty())
			{
				head=new llnode(x);
			}
			else
			{
				llnode *p,*q;
				p=new llnode(x);
				q=head;
				while(q->next !=NULL)
				{
					q=q->next;
				}
				q->next=p;
			}
		}
		void addatposi(int x,int i)
		{
			if(i<0)
			{
				cout<<"error : cant add element at negative position";
				return;
			}
			if(noofnodes()<i-1)
			{
				cout<<"error : i position does not exist in linked list";
				return;
			}
			else
			{
				if(i==1)
				{
					addatbegin(x);
					
				}
				else
				{
					llnode *p,*q,*r;
					p=head;
					q=new llnode(x);
					int j=1;
					while(j<i )
					{
						r=p;
						p=p->next;
						j++;
					}
					q->next=r->next;
					r->next=q;
				}
			}
		}
		void addafterposi(int x,int i)
		{
			if(i<0)
			{
				cout<<"error : cant add element at negative position";
				return;
			}
			
			if(noofnodes()<i)
			{
				cout<<"error : i position does not exist in linked list";
				return;
			}
			else 
			{
				llnode *q,*p;
				p=head;
				q=new llnode(x);
				int j=1;
				while(j<i)
				{
					p=p->next;
					j++;
				}
				q->next=p->next;
				p->next=q;
			}
		}
		void addbeforeposi(int x,int i)
		{
			if(i<0)
			{
				cout<<"error";
				return;
			}
			
			if(noofnodes()<i-1)
			{
				cout<<"error";
				return;
			}
			else
			{
				llnode *p,*q,*r;
				q=new llnode(x);
				p=head;
				int j=1;
				while(j<i)
				{
					r=p;
					p=p->next;
					j++;
				}
				q->next=r->next;
				r->next=q;
			}
		}
		void addafterinte(int x,int e)
		{
			if(empty())
			{
				cout<<"error";
				return;
			}
			llnode *q,*p;
			p=head;
			q=new llnode(x);
			int j=1;
			while(p->element != e && j<noofnodes())
			{
				p=p->next;
				j++;
			}
			if(j==noofnodes() && p->element != e)
			{
				cout<<"error";
				return;
			}
			q->next=p->next;
			p->next=q;
		}
		void addbeforeinte(int x,int e)
		{
			if(empty())
			{
				cout<<"error";
				return;
			}
			llnode *q,*p,*r;
			p=head;
			q=new llnode(x);
			int j=1;
			while(p->element != e && j<noofnodes())
			{
				r=p;
				p=p->next;
				j++;
			}
			if(j==noofnodes() && p->element != e)
			{
				cout<<"error";
				return;
			}
			q->next=r->next;
			r->next=q;
		}
		void deleteatbegin()
		{
			if(empty())
			{
				cout<<"error";
				return;
			}
			else
			{
				llnode *p=head;
				head=head->next;
				delete(p);
			}
		}
		void deleteatend()
		{
			if(empty())
			{
				cout<<"error";
				return;
			}
			else
			{
				llnode *p,*r;
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
		void deleteatposi(int i)
		{
			if(i<0)
			{
				cout<<"error";
				return;
			}
			if(noofnodes()<i)
			{
				cout<<"error";
				return;
			}
			else
			{
				llnode *p,*r;
				p=head;
				int j=1;
				while(j<i)
				{
					r=p;
					p=p->next;
					j++;
				}
				if(p==head){
					llnode *q=head;
					head=head->next;
					delete(q);
					return;
				}
				r->next=p->next;
				delete(p);
			}
		}
		void deleteafterposi(int i)
		{
			if(i<0)
			{
				cout<<"error";
				return;
			}
			if(noofnodes()<i+1)
			{
				cout<<"error";
				return;
			}
			else
			{
				llnode *p,*r;
				p=head;
				int j=1;
				while(j<i+1)
				{
					r=p;
					p=p->next;
					j++;
				}
				if(p==head){
					llnode *q=head;
					head=head->next;
					delete(q);
					return;
				}
				r->next=p->next;
				delete(p);
			}
		}
		void deletebeforeposi(int i)
		{
			if(i<0)
			{
				cout<<"error";
				return;
			}
			if(noofnodes()<i-1)
			{
				cout<<"error";
				return;
			}
			else
			{
				llnode *p,*r;
				p=head;
				int j=1;
				while(j<i-1)
				{
					r=p;
					p=p->next;
					j++;
				}
				if(p==head){
					llnode *q=head;
					head=head->next;
					delete(q);
					return;
				}
				r->next=p->next;
				delete(p);
			}
		}
		void deleteafterinte(int e)
		{
			if(empty())
			{
				cout<<"error";
				return;
			}
			llnode *p,*r;
			p=head;
			int j=1;
			while(p->element != e && j<noofnodes())
			{
				p=p->next;
				j++;
			}
			if(j==noofnodes() && p->element != e)
			{
				cout<<"error";
				return;
			}
			r=p->next;
			p->next=r->next;
			delete(r);
		}
		void deletebeforeinte(int e)
		{
			if(empty())
			{
				cout<<"error";
				return;
			}
			llnode *p,*r,*q;
			p=head;
			int j=1;
			while(p->next->element != e && j<noofnodes())
			{
				r=p;
				p=p->next;
				j++;
			}
			if(j==noofnodes() && p->element != e)
			{
				cout<<"error";
				return;
			}
			if(p==head){
					q=head;
					head=head->next;
					delete(q);
					return;
				}
			r=p->next;
			p->next=r->next;
			delete(r);
		}
		void mergesort(llist ob1,llist ob2)
		{
			llnode *p,*q,*r;
			p=ob1.head;
			q=ob2.head;
			while((p!=NULL)&&(q!=NULL))
			{
				if(p->element<q->element)
				{
					if(empty())
					{
						head=new llnode(p->element);
						r=head;
						p=p->next;
					}
					else
					{
						r->next=new llnode(p->element);
						r=r->next;
						p=p->next;
					}
				}
				else
				{
					if(empty())
					{
						head=new llnode(q->element);
						r=head;
						q=q->next;
					}
					else
					{
						r->next=new llnode(q->element);
						r=r->next;
						q=q->next;
					}
				}
			}
			if(p==NULL && q!=NULL)
			{
				while(q!=NULL)
				{
					r->next=new llnode(q->element);
					q=q->next;
					r=r->next;
				}
			}
			if(q==NULL && p!=NULL)
			{
				while(p!=NULL)
				{
					r->next=new llnode(p->element);
					p=p->next;
					r=r->next;
				}
			}
		}
		void concatinate(llist ob1, llist ob2)
		{
			llnode *p,*q,*r;
			p=ob1.head;
			q=ob2.head;
			head=p;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=q;
		}
		void rev()
		{
			llnode *p,*q,*r;
			p=head;
			q=p->next;
			p->next=NULL;
			r=q->next;
			while(q->next!=NULL)
			{
				q->next=p;
				p=q;
				q=r;
				r=r->next;
			}
			q->next=p;
			head=q;
		}
	
};
int main()
{
	int choice ,choice1,choice2,i,e,x,n1,n2;
	llist ob,ob1,ob2;
	char c='y',ch1='y',ch2='y';
	do
	{
		cout<<"linked list operations "<<endl;
		cout<<"1:add"<<endl<<"2:delete"<<endl<<"3:rev"<<endl<<"4:concatinATE"<<endl<<"5:merge"<<endl<<"6:exit"<<endl<<"enter your choice";
		cin>>choice;
		switch(choice)
		{
			case 1 :
				do{
					cout<<"1:add at begin"<<endl<<"2:add at end"<<endl<<"3:add at pos i"<<endl<<"4:add after pos i"<<endl<<"5:add at before pos i"<<endl<<"6:add after integer"<<endl<<"7:add before int "<<endl<<"8:exit"<<endl;
					cout<<"enter your choice";
					cin>>choice1;
					switch(choice1)
					{
						case 1 :
							ch1='y';
							cout<<"enter element to add :";
							cin>>x;
							ob.addatbegin(x);
							ob.disll();
							break;
						case 2 :
							ch1='y';
							cout<<"enter element to add :";
							cin>>x;
							ob.addatend(x);
							ob.disll();
							break;
						case 3 :
							ch1='y';
							cout<<"enter element to add :";
							cin>>x;
							cout<<"enter i :";
							cin>>i;
							ob.addatposi(x,i);
							ob.disll();
							break;
						case 4 :
							ch1='y';
							cout<<"enter element to add :";
							cin>>x;
							cout<<"enter i :";
							cin>>i;
							ob.addafterposi(x,i);
							ob.disll();
							break;
						case 5 :
							ch1='y';
							cout<<"enter element to add :";
							cin>>x;
							cout<<"enter i :";
							cin>>i;
							ob.addbeforeposi(x,i);
							ob.disll();
							break;
						case 6 :
							ch1='y';
							cout<<"enter element to add :";
							cin>>x;
							cout<<"enter integer e :";
							cin>>e;
							ob.addafterinte(x,e);
							ob.disll();
							break;
						case 7 :
							ch1='y';
							cout<<"enter element to add :";
							cin>>x;
							cout<<"enter integer e :";
							cin>>e;
							ob.addbeforeinte(x,e);
							ob.disll();
							break;
						case 8 :
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
					cout<<"1:delete at begin"<<endl<<"2:delete at end"<<endl<<"3:delete at pos i"<<endl<<"4:delete after pos i"<<endl<<"5:delete at before pos i"<<endl<<"6:delete after integer"<<endl<<"7:delete before int "<<endl<<"8:exit"<<endl;
					cout<<"enter your choice";
					cin>>choice2;
					switch(choice2)
					{
						case 1 :
							ch2='y';
							cout<<"enter element to delete :";
							cin>>x;
							ob.deleteatbegin();
							ob.disll();
							break;
						case 2 :
							ch2='y';
							cout<<"enter element to delete :";
							cin>>x;
							ob.deleteatend();
							ob.disll();
							break;
						case 3 :
							ch2='y';
							cout<<"enter element to delete :";
							cin>>x;
							cout<<"enter i :";
							cin>>i;
							ob.deleteatposi(i);
							ob.disll();
							break;
						case 4 :
							ch2='y';
							cout<<"enter element to delete :";
							cin>>x;
							cout<<"enter i :";
							cin>>i;
							ob.deleteafterposi(i);
							ob.disll();
							break;
						case 5 :
							ch2='y';
							cout<<"enter element to delete :";
							cin>>x;
							cout<<"enter i :";
							cin>>i;
							ob.deletebeforeposi(i);
							ob.disll();
							break;
						case 6 :
							ch2='y';
							cout<<"enter element to delete :";
							cin>>x;
							cout<<"enter integer e :";
							cin>>e;
							ob.deleteafterinte(e);
							ob.disll();
							break;
						case 7 :
							ch2='y';
							cout<<"enter element to delete :";
							cin>>x;
							cout<<"enter integer e :";
							cin>>e;
							ob.deletebeforeinte(e);
							ob.disll();
							break;
						case 8 :
							ch2='n';
							break;
						default :
							cout<<"you have entered wrong choice"<<endl;
						
					}
				}
				while(ch2=='y');
				break;
			case 3 :
				ob.rev();
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
					ob1.addatbegin(x);
				}
				ob1.rev();
				cout<<"first list";
				ob1.disll();
				cout<<"enter list 2"<<endl;
				for(int j=0;j<n2;j++)
				{
					cin>>x;
					ob2.addatbegin(x);
				}
				ob2.rev();
				cout<<"second list";
				ob2.disll();
				ob.concatinate(ob1,ob2);
				ob.disll();
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
					ob1.addatbegin(x);
				}
				ob1.rev();
				cout<<"first list";
				ob1.disll();
				cout<<"enter list 2"<<endl;
				for(int j=0;j<n2;j++)
				{
					cin>>x;
					ob2.addatbegin(x);
				}
				ob2.rev();
				cout<<"second list";
				ob2.disll();
				ob.mergesort(ob1,ob2);
				ob.disll();
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
