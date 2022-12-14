#include <iostream>
using namespace std;
class diagonal{
	int *a;
	int size;
	int n;
	public :
		diagonal(int x)
		{
			size=x;
			if(x<0)
			{
				cout<"error";
			}
			else
			{
				n=size;
				a=new int[size];
			}
		}
		void set(int i,int j,int x)
		{
			if(i==j)
			{
				a[i-1]=x;
			}
		}
		void get(int i,int j)
		{
			if(i==j)
			{
				cout<<a[i-1];
			}
			else if(i != j)
			{
				cout<<"0";
			}
		}
};
class tridiagonal{
	int *a;
	int size,n;
	public :
		tridiagonal(int x)
		{
			size=x;
			if(x<0)
			{
				cout<"error";
			}
			else
			{
				n=size;
				a=new int[3*size-2];
			}
		}
		void set(int i,int j,int x)
		{
			if(i==j+1)
			{
				a[i-2]=x;
			}
			else if(i==j)
			{
				a[n+i-2]=x;
			}
			else if(i==j-1)
			{
				a[2*n+i-2]=x;
			}
		}
		void get(int i,int j)
		{
			if(i==j+1)
			{
				cout<<a[i-2];
			}
			else if(i==j)
			{
				cout<<a[n+i-2];
			}
			else if(i==j-1)
			{
				cout<<a[2*n+i-2];
			}
			else
			{
				cout<<0;
			}
		}
};
class lowdiagonal{
	int *a;
	int size,n;
	public :
		lowdiagonal(int x)
		{
			size=x;
			if(x<0)
			{
				cout<"error";
			}
			else
			{
				n=size;
				a=new int[size*(size+1)/2];
			}
		}
		void set(int i,int j,int x)
		{
			if(i>=j)
			{
				a[(((i-1)*i)/2)+j-1]=x;
			}
		}
		void get(int i,int j)
		{
			if(i>=j)
			{
				cout<<a[(((i-1)*i)/2)+j-1];
			}
			else 
			{
				cout<<"0";
			}
		}
};
class updiagonal{
	int *a;
	int size,n;
	public :
		updiagonal(int x)
		{
			size=x;
			if(x<0)
			{
				cout<"error";
			}
			else
			{
				n=size;
				a=new int[size*(size+1)/2];
			}
		}
		void set(int i,int j,int x)
		{
			if(i<=j)
			{
				a[(((j-1)*j)/2)+i-1]=x;
			}
		}
		void get(int i,int j)
		{
			if(i<=j)
			{
				cout<<a[(((j-1)*j)/2)+i-1];
			}
			else 
			{
				cout<<"0";
			}
		}
};
class symmetric{
	int *a;
	int size,n;
	public :
		symmetric(int x)
		{
			size=x;
			if(x<0)
			{
				cout<"error";
			}
			else
			{
				n=size;
				a=new int[size*(size+1)/2];
			}
		}
		void set(int i,int j,int x)
		{
			if(i<=j)
			{
				a[(((j-1)*j)/2)+i-1]=x;
			}
			else
			{
				int temp=i;
				i=j;
				j=temp;
				set(i,j,x);
			}
		}
		void get(int i,int j)
		{
			if(i<=j)
			{
				cout<<a[(((j-1)*j)/2)+i-1];
			}
			else
			{
				int temp=i;
				i=j;
				j=temp;
				get(i,j);
			}
			
			
		}
};
int main(){
	char ch='y',ch1='y',ch2='y',ch3='y',ch4='y',ch5='y';
 	int n;
	do{
		cout<<"1 : diagonal sparce matrix"<<endl;
		cout<<"2 : tridiagonal sparce matrix"<<endl;
		cout<<"3 : lowtri sparce matrix"<<endl;
		cout<<"4 : uptri sparce matrix"<<endl;
		cout<<"5 : symmetric matrix"<<endl;
		cout<<"6 : exit"<<endl;
		cout<<"enter your choice ";
		int choice,choice1;
		cin>>choice;
		cout<<endl<<"enter order of matrix ";
		cin>>n;
		cout<<endl;
		diagonal ob1(n);
		tridiagonal ob2(n);
		lowdiagonal ob3(n);
		updiagonal ob4(n);
		symmetric ob5(n);
		switch(choice)
		{
			case 1 :
				do
				{
					cout<<"press 1: set elements "<<endl;
					cout<<"press 2 : get elements"<<endl;
					cout<<"press 3: exit"<<endl;
					cin>>choice1;
					int i,j,e;
					switch(choice1)
					{
						case 1 :
							ch1='y';
							cout<<"enter i,j to set value in mqatrix";
							cin>>i>>j;
							cout<<"enter value to set at "<<i<<" , "<<j<<"  : ";
							cin>>e;
							ob1.set(i,j,e);
							break;
						case 2 :
							ch1='y';
							cout<<"enter i,j to get value from mqatrix";
							cin>>i>>j;
							cout<<"value at "<<i<<" , "<<j<<" : ";
							ob1.get(i,j);
							break;
						case 3 :
							ch1='n';
							break;
						default : 
							cout<<"wrong choice ";
					}
				}
				while(ch1=='y');
				break;
			case 2 :
				do
				{
					cout<<"press 1: set elements "<<endl;
					cout<<"press 2 : get elements"<<endl;
					cout<<"press 3: exit"<<endl;
					cin>>choice1;
					int i,j,e;
					switch(choice1)
					{
						case 1 :
							ch2='y';
							cout<<"enter i,j to set value in mqatrix";
							cin>>i>>j;
							cout<<"enter value to set at "<<i<<" , "<<j<<"  : ";
							cin>>e;
							ob2.set(i,j,e);
							break;
						case 2 :
							ch2='y';
							cout<<"enter i,j to get value from mqatrix";
							cin>>i>>j;
							cout<<"value at "<<i<<" , "<<j<<" : ";
							ob2.get(i,j);
							break;
						case 3 :
							ch2='n';
							break;
						default : 
							cout<<"wrong choice ";
					}
				}
				while(ch2=='y');
				break;
			case 3 :
				do
				{
					cout<<"press 1: set elements "<<endl;
					cout<<"press 2 : get elements"<<endl;
					cout<<"press 3: exit"<<endl;
					cin>>choice1;
					int i,j,e;
					switch(choice1)
					{
						case 1 :
							ch3='y';
							cout<<"enter i,j to set value in mqatrix";
							cin>>i>>j;
							cout<<"enter value to set at "<<i<<" , "<<j<<"  : ";
							cin>>e;
							ob3.set(i,j,e);
							break;
						case 2 :
							ch3='y';
							cout<<"enter i,j to get value from mqatrix";
							cin>>i>>j;
							cout<<"value at "<<i<<" , "<<j<<" : ";
							ob3.get(i,j);
							break;
						case 3 :
							ch3='n';
							break;
						default : 
							cout<<"wrong choice ";
					}
				}
				while(ch3=='y');
				break;
			case 4 :
				do
				{
					cout<<"press 1: set elements "<<endl;
					cout<<"press 2 : get elements"<<endl;
					cout<<"press 3: exit"<<endl;
					cin>>choice1;
					int i,j,e;
					switch(choice1)
					{
						case 1 :
							ch4='y';
							cout<<"enter i,j to set value in mqatrix";
							cin>>i>>j;
							cout<<"enter value to set at "<<i<<" , "<<j<<"  : ";
							cin>>e;
							ob4.set(i,j,e);
							break;
						case 2 :
							ch4='y';
							cout<<"enter i,j to get value from mqatrix";
							cin>>i>>j;
							cout<<"value at "<<i<<" , "<<j<<" : ";
							ob4.get(i,j);
							break;
						case 3 :
							ch4='n';
							break;
						default : 
							cout<<"wrong choice ";
					}
				}
				while(ch4=='y');
				break;
			case 5 :
				do
				{
					cout<<"press 1: set elements "<<endl;
					cout<<"press 2 : get elements"<<endl;
					cout<<"press 3: exit"<<endl;
					cin>>choice1;
					int i,j,e;
					switch(choice1)
					{
						case 1 :
							ch5='y';
							cout<<"enter i,j to set value in mqatrix";
							cin>>i>>j;
							cout<<"enter value to set at "<<i<<" , "<<j<<"  : ";
							cin>>e;
							ob5.set(i,j,e);
							break;
						case 2 :
							ch5='y';
							cout<<"enter i,j to get value from mqatrix";
							cin>>i>>j;
							cout<<"value at "<<i<<" , "<<j<<" : ";
							ob5.get(i,j);
							break;
						case 3 :
							ch5='n';
							break;
						default : 
							cout<<"wrong choice ";
					}
				}
				while(ch5=='y');
				break;
			case 6 :
				ch='n';
				break;
			default :
				cout<<"wrong choice ";
		}
	}
	while(ch == 'y');
	
}
