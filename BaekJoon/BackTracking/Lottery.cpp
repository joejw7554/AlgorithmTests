#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// S: k개의 정수로 이루어진 집합 (오름차순 정렬되어 있음)
// k: 집합 S의 크기 (k > 6)
// 반환값: S에서 6개를 고르는 모든 조합을 2차원 벡터로 반환


void MakeCombination(int K, vector<int>& Combination, vector<int>& SelectedNums, vector<bool>& Selected)
{
	
	if (K > 5)
	{
		sort(Combination.begin(), Combination.end());
		for (const auto& Num : Combination)
		{
			cout << Num << " ";
		}
		cout << endl;

		return;
	}


	for (int i = 0; i < 6; i++)
	{
		if (Selected[i] == false)
		{
			Selected[i] = true;
			Combination.push_back( SelectedNums[i]);
			MakeCombination(K + 1, Combination, SelectedNums, Selected);
			Selected[i] = false;

			auto iter = find(Combination.begin(), Combination.end(), SelectedNums[i]);
			if ( iter != Combination.end())
			{
				Combination.erase(iter);
			}

		}
	}
}


void GetLottoCombinations(const vector<int>& S, int k)
{
	vector<int> SelectedNums;

	while (SelectedNums.size() < k)
	{
		int RandomIndex = rand() % S.size();
		int ChosenNumber = S[RandomIndex];
		
		if (find(SelectedNums.begin(), SelectedNums.end(), ChosenNumber)==SelectedNums.end())
		{
			SelectedNums.push_back(ChosenNumber);
		}
	}

	vector<int> Combination;
	vector<bool>Selected(k, false);

	MakeCombination(0, Combination, SelectedNums, Selected);
}

int main()
{

	
	vector<int> S = {1,2,3,5,8,13,21,34};
	int k = 6;
	GetLottoCombinations(S, k);
	// result에는 28개의 6개짜리 조합이 들어있음

}