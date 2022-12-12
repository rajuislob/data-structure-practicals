#include <iostream>
using namespace std;
template <class t>
class arraystack
{
	int n,tos;
	t *arr;
	public :
		arraystack()
		{
			cout<<"enter capacity of stack \n";
			cin>>n;
			arr=new t[n];
			tos=-1;
		}
		bool empty()
		{
			return tos==-1;
		}
		void push(t x)
		{
			if(tos == n-1)
			{
				cout<<"stack is overflow \n";
				return;
			}
			else
			{
				arr[++tos]=x;
				cout<<"element pushed at tos \n";
				return;
			}
		}
		void pop()
		{
			if(tos==-1)
			{
				cout<<"stack is underflow \n";
				return;
			}
			else
			{
				tos--;
				cout<<"element poped from tos \n";
			}
		}
		t top()
		{
			if(tos==-1)
			{
				cout<<"stack is empty \n";
				
			}
			else
			{
				return arr[tos];
			}
		}
		void clear()
		{
			while(tos !=-1)
			{
				pop();
			}
		}
		int size()
		{
			return tos+1;
		}
};
int main()
{
	arraystack<int> ob;
	int choice ,x,y,z;
	bool t = true;
	do
	{
		cout<<" 1: push \n 2: pop \n 3: top of stack \n 4: clear \n 5: current size \n 6: exit \n enter your choice \n ";
		cin>>choice;
		switch(choice)
		{
			case 1 :
				cout<<"enter element to push \n";
				cin>>x;
				ob.push(x);
				break;
			case 2 :
				ob.pop();
				break;
			case 3 :
				cout<<"element at tos : "<<ob.top()<<"\n";
				break;
			case 4 :
				cout<<"stack is cleared \n";
				ob.clear();
				break;
			case 5 :
				cout<<"current size : "<<ob.size()<<"\n";
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
