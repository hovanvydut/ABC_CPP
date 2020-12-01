#include "BoardingStudent.h"

BoardingStudent::BoardingStudent() : Student()
{

}

BoardingStudent::BoardingStudent(string name, int age, string address, bool gender, string studentId, double GPA, string roomCode)
  : Student(name, age, address, gender, studentId, GPA)
{
  this->roomCode = roomCode;
}
  
BoardingStudent::BoardingStudent(string name, int age, string address, bool gender, string studentId, double GPA, SectionClass* sectionClass, string roomCode)
  : Student(name, age, address, gender, studentId, GPA, sectionClass)
{
  this->roomCode = roomCode;
}

BoardingStudent::~BoardingStudent()
{

}

string BoardingStudent::getRoomCode() const
{
  return this->roomCode;
}

void BoardingStudent::setRoomCode(const string& roomCode)
{
  this->roomCode = roomCode;
}

void BoardingStudent::show() const
{
  Student::show();
  std::cout << "	roomCode: " << this->getRoomCode() << "\n";
}

ostream& operator << (ostream& o, const BoardingStudent& student)
{
  student.show();
  return o;
}

ostream& operator << (ostream& o, const BoardingStudent* student)
{
  student->show();
  return o;
}