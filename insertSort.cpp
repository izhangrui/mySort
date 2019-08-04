#include<iostream>
#include<vector>
#include<ctime>
#include<string>

using namespace std;
//插入排序
void insertSort(int *array,int st)
{
    for(int i=1;i<st;i++)
    {
        int j = i;
        while(j>0&&array[j]<array[j-1])
        {
            swap(array[j],array[j-1]);  
            j--;
        }
    }
}
//选择排序
void selectSort(int *array,int st)
{
    for(int i=0;i<st-1;i++)
    {
        int idx = i;
        for(int j=i+1;j<st;j++)
        {
            if(array[j]<array[idx])
                idx = j;    
        }
        swap(array[i],array[idx]);
    }
}
//冒泡排序
void bubbleSort(int *array,int st)
{
    for(int i=0;i<st;i++)
        for(int j=1;j<st;j++)
            if(array[j]<array[j-1])
                swap(array[j],array[j-1]);
}
void printArray(int *array,int st)
{
    for(int i=0;i<st;i++)
        cout<<array[i]<<" ";
    cout<<endl;
}
void testSort(int *array,int st,string sortName,void (*sortFun)(int*,int))
{
    clock_t startTime,endTime;
    startTime = clock();
    sortFun(array,st);
    endTime = clock();
    cout<<sortName+" take:"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
}
void copyArray(int* array,int *array1,int st)
{
    for(int i=0;i<st;i++)
        array1[i] = array[i];
}
int main()
{
    int st = 10000;//测试数组长度
    int array[st];
    int array1[st];
    int array2[st];
    //复制，使三个数组相同
    copyArray(array,array1,st);
    copyArray(array,array2,st);
    for(int i=0;i<st;i++)
        array[i] = rand()%st;
    //分别测试，算法性能
    testSort(array,st,"insertSort",insertSort);
    testSort(array1,st,"selectSort",selectSort);
    testSort(array2,st,"bublleSort",bubbleSort);
    //printArray(array,st);
    return 0;
}