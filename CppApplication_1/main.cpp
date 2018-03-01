#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "ListTest.h"
using namespace std;

//主函数

int main(int argc, char const *argv[]) {
    SqList list1;
    CreatList(list1);
    Show_1(list1);
    if(!ShowList(list1)){
        cerr<<"the list is null !"<<endl;
    }
    return 0;
}