#include <iostream>
#include <cmath>

/*
	cnt : ��ǰʱ���ܹ�����ļ������������cnt > k(�����ߵ�����������1Сʱֻ�ܸ�k̨���Դ�������
	cnt * 2 -> ��һʱ�̻�����ݵļ������������cnt * 2 > n�������˳�ѭ��
*/

using namespace std;

typedef long long LL;

int t;
LL n, k;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> k;
		LL res = 0ll;
		LL now = 0ll, cnt = 1ll;
		while (true) {
			if (cnt <= k && cnt * 2 <= n) {
				cnt *= 2;
				++now;
			}
			else {
				break;
			}
		}
		res += now;
		res += ceil(double(n - cnt) / min(cnt, k));
		cout << res << endl;
	}
	return 0;
}