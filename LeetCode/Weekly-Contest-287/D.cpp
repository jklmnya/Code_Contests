class Encrypter {

    vector<char> k;
    vector<string> v;
    vector<string> d;
    int f[26];
    unordered_map<char, string> vv;

public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        k = move(keys);
        v = move(values);
        d = move(dictionary);
        for (int i = 0; i < k.size(); ++i)
            f[k[i] - 'a'] = i;
        for (int i = 0; i < k.size(); ++i)
            vv.emplace(k[i], v[i]);
    }

    string encrypt(string word1) {
        string res = "";
        for (char ch : word1) {
            int idx = f[ch - 'a'];
            res += v[idx];
        }
        return res;
    }

    int decrypt(string word2) {
        int res = 0;
        for (auto& word : d) {
            string now = "";
            for (char ch : word)
                now += vv[ch];
            if (now == word2)
                ++res;
        }
        return res;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */