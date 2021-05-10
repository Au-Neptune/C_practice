#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector< vector <char> > list;
	int width, length;

	cout << "請輸入寬 高\n";
	while (cin >> width >> length)
	{
		char alphabet = 'a';
		// 先找最後的英文字
		char last = alphabet + (width * length - (width - 2) * (length - 2)) - 1;
		list.clear();

		for (int i = 0; i < length; i++)
		{
			vector <char> temp;
			for (int j = 0; j < width; j++)
			{
				if (j == 0) // 第一橫列
					temp.push_back(alphabet++);

				else if (i == 0) // 第一直行
					temp.push_back(last--);

				else if (i == length - 1) // 最後直行
					temp.push_back(alphabet++);

				else if (j == width - 1)// 最後橫列
					temp.push_back(last--);

				else
					temp.push_back(' ');
			}
			list.push_back(temp);
		}

		for (int i = 0; i < list.size(); i++)
		{
			for (int j = 0; j < list[i].size(); j++)
				cout << list[i][j];
			cout << endl;
		}

		cout << "\n請輸入寬 高\n";
	}
	return 0;
}
