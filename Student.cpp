#include "Student.h"

Student::Student(){

  timeArr = 0;
  stu = 0;
  timeNeed = 0;

}

Student::~Student(){

}


int Student::getAtTimeOfArrival(){

  return timeArr;

}

void Student::setAtTimeOfArrival(int timeArrival){

timeArr = timeArrival;

}

int Student::getStudent(){

return stu;
}

void Student::setStudent(int student){

stu = student;
}

int Student::getNeededTime(){

return timeNeed;
}

void Student::setNeededTime(int timeNeeded){

timeNeed = timeNeeded;
}
