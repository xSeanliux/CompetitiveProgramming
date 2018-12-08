#include <iostream>
#include <string.h>

using namespace std;
string ques;
bool isSupported;
struct Chem
{
    string str;
    int childN;
    Chem *children[10000];
    int elements;
    int amount;
};

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
    } else {
        return -1;
    }
}


float calculate(Chem *root)
{
    float sum = 0;

    if(root->elements <= 1 && !containsDigit(root->str) && !containsBrackets(root->str))
    {
        if(getMass(root->str) < 0) isSupported = false;
        return getMass(root->str);
    }
    else
    {
        for(int i = 0; i < root->childN; i++)
        {
            float k = calculate(root->children[i]) * root->children[i]->amount;
            if(k < 0) isSupported = false;
            sum += k;
        }
        return sum;
    }
}

void run(Chem *c)
{

    int len = c->str.length();
    string currentStr = "";
    string currentAmount = "";
    int amount = 1;
    int N = 0; //stack
    for(int i = 0; i < len; i++)
    {
        if(isUpper(c->str[i]))
        {
            c->elements++;
        }

        if(c->str[i] == '(')
        {
            N++;
        }
        else if(c->str[i] == ')')
        {
            N--;
        }

        if(N == 0)
        {
            if(currentStr == "")
            {
                if(isLower(c->str[i+1]))
                {
                    currentStr += c->str[i];
                    currentStr += c->str[i+1];
                    i++;
                }
                else
                {
                    currentStr = c->str[i];
                }
            }
            i++;
            while(isDigit(c->str[i]))
            { //
                currentAmount += c->str[i];
                i++;
            }
            i--;
            if(currentAmount != "")
                amount = stoi(currentAmount);
            }
            if(currentStr[0] == '(')
            {
                currentStr = currentStr.substr(1);
            }
            //
            Chem *child = new Chem;
            child->str = currentStr;
            child->childN = 0;
            child->elements = 0;
            child->amount = amount;
            c->children[c->childN] = child;
            c->childN++;
            currentStr = "";
            currentAmount = "";
            amount = 1;
        }}
        else
        {
            currentStr += c->str[i];
        }
    }
    if(c->elements <= 1 && !containsBrackets(c->str))
    {
        return;
    }
    else
    {
        for(int i = 0; i < c->childN; i++)
        {
            run(c->children[i]);
        }
    }

}

void f(string ques){

    isSupported = true;

    Chem *root = new Chem();
    root->str = ques;
    root->childN = 0;
    root->  elements = 0;
    root->amount = 1;
    run(root);
    float amount = calculate(root);
    if(isSupported){
        cout << amount << endl;
    } else {
        cout << "I'm sorry! Either there was an imaginary atom in there, or there was an element not supported by this program. This program can only handle atoms with atomic numbers less than 30." << endl << "Please go back and check your input. Thank you.";
    }

}
int cases;
int main()
{
    cin >> cases;
    for(int i = 0; i < cases; i++){
        cin >> ques;
        f(ques);
    }

}

