#include<iostream>
using namespace std;
int main()
{
    /*char name[10];
    char want[20];
    cout<<"Tell me what's your name";
    cin>>name;
    cout<<name<<endl;
    cout<<"And what input you want"<<endl;
    cin>>want;
    cout<<want<<endl;
    cout<<"Abvoe is not right manner"<<endl<<"you can use get()or getline()";
    cout<<"so we let again";
    */
    /*
    char name[10];
    char dessert[20];
    cout<<"Please input your name"<<endl;
    cin.getline(name,10);
    cout<<"Your name is "<<name<<endl;
    cout<<"What your favorite dessert"<<endl;
    cin.get(dessert,20);
    cout<<dessert<<endl;
    cout<<"That's all cin.getline() manner"<<endl<<"Next we start cin.get() manner";
    */
   char name[10];
   char dessert[20];
   cout<<"Please input your name"<<endl;
   cin.get(name,10).get();
   cout<<name<<endl;
   cout<<"What your favourite dessert"<<endl;
   cin.get(dessert,20);
   cout<<dessert<<endl;
   return 0;
}