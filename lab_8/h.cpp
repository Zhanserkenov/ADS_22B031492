//2304
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned ll
#define ioi exit(0);
 
#define inf (int)1e9+7
 
#define F first
#define S second
 
#define pb push_back
#define ppb pop_back
 
#define lb(x) lower_bound(x)
#define ub(x) upper_bound(x)
 
#define sz(x) x.size()
 
#define all(x) x.begin(),x.end()
 
#define NFS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

string findLongestCommonSubstring(vector<string>& strings) {
    int K = strings.size();
    if (K == 0) return "";

    int minLen = strings[0].length();
    for (int i = 1; i < K; i++) {
        minLen = min(minLen, (int)strings[i].length());
    }

    string longestCommonSubstring = "";
    int maxLen = 0;

    for (int i = 0; i < minLen; i++) {
        for (int j = i + 1; j <= minLen; j++) {
            string substring = strings[0].substr(i, j - i);
            bool isCommon = true;

            for (int k = 1; k < K; k++) {
                if (strings[k].find(substring) == string::npos) {
                    isCommon = false;
                    break;
                }
            }

            if (isCommon && substring.length() > maxLen) {
                maxLen = substring.length();
                longestCommonSubstring = substring;
            }
        }
    }

    return longestCommonSubstring;
}

int main() {

	NFS
	
    int K;
    cin >> K;
    vector<string> strings(K);

    for (int i = 0; i < K; i++){
        cin >> strings[i];
    }

    string longestCommonSubstring = findLongestCommonSubstring(strings);

    cout << longestCommonSubstring;

   	ioi
}
