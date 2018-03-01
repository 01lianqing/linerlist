#include <cstdio>
#include "ListTest.h"
#define value 5
using namespace std;

//主函数

int main(int argc, char const *argv[]) {
    SqList list1;
    CreatList(list1);
    DeleteSameValue1(list1,value);
    if(!ShowList(list1)){
        cerr<<"the list is null !"<<endl;
    }
    return 0;
}