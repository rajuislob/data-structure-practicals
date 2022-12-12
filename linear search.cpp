#include <iostream>
using namespace std;
class algo
{
	
	public :
		int n;
	int *a;
 		algo()
		{
			cout<<"enter size of array "<<endl;
			cin>>n;
			a=new int[n];
			cout<<"enter your array "<<endl;
			for(int i=0;i<n;i++)
			{
				cin>>a[i];
			}
		}
int linearsearch()
{
	int i;
	cout<<"enter number to search "<<endl;
    int x;
    cin>>x;
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		{
		   return i;
		}
	}
	return -1;
}
int reclinearsearch(int x,int i)
{
	if(i>=n)
	{
		return -1;
	}
	else if(a[i]==x)
	{
		return i;
	}
	else
	{
		return reclinearsearch(x,i+1);
	}
}
int binarysearch()
{
	cout<<"enter number to search "<<endl;
    int x;
    cin>>x;
    int lb=0;
    int ub=n-1;
    while(lb<=ub){
		int mid=lb+(ub-1)/2;
		if(a[mid]==x)
		{
			return mid;
	    }
		else if(a[mid]<x)
		{
			lb=mid+1;
		}
		else if(a[mid]>x)
		{
			ub=mid-1;
		}
	}
	return -1;
}
int recbinarysearch(int lb,int ub,int x)
{
	    if(lb>ub)
	    {
	    	return -1;
		}
		int mid=lb+(ub-1)/2;
		if(a[mid]==x)
		{
			return mid;
	    }
		else if(a[mid]<x)
		{
			return recbinarysearch(mid+1,ub,x);
		}
		else if(a[mid]>x)
		{
		    return recbinarysearch(lb,mid-1,x);
		}
	}
};

int main()
{
	int choice;
	int *a;
	int n;
	char c='y';
	algo obj;
	do
	{
		cout<<"press 1 : irrative linear search "<<endl;
		cout<<"press 2 : recursive linear search"<<endl;
		cout<<"press 3 : irrative binary search "<<endl;
		cout<<"press 4 : recursive binary search"<<endl;
		cout<<"press 5 : to exit"<<endl;
		cout<<"enter your choice ";
		cin>>choice;
		switch(choice)
		{
			case 1 :
				int r1;
				r1=obj.linearsearch();
				if(r1==-1)
				{
					cout<<"result not found"<<endl;
				}
				else
				{
					cout<<"number found at index :"<<r1<<endl;
				}
				break;
			case 2 :
				cout<<"enter number to search "<<endl;
				int x2,r2;
				cin>>x2;
				r2=obj.reclinearsearch(x2,0);
				if(r2==-1)
				{
					cout<<"result not found"<<endl;
				}
				else
				{
					cout<<"number found at index :"<<r2<<endl;
				}
				break;
			case 3 :
				int r3;
				r3=obj.binarysearch();
				if(r3==-1)
				{
					cout<<"result not found"<<endl;
				}
				else
				{
					cout<<"number found at index :"<<r3<<endl;
				}
				break;
			case 4 :
				cout<<"enter number to search "<<endl;
				int x4,r4;
				cin>>x4;
				r4=obj.recbinarysearch(0,obj.n,x4);
				if(r4==-1)
				{
					cout<<"result not found"<<endl;
				}
				else
				{
					cout<<"number found at index :"<<r4<<endl;
				}
				break;
			case 5 :
				c='no';
				break;
			default :
				cout<<"entered wrong choice "<<endl;
		}
	}
	while(c=='y');
}
