class CountIntervals {
    
    int res = 0;
    map<int, int> vv;
    vector<int> de;
    
public:
    
    CountIntervals() {
        vv.emplace(-1, -1);
        vv.emplace(1e9 + 10, 1e9 + 10);
    }
    
    void add(int left, int right) {
        auto iterL = vv.upper_bound(left);
        auto iterR = vv.upper_bound(right);
        --iterL;
        --iterR;
        int l, r;
        if (left <= iterL->second) {
            l = min(left, iterL->first);
        } else {
            l = left;
            ++iterL;
        }
        if (right >= iterR->first) {
            r = max(right, iterR->second);
        } else {
            r = right;
            --iterR;
        }
        de.clear();
        while (iterL->first <= iterR->first) {
            de.push_back(iterL->first);
            ++iterL;
        }
        res += r - l + 1;
        for (int d : de) {
            res -= vv[d] - d + 1;
            vv.erase(d);
        }
        vv.emplace(l, r);
    }
    
    int count() {
        return res;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */