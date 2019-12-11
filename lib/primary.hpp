#include <bits/stdc++.h>
using namespace std;


string readFile(string filename)
{
    string str, code;
    ifstream file;
    file.open(filename);

    if(file)
    {
        while(!file.eof())
        {
            getline(file, str);
            code += str + '\n';
        }
        file.close();
    }
    else
    {
        cout << "Something wrong while file opening" << endl;
    }

    return code;
}

vector <string> tokenize(string str, char ch)
{
    vector <string> tkns;
    stringstream check(str);
    string tkn;

    while(getline(check, tkn, ch))
    {
        tkns.push_back(tkn);
    }

    tkns.pop_back();

    return tkns;
}

string removeComment(string str)
{
    int i, j=0, inQuote=0;

    for(i=0; i<str.length(); i++)
    {
        if(str[i]=='"')
        {
            inQuote = !inQuote;
        }

        if(inQuote)
        {
            str[j] = str[i];
            j++;
        }
        else
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
    }

    for(i=j; i<str.length(); i++)
    {
        str[i] = '\0';
    }

    return str;
}

string removeWhitespace(string str)
{
    int i, j=0;

    for(i=0; i<str.length(); i++)
    {
        if(str[i]=='\n' && str[i+1]=='\n' && str[i+2])
        {
            continue;
        }
        else
        {
            str[j] = str[i];
            j++;
        }
    }

    for(i=j; i<str.length(); i++)
    {
        str[i] = '\0';
    }

    return str;
}
