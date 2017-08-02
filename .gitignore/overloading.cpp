#include<iostream>
using namespace std;
class single{
	int x,y;
	public:
		void get()
		{
			cin>>x>>y;
		}
		void dis()
		{
			cout<<x<<"   "<<y<<endl;
		}
		void operator-()
		{
			x=-x;
			y=-y;
		}
		void operator++()
		{
			x=++x;
			y=++y;
		}
		void didi()
		{
			cout<<"Feet"<<x<<"     Inch"<<y<<endl;
		}
		int operator>(single &s)
		{
			if(x>s.x)
			return 1;
			if((x==s.x)&&(y>s.y))
			return 1;
			return 0;
		}
		int operator==(single &s)
		{
			if((x==s.x)&&(y==s.y))
			return 1;
			return 0;
		}
		void operator()(int i)
		{
			x=x+i;
			y=y+i;
		}
		single operator +(single &d)
		{
			single s;
			s.x=x+d.x;
			s.y=y+d.y;
			return s;
		}
};
class arr{
	int b[10];
	public:
		void disarr()
		{
			int i;
			for(i=0;i<5;i++)
			cout<<"   "<<b[i];
		}
		int &operator[](int i)
		{
			return b[i];
		}
		arr operator+(int m)
		{
			arr h;
			for(int i=0;i<5;i++)
			{
				h.b[i]=b[i]+m;
			}
			return h;
		}
		friend istream &operator>>(istream &in,arr &s);
};
istream &operator>>(istream &in,arr &s)
{
	for(int i=0;i<5;i++)
	in>>s.b[i];
}
int main()
{
	single s[8];
	arr a,a1;
	int n,m,u;
	cout<<endl<<"- operator"<<endl;
	s[0].get();
	s[0].dis();
	-s[0];
	cout<<"after call";
	s[0].dis();
	cout<<endl<<"++ operator"<<endl;
	s[1].get();
	s[1].dis();
	++s[1];
	s[1].dis();
	cout<<endl<<"> operator"<<endl;
	s[2].get();
	s[3].get();
	s[2].didi();
	s[3].didi();
	if(s[2]>s[3])
	cout<<"1st is greater";
	else
	cout<<"2nd is greater";
	cout<<endl<<"== operator"<<endl;
	s[4].get();
	s[5].get();
	if(s[4]==s[5])
		cout<<"Equal";
	else
		cout<<"Not equal";
	cout<<endl<<"Function call () operator"<<endl;	
	s[6].get();
	s[6].dis();
	cin>>u;
	cout<<"After call";
	s[6](u);
	s[6].dis();
	cout<<endl<<"+ operator"<<endl;
	s[2].dis();
	s[4].dis();
	s[7]=s[2]+s[4];
	s[7].dis();
	cout<<endl<<">> operator"<<endl;
	cin>>a;
	a.disarr();
	cout<<endl<<"[] operator"<<endl;
	cin>>n;
	cout<<a[n];
	cout<<endl<<"obj+int operator"<<endl;
	cin>>m;
	a1=a+m;
	a1.disarr();
}
