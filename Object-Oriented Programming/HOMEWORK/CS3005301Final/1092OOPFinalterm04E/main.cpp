#include<iostream>
#include<string>
using namespace std;

int main() {
	unsigned int match_table_rows[26];
	unsigned int match_table_cols[26];

	int m;
	int n;
	while (std::cin >> m >> n) {

		if (m == 0 && n == 0)
			return 0;

		for (int i = 0; i < 26; i++) {

			match_table_rows[i] = match_table_cols[i] = (unsigned int)(1 << i);
		}

		while (m-- > 0) {
			char c0, c1;
			std::cin >> c0 >> c1;
			match_table_rows[c0 - 'a'] |= (unsigned int)(1 << (c1 - 'a'));
			match_table_cols[c1 - 'a'] |= (unsigned int)(1 << (c0 - 'a'));
		}

		for (int k = 0; k < 5; k++) {

			for (int i = 0; i < 26; i++) {
				for (int j = 0; j < 26; j++) {
					unsigned int transition_i_j = (match_table_rows[i] & match_table_cols[j]) ? 1 : 0;
					match_table_rows[i] |= (unsigned int)(transition_i_j << j);
					match_table_cols[j] |= (unsigned int)(transition_i_j << i);
				}
			}
		}

		string s0, s1;
		while (n-- > 0) {
			cin >> s0 >> s1;
			bool is_matched = false;

			if (s0.size() == s1.size()) {
				is_matched = true;

				for (int i = 0; i < s0.size(); i++) {

					bool found_match = ((match_table_rows[s0[i] - 'a'] >> (s1[i] - 'a')) & 1);
					if (!found_match) {
						is_matched = false;
						break;
					}
				}

			}

			if (is_matched) {
				cout << "yes" << endl;
			}
			else {
				cout << "no" << endl;
			}
		}
	}

	return 0;
}