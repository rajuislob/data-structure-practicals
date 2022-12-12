#include <iostream>
using namespace std;
int lise(int a[],int x)
{
	int n=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<n;i++)
	{
		if(a[i]==x) return i;
	}
	return -1;
}
int main()
{
	cout<<"enter no of elements in list";
	int n;
	cin>>n;
	cout<<"enter list ";
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"enter no to search in list ";
	int x;
	cin>>x;
	int idx =lise(a,x);
	if(idx==-1) cout<<"element not in list";
	else cout<<"element x is at index : "<<idx;
	return 0;
}
