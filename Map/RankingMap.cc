#include <map>
#include <vector>
#include <iostream>
#include <string>

void print(std::map <std::string, int> &p) {
	/*std::vector<int>v1(p.size());
	auto j = p.begin();
	for (auto i = v1.begin(); i != v1.end(); ++i) {
		i = j;

	}*/

	for (auto it = p.begin(); it != p.end(); ++it) {
		std::cout << it->first << " " << it->second << std::endl;
	}
}

int main() {
	std::map <std::string, int> puntuation;
	puntuation["John"] = 69;
	puntuation["James"] = 0;
	puntuation["Jason"] = 99;
	puntuation["Paul"] = 69;
	puntuation["MonkeyDonkey"] = 44;

	print(puntuation);

	return 0;
}