#include <iostream>
using namespace std;
class mymat
{
	int **mat;
	int r,c;
	public :
		mymat(int x=0,int y=0)
		{
			r=x;
			c=y;
			mat=new int*[r];
			for(int i=0;i<r;i++)
			{
				mat[i]=new int[c];
				for(int j=0;j<c;j++)
				{
					mat[i][j]=0;
				}
			}
		}
		mymat(const mymat& m)
		{
			r=m.r;
			c=m.c;
			mat=new int*[r];
			for(int i=0;i<r;i++)
			{
				mat[i]=new int[c];
				for(int j=0;j<c;j++)
				{
					mat[i][j]=0;
				}
			}
		}
		void getmat()
		{
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					cout<<"enter element at "<<i<<" , "<<j<<" : ";
					cin>>mat[i][j];
				}
			}
		}
		void dismat()
		{
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					cout<<mat[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		mymat operator =(const mymat& m)
		{
				r=m.r;
				c=m.c;
				for(int i=0;i<r;i++)
				{
					for(int j=0;j<c;j++)
					{
                        mat[i][j]=m.mat[i][j];
                    }
				}
				return *this;
		}
		mymat operator +(const mymat& m)
		{
			mymat temp(r,c);
			if((r==m.r)&&(c==m.c))
			{
				for(int i=0;i<r;i++)
				{
					for(int j=0;j<c;j++)
					{
					    temp.mat[i][j]=mat[i][j]+m.mat[i][j];
				    }
				}
			return temp;	
			}
		}
		mymat operator -(const mymat& m)
		{
			mymat temp(r,c);
			if((r==m.r)&&(c==m.c))
			{
				for(int i=0;i<r;i++)
				{
					for(int j=0;j<c;j++)
					{
					    temp.mat[i][j]=mat[i][j]-m.mat[i][j];
				    }
				}
				return temp;
			}
		}
		mymat operator *(const mymat& m)
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
							temp.mat[i][j]+=mat[i][k]*m.mat[k][j];
						}
					}
				}
				return temp;
			}
		}
		void operator +=(int a)
		{
			for(int i=0;i<r;i++)
			{
			    for(int j=0;j<c;j++)
			    {
 		            mat[i][j]=mat[i][j]+a;
 		        }
			}
		}
		void operator *=(int a)
		{
			for(int i=0;i<r;i++)
			{
			    for(int j=0;j<c;j++)
			    {
 		            mat[i][j]=mat[i][j]*a;
 		        }
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
		mymat ob5(ob1*ob2);
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
			ob5=ob1*ob2;
			cout<<"ob5=ob1*ob2"<<endl;
			ob5.dismat();
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
