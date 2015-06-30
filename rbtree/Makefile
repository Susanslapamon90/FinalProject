target:final_project
CPPFLAG: -std=c++11 -O2

final_project: md5.o process.o history3.o FPmainnew.o rb.o
	g++ md5.o process.o history3.o FPmainnew.o rb.o -o final_project
md5.o:md5.cpp
	g++ -std=c++11 -O2 md5.cpp -c
rb.o:rb.c
	gcc -O2 rb.c -c
process.o:process.cpp
	g++ -std=c++11 -O2 process.cpp -c
history3.o:history3.cpp
	g++ -std=c++11 -O2 history3.cpp -c
FPmainnew.o:FPmainnew.cpp
	g++ -std=c++11 -O2 FPmainnew.cpp -c
clean:
	rm -rf final_project *.o
