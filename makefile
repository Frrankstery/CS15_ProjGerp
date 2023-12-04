CXX=clang++
CXXFLAGS=-g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS=-g3



stringProcessing.o: stringProcessing.cpp stringProcessing.h main.o
	$(CXX) -c stringProcessing.cpp 

#Rule for FSTreeTraversal.o
FSTreeTraversal.o: FSTreeTraversal.cpp DirNode.h FSTree.h
	$(CXX) $(CXXFLAGS) -c FSTreeTraversal.cpp

main.o: main.cpp
	$(CXX) -c main.cpp


unit_test: unit_test_driver.o stringProcessing.o FSTreeTraversal.o DirNode.o FSTree.o
	$(CXX) unit_test_driver.o 


clean:
	@rm -r *~ *# *.o a.out core* vgcore*
