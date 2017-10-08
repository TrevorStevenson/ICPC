#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double distance(unsigned int dX, unsigned int dY)
{
    return sqrt(pow(dX, 2) + pow(dY, 2));
}

int main()
{
    int n;
    cin >> n;

    vector<int> x;
    vector<int> y;

    for (int i = 0; i < n; ++i)
    {
        unsigned int x1, y1;
        cin >> x1 >> y1;
        x.push_back(x1);
        y.push_back(y1);
    }

    int total = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            unsigned int dX, dY;
            
            if (x[j] > x[i]) dX = x[j] - x[i];
            else dX = x[i] - x[j];
            if (y[j] > y[i]) dY = y[j] - y[i];
            else dY = y[i] - y[j];

            if (dX > 2018 || dY > 2018) continue;
            if (distance(dX, dY) == 2018)
            {
                ++total;
            }
        }   
    }

    cout << total << endl;
}