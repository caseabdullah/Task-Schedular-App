#include "String.h"
#include <iostream>
using namespace std;

int String::getUserStringLength(const char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

void String::resize(int newCap)
{
	char* temp = new char[newCap];
	if (data != nullptr && data[0] != '\0') {
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
	}
	if (data != nullptr)
	{
		delete[] data;
	}
	size = newCap;
	data = temp;
}

void String::shrink()
{
	if (isEmpty())
	{
		return;
	}
	char* temp = new char[getLength() + 1];
	int i = 0;
	while (i < size - 1)
	{
		temp[i] = data[i];
		i++;
	}
	temp[i] = '\0';
	size = getLength() + 1;
	delete[]data;
	data = temp;
}

String::String()
{
	data = nullptr;
	size = 0;
}

String::String(const char c) :String()
{
	if ((c >= '0' && c <= '9') || c == '\0') {
		return;
	}
	data = new char[2];
	data[0] = c;
	data[1] = '\0';
	size = 2;
	return;
}

String::String(const char* str) : String()
{
	size = getUserStringLength(str) + 1;
	data = new char[size];

	for (int i = 0; i < size; i++)//inclded th '\0'
	{
		data[i] = str[i];
	}
	return;
}

String::String(const String& str) :String()
{
	if (str.data == nullptr) {
		return;
	}
	data = new char[str.size];
	size = str.size;
	for (int i = 0; i < size; i++)//inclded th '\0'
	{
		data[i] = str.data[i];
	}
}

String::~String()
{
	if (data != nullptr)
	{
		delete[]data;
		data = nullptr;
		size = 0;
	}
}

void String::input()
{
	char ch;
	int i = 0;
	if (isEmpty()) {
		resize(1);
	}
	while (cin.get(ch) && ch != '\n') {
		data[i] = ch;
		if ((i + 1) == size) {
			resize(size * 2);
		}
		i++;
	}
	data[i] = '\0';
}

char& String::at(const int index)//'\0' index included
{
	if (index < 0 || index >= size) {
		cout << "Wrong" << endl;
		exit(0);
	}
	return data[index];
}

const char& String::at(const int index) const
{
	if (index < 0 || index >= size) {
		cout << "Wrong" << endl;
		exit(0);
	}
	return data[index];
}

void String::display() const
{
	if (data == nullptr)
	{
		cout << "nothing";
		return;
	}
	cout << data << endl;
}

bool String::isEmpty() const
{
	if (data == nullptr || data[0] == '\0')
	{
		return true;
	}
	return false;
}

int String::getLength() const
{
	if (data == nullptr || data[0] == '\0') {
		return 0;
	}
	int len = 0;
	for (int i = 0; i < size - 1; i++)//even if ther this null temrinator in between it will ignore
	{
		if (data[i] != '\0') {
			len++;
		}
	}
	return len;
}

int String::getSize() const
{
	if (data == nullptr) {
		return 0;
	}
	int i = 0;
	while (data[i] != '\0') {
		i++;
	}
	i++;
	return i;
}

int String::find(const String& substr, const int start) const
{
	if (substr.data == nullptr || substr.data[0] == '\0' || this->data == nullptr || this->data[0] == '\0' || substr.size > this->size || start < 0) {
		return -1;
	}
	for (int i = start; i < size - 1; i++)
	{
		int index = 0;
		if (substr.data[index] == data[i]) {
			index++;
			for (int j = i + 1; j < size - 1 && index < substr.size - 1; j++)
			{
				if (substr.data[index] == data[j])
				{
					index++;
				}
				else {
					j = size;
				}
			}
			if (index == substr.size - 1)
			{
				return i;
			}
		}
	}

	return -1;
}

void String::insert(const int index, const String& subStr)
{
	if (subStr.data == nullptr || index < 0) {
		return;
	}
	if (isEmpty()) {//if the des is nullptr
		if (index != 0) {
			return;
		}
	}
	else if (index > size - 1)
	{
		return;
	}

	char* temp = new char[size + subStr.size - 1];
	int i = 0;
	while (i < index)
	{
		temp[i] = data[i];
		i++;
	}
	int x = i;
	for (int j = 0; j < subStr.size - 1; j++, i++)
	{
		temp[i] = subStr.data[j];
	}
	while (x < size - 1)
	{
		temp[i] = data[x];
		i++;
		x++;
	}
	temp[i] = '\0';
	delete[]data;
	size = size + subStr.size - 1;
	data = temp;
	return;
}

void String::remove(const int index, const int count) {
	if (index < 0 || index >= size - 1 || count <= 0)
	{
		return;
	}
	if (count > (size - index))
	{
		return;
	}
	if (index == 0 && count == size)
	{
		delete[]data;
		size = 0;
		data = nullptr;
	}
	char* temp = new char[size - count];
	int i = 0;
	while (i < index) {
		temp[i] = data[i];
		i++;
	}
	int x = index + count;
	while (x < size - 1)
	{
		temp[i] = data[x];
		i++;
		x++;
	}
	temp[i] = '\0';
	size = size - count;
	delete[]data;
	data = temp;
	return;
}

int String::replace(const String& old, const String& newSubStr) {
	if (isEmpty() || old.isEmpty() || newSubStr.isEmpty())
	{
		exit(0);
	}
	int count = 0;
	int start = 0;
	while (true)
	{
		int index = find(old, start);
		if (index == -1)
		{
			return count;
		}
		count++;
		remove(index, old.size - 1);
		insert(index, newSubStr);
		start += newSubStr.size - 1;
	}
}

void String::trimLeft()
{
	if (isEmpty())
	{
		return;
	}
	int  i = 0;
	int count = 0;
	while (i < size - 1 && data[i] == ' ')
	{
		count++;
		i++;
	}
	remove(0, count);
}

void String::trimRight()
{
	if (isEmpty())
	{
		return;
	}
	int i = size - 2;
	int count = 0;
	while (i >= 0 && data[i] == ' ')
	{
		count++;
		i--;
	}
	remove(i + 1, count);
}

void String::trim()
{
	if (isEmpty())
	{
		return;
	}
	trimLeft();
	trimRight();
}

void String::makeUpper()
{
	if (isEmpty())
	{
		return;
	}
	for (int i = 0; i < size - 1; i++)
	{
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			data[i] = data[i] - 32;
		}
	}
	return;
}

void String::makeLower()
{
	if (isEmpty())
	{
		return;
	}
	for (int i = 0; i < size - 1; i++)
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			data[i] = data[i] + 32;
		}
	}
	return;
}

void String::reverse()
{
	if (isEmpty())
	{
		return;
	}
	char* temp = new char[size];
	temp[size - 1] = '\0';
	int x = size - 2, i = 0;
	while (i < size - 1)
	{
		temp[i] = data[x];
		x--;
		i++;
	}
	delete[]data;
	data = temp;
}

int String::compare(const String& s2) const
{
	if (isEmpty() && s2.isEmpty())
	{
		return 0;
	}
	if (isEmpty())
	{
		return -1;
	}
	if (s2.isEmpty())
	{
		return 1;
	}
	for (int i = 0; i < (size < s2.size ? size - 1 : s2.size - 1); i++)
	{
		if (data[i] < s2.data[i])
		{
			return -1;
		}
		else if (data[i] > s2.data[i])
		{
			return 1;
		}
	}
	return 0;
}

String String::left(const int count)
{
	int nonCount = count;
	if (isEmpty() || count == 0) {
		String empty;
		return empty;
	}
	if (count > getLength())
	{
		nonCount = getLength();
	}
	char* temp = new char[nonCount + 1];
	int i = 0;
	while (i < nonCount)
	{
		temp[i] = data[i];
		i++;
	}
	temp[i] = '\0';
	String left{ temp };
	return left;
}

String String::right(const int count)
{
	int nonCount = count;
	if (isEmpty() || count == 0) {
		String empty;
		return empty;
	}
	if (count > getLength())
	{
		nonCount = getLength();
	}
	char* temp = new char[count + 1];
	int i = getLength() - nonCount;
	int x = 0;
	while (x < nonCount)
	{
		temp[x] = data[i];
		i++;
		x++;
	}
	temp[x] = '\0';
	String right{ temp };
	return right;
}

long long int String::convertToInteger() const
{
	for (int i = 0; i < size - 1; i++)
	{
		if (data[i] < '0' || data[i]>'9' || data == nullptr)
		{
			return 0;
		}
	}
	int num = 0;
	for (int i = 0; i < size - 1; i++)
	{
		num = (num * 10) + (data[i] - '0');
	}
	return num;
}

String String::concatenate(const String& s2) const
{
	if (data == nullptr && s2.data == nullptr)
	{
		String empty;
		return empty;
	}
	if (isEmpty())
	{
		return s2;
	}
	if (s2.isEmpty())
	{
		String concat{ *this };
		return concat;
	}
	char* temp = new char[(size - 1) + s2.size];
	int i = 0;
	while (i < size - 1)
	{
		temp[i] = data[i];
		i++;
	}
	int x = 0;
	while (x < s2.size - 1)
	{
		temp[i] = s2.data[x];
		i++;
		x++;
	}
	temp[i] = '\0';
	String concat;
	concat.data = temp;
	concat.size = (size - 1) + s2.size;
	return concat;
}

void String::concatEqual(const String& s2)
{
	if (s2.isEmpty())
	{
		return;
	}
	if (data == nullptr)
	{
		data = new char[s2.size];
		for (int i = 0; i < s2.size; i++)
		{
			data[i] = s2.data[i];
		}
		size = s2.size;
		return;
	}
	int oldSize = size;
	resize((size - 1) + s2.size);
	for (int i = oldSize - 1, x = 0; x < s2.size; i++, x++)
	{
		data[i] = s2.data[x];
	}
	return;
}

void String::setNumber(const long long int num)
{
	if (data != nullptr)
	{
		delete[]data;
		size = 0;
	}
	int count = 0;
	bool negative = false;
	if (num < 0)
	{
		negative = true;
	}
	long long int temp = negative ? (-1 * num) : num;
	long long int temp2 = negative ? (-1 * num) : num;
	if (num == 0)
	{
		count++;
	}
	else {
		while (temp != 0)
		{
			temp /= 10;
			count++;
		}
		if (negative)
		{
			count++;
		}
	}
	data = new char[count + 1];
	int i = count - 1;
	char c;
	while (i >= (negative ? 1 : 0)) {
		c = (temp2 % 10) + '0';
		data[i] = c;
		temp2 /= 10;
		i--;
	}
	if (negative)
	{
		data[0] = '-';
	}
	data[count] = '\0';
	return;
}

float String::convertToFloat() const
{
	if (data == nullptr)
	{
		return 0.0;
	}
	bool isDecimal = false;
	bool isNeagtive = false;
	if (data[0] == '-')
	{
		isNeagtive = true;
	}
	for (int i = isNeagtive ? 1 : 0; i < size - 1; i++)
	{
		if (data[i] == '.')
		{
			if (!isDecimal)
			{
				isDecimal = true;
			}
			else {
				return  0.0;
			}
		}
		else if ((data[i] < '0' || data[i]>'9'))
		{
			return 0.0;
		}
	}
	int decimalIndex = size - 1;
	float num = 0;
	for (int i = isNeagtive ? 1 : 0; i < size - 1; i++)
	{
		if (data[i] == '.')
		{
			decimalIndex = i;
		}
		else {
			num = (num * 10) + (data[i] - '0');
		}
	}
	float ten = 10;
	if (decimalIndex == size - 1)
	{
		ten = 1;
	}
	for (int i = 1; i < ((size - 1) - decimalIndex - 1); i++)
	{
		ten *= 10;
	}
	num = num / ten;
	if (isNeagtive)
	{
		num *= -1;
	}
	return num;
}

void String::changeString(const String& x)
{
	if (x.data == nullptr)
	{
		this-> ~String();
		return;
	}
	if (data != nullptr)
	{
		delete[]data;
	}
	data = new char[x.size];
	size = x.size;
	for (int i = 0; i < size; i++)
	{
		data[i] = x.data[i];
	}
	return;
}
