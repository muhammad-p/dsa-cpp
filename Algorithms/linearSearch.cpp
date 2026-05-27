#include<bits/stdc++.h>
using namespace std;
int linearSearch(vector<int> a,int n)
{
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i]==n) return i;
    }
    return -1;
    
}
int main()
{
    vector<int> arr(50,0);
    arr[8]=1;

    int index1=linearSearch(arr,1);
    std::cout<<index1<<endl;
    return 0;
}