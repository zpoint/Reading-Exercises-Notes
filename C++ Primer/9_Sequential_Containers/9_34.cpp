#include <vector>

int main()
{
		// will loop forever, everytime after ++iter, iter stay in the position enter the while loop
		std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		std::vector<int>::iterator iter = ivec.begin();
		while (iter != ivec.end())
		{
				if (*iter % 2)
						iter = ivec.insert(iter, *iter);
				++iter;
		}
		return 0;
}

