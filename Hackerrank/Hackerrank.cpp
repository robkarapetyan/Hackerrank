#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <stack>


int main()
{

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
			if (!outp.empty())
			{
				if (crnt > maximums.top())
					max = crnt;
				else
					max = maximums.top();
			}
			else
			{
				max = crnt;
			}
			outp.push(crnt);
			if (!maximums.empty())
			{
				if (maximums.top() != max)
				{
					maximums.push(max);
				}
			}
			else
			{
				maximums.push(max);
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
			std::cout << maximums.top() << std::endl;
			// if(outp.top() != max)
			// outp.push(max);
			break;
		}
		default:
			continue;
		}
	}
	return 0;
}
