#include <iostream>
#include "../include/binary_tree.hpp"

using namespace std;

using namespace Nlib;

namespace Cmd {

	enum {

		exit,
		add,
		clear,
		print

	};

}

int main(void){

	BinaryTree<int> bt;

	int cmd, new_data;

	do{

		cout << Cmd::exit  << ": exit, ";
		cout << Cmd::add   << ": add, ";
		cout << Cmd::clear << ": clear, ";
		cout << Cmd::print << ": print" << endl;

		cout << "Enter the command code: ";

		cin >> cmd;

		if(cmd == Cmd::add){

			cout << "Enter the new data: ";

			cin >> new_data;

		}

		switch(cmd){

			case Cmd::exit:
				break;
			case Cmd::add:
				bt.add(new_data) ? cout << "Successfully added " << new_data << '.' << endl : cout << "Failed: memory allocation failed." << endl;
				break;
			case Cmd::clear:
				bt.clear();
				cout << "Successfully cleared." << endl;
				break;
			case Cmd::print:
				bt.print(PrintStyle::suspend);
				break;
			default:
				cout << "Wrong command!" << endl;

		}

	}while(cmd != Cmd::exit);

	return 0;

}
