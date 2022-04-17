class ATM {
public:

    vector<long long> v;
    unordered_map<int, int> vv;

    ATM() {
        vv.emplace(0, 20);
        vv.emplace(1, 50);
        vv.emplace(2, 100);
        vv.emplace(3, 200);
        vv.emplace(4, 500);
        v.resize(5);
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i)
            v[i] += banknotesCount[i];
    }

    vector<int> withdraw(int amount) {
        vector<int> w(5);
        for (int i = 4; i >= 0; --i) {
            long long t = amount / vv[i];
            w[i] = min(v[i], t);
            amount -= w[i] * vv[i];
        }
        if (amount == 0) {
            for (int i = 0; i < 5; ++i)
                v[i] -= w[i];
            return w;
        }
        else {
            return { -1 };
        }
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */