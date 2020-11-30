#makefile

CXX=g++
SOURCE = main.cpp Lecturer/Lecturer.cpp LopSinhHoat/LopSinhHoat.cpp Person/Person.cpp SinhVien/SinhVien.cpp


build: $(SOURCE)
	g++ $? -o ./bin/main
run:
	./bin/main