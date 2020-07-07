#include <cstring>
#include <iostream>
#include <locale>
#include <string>
#include <vector>
using namespace std;

#define BUFFER_SIZE 1024

const string SEPARATORS = ": \t";

void PrintMenu()
{
    cout << "a - 12 to 24" << endl;
    cout << "b - 24 to 12" << endl;
    cout << "q - quit" << endl;
}

string trim(string str)
{

    const char *buffer = str.c_str();
    int s = 0, e = str.length() - 1;
    while (isspace(buffer[s]))
        s++;
    while (isspace(buffer[e]))
        e--;
    return str.substr(s, e - s + 1);
}

vector<string> split(string str)
{
    vector<string> vec;
    const char *cstr = str.c_str();
    int s, e;
    for (s = 0, e = 0; s < str.length() && e < str.length();)
    {
        while (SEPARATORS.find(cstr[s]) != string::npos)
            s++;
        while (SEPARATORS.find(cstr[e]) == string::npos)
            e++;
        vec.push_back(str.substr(s, e - s));
        s = e;
    }
    return vec;
}

void Handle12To24()
{
    cout << "please input your time with hh:mm:ss an format" << endl;

    string buffer;
    cin.ignore(1024, '\n');
    getline(cin, buffer);
    string trimed items = trim(buffer);

    if (items.size() != 4)
    {
        cout << "Invalid input, the valid input should with format with format hh:mm:ss am" << endl;
        return;
    }

    int hh, mm, ss;
    try
    {
        hh = stoi(items[0]);
        mm = stoi(items[1]);
        ss = stoi(items[2]);
    }
    catch (invalid_argument e)
    {
        cout << "Invalid input, cannot convert to int value" << endl;
        return;
    }

    if (hh <= 0 || hh > 12)
    {
        cout << "Invalid input, 12hr format hh need to between (0, 12]" << endl;
        return;
    }
    else if (mm < 0 || mm >= 60)
    {
        cout << ""
    }
}
