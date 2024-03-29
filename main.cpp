/* USER: u065
LANG: C++
TASK: hydrocarbons */

#include <iostream>
#include <fstream>
#include <vector>

int N, i, plethos;
float qlt, a, b, c;
std::vector<float> qualities;
std::vector<int> number;

void sort(std::vector<float> &to_sort, std::vector<int> &list) 
{
	int j, q, temp = 0;
	float tmpfl = 0;

	for (j = 0; j <= to_sort.size() - 1; j++)
	{
		q = j;
		while (q >= j && q <= to_sort.size() - 1)
		{
			
			if (j != q && to_sort[j] <= to_sort[q])
			{
				if (to_sort[j] < to_sort[q])
				{
					temp = list[j];
					list[j] = list[q];
					list[q] = temp;
				}
				else if (to_sort[j] == to_sort[q])
				{
					if (list[j] > list[q])
					{
						temp = list[j];
						list[j] = list[q];
						list[q] = temp;
					}
				}

				q++;
				continue;
			}
			else
			{
				q++;
				continue;
			}
		}
	}
}

int main()
{
	std::fstream file;
	file.open("hydrocarbons.in", std::ios::in);

	file >> N;
	for (i = 0; i <= N - 1; i++)
	{
		file >> a;
		file >> b;
		file >> c;

		qlt = a - a * b / 3000 - c * a / 40;

		if (qlt > 0)
		{
			number.push_back(i + 1);
			qualities.push_back(qlt);
			plethos++;
		}
		else if (qlt <= 0)
			continue;
	}

	file.close();

	if(!number.empty())
		sort(qualities, number);

	file.open("hydrocarbons.out", std::ios::out);
	file << plethos << std::endl;

	if (!number.empty())
	{
		for(i=0; i<=number.size()-1; i++)
			file << number[i] << " ";
	}

	file.close();

	return 0;
}
