class DataStream {
    
    int val, k;
    int cnt = 0;
    
public:
    DataStream(int value, int k) {
        this->val = value;
        this->k = k;
    }
    
    bool consec(int num) {
        if (num == val) {
            if (++cnt >= k) {
                return true;
            } else {
                return false;
            }
        } else {
            cnt = 0;
            return false;
        }
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */