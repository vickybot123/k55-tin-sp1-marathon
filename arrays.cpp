#include <iostream>
#include "arrays.h"

using namespace std ;

void arrays::inputIntArray(int arr[], int len)
{
    for (int i=0; i<len; i++)
    {
        cout << "["<< i << "] = ";
        cin >> arr[i];
    }
}

void arrays::printIntArray(int arr[], int len)
{
    cout << "[";
    for (int i=0; i<len; i++)
        cout << (i == 0 ? "" : ", ") << arr[i];
    cout << "]";
}

int arrays::sumIntArray(int arr[], int len)
{
    int sum = 0;
    for (int i=0; i<len; i++)
        sum += arr[i];
    return sum;
}

int arrays::maxIndexIntArray(int arr[], int len)
{
    int maxIndex = 0;
    for (int i=1; i<len; i++)
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    return maxIndex;
}

void arrays::removeIntArrayAt(int origin[], int len, int index, int output[])
{
    for (int i=0; i<index; i++)
        output[i] = origin[i];
    for (int i=index+1; i<len; i++)
        output[i-1] = origin[i];
}

void arrays::inputLongLongArray(long long arr[], int len)
{
    for( int i=0; i<len; i++)
    {
        cout << "["<< i<< "]=";
        cin >> arr[i];
    }
}

void arrays::printLongLongArray(long long arr[], int len)
{
    cout<<"[";
    for(int i=0 ; i<len ; i++)
        cout <<(i==0?"":", ") <<arr[i];
    cout << "]";
}

long long arrays::sumLongLongArray(long long arr[], int len)
{
    long long sum=0;
    for(int i=0; i<len; i++)
        sum += arr[i];
    return sum;
}

int arrays::maxIndexLongLongArray(long long arr[], int len)
{
    int maxIndex = 0;
    for (int i=1; i<len; i++)
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    return maxIndex;
}

