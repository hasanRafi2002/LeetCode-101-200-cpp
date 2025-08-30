


// class Solution {
// public:

//     int h(const string& x, const string& y) {
//         int z = 0;
//         while (z < x.size() && z < y.size() && x[z] == y[z]) {
//             z++;
//         }
//         return z;
//     }


//     vector<int> longestCommonPrefix(vector<string>& a) {
//         int b = a.size();
//         if (b == 1) return {0};
//         if (b == 2) return {0, 0};



//         vector<int> c(b - 1);
//         for (int d = 0; d < b - 1; d++) {
//             c[d] = h(a[d], a[d + 1]);
//         }

//         vector<int> e(b - 1);
//         e[0] = c[0];
//         for (int f = 1; f < b - 1; f++) {
//             e[f] = max(e[f - 1], c[f]);
//         }

//         vector<int> g(b - 1);
//         g[b - 2] = c[b - 2];
//         for (int j = b - 3; j >= 0; j--) {
//             g[j] = max(c[j], g[j + 1]);
//         }

//         vector<int> k(b, 0);
//         for (int m = 0; m < b; m++) {
//             int n = 0;
//             if (m - 2 >= 0) {
//                 n = e[m - 2];
//             }

//             int o = 0;
//             if (m - 1 >= 0 && m + 1 < b) {
//                 o = h(a[m - 1], a[m + 1]);
//             }

//             int p = 0;
//             if (m <= b - 3) {
//                 p = g[m + 1];
//             }

//             k[m] = max({n, o, p});
//         }

//         return k;
//     }

// };
