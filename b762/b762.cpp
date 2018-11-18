#include <iostream>
using namespace std;

int main()
{

    int kills, deaths, assists, currentKills, entries, statusi;
    string status;
    while(cin >> entries)
    {
        deaths = 0; kills = 0; assists = 0; currentKills = 0;
        for(int i = 0; i < entries; i++)
        {

        cin >> status;


        if(status == "Get_Kill") statusi = 1;
        if(status == "Get_Assist") statusi = 2;
        if(status == "Die") statusi = 3;




        switch( statusi ){

            case 1 :
            kills++;
            currentKills++;

            if(currentKills > 2)
            {
                if(currentKills == 3)
                {
                    cout << "KILLING SPREE!" << endl;
                }
                else if(currentKills == 4)
                {
                    cout << "RAMPAGE~" << endl;
                }
                else if(currentKills == 5)
                {
                    cout << "UNSTOPPABLE!" << endl;
                }
                else if(currentKills == 6)
                {
                    cout << "DOMINATING!" << endl;
                }
                else if(currentKills == 7)
                {
                    cout << "GUALIKE!" << endl;
                }
                else if(currentKills >= 8)
                {
                    cout << "LEGENDARY!" << endl;
                }
            } else {
                cout << "You have slain an enemie." << endl;
            }

            break;


        case 2:
            assists++;
            break;
        case 3:

            if(currentKills > 2){
                cout << "SHUTDOWN." << endl;
            } else {
                cout << "You have been slained." << endl;
            }

            currentKills = 0;
            deaths++;
            break;


        }



        }
        cout << kills << "/" << deaths << "/" << assists;


    }





}
