#include <iostream>
#include "queue.cpp"

using namespace std;

const int MAX = 100001;

int main()
{

    // ---------- Task 2: minimum coins (BFS) ----------
    int n, amount;
    cin >> n;

    int coins[100];
    int dist[MAX];
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cin >> amount;

    for (int i = 0; i <= amount; i++)
        dist[i] = -1;

    Queue<int> bfs;
    dist[0] = 0;
    bfs.enQueue(0);

    while (!bfs.isEmpty())
    {
        int sum;
        bfs.deQueue(sum);

        if (sum == amount)
            break;

        for (int i = 0; i < n; i++)
        {
            int next = sum + coins[i];
            if (next <= amount && dist[next] == -1)
            {
                dist[next] = dist[sum] + 1;
                bfs.enQueue(next);
            }
        }
    }

    cout << "Minimum number of coins needed: " << dist[amount] << endl;

    return 0;
}