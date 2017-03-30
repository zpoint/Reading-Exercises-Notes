
template <typename elemType> class ListItem;
template <typename elemType> class List
{
		public:
			List<elemType>() = default;
			List<elemType>(const List<elemType> &);
			List<elemType>& operator=(const List<elemType> &);
			~List() = default;
			void insert(ListItem<elemType> *ptr, elemType value); // ListItem is a template
		private:
			ListItem<elemType> *front, *end;
};

int main()
{
		List<int> il;
		return 0;
}
