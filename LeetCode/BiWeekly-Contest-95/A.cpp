class Solution {
    
    const int N = 1e4, V = 1e9, M = 100;
    
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool f1 = length >= N || width >= N || height >= N || (long long)length * width * height >= V;
        bool f2 = mass >= M;
        if (f1 && f2) {
            return "Both";
        } else if (!f1 && !f2) {
            return "Neither";
        } else if (f1 && !f2) {
            return "Bulky";
        } else if (!f1 && f2) {
            return "Heavy";
        }
        return "";
    }
};