class Queue 
{
public:
    stack<int> stack1;
    stack<int> stack2;
    
    // Push element x to the back of queue.
    void push(int x) 
    {
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) 
    {
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack2.pop();
    }

    // Get the front element.
    int peek(void) 
    {
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        return stack2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) 
    {
        return stack1.empty() && stack2.empty();
    }
};