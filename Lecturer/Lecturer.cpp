#include "Lecturer.h"

Lecturer::Lecturer() : Person()
{
}

Lecturer::Lecturer(string name, int age, string address, bool gender, string level)
    : Person(name, age, address, gender)
{
  this->level = level;
  // override method
  this->setName(name);
}

Lecturer::Lecturer(const Lecturer &lecture)
{
}

Lecturer::~Lecturer()
{
}

// setter, getter

// override
void Lecturer::setName(const string &name)
{
  this->name = name;
  this->setMaLecture();
}

string Lecturer::getLecturerCode() const
{
  return this->lecturerCode;
}

string Lecturer::getLevel() const
{
  return this->level;
}

void Lecturer::setLevel(const string &level)
{
  this->level = level;
}

void Lecturer::setMaLecture()
{
  // Le Thi My Hanh ==> 102ltmhanh
  // Dang Hoai Phuong ==> 102dhphuong
  this->lecturerCode = this->createLecturerCodeFromName(this->getName());
}

void Lecturer::show() const
{
  Person::show();
  std::cout << "	ma lecturer: " << this->getLecturerCode() << "\n";
  std::cout << "	cap bac: " << this->getLevel() << "\n";
}

string Lecturer::getClassName() const
{
  return "Lecturer";
}

string Lecturer::createLecturerCodeFromName(string str)
{
  string arr[100];
  int idx = 0;
  string temp = "";
  for (int i = 0; i < str.length(); i++)
  {
    char c = str[i];
    if (c == ' ' && temp.length() > 0)
    {
      arr[idx] = temp;
      idx++;
      temp = "";
    }
    else
    {
      temp += c;
    }
  }
  arr[idx] += temp;
  idx++;

  string result = "102";
  for (int i = 0; i < idx - 1; i++)
  {
    result += arr[i][0] <= 90 ? arr[i][0] + 32 : arr[i][0];
  }
  result += arr[idx - 1][0] <= 90 ? arr[idx - 1][0] + 32 : arr[idx - 1][0];
  ;
  for (int i = 1; i < arr[idx - 1].length(); i++)
  {
    result += arr[idx - 1][i];
  }

  return result;
}

ostream& operator << (ostream& o, const Lecturer& lecturer)
{
  o << lecturer.getClassName() << "\n";
  lecturer.show();
  return o;
}

ostream& operator << (ostream& o, const Lecturer* lecturer)
{
  o << lecturer->getClassName() << "\n";
  lecturer->show();
  return o;
}