/*
 * Name: Xia Zhao
 * Program: to convert the time from 24-hour notation to 12-hour notation and vice versa.
 * Date: 07/06/2020
*/

#include <iostream>
#include <cstring>

using namespace std;

int GetRightDate(int a) // the function to
{
    cin.ignore(1024, '\n');
    cin >> a;
    while (a < 0)
    {
        cout << "your input is uncorrect! please check and re-put: " << endl;
        cin >> a;
    }

    return a;
}

int GetInHour(int &n)
{
    cout << "Please intput the time you want to convert" << endl;
    cout << "Please intput hours:" << endl;
    n = GetRightDate(n);

    return n;
}

string GetInAmPm()
{
    string am_pm;
    cout << "Please intput the time you want to convert am or pm:" << endl;
    cin >> am_pm;

    return am_pm;
}

void TimeConvertTo12(int &n)
{

    if (n > 12)
    {
        n = n - 12;
        cout << "the time you convert is  "
             << "PM  " << n << " (12-hour notation)"
             << endl;
    }
    else
    {
        cout << "the time you convert is  "
             << "AM  " << n << " (12-hour notation)"
             << endl;
    }
}

void TimeConvertTo24(int &n, string str)
{

    if (str == "am")
        ;
    else
    {
        n += 12;
    }
    cout << "the time you convert is  " << n << " (24-hour notation)" << endl;
}

void PrintMenu()
{
    cout << "===============================================================" << endl;

    cout << "[a]To convert time from 12-hour notation to 24-hour notation" << endl;
    cout << "[b]To convert time from 24-hour notation to 12-hour notation" << endl;
    cout << "[q]To quit the program" << endl;
    cout << "Please input your command" << endl;

    cout << "===============================================================" << endl;
}

int main()
{
    char command;
    int hour;
    string str;

    do
    {
        PrintMenu();
        cin >> command;
        switch (command)
        {
        case 'a':
            str = GetInAmPm();
            hour = GetInHour(hour);
            TimeConvertTo24(hour, str);
            break;
        case 'b':
            hour = GetInHour(hour);
            TimeConvertTo12(hour);
            break;
        default:
            break;
        }
    } while (command != 'q');
    return 0;
}
