#include "fileReader.h"
#include "Student.h"
#include "Window.h"

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
  int studentCounter = 0; // this is for checking purposes
  int timeNeededCounter = 0;
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

    // put in function
    Window *window = new Window();
    window->setWindow(windows);
    delete window;
    //-----

  }
  cout << "window: " << windows << endl;

  while(continueReadingFile){
    while(!inputStream.eof()){



      getline(inputStream, line);
      atTimeOfArrival = stoi(line);
      cout << "time of arrival: " << atTimeOfArrival << endl;
      // put in function
      Student *stu = new Student();
      stu->setAtTimeOfArrival(atTimeOfArrival);
      delete stu;
      //-----


      getline(inputStream, line);
      students = stoi(line);
      studentCounter = students;
      //cout << "student counter: " << studentCounter << endl;

      cout << "students: " << students << endl;

      // put in function
      Student *stu2 = new Student();
      stu2->setStudent(students);
      delete stu2;
      //-----


      for(int i = 0; i < students; ++i) {

        getline(inputStream, line);
        timeNeeded = stoi(line);
        cout << "time needed: " << timeNeeded << endl;
        timeNeededCounter++;
        //cout << "time needed counter: " << timeNeededCounter << endl;


        // put in function
        Student *stu3 = new Student();
        stu3->setNeededTime(timeNeeded);
        delete stu3;
        //-----


      }
      // ok gonna attempt to check if the file is consider correct in the sense that ever thing matches up but we'll see that
      //wow i did it hahaha
      if(studentCounter == timeNeededCounter){ // start
        //cout << "ok matches, awesome! " << endl;
        studentCounter = 0;
        timeNeededCounter = 0;
      } else{ // idk why it doesnt print - ignores error if it does bot happen
        cout << "problem with file" << endl;
      }
      if(inputStream.eof()){
        continueReadingFile = false;
      }

      //inputStream.close(); --> um okkkk wtf so if i dont close it it actually reads the whole file or i guess i should move this else where ? BRUH
    } // end of while end of file
  } // end of continueReadingFile while statement
  inputStream.close(); // okay, i guess keeping it here is fine ? lol
}



/*

while(!find.eof())                        //as long as eof() is zero
{					  //that is, the file's end is not reached
:                                 //process the file
}
if(fin.eof())

https://codescracker.com/cpp/cpp-detecting-eof.htm
*/
