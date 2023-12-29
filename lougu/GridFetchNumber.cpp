#include <iostream>
#include <algorithm>

/*
 * # [NOIP2000 提高组] 方格取数

## 题目背景

NOIP 2000 提高组 T4

## 题目描述

设有 $N \times N$ 的方格图 $(N \le 9)$，我们将其中的某些方格中填入正整数，而其他的方格中则放入数字 $0$。如下图所示（见样例）:

![](https://cdn.luogu.com.cn/upload/image_hosting/0bpummja.png)

某人从图的左上角的 $A$ 点出发，可以向下行走，也可以向右走，直到到达右下角的 $B$ 点。在走过的路上，他可以取走方格中的数（取走后的方格中将变为数字 $0$）。
此人从 $A$ 点到 $B$ 点共走两次，试找出 $2$ 条这样的路径，使得取得的数之和为最大。

## 输入格式

输入的第一行为一个整数 $N$（表示 $N \times N$ 的方格图），接下来的每行有三个整数，前两个表示位置，第三个数为该位置上所放的数。一行单独的 $0$ 表示输入结束。

## 输出格式

只需输出一个整数，表示 $2$ 条路径上取得的最大的和。

## 样例 #1

### 样例输入 #1

```
8
2 3 13
2 6  6
3 5  7
4 4 14
5 2 21
5 6  4
6 3 15
7 2 14
0 0  0
```

### 样例输出 #1

```
67
```

## 提示

数据范围：$1\le N\le 9$。
 */
using namespace std;

const int MAX_N = 10;
int grid[MAX_N][MAX_N] = {0};
int dp[MAX_N][MAX_N][MAX_N] = {0};

int main() {
    int N;
    cin >> N;

    int x, y, value;
    while (cin >> x >> y >> value, x || y || value) {
        grid[x][y] = value;
    }

    for (int x1 = 1; x1 <= N; x1++) {
        for (int y1 = 1; y1 <= N; y1++) {
            for (int x2 = 1; x2 <= N; x2++) {
                int y2 = x1 + y1 - x2;
                if (y2 < 1 || y2 > N) continue;

                int maxVal = max({dp[x1 - 1][y1][x2], dp[x1][y1 - 1][x2], dp[x1 - 1][y1][x2 - 1], dp[x1][y1 - 1][x2 - 1]});
                dp[x1][y1][x2] = maxVal + grid[x1][y1];
                if (x1 != x2 || y1 != y2) {
                    dp[x1][y1][x2] += grid[x2][y2];
                }
            }
        }
    }

    cout << dp[N][N][N] << endl;
    return 0;
}