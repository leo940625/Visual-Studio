#include <iostream>
using namespace std;

int lengthOfLastWord(string s) {
   int fix;
   for (int i = 0; i < s.length(); i++)
   {
      if(s[i]=' ')
      {
        fix = 0;
      }
      else
      {
        fix++;
      }
   }
   return fix;
} 
          
        
          