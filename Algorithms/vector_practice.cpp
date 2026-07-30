#include <iostream>
#include <vector>

int main()
{
   std::vector<int> nums;
   int enterednum;
   
   for(int i = 0; i < 5; i++)
   {
       std::cout << "[" << i << "] Num " << i << ": ";
       std::cin>>enterednum;
       nums.push_back(enterednum);
   }
   for(int i = 0; i < nums.size(); i++)
   {
       std::cout<<nums[i] << ", ";
   }
    return 0;
}