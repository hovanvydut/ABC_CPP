#include "Person.h"

Person::Person(string name, int age, string address, bool gender)
{
  this->setName(name);
  this->setAge(age);
  this->setAddress(address);
  this->setGender(gender);
}

Person::Person(const Person &person)
{
  this->setName(person.name);
  this->setAge(person.age);
  this->setAddress(person.address);
  this->setGender(person.gender);
}

Person::~Person()
{
}

string Person::getName() const
{
  return this->name;
}

void Person::setName(const string &name)
{
  // validate tên, chỉ chưa các kí tự chữ, loại bỏ space đầu, cuối, và 2 space liên tiếp ở giữa
  this->name = this->removeSpaceAndValidateString(name);
}

int Person::getAge() const
{
  return this->age;
}

void Person::setAge(const int &age)
{
  if (age < 0 || age > 200)
  {
    throw "Error: age phai >= 0 va < 200";
  }

  this->age = age;
}

string Person::getAddress() const
{
  return this->address;
}

void Person::setAddress(const string &address)
{
  this->address = address;
}

bool Person::getGender() const
{
  return this->gender;
}

void Person::setGender(const bool &gender)
{
  this->gender = gender;
}

void Person::show() const
{
  std::cout << "	name: " << this->getName() << "\n";
  std::cout << "	age: " << this->getAge() << "\n";
  std::cout << "	address: " << this->getAddress() << "\n";
  if (this->getGender())
    std::cout << "	gender: nam" << "\n";
  else
    std::cout << "	gender: nu" << "\n";
}

string Person::getClassName() const
{
  return "Person";
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

// 
ostream& operator << (ostream& o, const Person& person)
{
  o << person.getClassName() << "\n";
  person.show();
  return o;
}
ostream& operator << (ostream& o, const Person* person)
{
  o << person->getClassName() << "\n";
  person->show();
  return o;
}