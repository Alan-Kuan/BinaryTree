CC = g++

.PHONY: demo, clean

demo: examples/binary_tree_demo.cpp src/binary_tree.tpp include/binary_tree.hpp
	$(CC) -o run_demo $<

clean:
	-rm *.o
	-rm run*
