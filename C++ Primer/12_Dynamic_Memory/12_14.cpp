#include <memory>
#include <iostream>

struct destination 
{
		int location;
		destination(int loc): location(loc) { }
};

struct connection
{
		destination dest;
		bool isconnected = false;
		connection(int c): dest(c) { }
};

connection connect(destination *dest)
{
		std::cout << "In function connect: " << std::endl;
		std::cout << "Destination: " << dest->location << std::endl;
		connection new_connection(dest->location);
		new_connection.isconnected = true;
		return new_connection;
}

void disconnect(connection conn)
{
		std::cout << "In function disconnect: " << std::endl;
		std::cout << "connection.dest.location: " << conn.dest.location << " isconnected: " << conn.isconnected << std::endl;
		conn.isconnected = false;
}

void end_connection(connection *p)
{
		disconnect(*p);
}

int main()
{
		destination dest_a(100);
		connection c = connect(&dest_a);
		std::shared_ptr<connection> p(&c, end_connection);
		return 0;
}
