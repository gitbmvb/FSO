#include <iostream>
#include <vector>

int main() {
	unsigned int n, t, pid, temp, j = 0, acc = 0;
	scanf("%u %u", &n, &t);
	std::vector<std::pair<unsigned int, int> > p;
	for (auto i = 0; i < n; i++) {
		scanf("%u %u", &pid, &temp);
		p.push_back(std::make_pair(pid, temp*1000));
	}
	while (n) {
		p[j].second -= t;
		acc += t;
		if (p[j].second <= 0) {
			acc += p[j].second;
			printf("%u (%u)\n", p[j].first, acc);
			p.erase(p.begin() + j);
			if (j == --n) j = 0;
		} else if (++j == n) j = 0;
	}
	return 0;
}