
#ifndef LISTTEST_H
#define LISTTEST_H
#include<iostream>
#include<cmath>
#include <cstdlib>
// swap algorithm example
#include <algorithm> 

using namespace std;
//定义顺序表
#define MaxSize 20
#define ElemType int

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

/*
 * 初始化,先输入长度，第二行是数据
8
 2 5 5 4 2 5 5 6
 */

bool CreatList(SqList &list) {
    list.length = 0;
    cin >> list.length;
    for (int i = 0; i < list.length; i++) {
        cin >> list.data[i];
    }
    return true;
}

bool ShowList(SqList List) {
    //检查特殊情形
    if (List.length == 0) return false;
    else {
        for (int i = 0; i < List.length; i++) {
            cout << " " << List.data[i];
        }
        cout << endl;
        return true;
    }
}
//第一题

bool ReturnMin_delete(SqList &List, ElemType &ReturnValue) {
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

void Show_1(SqList &list) {
    //第一题
    ElemType minValue;
    if (!ReturnMin_delete(list, minValue))
        cout << "list is null" << endl;
    else {
        cout << "min value is " << minValue << endl;
    }
}
//2

bool Reverse1(SqList &list) {
    if (list.length == 0) return false;
    int left = 0, right = list.length - 1;
    while (left < right) {
        swap(list.data[left], list.data[right]);
        left++;
        right--;
    }
    return true;
}

bool Reverse2(SqList &List) {
    if (List.length == 0) return false;
    int len = List.length;
    for (int i = 0; i < len / 2; i++) {
        swap(List.data[i], List.data[len - i - 1]);
    }
    return true;
}
//3

bool DeleteSameValue1(SqList &list, ElemType value) {
//     2 5 5 4 2 5 5 6
    if (list.length == 0) return false;
    int right = 0, left = list.length - 1;
    while (right < left) {
        while (list.data[right] != value) right++;
        while (list.data[left] == value && right < left) left--;
        list.data[right] = list.data[left];
        list.data[left]=value;
    }
    list.length=left;
}

bool DeleteSameValue2(SqList &list, ElemType value) {
    if (list.length == 0) return false;
    int count = 0, i = 0;
    while (i < list.length) {
        if (list.data[i] == value) count++;
        else {
            list.data[i - count] = list.data[i];
        }
        i++;
    }
    list.length -= count;
}
#endif /* LISTTEST_H */

