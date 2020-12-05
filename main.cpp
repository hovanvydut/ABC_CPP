#include <iostream>
#include "Person/Person.h"
#include "Lecturer/Lecturer.h"
#include "SectionClass/SectionClass.h"
#include "Student/Student.h"
#include "Lecturer/Lecturer.h"
#include "BoardingStudent/BoardingStudent.h"
#include "NormalStudent/NormalStudent.h"
using namespace std;

int main()
{
  /* Student *fakeStudent = new Student("afasfds", 123, "Tdafd", true, "1234567890", 4.0);
  Student *student1 = new Student("Ho Van      Vy", 19, "TT.Hue", true, "1234567890", 2.3);
  Student *student2 = new Student(" Nguyen Huy   Tuong", 30, "Quang Nom", true, "5432167890", 4.0);
  Student *student3 = new Student("Nguyen  Duy Thinh", 22, "TT.Hue", false,"7654321890", 3.0);
  BoardingStudent *bstudent1 = new BoardingStudent("Tran Viet Truong", 33, "Da Neng", false, "8765432190", 3.9, "B304");
  NormalStudent *nstudent1 = new NormalStudent("Nguyen Van Thanh", 22, "Quang Nom", false,"7654321890", 3.0, "P12121212");
  Lecturer lecturerOOP("Dang Hoai Phuong", 40, "Unknown", false, "Expert");

  SectionClass *toangCLC = SectionClass::getInstance();

  toangCLC->setLecturer(&lecturerOOP);
  toangCLC->setName("19TCLC_DT4");

  cout << "List students of " + toangCLC->getName() << endl;
  toangCLC->addStudent(student1);
  toangCLC->addStudent(student2);
  toangCLC->addStudent(student3);
  toangCLC->addStudent(bstudent1);
  toangCLC->addStudent(nstudent1);
  toangCLC->addStudent(fakeStudent);
  
  cout << toangCLC << endl;

  cout << "----------" << endl;
  
  if (toangCLC->removeStudentById("5432167890"))
  {
    cout << "Removed" << endl;
  }
  toangCLC->sortGPAStudentDESC();
  cout << toangCLC << endl;

  cout << "------------------\n";
  cout << (*toangCLC)[0] << endl;

  cout << "------------------\n";
  cout << (toangCLC->findStudentById("8765432190")) << endl; */

  // init
  SectionClass *myClass = SectionClass::getInstance();
  Lecturer* dhPhuong = new Lecturer();

  cout << "HO VAN VY - 102190200" << endl;
  int choice;
  do {
    MENU:
    cout << "\n+------------------------------------------------------------------+" << endl;
    cout << "Nhan so tuong ung de chon: " << endl;
    cout << "\t1. Nhap thong tin lop sinh hoat" << endl;
    cout << "\t2. Nhap du lieu giao vien chu nhiem " << endl;
    cout << "\t3. Nhap du lieu Sinh Vien" << endl;
    cout << "\t4. Hien thi toan bo thong tin lop sinh hoat" << endl;
    cout << "\t5. Tim kiem sinh vien bang ma sinh vien" << endl;
    cout << "\t6. Sap xep danh sach sinh vien theo diem GPA tang dan" << endl;
    cout << "\t7. Sap xep danh sach sinh vien theo diem GPA giam dan" << endl;
    cout << "\t8. Xoa sinh vien khoi lop sinh hoat bang ma sinh vien" << endl;
    cout << "\t0. Thoat chuong trinh" << endl;
    cout << "+------------------------------------------------------------------+\n" << endl;

    INPUT_CHOICE:
    cout << "$ "; cin >> choice;

    if (choice < 0 || choice > 8)
    {
      cout << "Vui long nhap [0-8] !!!" << endl;
      goto INPUT_CHOICE;
    }

    switch(choice)
    {
      case 0:
      {
        cout << "Bye Bye thay Phuong !!!" << endl;
        exit(0);
        break;
      }

      case 1:
      {
        cin >> myClass;
        goto MENU;
        break;
      }

      case 2:
      {
        cin >> dhPhuong;
        myClass->setLecturer(dhPhuong);
        goto MENU;
        break;
      }

      case 3:
      {
        INPUT_STUDENT:
        cout << "*** Nhap 'N' de nhap du lieu cho NormalStudent, 'B' cho BoardingStudent' " << endl;
        char ch;
        cout << "$ "; cin >> ch;
        if (ch == 'N')
        {
          NormalStudent* newStudent = new NormalStudent();
          cin >> newStudent;
          myClass->addStudent(newStudent);
        } else if (ch == 'B')
        {
          BoardingStudent* newStudent = new BoardingStudent();
          cin >> newStudent;
          myClass->addStudent(newStudent);
        } else 
        {
          cout << "Vui long nhap 'N' hoac 'B' !!!" << endl;
          goto INPUT_STUDENT;
        }
        
        goto MENU;
        break;
      }

      case 4:
      {
        cout << myClass;
        goto MENU;
        break;
      }

      case 5:
      {
        string studentId;
        cout << "* Nhap studentID = "; cin >> studentId;
        const Student* student = myClass->findStudentById(studentId);
        if (student == nullptr)
        {
          cout << "Khong tim thay !!!" << endl;
        } else
        {
          cout << student;
        }
        goto MENU;
        break;
      }

      case 6:
      {
        myClass->sortGPAStudentASC();
        cout << myClass;
        goto MENU;
        break;
      }

      case 7:
      {
        myClass->sortGPAStudentDESC();
        cout << myClass;
        goto MENU;
        break;
      }

      case 8:
      {
        string studentId;
        cout << "* Nhap studentID = "; cin >> studentId;
        bool result = myClass->removeStudentById(studentId);
        if (result == false)
        {
          cout << "Khong tim thay !!!" << endl;
        } else
        {
          cout << "Da xoa Student co id = " << studentId << endl;
        }
        goto MENU;
        break;
      }
    }
  } while (choice != 0);

  return 0;
}