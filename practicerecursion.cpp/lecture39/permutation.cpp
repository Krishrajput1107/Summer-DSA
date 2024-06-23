#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<int>> &ans, vector<int> &nums, int index) {
    // base case
    if (index >= nums.size()) {
        ans.push_back(nums);
        return;
    }
    // recursive case
    for (int j = index; j < nums.size(); j++) {
        swap(nums[j], nums[index]);
        solve(ans, nums, index + 1); // Use index + 1 to progress in the recursion
        // backtrack
        swap(nums[j], nums[index]);
    }
}

vector<vector<int>> funcn(vector<int> &nums) {
    vector<vector<int>> ans;
    int index = 0;
    solve(ans, nums, index);
    return ans;
}

int main() {
    vector<int> nums;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    nums.resize(size);
    cout << "Enter elements: ";
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> ans = funcn(nums);

    cout << "Permutations: " << endl;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
