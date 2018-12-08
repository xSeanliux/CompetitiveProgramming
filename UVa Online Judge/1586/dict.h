#include <iostream>
#include <string.h>
using namespace std;

bool containsBrackets(string str)
{
    int l = str.length();
    for(int i = 0; i < l; i++)
    {
        if(str[i] == ')' || str[i] == '(' )
        {
            return true;
        }

    }
    return false;
}

bool containsOps(string str)
{
    int l = str.length();
    for(int i = 0; i < l; i++)
    {
        if(str[i] == ')' || str[i] == '(' || str[i] == '*' || str[i] == '+')
        {
            return true;
        }

    }
    return false;
}

bool isUpper(char c)
{
    return (c <= 'Z' && c >= 'A');
}
bool isLower(char c)
{
    return (c <= 'z' && c >= 'a');
}

bool isDigit(char c)
{
    return (c <= '9' && c >= '0');
}

bool containsDigit(string str)
{
    int l = str.length();
    for(int i = 0; i < l; i++)
    {
        if(isDigit(str[i]))
        {
            return true;
        }

    }
    return false;
}

float getMass(string str)
{
    if(str == "H")
    {
        return 1.008;
    }
    else if(str == "C")
    {
        return 12.01;
    }
    else if(str == "N")
    {
        return 14.01;
    }
    else if(str == "O")
    {
        return 16;
    }
}


string query;

int showWorking(string query)
{

    string currentStr = "";
    int len = query.length();
    for(int i = 0; i < len; i++)
    {
        if(isDigit(query[i]))
        {
            currentStr += "*";
            currentStr += query[i];
            i++;
            while(isDigit(query[i]))
            {
                i++;
                currentStr += query[i];
            }
            i--;
            if(!(isDigit(query[i+1]) || query[i+1] == ')' || i == len-1))
            {
                currentStr += '+';
            }
        }
        else if(isUpper(query[i]))
        {
            string currentElement = "";
            currentElement += query[i];
            if(isLower(query[i+1]))
            {
                i++;
                currentElement += query[i];
            }
            double currentAmount = getMass(currentElement);
            currentStr += to_string(currentAmount);
            if(!(isDigit(query[i+1]) || query[i+1] == ')' || i == len-1))
            {
                currentStr += '+';
            }
        }
        else
        {
            currentStr += query[i];
        }

    }
    cout << currentStr << endl;


}



