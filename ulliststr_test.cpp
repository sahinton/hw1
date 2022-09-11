/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"


int main(int argc, char* argv[])
{
	//casual test
	ULListStr dat;
	dat.push_front("5");
	std::cout << "Push front on empty." << std::endl;
	dat.push_back("12");
	dat.push_back("10");
	dat.push_back("8");
	dat.pop_front();
	dat.pop_back();
	std::cout << dat.back() << " back" << std::endl;
	std::cout << dat.get(0) << " get 0" << std::endl;
	std::cout << dat.size() << " size" << std::endl;
	std::cout << dat.front() << " front" << std::endl;
	dat.set(0, "20");
	std::cout << dat.front() << " front after setting" << std::endl;
	dat.clear();
	std::cout << "New List" << std::endl << std::endl;

	//test for large lists
	for (int i = 0; i < 50; i++){
		dat.push_back(std::to_string(i));
	}
	std::cout << dat.front() << " front" << std::endl;
	std::cout << dat.back() << " back" << std::endl;
	std::cout << dat.get(12) << " get 12" << std::endl;
	std::cout << dat.get(1) << " get 1" << std::endl;
	std::cout << dat.size() << " size" << std::endl;
	dat.clear();
	std::cout << "New List" << std::endl << std::endl;

	//test for multiple pop_backs
	dat.push_back("1");
	std::cout << "Push back on empty." << std::endl;
	dat.pop_back();
	dat.pop_back();
	std::cout << "Pop on empty." << std::endl;
	dat.push_back("5");
	dat.push_back("12");
	dat.push_back("10");
	dat.push_back("8");
	dat.pop_back();
	dat.pop_back();
	dat.pop_back();
	dat.pop_back();
	dat.pop_back();
	std::cout << dat.size() << " size" << std::endl;
	dat.clear();
	std::cout << "New List" << std::endl << std::endl;

	//test for multiple pop_fronts
	dat.pop_front();
	std::cout << "Pop on empty." << std::endl;
	dat.push_back("5");
	dat.push_back("12");
	dat.push_back("10");
	dat.push_back("8");
	dat.pop_front();
	dat.pop_front();
	dat.pop_front();
	dat.pop_front();
	dat.pop_front();
	std::cout << dat.size() << " size" << std::endl;
	dat.clear();
	std::cout << "New List" << std::endl << std::endl;

	//get value at bad loc
	//std::cout << "Calling bad loc." << std::endl;
	//std::cout << dat.get(1);
	dat.clear();


  return 0;
}
