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
  string getRoomCode() const;
  void setRoomCode(const string&);

  // override method
  void show() const;
  string getClassName() const;

  friend ostream& operator << (ostream& o, const BoardingStudent& student);
  friend ostream& operator << (ostream& o, const BoardingStudent* student);
};

#endif