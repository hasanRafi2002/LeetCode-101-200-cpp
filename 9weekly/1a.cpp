#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> partitionString(string s) {
        if (s.empty()) return {};
        
        const long long base1 = 131;
        const long long base2 = 1331;
        const long long mod1 = 1000000007;
        const long long mod2 = 1000000009;
        
        unordered_set<pair<long long, long long>, PairHash> seen;
        vector<string> res;
        int i = 0;
        int n = s.length();
        
        while (i < n) {
            long long hash1 = 0;
            long long hash2 = 0;
            int j = i;
            bool found = false;
            while (j < n) {
                int c = s[j] - 'a' + 1;
                hash1 = (hash1 * base1 + c) % mod1;
                hash2 = (hash2 * base2 + c) % mod2;
                pair<long long, long long> current_hash = {hash1, hash2};
                
                if (seen.find(current_hash) == seen.end()) {
                    seen.insert(current_hash);
                    res.push_back(s.substr(i, j - i + 1));
                    i = j + 1;
                    found = true;
                    break;
                } else {
                    j++;
                }
            }
            if (!found && i < n) {
                res.push_back(s.substr(i));
                seen.insert({hash1, hash2});
                i = n;
            }
        }
        return res;
    }
    
private:
    struct PairHash {
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 1);
        }
    };
};

// ---------- MAIN FUNCTION ----------
int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    
    Solution sol;
    vector<string> result = sol.partitionString(s);
    
    cout << "Output Segments:\n";
    for (const string& segment : result) {
        cout << "\"" << segment << "\" ";
    }
    cout << endl;

    return 0;
}
