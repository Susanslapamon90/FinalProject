target:final_project
CPPFLAG: -std=c++11 -O2

final_project: md5.o processavl.o history3.o FPmainnew.o avl.o
	g++ md5.o processavl.o history3.o FPmainnew.o avl.o -o final_project
md5.o:md5.cpp
	g++ -std=c++11 -O2 md5.cpp -c
avl.o:avl.c
	gcc avl.c -c
processavl.o:processavl.cpp
	g++ -std=c++11 -O2 processavl.cpp -c
history3.o:history3.cpp
	g++ -std=c++11 -O2 history3.cpp -c
FPmainnew.o:FPmainnew.cpp
	g++ -std=c++11 -O2 FPmainnew.cpp -c
clean:
	rm -rf final_project *.o
