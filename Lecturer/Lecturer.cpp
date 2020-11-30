#include "Lecturer.h"

Lecturer::Lecturer() : Person()
{
}

Lecturer::Lecturer(string ten, int tuoi, string dia_chi, bool gioi_tinh, string cap_bac)
    : Person(ten, tuoi, dia_chi, gioi_tinh)
{
  this->cap_bac = cap_bac;
  // override method
  this->setTen(ten);
}

Lecturer::Lecturer(const Lecturer &lecture)
{
}

Lecturer::~Lecturer()
{
}

// setter, getter

// override
void Lecturer::setTen(const string &ten)
{
  this->ten = ten;
  this->setMaLecture();
}

string Lecturer::getMaLecture() const
{
  return this->ma_lecture;
}

string Lecturer::getCapBac() const
{
  return this->cap_bac;
}

void Lecturer::setCapBac(const string &cap_bac)
{
  this->cap_bac = cap_bac;
}

void Lecturer::setMaLecture()
{
  // Le Thi My Hanh ==> 102ltmhanh
  // Dang Hoai Phuong ==> 102dhphuong
  this->ma_lecture = this->createIdLecturerFromName(this->getTen());
}

void Lecturer::show()
{
  Person::show();
  std::cout << "	ma lecturer: " << this->getMaLecture() << "\n";
  std::cout << "	cap bac: " << this->getCapBac() << "\n";
}

string Lecturer::createIdLecturerFromName(string str)
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