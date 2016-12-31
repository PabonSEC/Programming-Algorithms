#include<bits/stdc++.h>

using namespace std;

stack<char>st;

queue<char>postfix;

char arr[100];

void Clear()
{
    while(!st.empty())
        st.pop();
}

int main()
{
    int len,a,t,i;

    string str1;

    str1+="(";

    gets(arr);

    str1+=arr;


    str1+=')';

    len = str1.length();

    for(i=0; i<len; i++)
    {
        if(str1[i]=='(')
        {
            st.push(str1[i]);
        }
        else if((str1[i]>='0'&&str1[i]<='9')||(str1[i]>='A' && str1[i]<='Z')||(str1[i]>='a' && str1[i]<='b'))
        {
            postfix.push(str1[i]);
        }
        else if(str1[i]=='*'||str1[i]=='/')
        {
            while(st.size() && (st.top()=='*'||st.top()=='/'))
            {
                postfix.push(st.top());

                st.pop();
            }

            st.push(str1[i]);
        }
        else if(str1[i]=='+'|str1[i]=='-')
        {
            while(st.size() && (st.top()=='+'|st.top()=='-'|st.top()=='*'|st.top()=='/'))
            {
                postfix.push(st.top());

                st.pop();
            }

            st.push(str1[i]);
        }
        else if(str1[i]==')')
        {
            while(st.size() && st.top()!='(')
            {
                postfix.push(st.top());

                st.pop();
            }
            st.pop();
        }
    }

    printf("\nThe Postfix conversion of the following expression is: ");

    while(!postfix.empty())
    {
        printf("%c",postfix.front());
        postfix.pop();
    }

    printf("\n");

    Clear();

    str1="";

    return 0;
}
