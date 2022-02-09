class Bitset {
    
    unordered_set<int> zero, ones;
    int ss;
    
public: 
    Bitset(int size) {
        ss = size;
        for (int i = 0;i<ss;++i)
            zero.emplace(i);
    }
    
    void fix(int idx) {
        if (!ones.count(idx)) {
            ones.emplace(idx);
            zero.erase(idx);
        }
    }
    
    void unfix(int idx) {
        if (!zero.count(idx)) {
            zero.emplace(idx);
            ones.erase(idx);
        }
    }
    
    void flip() {
        swap(zero, ones);
    }
    
    bool all() {
        return ones.size() == ss;
    }
    
    bool one() {
        return ones.size() >= 1;
    }
    
    int count() {
        return ones.size();
    }
    
    string toString() {
        string res(ss, '0');
        for (auto i : ones)
            res[i] = '1';
        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
