#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class fileReader
{
public:
  fileReader();
  ~fileReader();
  void filePrompt(string error);
  void readAFile(string file);

};
