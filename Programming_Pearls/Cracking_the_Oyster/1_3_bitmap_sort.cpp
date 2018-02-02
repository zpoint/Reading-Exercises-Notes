#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <bitset>

class RandomToFile
{
		public:
			RandomToFile(std::size_t n) 
			{
					std::size_t index = 1;
					std::random_device rd;
					std::mt19937 g(rd());

					while (index <= n)
							ivec.push_back(index++);
					std::shuffle(ivec.begin(), ivec.end(), g);
			}
			bool to_file(std::string filename)
			{
					std::ofstream ofs(filename);
					if (!ofs.good())
							return false;
					for (const auto i : ivec)
							ofs << i << "\n";
					return true;
			}
		private:
			std::vector<int> ivec;
};

class NormalSort
{
		public:
			NormalSort(std::string filename_in, std::string filename_out)
			{
					auto start = std::chrono::high_resolution_clock::now();
					std::cout << "Begin Normal Sort" << std::endl; 

					std::ifstream ifs(filename_in);
					std::vector<int> ivec;
					int i;
					while (ifs >> i)
					{
							ivec.push_back(i);
					}
					std::sort(ivec.begin(), ivec.end());
					ifs.close();

					std::ofstream ofs(filename_out);
					for (const auto &i : ivec)
							ofs << i << "\n";
					auto elapsed = std::chrono::high_resolution_clock::now() - start;
					long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
					std::cout << "Normal Sort Done, cost: " << microseconds / 1000000.0 << " seconds" << std::endl;
			}
};

class BitMapSort
{
		public:
			BitMapSort(std::string filename_in, std::string filename_out)
			{
					auto start = std::chrono::high_resolution_clock::now();
					std::cout << "Begin BitMapSort" << std::endl;
					std::bitset<50000001> bs;
					int value;
					std::ifstream ifs(filename_in);
					while (ifs >> value)
					{
							bs.set(value);
					}
					ifs.close();

					std::ofstream ofs(filename_out);
					value = 1;
					for (std::size_t i = 0; i <= 50000000; ++i)
					{
							if (bs[i])
									ofs << value << "\n";
							++value;
					}
					auto elapsed = std::chrono::high_resolution_clock::now() - start;
					long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
					std::cout << "Bitmap Sort Done, cost: " << microseconds / 1000000.0 << " seconds" << std::endl;

			}
};

int main()
{
		RandomToFile r(50000000);
		r.to_file("test.txt");
		NormalSort n("test.txt", "test2.txt");
		BitMapSort("test.txt", "test2.txt");
		return 0;
}
