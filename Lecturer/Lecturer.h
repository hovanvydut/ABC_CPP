#ifndef LECTURER_H
#define LECTURER_H

#include "../Person/Person.h"

class Lecturer : public Person
{

private:
  string lecturerCode;
  string level;

public:
  Lecturer();
  Lecturer(string, int, string, bool, string);
  Lecturer(const Lecturer &);
  ~Lecturer();

  // setter, getter
  // override setName()
  void setName(const string &);

  string getLecturerCode() const;

  string getLevel() const;
  void setLevel(const string &);

  void show() const;

  friend ostream& operator << (ostream& o, const Lecturer& lecturer);
  friend ostream& operator << (ostream& o, const Lecturer* lecturer);

private:
  void setMaLecture();
  string createLecturerCodeFromName(string str);
};

#endif