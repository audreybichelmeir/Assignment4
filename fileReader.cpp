#include "fileReader.h"

fileReader::fileReader()
{
}

fileReader::~fileReader()
{
}

void fileReader::filePrompt(string error)
{
  string fileChecker = " ";
bool isGood = false;

while(!isGood)
{
  cout << "Enter file name:" << endl;
  cin >> fileChecker;
  if(fileChecker.length() > 0){
    isGood = true;
  }
}
readAFile(fileChecker);
// return error;

}

void fileReader::readAFile(string file)
{
  fileReader fr;
  string line = " ";
  fstream inputStream;

  inputStream.open(file);

  if (!inputStream)
  {
    cout << file << " does not exist. " << endl;
    exit(1);
  }

  while(getline(inputStream, line))
  {
    cout << line << endl;
  }
  inputStream.close();

  //return file;

}
