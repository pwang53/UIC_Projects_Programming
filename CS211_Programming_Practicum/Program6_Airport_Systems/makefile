proj6: pwang53Proj6.o Airport.o FileList.o
        g++ -o proj6 pwang53Proj6.o Airport.o FileList.o

pwang53Proj6.o: pwang53Proj6.cpp myClasses.h
        g++ -c pwang53Proj6.cpp

Airport.o: Airport.cpp myClasses.h
        g++ -c Airport.cpp

FileList.o: FileList.cpp myClasses.h
        g++ -c FileList.cpp

clean:
        rm proj6 pwang53Proj6.o Airport.o FileList.o