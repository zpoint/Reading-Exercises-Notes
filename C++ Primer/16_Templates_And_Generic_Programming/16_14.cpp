
template <unsigned N, unsigned M> class Screen
{
		public:
			Screen(): width(N), height(M) { }
		private:
			unsigned width;
			unsigned height;
};

int main()
{
		Screen<1, 2> s;
		return 0;
}
