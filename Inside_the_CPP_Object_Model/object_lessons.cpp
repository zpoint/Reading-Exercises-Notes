#include <iostream>

class Point3d
{
		public:
			Point3d(float x = 0.0, float y = 0.0, float z = 0.0): _x(x), _y(y), _z(z) { }

			float x() const { return _x; }
			float y() const { return _y; }
			float z() const { return _z; }

			void x(float xval) { _x = xval; }

		private:
			float _x;
			float _y;
			float _z;
};

inline std::ostream& operator<<(std::ostream &os, const Point3d &pt)
{
		return os << "( " << pt.x() << ","
		          << pt.y() << ", " << pt.z() << " )";
}

int main()
{
		Point3d p3d(1.1, 2.2, 3.3);
		std::cout << p3d << std::endl;
		return 0;
}
