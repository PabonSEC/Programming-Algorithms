#include<bits/stdc++.h>

using namespace std;

map<char,int>RomanToDecimal;

map<int,string>DecimalToRoman;

string R;

void DtoR(int value)
{
    DecimalToRoman[1000] = "M"; DecimalToRoman[900] = "CM";

    DecimalToRoman[500] = "D"; DecimalToRoman[400] = "CD";

    DecimalToRoman[100] = "C"; DecimalToRoman[90] = "XC";

    DecimalToRoman[50] = "L"; DecimalToRoman[40] = "XL";

    DecimalToRoman[10] = "X"; DecimalToRoman[9] = "IX";

    DecimalToRoman[5] = "V"; DecimalToRoman[4] = "IV";

    DecimalToRoman[1] = "I";

    map<int,string>::reverse_iterator it;

    for(it = DecimalToRoman.rbegin();it!=DecimalToRoman.rend();it++)
    {
        while(value>=it->first)
        {
            printf("%s",((string) it->second).c_str());

            value-=it->first;
        }
    }

    puts("");
}



int RtoD()
{
    RomanToDecimal['I'] = 1;
    RomanToDecimal['V'] = 5;

    RomanToDecimal['X'] = 10;
    RomanToDecimal['L'] = 50;

    RomanToDecimal['C'] = 100;
    RomanToDecimal['D'] = 500;

    RomanToDecimal['M'] = 1000;

    int i,value = 0;

    for(i=0; R[i]; i++)
    {
        if(R[i+1] && RomanToDecimal[R[i]] < RomanToDecimal[R[i+1]])
        {
            value+=RomanToDecimal[R[i+1]]-RomanToDecimal[R[i]];

            i++;
        }
        else
        {
            value+=RomanToDecimal[R[i]];
        }
    }

    return value;
}


int main()
{
    int len,i,value;

    while(cin>>R)
    {
        if(R[0]>='0' && R[0]<='9')
        {
            len = R.length();

            value = 0;

            for(i=0;i<len;i++)
            {
                value = value*10+(R[i]-48);
            }

            DtoR(value);
        }
        else
        {
            cout<<RtoD()<<endl;
        }
    }

    return 0;
}
