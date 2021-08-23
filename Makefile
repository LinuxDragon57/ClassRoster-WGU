all: ClassRosterExec

ClassRosterExec : main.cpp roster.o student.o
	g++ -Wall -g main.cpp roster.o -o ClassRosterExec

roster.o : roster.cpp roster.h student.cpp student.h degree.h
	g++ -Wall -g -c roster.cpp student.cpp

student.o : student.cpp student.h
	g++ -Wall -g -c student.cpp student.h

clean :
	rm -f student.o roster.o ClassRosterExec