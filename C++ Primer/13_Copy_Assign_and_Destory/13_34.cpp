#include <string>
#include <set>

class Folder;

class Message {
		friend class Folder;
		public:
			explicit Message(const std::string &str = ""): contents(str) { }
			Message(const Message&);
			Message& operator=(const Message&);
			~Message();
			void save(Folder&);
			void remove(Folder&);
		private:
			std::string contents;
			std::set<Folder*> folders;

			void add_to_Folders(const Message&);
			void remove_from_Folders();
			// 13_37
			void addFldr(Folder *f) { folders.insert(f); }
			void remFldr(Folder *f) { folders.erase(f); }
};
