#include "heap.h"
#include "sorttesthelper.h"


template<typename T>
void HeapSort1(T arr[],const int len)
{
    MaxHeap<T> maxheap = MaxHeap<T>(len);
    for(int i = 0;i<len;i++)
        maxheap.insert(arr[i]);
    for(int j = len-1;j>=0;j--)
        arr[j] = maxheap.ExtractMax();
}

template<typename T>
void HeapSort2(T arr[],const int len)
{
    MaxHeap<T> maxheap = MaxHeap<T>(arr,len);
    for(int j = len-1;j>=0;j--)
        arr[j] = maxheap.ExtractMax();
}

template<typename T>
void __shitfDowm(T arr[],const int len,int k)
{
    //左孩子 2×k+1 
    while(2*k+1<len)
    {
        int maxChildIndex = 2*k+1;
        if(maxChildIndex+1<len && arr[maxChildIndex]<arr[maxChildIndex+1])
            maxChildIndex++;
        if(arr[k]>arr[maxChildIndex])
            break;
        swap(arr[k],arr[maxChildIndex]);
        k = maxChildIndex;
    }
}


template<typename T>
void HeapSort3(T arr[],const int len)
{
    //将第一个飞叶子节点向下移动
    for(int i = (len-1)/2;i>=0;i--)
    {
        __shitfDowm(arr,len,i);
    }

    for(int i = len-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        __shitfDowm(arr,i,0);
    }


}


int main() {

    const int len = 100000;
    int* a = SortTestHelper::GenerateRandomArray(len,0,len);
    int* b = SortTestHelper::CopyArray(a,len);
    int* c = SortTestHelper::CopyArray(a,len);
    SortTestHelper::TestSort("HeapSort1",HeapSort1,a,len);
    SortTestHelper::TestSort("HeapSort2",HeapSort2,b,len);
    SortTestHelper::TestSort("HeapSort3",HeapSort3,c,len);

    //SortTestHelper::PrintArray(a,len);
    delete[] a;
    return 0;
}