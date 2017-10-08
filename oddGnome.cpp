#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int d, prev;
        cin >> d >> prev;

        for (int j = 1; j < d; ++j)
        {
            int k;
            cin >> k;
            if (k != prev + 1)
            {
                cout << (j+1) << endl;
                string line;
                getline(cin, line);
                break;
            }
            prev = k;
        }
    }
}