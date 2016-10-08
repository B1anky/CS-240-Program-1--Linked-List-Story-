#include <stdlib.h>
class  DynamicArray {
	public:
	DynamicArray();
	void push_back(const char & v);
	size_t size();
	char& operator[](int index);
	char* getData();
	void clear();
	~DynamicArray();

	private:
		int num;
		int capacity;
		char* data;
		int Log;
};