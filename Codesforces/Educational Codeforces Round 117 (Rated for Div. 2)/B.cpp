#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>

/*
	greedy -> ��n��ʼѡ������a�Ҳ�����b������(n / 2) - 1�����������
	�������ѡ������������(n / 2) - 1�������ߣ�ʣ������������b����˵�����������
*/

using namespace std;

int T, n, a, b;
int ss[110];

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> a >> b;
		int e = n, cnt = 0;
		while (e > a && cnt < (n / 2) - 1) {
			if (e != b)
				ss[++cnt] = e;
			--e;
		}
		ss[++cnt] = a;
		if (a == e)
			--e;
		if (cnt == n / 2 && b >= e) {
			while (e) {
				if (e != a)
					ss[++cnt] = e;
				--e;
			}
			ss[++cnt] = b;
			for (int i = 1; i <= n; ++i)
				cout << ss[i] << ' ';
			cout << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}