CPPFLAGS = -O2 -Wall
LO = md5.cpp history.cpp
OTHER = process.cpp
name = final_project

all : $(TARGET)

all:
	g++ $(CPPFLAGS) $(LO) $(OTHER) FPmain.cpp -o $(name)
rm:
	rm *.cpp~ *.h~ Makefile~
