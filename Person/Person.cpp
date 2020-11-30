#include "Person.h"

Person::Person()
{
}

Person::Person(string ten, int tuoi, string dia_chi, bool gioi_tinh)
{
  this->setTen(ten);
  this->setTuoi(tuoi);
  this->setDiaChi(dia_chi);
  this->setGioiTinh(gioi_tinh);
}

Person::Person(const Person &person)
{
  this->setTen(person.ten);
  this->setTuoi(person.tuoi);
  this->setDiaChi(person.dia_chi);
  this->setGioiTinh(person.gioi_tinh);
}

Person::~Person()
{
}

string Person::getTen() const
{
  return this->ten;
}

void Person::setTen(const string &ten)
{
  // validate tên, chỉ chưa các kí tự chữ, loại bỏ space đầu, cuối, và 2 space liên tiếp ở giữa
  this->ten = this->removeSpaceAndValidateString(ten);
}

int Person::getTuoi() const
{
  return this->tuoi;
}

void Person::setTuoi(const int &tuoi)
{
  if (tuoi < 0 && tuoi < 200)
  {
    throw "Error: tuoi phai lon hon 0";
  }

  this->tuoi = tuoi;
}

string Person::getDiaChi() const
{
  return this->dia_chi;
}

void Person::setDiaChi(const string &dia_chi)
{
  this->dia_chi = dia_chi;
}

bool Person::getGioiTinh() const
{
  return this->gioi_tinh;
}

void Person::setGioiTinh(const bool &gioi_tinh)
{
  this->gioi_tinh = gioi_tinh;
}

void Person::show()
{
  std::cout << "Person: \n";
  std::cout << "	ten: " << this->getTen() << "\n";
  std::cout << "	tuoi: " << this->getTuoi() << "\n";
  std::cout << "	dia chi: " << this->getDiaChi() << "\n";
  std::cout << "	gioi tinh: " << this->getGioiTinh() << "\n";
}

string Person::removeSpaceAndValidateString(string str)
{
  string temp = "";
  string result = "";
  for (char c : str)
  {
    if (!((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == ' '))
    {
      throw "Error: Ten phai la ki tu [A-Za-z] va dau cach";
    }
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
    {
      temp += c;
    }
    else
    {
      if (temp.length() > 0)
        result = result + temp + ' ';
      temp = "";
    }
  }

  result += temp;

  if (result[result.length() - 1] == ' ')
  {
    string s = "";
    for (int i = 0; i < result.length() - 1; i++)
    {
      s += result[i];
    }
    return s;
  }
  return result;
}