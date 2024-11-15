# Target to compile the object file
sorting_searching: sorting_searching.o
	g++ sorting_searching.o -o sorting_searching.exe

# Target to compile the C++ program
sorting_searching.o: sorting_searching.cpp
	g++ -c sorting_searching.cpp -o sorting_searching.o

# Target to run the program (interactively)
run: sorting_searching
	./sorting_searching.exe

# Target to compile the object Test file
sorting_searchingTest: sorting_searchingTest.o
	g++ sorting_searchingTest.o -o sorting_searchingTest.exe

# Target to compile the C++ Test program
sorting_searchingTest.o: sorting_searchingTest.cpp
	g++ -c sorting_searchingTest.cpp -o sorting_searchingTest.o

# Target to run the Test program
test: sorting_searchingTest
	./sorting_searchingTest.exe

# Target to clean up compiled files
clean:
	rm -f sorting_searching.o sorting_searchingTest.o sorting_searching.exe sorting_searchingTest.exe
