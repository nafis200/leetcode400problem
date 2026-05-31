// Goldman Sachs (3) — Google (2) — Roku (2)

// Problem_Link:
// https://leetcode.com/problems/backspace-string-compare/description/

#include <bits/stdc++.h>
using namespace std;

// time o(n) space o(n)

// string compare(string s){
//     string ans;
//     for(int i = 0; i < (int)s.size(); i++){
//          if(s[i] == '#'){
//             if(!ans.empty()){
//                 ans.pop_back();
//             }
//          }
//          else{
//             ans.push_back(s[i]);
//          }
//     }
//     return ans;
// }

// bool backspaceCompare(string s, string t) {
//     return (compare(s) == compare(t));
// }


// abcs#c##
// ab

bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        
        int skipS = 0; // s স্ট্রিংয়ের ব্যাকস্পেস কাউন্টার
        int skipT = 0; // t স্ট্রিংয়ের ব্যাকস্পেস কাউন্টার
        
        while (i >= 0 || j >= 0) {
            
            // ১. s স্ট্রিংয়ের জন্য পরবর্তী বৈধ ক্যারেক্টার খুঁজে বের করা
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break; // বৈধ ক্যারেক্টার পাওয়া গেছে, লুপ থেকে বের হও
                }
            }
            
            // ২. t স্ট্রিংয়ের জন্য পরবর্তী বৈধ ক্যারেক্টার খুঁজে বের করা
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else {
                    break; // বৈধ ক্যারেক্টার পাওয়া গেছে, লুপ থেকে বের হও
                }
            }
            
            // ৩. শর্টকাট ছাড়া সাধারণ if-else দিয়ে পজিশন চেক করা:
            
            // s স্ট্রিংয়ে ক্যারেক্টার বাকি আছে (i >= 0), কিন্তু t স্ট্রিং শেষ হয়ে গেছে (j < 0)
            if (i >= 0 && j < 0) {
                return false; 
            }
            
            // t স্ট্রিংয়ে ক্যারেক্টার বাকি আছে (j >= 0), কিন্তু s স্ট্রিং শেষ হয়ে গেছে (i < 0)
            if (j >= 0 && i < 0) {
                return false;
            }
            
            // যদি দুটি স্ট্রিংয়েই বৈধ ক্যারেক্টার বাকি থাকে, তবে তাদের তুলনা করা
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false; // ক্যারেক্টার দুটি না মিললে false
                }
            }
            
            // পয়েন্টার দুটিকে এক ঘর বামে সরানো
            i--;
            j--;
        }
        
        // সব ক্যারেক্টার মিলে গেলে true
        return true;
    }

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //   string s = "xywrrmp", t = "xywrrmu#p";
  string s = "ab##", t = "c#d#";
  bool ans = backspaceCompare(s, t);
  cout << ans << "\n";
}
