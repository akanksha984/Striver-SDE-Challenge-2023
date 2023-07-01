class minStack
{
	private: vector<pair<int,int>> vec;
    public:
		minStack() 
		{ 
		}
		void push(int num)
		{
			if(vec.empty()) vec.push_back({num,num});
            else vec.push_back({num,min(vec.back().second,num)});
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{  if(vec.empty()) return -1;
             int val=vec.back().first;
             vec.pop_back();
             return val;
			
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{   
			return vec.empty()?-1:vec.back().first;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
            return vec.empty()?-1:vec.back().second;
		}
};
