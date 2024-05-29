#include <iostream>
using namespace std;
int main()
{
  int pizzas;
  cout << "How many pizzas do you want?";
  cin >> pizzas;
  cout << "You need to pay " << pizzas*50 << " yuan, thank you.";
  return 0;
}