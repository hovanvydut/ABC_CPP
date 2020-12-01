#makefile

CXX=g++
SOURCE = main.cpp Lecturer/Lecturer.cpp SectionClass/SectionClass.cpp Person/Person.cpp Student/Student.cpp \
BoardingStudent/BoardingStudent.h


build: $(SOURCE)
	g++ $? -o ./bin/main
run:
	./bin/main