// 0 - 3 months:
// Google (12) — Microsoft (5) — Amazon (4) — Meta (2) — Bloomberg (2)

// 6 months ago:
// Apple (7) — Yandex (4) — Infosys (2) — Adobe (2) — EPAM Systems (2) — TikTok (2) — Zoho (2) — Visa (2) — Zomato (2)


// Problem_Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include<bits/stdc++.h>
using namespace std;


// Time o(nlogn) space o(n)

// vector<int> twoSum(vector<int>& numbers, int target) {
  
//     map<int,int>mp;
//     vector<int>ans;
//     for(int i = 0; i < (int)numbers.size(); i++){
//         if(mp.find(target - numbers[i]) != mp.end()){
//             ans.push_back(mp[target - numbers[i]]);
//             ans.push_back(i + 1);
//             break;
//         }
//         mp[numbers[i]] = i + 1;
//     }
//     return ans;
// }


// Time o(n) space o(1)

vector<int> twoSum(vector<int>& numbers, int target) {
  
    vector<int>ans;
    int l = 0, r = numbers.size() - 1;

    while(l < r){
        if(numbers[l] + numbers[r] == target){
             ans.push_back(l + 1);
             ans.push_back(r + 1);
             break;
        }
        else if(numbers[l] + numbers[r] > target){
            r--;
        }
        else{
            l++;
        }
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {2, 7, 11, 15};
    int target = 9;
    vector<int>ans = twoSum(nums, target);

    cout << ans[0] << " " << ans[1] << "\n";

}