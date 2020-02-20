#include <iostream>
#include "../include/AVL_tree.hpp"

using namespace std;

using namespace Nlib;

namespace Cmd{

	enum {

		exit,
		insert,
		exists,
		remove,
		clear,
		print

	};

}

int main(void){

	AVLTree<int> avl_tree;

	int cmd, data;

	do{

		cout << Cmd::exit << ": exit, ";
		cout << Cmd::insert  << ": insert, ";
		cout << Cmd::exists << ": exists, ";
		cout << Cmd::remove << ": remove, ";
		cout << Cmd::clear << ": clear, ";
		cout << Cmd::print << ": print" << endl;

		cout << "Enter the command code: ";

		cin >> cmd;

		if(Cmd::insert <= cmd && cmd <= Cmd::remove){

			cout << "Enter the data: ";

			cin >> data;

		}

		switch(cmd){

			case Cmd::exit:
				break;
			case Cmd::insert:
				avl_tree.insert(data) ? cout << "Successfully added " << data << '.' << endl : cout << "Failed: Duplicate data or memory allocation failed." << endl;
				break;
			case Cmd::exists:
				cout << data << " is" << (avl_tree.exists(data) ? "" : " not" ) << " in the tree" << endl;
				break;
			case Cmd::remove:
				avl_tree.remove(data) ?  cout << "Successfully removed." << endl : cout << "Failed: Not found!" << endl;
				break;
			case Cmd::clear:
				avl_tree.clear();
				cout << "Successfully cleared." << endl;
				break;
			case Cmd::print:
				if(!avl_tree.empty())
					cout << "height: " << avl_tree.getRoot() -> getHeight() << endl;
				avl_tree.print(PrintStyle::stretch);
				break;
			default:
				cout << "Wrong command!" << endl;

		}

	}while(cmd != Cmd::exit);

	return 0;

}
