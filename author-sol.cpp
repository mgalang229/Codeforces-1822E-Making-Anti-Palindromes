#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void test_case(int& tc) {
	int n;
	string s;
	cin >> n >> s;
	if (n % 2 == 1) {
		cout << "-1\n";
		return;
	}
	int freq[26];
	memset(freq, 0, sizeof(freq));
	for (int i = 0; i < n; i++) {
		freq[s[i]-'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (freq[i] * 2 > n) {
			cout << "-1\n";
			return;
		}
	}
	int pairs = 0;
	int freq_pairs[26];
	memset(freq_pairs, 0, sizeof(freq_pairs));
	for (int i = 0; i * 2 < n; i++) {
		if (s[i] == s[n-1-i]) {
			pairs++;
			freq_pairs[s[i]-'a']++;
		}
	}
	for (int i = 0; i < 26; i++) {
		// If freq_pairs[i] > pairs / 2, then we need to use/swap characters s[i] != s[n-1-i] (i.e., not included in 'pairs')
		if (freq_pairs[i] * 2 > pairs) {
			cout << freq_pairs[i] << "\n";
			return;
		}
	}
	cout << (pairs + 1) / 2 << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
