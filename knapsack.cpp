#include <iostream>

void knapsack();
int max(int, int);

int i, j, n, m, p[10], w[10], v[10][10];

int main()
{
    std::cout << "Enter the no. of items: ";
    std::cin >> n;

    std::cout << "Enter the weight of each item:\n";
    for (i = 1; i <= n; i++)
    {
        std::cin >> w[i];
    }

    std::cout << "Enter the profit of each item:\n";
    for (i = 1; i <= n; i++)
    {
        std::cin >> p[i];
    }

    std::cout << "Enter the knapsack's capacity: ";
    std::cin >> m;

    knapsack();

    return 0;
}

void knapsack()
{
    int x[10];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                v[i][j] = 0;
            }
            else if (j - w[i] < 0)
            {
                v[i][j] = v[i - 1][j];
            }
            else
            {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
            }
        }
    }

    std::cout << "\nThe output is:\n";
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            std::cout << v[i][j] << "\t";
        }
        std::cout << "\n\n";
    }

    std::cout << "\nThe optimal solution is " << v[n][m];
    std::cout << "\nThe solution vector is:\n";
    for (i = n; i >= 1; i--)
    {
        if (v[i][m] != v[i - 1][m])
        {
            x[i] = 1;
            m = m - w[i];
        }
        else
        {
            x[i] = 0;
        }
    }

    for (i = 1; i <= n; i++)
    {
        std::cout << x[i] << "\t";
    }
}

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
