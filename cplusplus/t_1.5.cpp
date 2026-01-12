#include<iostream>
int main()
{
    //1.指向const变量的指针
    const int a=10;
    //int *pa=&a 报错
    const int *pa=&a;
    std::cout<<*pa<<std::endl;
    //true
    int b=20;//+const true
    pa=&b;
    std::cout<<*pa<<std::endl;
    //true
    //in conclusion 
    //const修饰的变量只能由指向const变量的指针去指向（这个指针可以改变）


    //2.被const修饰的指针
    //这个指针一旦指向了一个变量，不能再指向其他变量
    //但是，被指向的变量可以改变
    int a1=10;
    int *const pa1=&a1;
    int b1=20;
    //pa=&b1;//fasle
    return 0;
}