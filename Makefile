CPPFLAGS = -O2 -Wall
LO = encode.cpp
OTHER = process.cpp
name = final_project

all : $(TARGET)

all:
	g++ $(CPPFLAGS) $(LO) $(OTHER) FPmain.cpp -o $(name)
