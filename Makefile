CXX = g++

vpath %.hpp include/
vpath %.tpp src/

.PHONY: demo, demo2, clean

demo: examples/binary_tree_demo.cpp binary_tree.tpp binary_tree.hpp
	$(CXX) -o run_demo $<

demo2: examples/binary_search_tree_demo.cpp binary_search_tree.tpp binary_search_tree.hpp binary_tree.tpp binary_tree.hpp
	$(CXX) -o run_demo2 $<

clean:
	-rm *.o
	-rm run*
