#include <iostream>
#include "../include/binary_search_tree.hpp"

using namespace std;

using namespace Nlib;

namespace Cmd{

	enum {

		exit,
		add,
		exists,
		remove,
		clear,
		print

	};

}

int main(void){

	BinarySearchTree<int> BST;

	int cmd, data;

	do{

		cout << Cmd::exit << ": exit, ";
		cout << Cmd::add  << ": add, ";
		cout << Cmd::exists << ": exists, ";
		cout << Cmd::remove << ": remove, ";
		cout << Cmd::clear << ": clear, ";
		cout << Cmd::print << ": print" << endl;

		cout << "Enter the command code: ";

		cin >> cmd;

		if(Cmd::add <= cmd && cmd <= Cmd::remove){

			cout << "Enter the data: ";

			cin >> data;

		}

		switch(cmd){

			case Cmd::exit:
				break;
			case Cmd::add:
				BST.add(data) ? cout << "Successfully added " << data << '.' << endl : cout << "Failed: Duplicate data or memory allocation failed." << endl;
				break;
			case Cmd::exists:
				cout << data << " is" << (BST.exists(data) ? "" : " not" ) << " in the tree" << endl;
				break;
			case Cmd::remove:
				BST.remove(data);
			    cout << "Successfully removed." << endl;
				break;
			case Cmd::clear:
				BST.clear();
				cout << "Successfully cleared." << endl;
				break;
			case Cmd::print:
				BST.print();
				break;
			default:
				cout << "Wrong command!" << endl;

		}

	}while(cmd != Cmd::exit);

	return 0;

}
