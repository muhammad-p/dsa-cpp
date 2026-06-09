#include <bits/stdc++.h>
#define endl char(10)

using namespace std;

typedef long long ll;

vector<int> insertionSort(vector<int> nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = i; j > 0 && nums[j] < nums[j - 1]; j--)
            swap(nums[j], nums[j - 1]);
    }
    return nums;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> ans = insertionSort({1, 4, 3, -22, 32});
    for (int x : ans)
        cout << x << " ";

    return 0;
}