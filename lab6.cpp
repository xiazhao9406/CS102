/*
 * Name: Xia Zhao
 * Program: to convert the time from 24-hour notation to 12-hour notation and vice versa.
 * Date: 07/06/2020
*/

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

/**
 * The function to prevent negative hour, mins, seconds input.
 */
int GetRightDate(int a)
{
    cin >> a;
    while (a < 0)
    {
        cout << "your input is uncorrect! please check and re-put: " << endl;
        cin >> a;
    }
    return a;
}

/**
 * The function to get input of int time.
 */
void GetTime(int *array, int size)
{
    cout << "Please intput the time you want to convert" << endl;
    cout << "Please intput hours:" << endl;
    array[0] = GetRightDate(array[0]);
    cout << "Please intput mins:" << endl;
    array[1] = GetRightDate(array[1]);
    cout << "Please intput seconds:" << endl;
    array[2] = GetRightDate(array[2]);
}

/**
 * The function to get 12-hour nonation am or pm.
 */
string GetAmPm()
{
    string am_pm;
    cout << "Please intput the time you want to convert am or pm:" << endl;
    cin >> am_pm;

    return am_pm;
}

/**
 * The function to convert time to 12-hour nonation.
 */
void TimeConvertTo12(int &n)
{
    if (n > 12)
    {
        n -= 12;
        cout << "PM  ";
    }
    else if (n == 12)
    {
        cout << "PM  ";
    }
    else
    {
        cout << "AM  ";
    }
}

/**
 * The function to convert time to 12-hour nonation.
 */
void TimeConvertTo24(int &n, string str)
{

    if (str == "am")
    {
        ;
    }
    else if (n == 12)
    {
    }
    else
    {
        n += 12;
    }
}

/**
 * The function to print result.
 */
void PrintResult(int *array, int size)
{
    cout << setfill('0') << setw(2) << array[0] << ":"
         << setfill('0') << setw(2) << array[1] << ":"
         << setfill('0') << setw(2) << array[2];
}

/**
 * The function to print menu.
 */
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
    char command; // char to get command
    int array[3]; // array int to get hour, mins and second;
    string str;   // string to get am or pm for 12-hour nonation

    do
    {
        PrintMenu();
        cin >> command;
        switch (command)
        {
        case 'a':
            str = GetAmPm();
            GetTime(array, 3);
            cout << "The time you convert is :" << endl;
            TimeConvertTo24(array[0], str);
            PrintResult(array, 3);
            cout << "   (24-hour nonation)" << endl;
            break;
        case 'b':
            GetTime(array, 3);
            cout << "The time you convert is :" << endl;
            TimeConvertTo12(array[0]);
            PrintResult(array, 3);
            cout << "   (12-hour nonation)" << endl;
            break;
        default:
            break;
        }
        cin.ignore(1024, '\n');
    } while (command != 'q');
    return 0;
}
