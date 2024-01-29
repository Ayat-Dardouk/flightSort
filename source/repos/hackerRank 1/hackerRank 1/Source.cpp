#include<iostream>
#include<vector>
#include<string>
using namespace std;


string findSubstring(string s, int k) {
    char vowels[] = { 'a','e','i','o','u' };
    vector<int> count(s.length() - k, 0);
    int trace = 0;
    char* subString = new char[k];

    int kmove = k - 1;
    for (int y = 0;y<s.length() - k;y++) {
        kmove++;
        for (int i = y;i<s.length() && i < kmove;i++) {
            for (int j = 0;j < 5;j++) {
                {if (s[i] == vowels[j])
                    count[trace]++;
               
                }
            }

        }
        trace++;
    }

    int maxValue = 0;
    int max = count[0];
    for (int i = 0;i < s.length() - k;i++)
    {
        if (count[i] > max)
            max = i;
        maxValue = count[i];
    }

    if (maxValue == 0)
    {
        cout << "not found\n";
        return subString;
    }


    for (int i = 0;i < k;i++, max++)
    {
        subString[i] = s[max];
    }

    return subString;
}
int main()
{
   
    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = 5;

    string result = findSubstring(s, k);

    cout << result << "\n";

   

    return 0;
}

