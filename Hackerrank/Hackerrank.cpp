#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <stack>


int main(){
std::stack<int> maximums, outp;
int N, crnt;
std::ifstream find("text.txt");
find >> N;
for (int i = 0; i < N; ++i) {
	int max = 0;
	find >> crnt;
	switch (crnt)
	{
	case 1:
	{
		find >> crnt;
		outp.push(crnt);
		if (!maximums.empty())
		{
			if (maximums.top() <= crnt)
			{
				maximums.push(crnt);
			}
		}
		else
		{
			maximums.push(crnt);
		}
		break;
	}
	case 2:
	{
		if (!outp.empty())
		{
			if (outp.top() == maximums.top())
			{
				maximums.pop();
			}
			outp.pop();
		}
		break;
	}
	case 3:
	{
		if (!maximums.empty())
		{
			std::cout << maximums.top() << std::endl;
		}
		break;
	}
	default:
		continue;
	}
}
	return 0;
}