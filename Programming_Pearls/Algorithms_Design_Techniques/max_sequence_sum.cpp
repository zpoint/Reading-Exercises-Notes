#include <iostream>
#include <cstdlib>
#include <vector>

inline int max(int i, int j)
{
		return i > j ? i : j;
}

inline int max(int i, int j, int k)
{
		if (i > j)
				return max(i, k);
		else
				return max(j, k);
}

class Solutions
{
		public:
			int Algorithms1(int *, std::size_t);
			int Algorithms2(int *, std::size_t);
			int Algorithms3(int *, std::size_t);
			int Algorithms4(int *, std::size_t);
			int Algorithms5(int *, std::size_t);
			int split_algorithm(int *, std::size_t, std::size_t);
			void test(int *, std::size_t);
};

int Solutions::Algorithms1(int *arr, std::size_t sz)
{
		std::size_t i = 0, j = 0;
		int max_val = 0;
		for (; i < sz; ++i)
		{
				for (j = i; j < sz; ++j)
				{
						int curr_max = 0;
						for (std::size_t k = i; k <= j; ++k)
							curr_max += arr[k];
						max_val = max(max_val, curr_max);
				}
		}
		return max_val;
}

int Solutions::Algorithms2(int *arr, std::size_t sz)
{
		std::size_t i = 0, j = 0;
		int max_val = 0;
		for (; i <= sz; ++i)
		{
				int curr_max = 0;
				for (j = i; j < sz; ++j)
				{
						curr_max += arr[j];
						max_val = max(max_val, curr_max);
				}
		}
		return max_val;
}

int Solutions::Algorithms3(int *arr, std::size_t sz)
{
		int max_val = 0;
		int *sum_arr = (int *)malloc(sizeof(int) * (sz + 1));
		sum_arr[0] = 0;
		for (std::size_t i = 1; i < sz + 1; ++i)
				sum_arr[i] = sum_arr[i - 1] + arr[i - 1];
		for (std::size_t i = 0; i < sz; ++i)
		{
				for (std::size_t j = i; j < sz; ++j)
						max_val = max(sum_arr[j + 1] - sum_arr[i], max_val);
		}
		free(sum_arr);
		return max_val;
}

int Solutions::Algorithms4(int *arr, std::size_t sz)
{
		return split_algorithm(arr, 0, sz - 1);
}

int Solutions::split_algorithm(int *arr, std::size_t l, std::size_t r)
{
		if (l > r)
				return 0;
		else if (l == r)
				return arr[l];

		std::size_t m = (l + r) / 2;
		int max_l = 0, sum_l = 0, max_r = 0, sum_r = 0;
		for (int i = m; i >= 0; --i)
		{
				sum_l += arr[i];
				max_l = max(max_l, sum_l);
		}
		for (int i = m + 1; i <= (int)r; ++i)
		{
				sum_r += arr[i];
				max_r = max(max_r, sum_r);
		}
		return max(max_l + max_r, split_algorithm(arr, 0, m), split_algorithm(arr, m + 1, r)); 

}

int Solutions::Algorithms5(int *arr, std::size_t sz)
{
		int max_so_far = 0, max_exending_here = 0;
		for (std::size_t i = 0; i < sz; ++i)
		{
				max_exending_here = max(max_exending_here + arr[i], 0);
				max_so_far = max(max_so_far, max_exending_here);
		}
		return max_so_far;
}

void Solutions::test(int *arr, std::size_t size)
{
		std::vector<int (Solutions::*)(int*, std::size_t)> member_func_vec = {
				&Solutions::Algorithms1, 
				&Solutions::Algorithms2, 
				&Solutions::Algorithms3,
				&Solutions::Algorithms4,
				&Solutions::Algorithms5
		};
		std::size_t index = 0;
		for (int (Solutions::*x)(int *, std::size_t) : member_func_vec)
		{
				std::cout << "Algorithms" << index << ": " << (this->*x)(arr, size) << std::endl;
				std::cout << "going to run 1000000 test\n";
				auto start = std::chrono::high_resolution_clock::now();
				for (std::size_t i = 0; i < 1000000; ++i)
						(this->*x)(arr, size);
				auto elapsed = std::chrono::high_resolution_clock::now() - start;
				long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
				std::cout << "Cost: " << microseconds / 1000000.0 << " seconds" << std::endl;
				index++;
		}


}


int main()
{
		int arr[] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84, 22, 33, 44, 19, 30, 55, -4, -7, 6, -1};
		Solutions s = Solutions();
		s.test(arr, sizeof(arr) / sizeof(int));
}
