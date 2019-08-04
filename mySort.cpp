#include"mySort.h"

void MySort::insertSort(vector<int> &array)
{
    for(int i=1;i<array.size();i++)
    {
        int j = i;
        while(j>0&&array[j]<array[j-1])
        {
            swap(array[j],array[j-1]);
            j--;
        }
    }
}

void MySort::selectSort(vector<int> &array)
{
    for(int i=0;i<array.size()-1;i++)
    {
        int minIdx = i;
        for(int j=i+1;j<array.size();j++)
        {
            if(array[j]<array[minIdx])
                minIdx = j;
        }
        swap(array[i],array[minIdx]);
    }
}

void MySort::bubbleSort(vector<int> &array)
{
    for(int i=0;i<array.size();i++)
    {
        for(int j=1;j<array.size()-1;j++)
            if(array[j]<array[j-1])
                swap(array[j],array[j-1]);
    }
}

void MySort::__merge(vector<int> &array,int l1,int r1,int l2,int r2)
{
    //cout<<r1<<" ";
    vector<int> temp(r2-l1+1);
    for(int i=l1;i<=r2;i++)
        temp[i-l1] = array[i];
    int i=0;
    int j=l2-l1;
    int k=l1;
    while(i<=(r1-l1)||j<=(r2-l1))
    {
        if(i>(r1-l1))
        {
            array[k]=temp[j];
            j++;
        }
        else if(j>(r2-l1))
        {
            array[k]=temp[i];
            i++;
        }
        else if(temp[i]>temp[j])
        {
            array[k] = temp[j];
            j++;
        }
        else
        {
            array[k] = temp[i];
            i++;
        }
        k++;
    }
}
void MySort::__mergeSort(vector<int> &array,int left,int right)
{
    if(left>=right) return;
    int mid = (right-left)/2+left;
    __mergeSort(array,left,mid);
    __mergeSort(array,mid+1,right);
    __merge(array,left,mid,mid+1,right);
}
void MySort::mergeSort(vector<int> &array)
{
    __mergeSort(array,0,array.size()-1);
}


int MySort::__partition(vector<int> &array,int l,int r)
{
    int v=array[l];
    int j = l+1; 
    for(int i=l+1;i<=r;i++)
    {
        if(array[i]<v)
        {
            swap(array[i],array[j]);
            j++;
        }
    }
    swap(array[l],array[j-1]);
    return j-1;

}
void MySort::__quickSort(vector<int> &array,int l,int r)
{
    if(l>=r) return;
    int mid = __partition(array,l,r);
    __quickSort(array,l,mid-1);
    __quickSort(array,mid+1,r);
}
void MySort::quickSort(vector<int> &array)
{
    __quickSort(array,0,array.size()-1);
}

