#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int cases;
	cout << "Input:\n";
	cin >> cases;

	while (cases--)
	{
		int size;
		cin >> size;

		vector<int> *streets = new vector<int>(size);
		vector<int> *distances = new vector<int>(size);

		for (int i = 0; i < size; i++)
			cin >> streets->at(i);

		for (int i = 0; i < size; i++)
		{
			int sum = 0;
			for (int j = 0; j < size; j++)
				if (i != j)
					sum += abs(streets->at(i) - streets->at(j));
			distances->at(i) = sum;
			sum = 0;
		}
		
		cout << "Output:\n" << *min_element(distances->begin(), distances->end()) << endl;
	}
	return 0;
}

/* Sample Execution:
Input:
2
2 2 4
Output:
2
3 2 4 6
Output:
4
Press any key to continue . . .
*/