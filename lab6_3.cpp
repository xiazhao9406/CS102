#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

#define BUFFER_SIZE 1024

const string SEPARATORS = ": \t";

void PrintMenu()
{
    cout << "a -- 12hour convert to 24 hours" << endl;
    cout << "b -- 24 hours convert to 12 hours" << endl;
    cout << "q -- quit" << endl;
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
        while (s < str.length() && SEPARATORS.find(cstr[s]) != string::npos)
            s++;
        e = s + 1;
        while (e < str.length() && SEPARATORS.find(cstr[e]) == string::npos)
            e++;
        vec.push_back(str.substr(s, e - s));
        s = e;
    }
    return vec;
}

void Handle12To24()
{
    cout << "please input your time with hh:mm:ss am format" << endl;

    string buffer;
    cin.ignore(1024, '\n');
    getline(cin, buffer);
    string trimed = trim(buffer);
    vector<string> items = split(trimed);

    if (items.size() != 4)
    {
        cout << "Invalid input , the valid input should with format hh:mm:ss am" << endl;
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
        cout << "Invalid input, hh need to between (0, 12]" << endl;
        return;
    }
    else if (mm < 0 || mm >= 60)
    {
        cout << "Invalid input, mm need to between (0, 60]" << endl;
    }
    else if (ss < 0 || ss >= 60)
    {
        cout << "Invalid input, ss need to between [0, 60)" << endl;
    }
    string ampm = items[3];
    if (ampm == "AM" || ampm == "Am" || ampm == "aM" || ampm == "am")
    {
        if (hh == 12)
        {
            hh = 0;
        }
    }
    else if (ampm == "PM" || ampm == "Pm" || ampm == "pM" || ampm == "pm")
    {
        if (hh != 12)
        {
            hh += 12;
        }
    }
    else
    {
        cout << "Invalid input, am/pm value not recognized" << endl;
        return;
    }

    cout.fill('0');
    cout << "24hr format of" << buffer << " is "
         << setw(2) << hh << ":"
         << setw(2) << mm << ":"
         << setw(2) << ss << endl;
}

void Handle24To12()
{
    cout << "please input your time with hh:mm:ss am format" << endl;

    string buffer;
    cin.ignore(1024, '\n');
    getline(cin, buffer);
    string trimed = trim(buffer);
    vector<string> items = split(trimed);

    if (items.size() != 3)
    {
        cout << "Invalid input , the valid input should with format hh:mm:ss" << endl;
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

    if (hh <= 0 || hh > 23)
    {
        cout << "Invalid input, hh need to between (0, 12]" << endl;
        return;
    }
    else if (mm < 0 || mm >= 60)
    {
        cout << "Invalid input, mm need to between (0, 60]" << endl;
    }
    else if (ss < 0 || ss >= 60)
    {
        cout << "Invalid input, ss need to between [0, 60)" << endl;
    }
    string ampm;
    if (hh > 12)
    {
        hh -= 12;
        ampm = "PM";
    }
    else if (hh == 12)
    {
        ampm = "PM";
    }
    else
    {
        ampm = "AM";
    }

    cout.fill('0');
    cout << "24hr format of" << buffer << " is "
         << setw(2) << hh << ":"
         << setw(2) << mm << ":"
         << setw(2) << ss << " " << ampm << endl;
}

int main()
{
    char command;
    do
    {
        PrintMenu();
        cin >> command;
        switch (command)
        {
        case 'a':
            Handle12To24();
            break;
        case 'b':
            Handle24To12();
            break;
        default:
            break;
        }

    } while (command != 'q');
    return 0;
}
