#include <iostream>
#include <vector>
int pIndex(std::vector<int> &nums, int left, int right)
{
    int i = left, j = right;
    while (i < j)
    {
        while (nums[i] <= nums[left] && i <= right - 1)
            i++;
        while (nums[j] > nums[left] && j >= left + 1)
            j--;
        if (i < j)
            std::swap(nums[i], nums[j]);
    }
    std::swap(nums[left], nums[j]);
    return j;
}
void quickSort(std::vector<int> &nums, int low, int high)
{
    if (low >= high)
        return;
    int pivotIndex = pIndex(nums, low, high);
    quickSort(nums, low, pivotIndex - 1);
    quickSort(nums, pivotIndex + 1, high);
}

int main()
{
    std::vector<int> nums = {0, 11, 982, 33, 1, -212, 212, 22, 3, 1, 0, 1, 2};
    quickSort(nums, 0, nums.size() - 1);
    for (int x : nums)
        std::cout << x << " ";
    return 0;
}