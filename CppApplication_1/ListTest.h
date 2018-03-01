
#ifndef LISTTEST_H
#define LISTTEST_H
#include<iostream>
using namespace std;
//定义顺序表
#define MaxSize 20
#define ElemType int

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;
//初始化

bool CreatList(SqList &list) {
     int length = 0;
    cout << "inupt the length of list :";
    cin>>length;
    cout << endl;
    cout << "input " << length << " elements :" ;
    for (int i = 0; i < length; i++) {
        cin >> list.data[i];
    }
    list.length = length;
    cout<<endl;
    return true;
}
bool ShowList(SqList List)
{
//检查特殊情形
    if (List.length == 0) return false;
    else {
        for(int i=0;i<List.length;i++){
            cout<<List.data[i]<<" ";
        }
        cout<<endl;
        return true;
    }
}
//第一题
bool ReturnMin_delete(SqList &List,ElemType &ReturnValue) {
    //检查特殊情形
    if (List.length == 0) return false;
    //找到最小值的序号
    int MinIndex = 0;
    for (int i = 1; i < List.length; i++) {
        if (List.data[i] < List.data[MinIndex])
            MinIndex = i;
    }
    //用末尾值复写在最小值的位置
    ReturnValue = List.data[MinIndex];
    List.data[MinIndex] = List.data[List.length - 1];
    // 长度减一
    List.length--;
    return true;
}
void Show_1(SqList &list){
     //第一题
    ElemType minValue;
    if(!ReturnMin_delete(list,minValue) )
        cout<<"list is null"<<endl;
    else{
        cout<<"min value is "<<minValue<<endl;
    }
}

#endif /* LISTTEST_H */

