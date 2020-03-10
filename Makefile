CXX = g++

CXXFLAGS = -I include/

.PHONY: all demo demo2 demo3 clean

all: demo demo2 demo3

demo: examples/binary_tree_demo.cpp
	$(CXX) -o run_demo $< $(CXXFLAGS)

demo2: examples/binary_search_tree_demo.cpp
	$(CXX) -o run_demo2 $< $(CXXFLAGS)

demo3: examples/AVL_tree_demo.cpp
	$(CXX) -o run_demo3 $< $(CXXFLAGS)

clean:
	-rm *.o
	-rm run*
