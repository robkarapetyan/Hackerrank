#include "pch.h"
#include <iostream>
#include "queue.h"
#include <fstream>

int main()
{

	std::ifstream fin("test.txt");
	std::ofstream fout{ "result.txt"};
	int crnt,n;
	Queue<int> b;

	fin >> n;
	for (int i = 0; i < n; ++i)
	{
		fin >> crnt;
		switch (crnt)
		{
			case 1:
			{
				fin >> crnt;
				b.enqueue(crnt);
				break;
			}
			case 2:
			{	
				b.dequeue();
				break;
			}
			case 3:
			{	
				fout << b.front() << std::endl;
				break;
			}
			default:
				continue;
	}
	}
	fin.close();
	fout.close();
	return 0;
}
