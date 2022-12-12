#include <iostream>
using namespace std;
int bise(int a[],int n)
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
int main()
{
	cout<<"enter no of elements in list";
	int n;
	cin>>n;
	cout<<"enter list in arranging order ";
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int idx =bise(a,n);
	if(idx==-1) cout<<"element not in list";
	else cout<<"element x is at index : "<<idx;
	return 0;
}
