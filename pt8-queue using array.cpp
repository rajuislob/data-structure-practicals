#include<iostream>
using namespace std;
template<class T>
class queue
{ 
	int capacity,size,front,rear;
	T* p;
	public:
	queue(int capacity)
	{
		this->capacity=capacity;
		p=new int[this->capacity];
		front=rear=-1;
	}
	bool isempty()
	{
		if(size==0) return true;
		else  return false;
	}
	T getfront()
	{
		return p[front];
	}
	T getrear()
	{
		return p[rear];
	}
	void enqueue(T n)
	{
		if(size==capacity)
		{
			cout<<"Queue Full\n";
			return;
		}
		rear++;
		if(rear==capacity-1 && size<capacity)rear=0;
		if(front==-1) front=0;
		p[rear]=n;
		size++;		
		}	
	void dequeue()
	{
		if(size==0) 
		{
			cout<<"Queue Empty\n";
			return;
		}
		if(front==capacity-1 && size==capacity) front=0;
		front++;
		size--;
	}
	int getsize()
	{
		return size;
	}
};
int main()
{
	int capacity;
	cout<<"Enter capacity\n";
	cin>>capacity;
	queue<int>q(capacity);int x,ch;
	do
	{
		cout<<"Enter choice \n1.Enqueue \n2.Dequeue \n3.GetFront \n4.GetRear \n5.GetSize \n6.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"Enter Element\n";
					cin>>x;
					q.enqueue(x);
					break;
			case 2:cout<<"Element Deleted\n";
					q.dequeue();
					break;
			case 3:cout<<"The element at front is:"<<q.getfront()<<endl;
					break;
			case 4:cout<<"Element at Rear is:"<<q.getrear()<<endl;
					break;
			case 5:cout<<"Current size is:"<<q.getsize()<<endl;
					break;
			case 6:exit(0);
			default:break;
		}
		cout<<"----------------------------------------------------------------------------------------------------------------\n";
	}
	while(true);
	return 0;
}
