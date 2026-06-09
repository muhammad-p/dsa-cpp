#include<bits/stdc++.h>
void bubbleSort(std::vector <int> &nums,int low,int high)
{
    if(high<=low)
        return;
    for(int i=low; i<high;i++)
    if(nums[i]>nums[i+1])
        std::swap(nums[i],nums[i+1]);
    bubbleSort(nums,low,high-1);
}
int main()
{
    std::vector<int> nums = {0, 11, 982, 33, 1, -212, 212, 22, 3, 1, 0, 1, 2};
    bubbleSort(nums, 0, nums.size() - 1);
    for (int x : nums)
        std::cout << x << " ";
    return 0;
}