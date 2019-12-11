#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char idtbl[100];
int valtbl[100];
int tblCounter = 0;
char kwtbl[] = {'print', 'input'};
char optbl[] = {'(', ')', '\n'};
char tokens[1000];

FILE *fp;
char str[1000];

#define devMode true

//prototypes
void readFile();
void cleanFile();
void checkStream();
void showFile();

int main(int argc, char **argv)
{
    fp = fopen(argv[1], "r");
    char ch;
    int i = 0;

    if(fp)
    {
        while((ch = getc(fp)) != EOF)
        {
            str[i] = ch;
            i++;
        }
    }
    else
    {
        cout << "error occured while file opening" << endl;
    }
//    showFile();
    cleanFile();
    checkStream();
}

void readFile(char filename[10])
{
    fp = fopen(filename, "r");
    char ch;
    int i = 0;

    if(fp)
    {
        while((ch = getc(fp)) != EOF)
        {
            str[i] = ch;
            i++;
        }
    }
    else
    {
        cout << "error occured while file opening" << endl;
    }
}

void showFile()
{
    int i;

    for(i=0; i<strlen(str); i++)
    {
        cout << str[i];
    }
}

void checkStream()
{
    int i, j=0;
    char *token = strtok(str, optbl);

    while(token != NULL)
    {
        if(strcmp(token, "print") == 0)
        {
            token = strtok(NULL, optbl);

            if(token[0] == '"')
            {
                for(i=1; i<strlen(token)-1; i++)
                {
                    if(token[i] == '\\' && token[i+1] == 'n')
                    {
                        cout << endl;
                        i++;
                    }
                    else
                    {
                        cout << token[i];
                    }
                }
            }
            else if(token[0] >= 'a' && token[0] <= 'z' || token[0] >= 'A' && token[0] <= 'Z')
            {
                for(i=0; i<tblCounter; i++)
                {
                    if(idtbl[i] == token[0])
                    {
                        cout << valtbl[i];
                    }
                }
            }

            continue;
        }
        else
        {
            int num1, num2, res;

            for(i=0; i<strlen(token); i++)
            {
                if(token[i] == '=' && token[i+1] == '"' || token[i] == '=' && token[i+1] >= '0' && token[i+1] <= '9')
                {
                    idtbl[tblCounter] = token[i-1];
                    valtbl[tblCounter] = token[i+1] - '0';
                    tblCounter++;
                }
                else if(token[i] == '+')
                {
                    for(i=0; i<tblCounter; i++)
                    {
                        if(idtbl[i] == token[i-1])
                        {
                            num1 = valtbl[i-1];
                        }
                    }
                    for(i=0; i<tblCounter; i++)
                    {
                        if(idtbl[i] == token[i+1])
                        {
                            num2 = valtbl[i+1];
                        }
                    }
                    res = num1+num2;
                    idtbl[tblCounter] = token[i-3];
                    valtbl[tblCounter] = res;
                    tblCounter++;
                }
            }
        }
        cout << "[token]" << token << endl;
        token = strtok(NULL, optbl);
    }

    if(devMode)
    {
        cout << endl << endl << "Here is all declared variables (Only show in development mode)" << endl;
        for(i=0; i<tblCounter; i++)
        {
            cout << idtbl[i] << "\t";
            cout << valtbl[i] << endl;
        }
    }
}

void cleanFile()
{
    int i, j=0;

    for(i=0; i<strlen(str); i++)
    {
        if(str[i]=='<' && str[i+1]=='<')
        {
            while(str[i-1] != '>' && str[i-2] != '>')
            {
                i++;
            }
        }
        else
        {
            str[j] = str[i];
            j++;
        }
    }

    for(i=j; i<strlen(str); i++)
    {
        str[i] = '\0';
    }
}
