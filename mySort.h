#include<iostream>
#include<vector>
#include<string>

using namespace std;
class MySort
{
public:
    void insertSort(vector<int> &array);
    void selectSort(vector<int> &array);
    void bubbleSort(vector<int> &array);
    void mergeSort(vector<int> &array);
    void quickSort(vector<int> &array);
private:
    void __mergeSort(vector<int> &array,int left,int right);
    void __merge(vector<int> &array,int l1,int r1,int l2,int r2);
    int __partition(vector<int> &array,int l,int r);
    void __quickSort(vector<int> &array,int l,int r);
    
};