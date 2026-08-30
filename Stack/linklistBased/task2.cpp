#include <iostream>
#include <string>
#include <cctype>
#include "stacktype.cpp"

using namespace std;

template <class T>
void Print(StackType<T> &s)
{
    StackType<T> t;
    while (!s.IsEmpty())
    {
        t.Push(s.Top());
        s.Pop();
    }
    while (!t.IsEmpty())
    {
        cout << t.Top() << " ";
        s.Push(t.Top());
        t.Pop();
    }
    cout << endl;
}

int Prec(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

bool ToPostfix(string in, string &post)
{
    StackType<char> ops;
    post = "";
    bool wantNum = true;
    int open = 0;

    for (int i = 0; i < (int)in.length(); i++)
    {
        char c = in[i];

        if (c == ' ')
            continue;

        if (isdigit(c))
        {
            if (!wantNum)
                return false;
            while (i < (int)in.length() && isdigit(in[i]))
            {
                post += in[i];
                i++;
            }
            post += " ";
            i--;
            wantNum = false;
        }
        else if (c == '(')
        {
            if (!wantNum)
                return false;
            ops.Push(c);
            open++;
        }
        else if (c == ')')
        {
            if (wantNum || open == 0)
                return false;
            while (ops.Top() != '(')
            {
                post += ops.Top();
                post += " ";
                ops.Pop();
            }
            ops.Pop();
            open--;
            wantNum = false;
        }
        else if (Prec(c) > 0)
        {
            if (wantNum)
                return false;
            while (!ops.IsEmpty() && Prec(ops.Top()) >= Prec(c))
            {
                post += ops.Top();
                post += " ";
                ops.Pop();
            }
            ops.Push(c);
            wantNum = true;
        }
        else
            return false;
    }

    if (wantNum || open != 0)
        return false;

    while (!ops.IsEmpty())
    {
        post += ops.Top();
        post += " ";
        ops.Pop();
    }
    return true;
}

bool Evaluate(string post, double &result)
{
    StackType<double> st;

    for (int i = 0; i < (int)post.length(); i++)
    {
        if (post[i] == ' ')
            continue;

        if (isdigit(post[i]))
        {
            double n = 0;
            while (i < (int)post.length() && isdigit(post[i]))
            {
                n = n * 10 + (post[i] - '0');
                i++;
            }
            i--;
            st.Push(n);
        }
        else
        {
            double b = st.Top();
            st.Pop();
            double a = st.Top();
            st.Pop();

            if (post[i] == '+')
                st.Push(a + b);
            else if (post[i] == '-')
                st.Push(a - b);
            else if (post[i] == '*')
                st.Push(a * b);
            else
            {
                if (b == 0)
                    return false;
                st.Push(a / b);
            }
        }
    }

    result = st.Top();
    st.Pop();
    return true;
}

int main()
{
    string in, post;
    double result;

    cout << "Infix: ";
    getline(cin, in);

    if (ToPostfix(in, post) && Evaluate(post, result))
    {
        cout << post << endl
             << result << endl;
    }
    else
    {
        cout << "Invalid Expression" << endl;
    }

    return 0;
}