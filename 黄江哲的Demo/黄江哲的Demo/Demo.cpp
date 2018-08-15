#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
void inputagoods (string *n, int *p, int *s)
{
	cout<<"    name: ";
	cin>>*n;
	cout<<"    price: ";
	cin>>*p;
	cout<<"    stock: ";
	cin>>*s;
}
int funfind(string n[ ],int num)
{
string x;
int i;
cout<<"input name of goods: ";
cin>>x;
for(i=num-1;i>=0;i--)
{
if(x==n[i]) 
break;
}
return i;
}
int funinsert(int num, string n[], int p[], int s[])
{
string xi;
int pi, si;
if(num<=100)
{
cout<<"input goods: "<<endl;
inputagoods(&xi, &pi, &si);
n[num]=xi;
p[num]=pi;
s[num]=si;
num++;
cout<<endl<<"insert finish!"<<endl;
}
else
cout<<endl<<"not insert!"<<endl;
return num;
}
int fundelete(int num, string n[], int p[] ,int s[])
{
string x;
int i, k;
if (num>0)
{
if((k=funfind(n, num))>=0)
{
for(i=k+1;i<num;i++)
{
n[i-1]=n[i];
p[i-1]=p[i];
s[i-1]=s[i];
}
num--;
cout<<endl<<"delete finish!"<<endl;
}
else
cout<<"not find!"<<endl;
}
else
cout<<endl<<"not goods!"<<endl;
return num;
}
void show(string n[], int p[], int s[], int num)
{
cout<<"-----------------------------------------------------"<<endl;
if(num>=0)
{
cout<<"name of goods: "<<n[num]<<endl;
cout<<"price of goods: "<<p[num]<<endl;
cout<<"stock of goods: "<<s[num]<<endl;
}
else
cout<<"               not find!"<<endl;
cout<<"--------------------------------------------------------"<<endl;
}
void show(int num, string n[], int p[], int s[])
{
int i;
cout<<"             goods"<<endl;
cout<<"--------------------------------------------------------"<<endl;
cout<<"      name         |   price   |          stock"<<endl;
cout<<"--------------------------------------------------------"<<endl;
if(num!=0)
for(i=0;i<num;i++)
{
cout<<setw(20)<<n[i]<<"  ";
cout<<setw(7)<<p[i]<<"  ";
cout<<setw(7)<<s[i]<<endl;
}
else
cout<<endl<<"non!!!"<<endl<<endl;
cout<<"--------------------------------------------------------"<<endl;
}
int menu()
{
int choice=0;
cout<<endl<<endl<<endl;
cout<<"           menu"<<endl;
cout<<"--------------------------------------------------------"<<endl;
cout<<"  1. find Goods"<<endl;
cout<<"  2.insert Goods"<<endl;
cout<<"  3.delete Goods"<<endl;
cout<<"  4.show Goods"<<endl;
cout<<"  0.exit"<<endl;
cout<<"--------------------------------------------------------"<<endl;
cout<<"your choice: ";
cin>>choice;
cout<<endl<<endl<<endl;
return choice;
}
int main()
{
int i,n=0,choice=0;
int price[100], stock[100];
string name[100];
while (n<=0 || n>=100)
{
cout<<"Please input n=";
cin>>n;
}
cout<<endl;
for(i=0;i<n;i++)
{
cout<<"input "<<i+1<<"th goods: "<<endl;
inputagoods(&name[i], &price[i], &stock[i]);
}
cout<<endl<<"input finish"<<endl<<endl;
while((choice=menu())!=0)
{
switch(choice)
{
case 1:
i=funfind(name, n);
show(name, price, stock, i);
break;
case 2:
n=funinsert(n, name, price, stock);
break;
case 3:
n=fundelete(n, name, price, stock);
break;
case 4:
show(n, name, price, stock);
break;
}
}
return 0;
}
