CXX=clang++
CXXFLAGS=-g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS=-g3



stringProcessing.o: stringProcessing.cpp stringProcessing.h main.o
	$(CXX) -c stringProcessing.cpp 

main.o: main.cpp
	$(CXX) -c main.cpp


unit_test: unit_test_driver.o CharLinkedList.o 
	$(CXX) unit_test_driver.o CharLinkedList.o 


clean:
	@rm -r *~ *# *.o a.out core* vgcore*
