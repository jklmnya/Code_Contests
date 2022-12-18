class Allocator {
    
    int len;
    vector<bool> vec;
    unordered_map<int, vector<pair<int, int>>> vv;
    
public:
    Allocator(int n) {
        len = n;
        vec.resize(n);
    }
    
    int allocate(int size, int mID) {
        int s = 0;
        while (s < len) {
            if (!vec[s]) {
                int e = s;
                while (e < len && !vec[e]) {
                    ++e;
                }
                if (e - s >= size) {
                    vv[mID].push_back({s, size});
                    // cout << s << ' ' << s + size << '\n';
                    for (int i = s;i<s + size;++i) {
                        vec[i] = true;
                    }
                    return s;
                } else {
                    s = e;
                }
            } else {
                ++s;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        if (vv.count(mID)) {
            int res = 0;
            for (auto& [s, size] : vv[mID]) {
                res += size;
                for (int i = s;i<s + size;++i) {
                    vec[i] = false;
                }
            }
            vv.erase(mID);
            return res;
        }
        return 0;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 
 [null, 0, 1, 2, 1, 3, 1, 6, 3, -1, 0]
 
 */