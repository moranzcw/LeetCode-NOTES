class Solution 
{
public:
    int calculate(string s) 
    {
        stack<int> numbers; //存储操作数
        stack<char> operators; //存储操作符，包含左括号
        int tempNumber = 0;
        
        for(int i=0;i<s.size();i++)
        {
            /* 当获取一个操作数时，如果符号栈顶为运算符+或-，且?数栈不为空，则立即计算，将结果压入数栈，否则直接压入数栈。*/
            if(s[i]>='0' && s[i]<='9')
            {
                tempNumber = tempNumber*10 + (s[i]-'0');
                if(i+1 == s.size() || (s[i+1]<'0' || s[i-1]>'9') )
                {
                    if(numbers.size()>0)
                    {
                        switch(operators.top())
                        {
                            case '+':
                                tempNumber = numbers.top() + tempNumber;
                                numbers.pop();operators.pop();
                                break;
                            case '-':
                                tempNumber = numbers.top() - tempNumber;
                                numbers.pop();operators.pop();
                                break;
                        }
                    }
                    numbers.push(tempNumber);
                    tempNumber = 0;
                }
            }
            /* 获取)时，符号栈顶必为(，将其出栈，然后运算，直到找到另一个(。*/
            switch(s[i])
            {
                case ' ':break;
                case '+':operators.push('+');break;
                case '-':operators.push('-');break;
                case '(':operators.push('(');break;
                case ')':
                    if(operators.size()>0 && operators.top() == '(')
                        operators.pop();
                    if(operators.size()>0 && operators.top() != '(')
                    {
                        tempNumber = numbers.top();numbers.pop();
                        switch(operators.top())
                        {
                            case '+':
                                tempNumber = numbers.top() + tempNumber;
                                numbers.pop();operators.pop();
                                break;
                            case '-':
                                tempNumber = numbers.top() - tempNumber;
                                numbers.pop();operators.pop();
                                break;
                        }
                        numbers.push(tempNumber);
                        tempNumber = 0;
                    }
                    break;
            }
        }
        return numbers.top();
    }
};