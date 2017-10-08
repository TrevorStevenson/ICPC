#include <iostream>
#include <vector>
#include <string>

using namespace std;

void encrypt(string s)
{
    vector<int> key(s.length());

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ' ') key[i] = 0;
        else key[i] = s[i] - 'a' + 1;
        
        if (i > 0) key[i] += key[i-1];
        if (i > 1) key[i-2] %= 27;
    }

    key[s.length()-2] %= 27;
    key[s.length()-1] %= 27;

    string ans;

    for (int i : key)
    {
        if (i == 0) ans += " ";
        else ans += char('a' + i - 1);
    }
    
    ans = ans.substr(0, s.length());
    cout << ans << endl;
}

void decrypt(string s)
{
    vector<int> key(s.length());

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ' ') key[i] = 0;
        else key[i] = s[i] - 'a' + 1;
    }

    int prev = key[0];
    string ans;
    ans += char('a' + key[0] - 1);

    for (int i = 1; i < s.length(); ++i)
    {
        int guess = key[i];
        while (guess - prev < 0 || guess - prev > 26)
        {
            guess += 27;
        }

        if (guess - prev == 0) ans += " ";
        else ans += char('a' + guess - prev - 1);        
        prev = guess;
    }

    ans = ans.substr(0, s.length());    
    cout << ans << endl;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        string line;
        getline(cin, line);
        line = line.substr(1);

        if (c == 'e') encrypt(line);
        else decrypt(line);
    }

    return 0;
}