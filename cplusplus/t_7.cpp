#include<iostream>
#include<cctype>
#include<vector>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
string s="hello world";
int main()
{
//for(auto &c:s)
//{
   //c=toupper(c);
//}
//string s;
//cin>>s;
//for(auto &c:s)
//{
   // c='X';
//}
//string s;
//cin>>s;
//string result;
//for(auto x:s)
//{
  //  if(!ispunct(x))
    //{
      //  result+=x;
    //}
//}
//cout<<result<<endl;
//string word;
//vector<string>svec;
//while(cin>>word)
//{
    //svec.push_back(word);
//}
//for(auto&c:svec)
//{
    //cout<<" "<<c<<endl;
//}
string s;
vector<string>svec;
while(cin>>s)
{
    svec.push_back(s);
}
for(auto &c:svec)
{
    for(auto&x:c)
    {
        x=toupper(x);
    }
    //c=toupper(c);
}
for(auto y:svec)
{
    cout<<" "<<y<<endl;
}
    return 0;
}