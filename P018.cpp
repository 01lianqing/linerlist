//命名的习惯，独立词汇开头都是大写
前提：顺序表
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
//定义顺序表
#define MaxSize 20
#define ElemType int
typedef struct linerList
{
	ElemType data[MaxSize];
	int length;
}SqList;


p018
第一题：删除最小值，最后的元素来替换最小值，返回最小值
粗看：找到最小值，交换末尾值，删除末尾值，返回最小值
再看的话，里面有两个量需要记录：Index和MinValue,由于随机查找，序号就可以得到最小值
细看：序号标记法，O(n)得到最小值的编号，swap(),使得表长减一即可，最后返回
code:
ElemType ReturnMin_delete(SqList &List){
	//找到最小值的序号
	int MinIndex=0;
	for(int i=1;i<length;i++){
		if(List.data[i]<List.data[MinIndex])
			MinIndex=i;
	}
	//用末尾值复写在最小值的位置
	ElemType temp=List.data[MinIndex];
	MaxIndex=List.length-1;
	List.data[MinIndex]=List.data[MaxIndex];
	// 长度减一
	List.length--;
	return temp;
}
优化：一，可以双指针查找最小值的序号

int left=0,right=List.length-1,MinIndex=0;

while(left<right){
	if(List.data[left] >= List.data[MinIndex]) left++;
	else MinIndex=left;
	if(List.data[right]>= list.data[MinIndex] && left<right) right--;
    else MinIndex=right;
}
二、事实上没有必要交换，复写就可以了
三、检查必要性，如果是空表，就直接退出
if (List.length==0)
{
	cerr<<"表空，已退出"<<endl;
	exit(0);//这里很为难，不知道返回值的类型是什么？应该返回什么表示失败呢？
}
参考http://blog.csdn.net/u010046690/article/details/47105665
exit() 结束当前进程/当前程序/，在整个程序中，只要调用 exit ，就结束
return() 是当前函数返回，当然如果是在主函数main, 自然也就结束当前进程了，
如果不是，那就是退回上一层调用。
四、为了解决上面的难题，可以设计统一的bool返回值，其他的返回要求使用参数引用来实现
bool function(ElemType &returnValue,...)
{
	if(empty()) return false;
	...
}
debug:
error：stray'\243'in program 是因为出现了非ASCII码字符
final:
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

第二题：空间复杂度为O(1)的逆置
双指针：
bool Reverse(SqList &list){
	 if (List.length == 0) return false;
	int left=0,right=list.length;
	while(left<right){
		swap(list.data[left],list.data[right]);
		left++;
		right--;
	}
	return true;
}
数学关系:交换i与len-i-1
bool Reverse(SqList &list){
	if (List.length == 0) return false;
	int len = List.length;
	for(int i=0;i<len/2;i++){
		swap(List.data[i],List.data[len-i-1]);
	}
	return true;
}

第三题：删除表中所有的x，时间O(n),空间O(1)
粗看：找一个，时间O(n)，删一个，时间O(n)
a、如果不考虑顺序的话，可以采用第一题中的方法从末尾复写，
找到一个就从末尾找一个复写，记录个数，最后修改length
在优化的可以想到双指针，找到就复写
b、考虑到顺序，每一个需要移动的数字，需要移动的长度仅仅依赖于
他前面出现的x的个数k，这样看来只需要记录一下当前的k
细看：
    一、从后向前找的时候，遇到相同的直接跳过，从前向后找的时候，遇到相等的停下来
    然后把后面找到的复写掉前面的，最后修改长度就是right的值 --left的值
    二、建立一个计数器count，遇到不相等的就移动到index-count位置，至于length就
    是原来的长度去掉count
code：
bool DeleteSameValue1(SqList &list,ElemType value)
{
	if(list.length==0) return false	;
	int right=0,left=list.length-1;
	while(right<left){
		while(list.data[right] != value) right++;
		while(list.data[left] == value && right<left) left--;
		list.data[right]=list.data[left];
		list.data[left]=value;//debug:保证left可以向前动，是已经知道一个数字的交换
	}
	list.length=left;
}

bool DeleteSameValue2(SqList list,Elemtype value){
	if(list.length==0) return false	;
	int count=0,i=0;
	while(i<list.length){
		if(list.data[i] == value) count++;
		else{
			list.data[i-count] = list.data[i];
		}
		i++;//debug:忘记变量的更新
	}
	list.length-=count;
}