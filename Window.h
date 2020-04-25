#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Window
{
public:
  Window();
  ~Window();
  int getWindow(); // empty
  void setWindow(int windows);

private:
  unsigned int window;
};
