#include "MutantStack.hpp"

int	main()
{
	{
		MutantStack<int>	mstack;

		std::cout << "Push 0 to mutantstack" << std::endl;
		std::cout << "Push 1 to mutantstack" << std::endl;
		std::cout << "Push 2 to mutantstack" << std::endl;
		std::cout << "Push 3 to mutantstack" << std::endl;
		std::cout << "Push 4 to mutantstack" << std::endl;
		std::cout << "Push 5 to mutantstack" << std::endl;
		mstack.push(0);
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);
		std::cout << std::endl;

		std::cout << "Iterate to MutantStack using iterators: "<< std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		for (; it != ite; it++) {
			std::cout << *it << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Main test with MutantStack:" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	std::cout << "Main test with std::list:" << std::endl;
	{
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;

		mstack.pop_back();

		std::cout << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return (0);
}
