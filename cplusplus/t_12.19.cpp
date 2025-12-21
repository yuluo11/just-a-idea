#include<iostream>
#include<string>
using namespace std;
typedef struct 
{
    string name;
    int age;
    double high;
}student;
int main()
{
    //string str1={"yura luan"};
    //cout<<str1<<endl;
    //string str2;
    //cin>>str2;
    //cout<<str2<<endl;
    //string str3;
    //str3=str1+str2;
    //str1+=str2;
    //cout<<str3<<endl<<str1<<endl;
    //string * str1=new string;
    //cin >> *str1;
    //delete str1;
    student *s1=new student;
    cin>>(*s1).name;
    cout<<(*s1).name;
    //....
    delete s1;

    
    return 0;
}