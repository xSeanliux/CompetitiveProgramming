#include <iostream>
using namespace std;
int sudoku[9][9];
bool isSolution(int sudoku[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            for( int k = 0; k < 9; k++)
            {
                if(sudoku[i][j] == sudoku[i][k] & j != k)  //same number in row
                {
                    //cout << " a: sudoku[" << i << "][" << j << "] == " << "sudoku[" << i << "][" << k << "] => " <<  sudoku[i][j] << " == " << sudoku[i][k] << endl;
                    return false;
                }
                else if( sudoku[i][j] == sudoku[k][j] & (i != k) )   //same number in column
                {
                    //cout << " b: sudoku[" << i << "][" << j << "] == " << "sudoku[" << k << "][" << i << "]  => " <<  sudoku[i][j] << " == " << sudoku[k][i] << endl;
                    return false;
                }
            }

        }
    }
    //Checking all the 3x3 grids
    for(int i = 0; i < 9; i+=3)  //go over all the sub-squares, 0, 3, 6.
    {
        for(int ii = 0; ii < 9; ii += 3)
        {
            for(int j = i; j < i+3; j++)  //j and k are the first.
            {
                for(int k = ii; k<ii+3; k++)
                {
                    for(int l = i; l < i+3; l++)  //l and m are the values to compare
                    {
                        for(int m = ii; m < ii+3; m++)
                        {
                            if(sudoku[j][k] == sudoku[l][m] & (j != l | m != k))  //comparing every single square with every other square, bad method.
                            {
                                //cout << " c: sudoku[" << j << "][" << k << "] == " << "sudoku[" << l << "][" << m << "]  => " <<  sudoku[i][j] << " == " << sudoku[l][m] << ", i = " << i << ", ii = " << ii << endl;
                                return false;
                            }
                        }
                    }
                }

            }

        }

    }

    return true;
}
int main()
{
    int sudoku[9][9];
    string output;
    while( !cin.eof() )
    {
        output = "";
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cin >> sudoku[i][j];
            }
        }
        output = isSolution(sudoku) ? "yes" : "no";
        cout << output << endl;

    }
}


