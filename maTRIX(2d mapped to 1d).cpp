#include <iostream>
using namespace std;
class mymat
{
	int *mat;
	int r,c;
	public :
		mymat(int x=0,int y=0)
		{
			r=x;
			c=y;
			mat=new int[r*c];
			for(int i=0;i<r*c;i++)
			{
				mat[i]=0;
			}
		}
		mymat(const mymat& m)
		{
			r=m.r;
			c=m.c;
			mat=new int[r*c];
			for(int i=0;i<r*c;i++)
			{
				mat[i]=0;
			}
		}
		void getmat()
		{
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					cout<<"enter element at "<<i<<" , "<<j<<" : ";
					cin>>mat[i*c+j];
				}
			}
		}
		void dismat()
		{
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					cout<<mat[i*c+j]<<" ";
				}
				cout<<endl;
			}
		}
		mymat operator =(const mymat& m)
		{
				r=m.r;
				c=m.c;
				for(int i=0;i<r*c;i++)
				{
					mat[i]=m.mat[i];
				}
				return *this;
		}
		mymat operator +(const mymat& m)
		{
			mymat temp(r,c);
			if((r==m.r)&&(c==m.c))
			{
				for(int i=0;i<r*c;i++)
				{
					temp.mat[i]=mat[i]+m.mat[i];	
				}
			return temp;	
			}
		}
		mymat operator -(const mymat& m)
		{
			mymat temp(r,c);
			if((r==m.r)&&(c==m.c))
			{
				for(int i=0;i<r*c;i++)
				{
					temp.mat[i]=mat[i]-m.mat[i];
				}
				return temp;
			}
		}
		void operator +=(int a)
		{
			for(int i=0;i<r*c;i++)
			{
 		        mat[i]=mat[i]+a;
			}
		}
		void operator *=(int a)
		{
			for(int i=0;i<r*c;i++)
			{
 		        mat[i]=mat[i]*a;
			}
		}
		void operator *(const mymat& m)
		{
			mymat temp(r,m.c);
			if(c==m.r)
			{
				for(int i=0;i<r;i++)
				{
					for(int j=0;j<m.c;j++)
					{
						for(int k=0;k<c;k++)
						{
							temp.mat[i*m.c+j]+=mat[i*c+k]*m.mat[k*m.c+j];
						}
					}
				}
				temp.dismat();
			}
			else 
			{
				cout<<"multiplication not possible ";
			}
		}
};
int main()
{
	int choice;
	int x,y;
		cout<<"enter row and column of ob1 "<<endl;
		cin>>x>>y;
		mymat ob1(x,y);
		cout<<"enter values of ob1 "<<endl;
		ob1.getmat();
		cout<<"entered ob1 "<<endl;
		ob1.dismat();
		mymat ob2(ob1);
		mymat ob3(ob1+ob2);
		mymat ob4(ob1-ob2);
		cout<<endl;
	do
	{
		cout<<"press 1 to perform = operator"<<endl;
		cout<<"press 2 to perform + operator"<<endl;
		cout<<"press 3 to perform - operator"<<endl;
		cout<<"press 4 to perform * operator"<<endl;
		cout<<"press 5 to perform += operator"<<endl;
		cout<<"press 6 to perform *= operator"<<endl;
		cout<<"press 7 to exit"<<endl;
		cout<<"enter your choice :";
		cin>>choice;
		if(choice==1)
		{
			
			ob2=ob1;
			cout<<"ob2=ob1"<<endl;
			ob2.dismat();
		}
		else if(choice == 2)
		{
			ob3=ob1+ob2;
			cout<<"ob3=ob1+ob2"<<endl;
			ob3.dismat();
		}
		else if(choice == 3)
		{
			ob4=ob1-ob2;
			cout<<"ob4=ob1-ob2"<<endl;
			ob4.dismat();
		}
		else if(choice == 4)
		{
			
			cout<<"ob1*ob2"<<endl;
			ob1*ob2;
			cout<<endl;
		}
		else if(choice ==5)
		{
			ob1+=10;
			cout<<"ob1+=10"<<endl;
			ob1.dismat();
			ob1=ob2;
		}
		else if(choice ==6)
		{
			ob1*=3;
			cout<<"ob1*=3"<<endl;
			ob1.dismat();
			ob1=ob2;
		}
		else if(choice==7)
		{
			cout<<endl<<"exiciting ";
		}
	}
	
	while(choice != 7);
	
	return 0;
}
