#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>

class Dictionary
{
		public:
			Dictionary() = default;
			bool insert(std::string word)
			{
					std::string signature = _get_signature(word);
					_dict[signature].push_back(word);
					return true;
			}
			void pr_anargam()
			{
					for (auto items : _dict)
					{
							std::cout << items.first << (items.second.size() > 1 ? "(anagram)" : "") << ": ";
							for (auto &each : items.second)
									std::cout << each << " ";
							std::cout << "\n";
					}
			}
		private:
			std::map<std::string, std::vector<std::string>> _dict;
			std::string _get_signature(std::string word)
			{
					std::size_t word_size = word.size();
					char* temp_word = (char *)std::malloc(sizeof(char) * (word_size + 1));
					// copy
					temp_word[word_size] = '\0';
					for (std::size_t index = 0; index < word_size; ++index)
							temp_word[index] = word[index];
					// quicksort
					qsort(temp_word, 0, word_size - 1);
					std::string ret_str = std::string(temp_word);
					free(temp_word);
					return ret_str;
			}

			// quicksort
			void qsort(char* start_ptr, std::size_t first_index, std::size_t last_index)
			{
					char temp_char, pivot = start_ptr[last_index];
					std::size_t original_last_index = last_index;
					std::size_t original_first_index = first_index;

					while (first_index < last_index)
					{
							while (start_ptr[first_index] < pivot)
									++first_index;
							while (start_ptr[last_index] > pivot and last_index > first_index)
									--last_index;

							if (first_index != last_index)
							{
									temp_char = start_ptr[first_index];
									start_ptr[first_index] = start_ptr[last_index];
									start_ptr[last_index] = temp_char;
									++first_index;
							}
					}

					if (original_first_index < first_index - 1)
							qsort(start_ptr, original_first_index, first_index - 1);
					if (first_index < original_last_index)
							qsort(start_ptr, first_index, original_last_index);
			}
};


int main()
{
		Dictionary d;
		d.insert("good");
		d.insert("oodg");
		d.insert("dgoo");
		d.insert("axxx");
		d.insert("hello");
		d.insert("oehll");
		d.insert("5345341");
		d.insert("5543143");
		d.pr_anargam();
		return 0;
}
