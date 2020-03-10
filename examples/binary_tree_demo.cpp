#include <iostream>
#include "binary_tree.hpp"

using namespace std;

using namespace Nlib;

namespace Cmd {

	enum {

		exit,
		insert,
		clear,
		print

	};

}

int main(void){

	BinaryTree<int> bt;

	int cmd, new_data;

	do{

		cout << Cmd::exit  << ": exit, ";
		cout << Cmd::insert   << ": insert, ";
		cout << Cmd::clear << ": clear, ";
		cout << Cmd::print << ": print" << endl;

		cout << "Enter the command code: ";

		cin >> cmd;

		if(cmd == Cmd::insert){

			cout << "Enter the new data: ";

			cin >> new_data;

		}

		switch(cmd){

			case Cmd::exit:
				break;
			case Cmd::insert:
				bt.insert(new_data) ? cout << "Successfully added " << new_data << '.' << endl : cout << "Failed: memory allocation failed." << endl;
				break;
			case Cmd::clear:
				bt.clear();
				cout << "Successfully cleared." << endl;
				break;
			case Cmd::print:
				if(!bt.empty())
					cout << "height: " << bt.getRoot() -> getHeight() << endl;
				bt.print(PrintStyle::suspend);
				break;
			default:
				cout << "Wrong command!" << endl;

		}

	}while(cmd != Cmd::exit);

	return 0;

}
