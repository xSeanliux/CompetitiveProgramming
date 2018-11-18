#include<iostream>
using namespace std;



struct Char
{
    char c;
    Char *next;

};

Char *c_start, *c_end, *temp_end;


void pushEnd(char n)
{
    Char *a = new Char;
    //cout << "j" << endl;

    Char *temp = temp_end->next;
    //cout << "z" << endl;
    a -> c=n;
    temp_end->next = a;
    temp_end = a;
    temp_end->next = temp;
    if(temp == NULL){
        c_end = a;
    }
}

void display(){
    for(Char *dong = c_start->next; dong != NULL; dong = dong->next){
        cout << dong->c;
    }
    cout << endl;
}

int main()
{
    char currentChar;
    c_start = new Char;
    c_end = c_start;
    c_start -> next = NULL;
    temp_end = c_end;
    while(cin.get(currentChar))
    {
        //cout << currentChar << " ";
        if(currentChar == '\n'){
            display();
            c_start = new Char;
            c_end = c_start;
            c_start -> next = NULL;
            temp_end = c_end;
        }
        else if(currentChar == '[')
        {
            temp_end = c_start;
        }
        else if(currentChar == ']')
        {
            temp_end = c_end;
        }
        else
        {
            //cout << "P " << endl;
            pushEnd(currentChar);
            //cout << "G " << endl;
            //cout << "One " << endl;

        }


    }




}
