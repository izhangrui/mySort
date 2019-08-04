#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include"mySort.h" 

using namespace std;
void printArray(const vector<int>array)
{
    for(int i=0;i<array.size();i++)
        cout<<array[i]<<" ";
    cout<<"\n";
}
void cheakSort(vector<int>array)
{
    bool flag = true;
    for(int i=1;i<array.size();i++)
        if(array[i]<array[i-1])
        {
            cout<<"this array is not sorted"<<endl;
            return;
        }
    cout<<"this array sort ok"<<endl;
}
template<class T>
void testSort(vector<int> array,string sortName,T *mySort,void (T::*sortFun)(vector<int>&))
{
    clock_t startTime,endTime;
    startTime = clock();
    (mySort->*sortFun)(array);
    //cheakSort(array);
    endTime = clock();
    cout<<sortName+" take:"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
    //cheakSort(array);
}
int main()
{
    
    srand(int(time(0)));
    vector<int>array(5000); 
    for(int i=0;i<array.size();i++)
        array[i] = rand()%array.size();
    MySort mySort;
    testSort(array,"bubbleSort",&mySort,MySort::bubbleSort);
    testSort(array,"insertSort",&mySort,MySort::insertSort);
    // testSort(array,"selectSort",&mySort,MySort::selectSort);
    //testSort(array,"mergeSort",&mySort,MySort::mergeSort);
    //testSort(array,"quickSort",&mySort,MySort::quickSort);
    // mySort.quickSort(array);
    // printArray(array);
    return 0;
}