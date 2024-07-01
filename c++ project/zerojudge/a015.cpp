#include <iostream>
using namespace std;

int main()
{
  int a, b;
  while (cin >> a >> b)
  {
    int matrix[a][b];
    for (int j = 0; j < a; j++)
    {
      for (int i = 0; i < b; i++)
      {
        cin >> matrix[j][i];
      }
    }
    for (int i = 0; i < b; i++)
    {
      for (int j = 0; j < a; j++)
      {
        cout << matrix[j][i] << ' ';
      }
      cout << '\n';
    }
  }
}