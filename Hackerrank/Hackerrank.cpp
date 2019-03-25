#include <iostream>
#include <sstream>
#include <stack>

int main() {

	std::stack<int> container, outp;
	std::string ss, maximums;
	int N;

	std::cin >> N;
	for (int i = 0; i <= N; ++i) {
		std::getline(std::cin, ss);
		std::stringstream aa(ss);
		int max = 0;
		ss = "";
		aa >> ss;
		if (ss == "1") {
			aa >> ss;
			if (!outp.empty()) {
				if (stoi(ss) > outp.top()) {
					outp.push(stoi(ss));
				}

			}
			else {
				outp.push(stoi(ss));
			}
			container.push(stoi(ss));
		}
		else if (ss == "2") {
			if (!container.empty()) {
				if ((container.top() == outp.top()) && !outp.empty()) {
					outp.pop();
					container.pop();
				}
				else {
					container.pop();
				}
			}
		}
		else if (ss == "3") {
			std::cout << outp.top() << std::endl;
			// if(outp.top() != max)
			// outp.push(max);
		}
	}
	return 0;
}
