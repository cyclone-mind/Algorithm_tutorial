#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> nums(n, vector<int>(m,0));
	int sum = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0; j < m; j++) {
			cin >> nums[i][j];
			sum += nums[i][j];
		}
	}

	// 计算行前缀和
	vector<int> rowPrefixSum(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			rowPrefixSum[i] += nums[i][j];
		}
		rowPrefixSum[i] += (i > 0 ? rowPrefixSum[i - 1] : 0);
	}
	// 计算列前缀和
	vector<int> colPrefixSum(m, 0);
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			colPrefixSum[j] += nums[i][j];
		}
		colPrefixSum[j] += (j > 0 ? colPrefixSum[j - 1] : 0);
	}

	// 计算差值
	int result = INT_MAX;
	for (int i = 0; i < n-1;i++) {
		result = min(result, abs(sum - 2 * rowPrefixSum[i]));
	}
	for (int i = 0; i < m-1;i++) {
		result = min(result, abs(sum - 2 * colPrefixSum[i]));
	}
	cout << result << endl;
	cin.get();
	cin.get();
	return 0;
}