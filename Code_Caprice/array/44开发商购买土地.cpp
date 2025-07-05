#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*边计算边枚举分割点，还是很考验代码掌控能力的
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<vector<int>> nums(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> nums[i][j];
            sum += nums[i][j];
        }
    }
    // 行前缀和 - 边计算边枚举分割点
    int row_prefix_sum = 0; // 累积的行前缀和
    int rows_min_val = INT_MAX;
    for (int i = 0; i < n; i++) {
        // 计算第i行的总和
        int current_row_sum = 0;
        for (int j = 0; j < m; j++) {
            current_row_sum += nums[i][j];
        }
        row_prefix_sum += current_row_sum; // 累加到前缀和

        // 如果不是最后一行，就可以在这里分割
        if (i < n - 1) {
            int upper = row_prefix_sum;       // 上半部分（第0行到第i行）
            int lower = sum - row_prefix_sum; // 下半部分（第i+1行到第n-1行）
            rows_min_val = min(rows_min_val, abs(upper - lower));
        }
    }

    // 列前缀和 - 边计算边枚举分割点
    int col_prefix_sum = 0; // 累积的列前缀和
    int cols_min_val = INT_MAX;
    for (int j = 0; j < m; j++) {
        // 计算第j列的总和
        int current_col_sum = 0;
        for (int i = 0; i < n; i++) {
            current_col_sum += nums[i][j];
        }
        col_prefix_sum += current_col_sum; // 累加到前缀和

        // 如果不是最后一列，就可以在这里分割
        if (j < m - 1) {
            int left = col_prefix_sum;        // 左半部分（第0列到第j列）
            int right = sum - col_prefix_sum; // 右半部分（第j+1列到第m-1列）
            cols_min_val = min(cols_min_val, abs(left - right));
        }
    }

    cout << min(cols_min_val, rows_min_val) << endl;
}
*/
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

