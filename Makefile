CXX = g++

BT = binary_tree.tpp binary_tree.hpp
BST = binary_search_tree.tpp binary_search_tree.hpp
AVLT = AVL_tree.tpp AVL_tree.hpp

vpath %.hpp include/
vpath %.tpp src/

.PHONY: all demo demo2 demo3 clean

all: demo demo2 demo3

demo: examples/binary_tree_demo.cpp binary_tree.tpp binary_tree.hpp
	$(CXX) -o run_demo $<

demo2: examples/binary_search_tree_demo.cpp binary_search_tree.tpp binary_search_tree.hpp binary_tree.tpp binary_tree.hpp
	$(CXX) -o run_demo2 $<

demo3: examples/AVL_tree_demo.cpp $(AVLT) $(BST) $(BT)
	$(CXX) -o run_demo3 $<

clean:
	-rm *.o
	-rm run*
