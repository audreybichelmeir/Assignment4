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
  string strWindow = " ";
  int windows = 0;
  int atTimeOfArrival = 0;
  int students = 0;
  int timeNeeded = 0;
  bool continueReadingFile = true; // continues reading the file so it does not stop at the first line

  inputStream.open(file);

  if (!inputStream)
  {
    cout << file << " does not exist. " << endl;
    exit(1);
  }

  if (inputStream) // ok this if statement gets the window number
  {
    getline(inputStream, strWindow);
    windows = stoi(strWindow);

  }
  cout << "window: " << windows << endl;

  while(continueReadingFile){
    //cotinues to read in the current line
    getline(inputStream, line);
    atTimeOfArrival = stoi(line);
    //store int conversion
    getline(inputStream, line))
    students = stoi(line);
    for(int i = 0; i < students; ++i) {
    }
    getline(inputStream, line))
    timeNeeded = stoi(line);

    inputStream.close();
  }
}
