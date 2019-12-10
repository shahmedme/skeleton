#include <bits/stdc++.h>
using namespace std;

void streamCheck(char fs[1000], char *idTbl)
{
    for(int i=0; fs[i] != '\0'; i++)
    {
        if(fs[i] == 'p' && fs[i+1] == 'r' && fs[i+2] == 'i' && fs[i+3] == 'n' && fs[i+4] == 't')
        {
            i+=7;
            while(fs[i] != '"')
            {
                cout << fs[i];
                i++;
            }
        }
        else if(fs[i] == '=')
        {
            addId(idTbl);
        }
    }
}

void print()
{
    cout << "ok";
}

void addId()
{

}

void displayFS(char fs[1000]) {

    for(int i=0; fs[i] != '\0'; i++)
    {
        cout << fs[i];
    }

    cout << endl;
}
