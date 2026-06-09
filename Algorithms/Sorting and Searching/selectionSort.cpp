#include <bits/stdc++.h>
#define endl char(10)

using namespace std;

typedef long long ll;

vector<int> selectionSort(vector<int> nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i; j < nums.size(); j++)
            if (nums[j]< nums[minIndex])
                minIndex=j;
        swap(nums[minIndex],nums[i]);
    }
    return nums;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> ans = selectionSort({1, 4, 3, -22, 32});
    for (int x : ans)
        cout << x << " ";
    return 0;
}