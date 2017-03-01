#include "13_34.cpp"

class Folder {
		friend class Message;
		public:
			Folder() {};
			Folder& operator=(const Folder &);
			~Folder();
		private:
			std::set<Message*> msgs;
			void add_to_Message(const Folder&);
			void remove_from_Message();

			void addMsg(Message *m) { msgs.insert(m); }
			void remMsg(Message *m) { msgs.erase(m); }
};

Message::Message(const Message& msg): contents(msg.contents), folders(msg.folders){ add_to_Folders(msg); }

Message& Message::operator=(const Message &msg)
{
		this->remove_from_Folders();
		contents = msg.contents;
		folders = msg.folders;
		this->add_to_Folders(msg);
		return *this;
}

Message::~Message()
{
		remove_from_Folders();
}

void Message::save(Folder& f)
{
		f.addMsg(this);
		folders.insert(&f);
}

void Message::remove(Folder& f)
{
		f.remMsg(this);
		folders.erase(&f);
}

void Message::add_to_Folders(const Message& msg)
{
		for (auto f: msg.folders)
				f->addMsg(this);
}

void Message::remove_from_Folders()
{
		for (auto f : this->folders)
				f->remMsg(this);
}

Folder::Folder(const Folder& f): msgs(f.msgs) { add_to_Folders(f); }

Folder& Folder::operator=(const Folder& f)
{
		this->remove_from_Message();
		msgs = f.msgs;
		this->add_to_Message(f);
		return *this;
}

Folder::~Folder() { remove_from_Message(); }

void Folder::add_to_Message(const Folder& f)
{
		for (auto i : f.msgs)
				i->addFldr(this);
}

void Folder::remove_from_Message()
{
		for (auto i : this->msgs)
				i->remFldr(this);
}
