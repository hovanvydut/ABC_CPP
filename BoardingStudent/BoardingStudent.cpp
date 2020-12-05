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

string BoardingStudent::getClassName() const
{
  return "BoardingStudent";
}

ostream& operator << (ostream& o, const BoardingStudent& student)
{
  o << student.getClassName() << "\n";
  student.show();
  return o;
}

ostream& operator << (ostream& o, const BoardingStudent* student)
{
  o << student->getClassName() << "\n";
  student->show();
  return o;
}

istream& operator >> (istream& in, BoardingStudent& student)
{
  string name, address, studentId, roomCode;
  int age, gender;
  double GPA;

  cout << "*** Vui long nhap: \n";

  in.ignore();
  cout << "* Ten: "; getline(in, name);
  student.setName(name);

  INPUT_AGE:
  cout << "* Tuoi: "; in >> age;
  try {
    student.setAge(age);
  } catch (const char* msg)
  {
    cout << msg << endl;
    goto INPUT_AGE;
  }

  in.ignore();
  cout << "* Dia chi: "; getline(in, address);
  student.setAddress(address);

  INPUT_GENDER:
  cout << "* Gioi tinh(0: nu, 1: nam): "; in >> gender;
  if (gender == 1)
    student.setGender(true);
  else if (gender == 0)
    student.setGender(false);
  else
  {
    cout << "Error: Nhap 0 hoac 1 \n";
    goto INPUT_GENDER;
  }

  int count = 1;
  INPUT_STUDENT_CODE:
  cout << "* Ma sinh vien (gom 10 ki tu, khong duoc bat dau bang ki tu 0): ";
  if (count == 1)
    in.ignore();
  try
  {
    count++;
    getline(in, studentId);
    student.setStudentId(studentId);
  } catch (const char* msg)
  {
    cout << msg << endl;
    goto INPUT_STUDENT_CODE;
  }
  
  INPUT_GPA:
  try {
    cout << "* GPA: ";
    in >> GPA;
    student.setGPA(GPA);
  } catch (const char* msg)
  {
    cout << msg << endl;
    goto INPUT_GPA;
  }

  in.ignore();
  cout << "* Nhap ma phong ngu: "; getline(in, roomCode);
  student.setRoomCode(roomCode);

  return in;
}

istream& operator >> (istream& in, BoardingStudent* student)
{
  string name, address, studentId, roomCode;
  int age, gender;
  double GPA;

  cout << "*** Vui long nhap: \n";

  in.ignore();
  cout << "* Ten: "; getline(in, name);
  student->setName(name);

  INPUT_AGE:
  cout << "* Tuoi: "; in >> age;
  try {
    student->setAge(age);
  } catch (const char* msg)
  {
    cout << msg << endl;
    goto INPUT_AGE;
  }

  in.ignore();
  cout << "* Dia chi: "; getline(in, address);
  student->setAddress(address);

  INPUT_GENDER:
  cout << "* Gioi tinh(0: nu, 1: nam): "; in >> gender;
  if (gender == 1)
    student->setGender(true);
  else if (gender == 0)
    student->setGender(false);
  else
  {
    cout << "Error: Nhap 0 hoac 1 \n";
    goto INPUT_GENDER;
  }

  int count = 1;
  INPUT_STUDENT_CODE:
  cout << "* Ma sinh vien (gom 10 ki tu, khong duoc bat dau bang ki tu 0): ";
  if (count == 1)
    in.ignore();
  try
  {
    count++;
    getline(in, studentId);
    student->setStudentId(studentId);
  } catch (const char* msg)
  {
    cout << msg << endl;
    goto INPUT_STUDENT_CODE;
  }
  
  INPUT_GPA:
  try {
    cout << "* GPA: ";
    in >> GPA;
    student->setGPA(GPA);
  } catch (const char* msg)
  {
    cout << msg << endl;
    goto INPUT_GPA;
  }

  in.ignore();
  cout << "* Nhap ma phong ngu: "; getline(in, roomCode);
  student->setRoomCode(roomCode);

  return in;
}
