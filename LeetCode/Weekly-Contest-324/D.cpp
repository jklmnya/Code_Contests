class Solution {
    
    vector<pair<int, int>> vec;
    
    int foo(int idx) {
        for (int i = 0;i<vec.size();++i) {
            auto& range = vec[i];
            if (idx >= range.first && idx <= range.second) {
                return i;
            }
        }    
        return 0;
    }
    
    int fun(int a, int b) {
        while (a != b) {
            if (a > b) {
                a = a % 2 ? ((a - 1) >> 1) : (a >> 1);
            } else {
                b = b % 2 ? ((b - 1) >> 1) : (b >> 1);
            }
        }
        return foo(a);
    }
    
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& qs) {
        vec.push_back( {1, 1} );
        while (--n) {
            auto& last = vec.back();
            vec.push_back( {last.first * 2, last.second * 2 + 1} );
        }
        int m = qs.size();
        vector<int> res;
        for (auto& q : qs) {
            int a = foo(q[0]);
            int b = foo(q[1]);
            res.push_back(a + b + 1 - 2 * fun(q[0], q[1]));
        }
        return res;
    }
};