#include <bits/stdc++.h>
void merge(std::vector<int> &arr, const int low, int mid, const int high)
{
    std::vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }
    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= high)
        temp.push_back(arr[right++]);
    for (int i = 0; i < temp.size(); i++)
        arr[low+i] = temp[i];
}
void mS(std::vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;

    mS(arr, low, mid);
    mS(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    std::vector<int> nums={1,2,3,55,4,7,1,1,3,1,4,6,0,5};
    mS(nums,0,nums.size()-1);
    for(int x:nums)
        std::cout<<x<<" ";
    return 0;
}