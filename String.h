#ifndef STRING_H
#define STRING_H

class String
{
	char* data;
	int size;
	int getUserStringLength(const char*);//for string string user enter
public:
	String();
	String(const char);
	String(const char*);
	String(const String&);
	~String();
	void input();
	char& at(const int);
	const char& at(const int) const;
	void display() const;
	bool isEmpty() const;
	int getLength() const;
	int getSize() const;
	int find(const String&, const int = 0) const;
	void insert(const int, const String&);
	void remove(const int, const int = 1);
	int replace(const String&, const String&);
	void trimLeft();
	void trimRight();
	void trim();
	void makeUpper();
	void makeLower();
	void reverse();
	void resize(int newCap);
	void shrink();
	int compare(const String&) const;
	String left(const int);
	String right(const int);
	long long int convertToInteger() const;
	String concatenate(const String& s2) const;
	void concatEqual(const String& s2);
	void setNumber(const long long int num);
	float convertToFloat() const;
	void changeString(const String&);
};

#endif

