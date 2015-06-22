CPPFLAGS = -std=c++11  -O2 -Wall
LO = md5.cpp history.cpp
OTHER = process.cpp
GENERATE = num_small_big.cpp
name = final_project

all : $(TARGET)

all:
	g++ $(CPPFLAGS) $(LO) $(OTHER) FPmain.cpp -o $(name)
rm:
	rm *.cpp~ *.h~ Makefile~
name:
	g++ $(CPPFLAGS) $(GENERATE) -o ID_generator
