#include <iostream>
using namespace std;
using std::string;

int main()
{
  string first;
  while (getline(cin, first))
  {
    string second;
    for (int i = 0; i < first.length(); i++)
    {
      second += char(int(first[i]) - 7);
    }
    cout << second << endl;
  }
  return 0;
}
