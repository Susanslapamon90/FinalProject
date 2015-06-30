target:final_project

final_project: md5.o processbst.o history3.o FPmainnew.o bst.o
	g++ md5.o processbst.o history3.o FPmainnew.o bst.o -o final_project
md5.o:md5.cpp
	g++ -std=c++11 -O2 md5.cpp -c
bst.o:bst.c
	gcc bst.c -c
processbst.o:processbst.cpp
	g++ -std=c++11 -O2 processbst.cpp -c
history3.o:history3.cpp
	g++ -std=c++11 -O2 history3.cpp -c
FPmainnew.o:FPmainnew.cpp
	g++ -std=c++11 -O2 FPmainnew.cpp -c
clean:
	rm -rf final_project *.o
