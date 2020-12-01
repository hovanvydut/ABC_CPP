#ifndef BOARDINGSTUDENT_H
#define BOARDINGSTUDENT_H

#include "../SectionClass/SectionClass.h"
#include "../Student/Student.h"
#include <string>

class BoardingStudent : public Student
{

private:  
  string roomCode;

public:  
  BoardingStudent();
  BoardingStudent(string, int, string, bool, string, double, string);
  BoardingStudent(string, int, string, bool, string, double, SectionClass*, string);
  ~BoardingStudent();

  // setter, getter
  string getRoomCode();
  void setRoomCode(const string&);
};

#endif