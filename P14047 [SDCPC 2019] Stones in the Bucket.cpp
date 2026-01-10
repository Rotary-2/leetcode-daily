#include <iostream>
#include <cstdlib>
using namespace std;

long long n;
const int N = 1e6 + 10;
int a[N];
long long sum = 0, ans = 0;

inline long long read() {
	long long x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <='9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int main() {
	int T = read();

	while (T--) {
		n = read();
		if (n == 1) {
			printf("0\n");
			continue;
		} 
		sum = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			a[i] = read();
			sum += a[i];	
		}
		
		long long x = sum % n;
		sum -= sum % n;
		long long y = sum / n;
		for (int i = 0; i < n; i++) ans += abs(a[i] - y);
		
		ans = (ans - x)/2 + x;
		printf("%lld\n", ans);
	} 
	return 0;
}

