#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Student
{
public:
  Student();
  ~Student();

  int getAtTimeOfArrival(); // empty
  void setAtTimeOfArrival(int timeArrival);

  int getStudent();
  void setStudent(int student);

  int getNeededTime();
  void setNeededTime(int timeNeeded);

private:
  unsigned int timeArr;
  unsigned int stu;
  unsigned int timeNeed;
};
