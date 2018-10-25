class MinStack 
{
private:
    std::stack<int> stack;  
    std::stack<int> min_stack; 
public:
    void push(int x) 
    {
        stack.push(x);
        if (min_stack.empty() || ((!min_stack.empty()) && x <= min_stack.top())) 
        {
            min_stack.push(x);  
        }  
    }

    void pop() 
    {
        if (!stack.empty()) 
        {  
            if (stack.top() == min_stack.top())  
                min_stack.pop();  
            stack.pop();  
        }  
    }

    int top() 
    {
        if (!stack.empty())  
            return stack.top();
    }

    int getMin() 
    {
        if (!min_stack.empty())  
            return min_stack.top(); 
    }
};