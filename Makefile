CPPFLAGS = -std=c++11  -O2 -Wall
LO = md5.cpp history.cpp
OTHER = process.cpp
GENERATE = num_small_big.cpp
name = final_project
name2 = dlte

all : $(TARGET)

all:
	g++ $(CPPFLAGS) $(LO) $(OTHER) FPmain.cpp -o $(name)
rm:
	rm -rf *.cpp~ *.h~ Makefile~
name:
	g++ $(CPPFLAGS) $(GENERATE) -o ID_generator
list:
	g++ $(CPPFLAGS) list10.cpp -o list
