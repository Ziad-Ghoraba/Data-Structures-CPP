#include <iostream>
#include <vector>
using namespace std;

class stack
{
private:
    int size{};
    int top{};
    int* array{};

public:
    stack(int size = 0) : size(size), top(-1)  //Time Complexity O(n) and Space Complexity O(n)
    {
        array = new int[size];
    }

    bool is_full() //Time Complexity O(1) and Space Complexity O(1)
    {
        return top == size - 1;
    }


    bool is_empty() //Time Complexity O(1) and Space Complexity O(1)
    {
        return top == -1;
    }

    int peek()
    {
        if (!is_empty())
            return array[top];
    }

    void display() //Time Complexity O(n) and Space Complexity O(1)
    {
        for (int i = top; i > -1; i--)
            cout << array[i] << " ";
        cout << "\n";
    }

    bool push(int value) //Time Complexity O(1) and Space Complexity O(1)
    {
        if (is_full())
            return false;
        else
            array[++top] = value;
        return true;
    }

    int pop() //Time Complexity O(1) and Space Complexity O(1)
    {
        if (is_empty())
            cout << "Stack is empty\n";
        else
            return array[top--];
    }

    void insert_at_bottom(int value) //Time Complexity O(n) and Space Complexity O(n)
    {
        if (this->is_empty())
        {
            this->push(value);
            return;
        }

        int x = this->pop();
        insert_at_bottom(value);
        this->push(x);
    }

    void reverse()  //Time Complexity O(n^2) and Space Complexity O(n)
    {
        if (this->is_empty())
            return;
        int cur = this->pop();
        reverse();
        insert_at_bottom(cur);
    }
};


string reverse_subWords(string line) //Time Complexity O(n) and Space Complexity O(n)
{
    string result;
    line += ' ';
    stack stck = stack(line.length());
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ' ')
        {
            while (!stck.is_empty())
                result += stck.pop();
            result += ' ';
        }
        else
        {
            stck.push(line[i]);
        }
    }
    return result;
}

int reverse_num(int num) //Time Complexity O(n) and Space Complexity O(n)
{
    if (num == 0)
        return 0;

    int numv = num, counter = 0;

    while (numv)
    {
        ++counter;
        numv /= 10;
    }
    stack nums = stack(counter);

    while (num)
        nums.push(num % 10), num /= 10;
    int tens = 1;

    while (!nums.is_empty())
    {
        numv = nums.pop() * tens + numv, tens *= 10;
    }
    return numv;
        
}

bool valid_parentheses(string str) //Time Complexity O(n) and Space Complexity O(n)
{
    if (str.length() % 2 != 0)
        return false;
    stack stck = stack(str.length() / 2);
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == '[' || str[i] == '(' || str[i] == '{')
            stck.push(str[i]);
        else
        {
            if (stck.is_empty() || !(stck.peek() == '(' && str[i] == ')' ||
                stck.peek() == '[' && str[i] == ']' || 
                stck.peek() == '{' && str[i] == '}')||
                stck.is_empty())
                return false;
            stck.pop();
        }
    }
    return stck.is_empty();
}

string removeDuplicates(string s) //Time Complexity O(n) and Space Complexity O(n)
{
    stack stck = stack(s.length());
    for (int i = 0; i < s.length(); i++)
    {
        if (stck.is_empty() || s[i] != stck.peek())
            stck.push(s[i]);
        else
            stck.pop();
    }
    s = "";
    while (!stck.is_empty())
    {
        s.insert(0, string(1, stck.pop()));
    }
    return s;
}
vector<int> asteroidCollision(vector<int>& asteroids) {  //Time Complexity O(n) and Space Complexity O(n)
    stack aster = stack(asteroids.size());
    bool flag = true;
    for (int i = asteroids.size() - 1; i >= 0; i--)
    {
        flag = true;

        while (flag)
        {
            if (aster.is_empty() || signbit(aster.peek()) == signbit(asteroids[i]) 
                || signbit(aster.peek()) == false && signbit(asteroids[i]) == true)
            {
                aster.push(asteroids[i]);
                flag = false;
            }
            else if (abs(aster.peek()) == abs(asteroids[i]))
            {
                aster.pop();
                flag = false;
            }
            else if (abs(aster.peek()) > abs(asteroids[i]))
            {
                flag = false;
            }
            else {
                aster.pop();
            }
        }
    }
    asteroids.clear();

    while (!aster.is_empty())
    {
        asteroids.push_back(aster.peek());
        aster.pop();
    }
    return asteroids;
}


//Time Complexity O(1) and Space Complexity O(1)
int precedence(char op) //Infix_to_postfix Helper
{
    if (op == '^')
        return 3;
    if (op == '-' || op == '+')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

//Time Complexity O(1) and Space Complexity O(1)
bool check_precedence( char op, char s) //Infix_to_postfix Helper 2
{
    if (op == '-' || op == '+' ||
        op == '*' && s == '*' || op == '*' && s == '/' ||
        op == '/' && s == '/' || op == '/' && s == '*')
        return true;
    return false;
}

//Time Complexity O(n) and Space Complexity O(n)
string infix_to_postfix(const string &infix) //for simplicity there is no negative or positive values like this (-1 or +1) and only values from one digit are welcomed
{
    string postfix; 
    stack operators = stack(infix.length());
    for (int i = 0; i < infix.length(); i++)
    {
        if (isdigit(infix[i]))
            postfix += infix[i];
        else if (infix[i] == '(')
            operators.push(infix[i]);
        else if (infix[i] == ')')
        {
            while (operators.peek() != '(')
                postfix += operators.pop();
             operators.pop();
        }
        else
        {
            bool flag = precedence(infix[i]) <= precedence(operators.peek()); 
            if (infix[i] == '^' && operators.peek() == '^')
                flag = false;
            while (!operators.is_empty() && flag) //check_precedence(infix[i], operators.peek())
                postfix += operators.pop();
                
            operators.push(infix[i]);
        }
    }
    while (!operators.is_empty())
        postfix += operators.pop();
    return postfix;
}

//Time Complexity O(n) and Space Complexity O(n)
string infix_to_postfix_efficient(string infix) //for simplicity there is no negative or positive values like this (-1 or +1) and only values from one digit are welcomed
{
    infix += '+';
    string postfix;
    stack operators = stack(infix.length());
    operators.push('#');
    for (int i = 0; i < infix.length(); i++)
    {
        if (isdigit(infix[i]))
            postfix += infix[i];
        else if (infix[i] == '(')
            operators.push(infix[i]);
        else if (infix[i] == ')')
        {
            while (operators.peek() != '(')
                postfix += operators.pop();
            operators.pop();
        }
        else
        {
            while (precedence(infix[i]) <= precedence(operators.peek())) //check_precedence(infix[i], operators.peek())
                postfix += operators.pop();

            operators.push(infix[i]);
        }
    }
    return postfix;
}




int main()
{
}

