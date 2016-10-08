#ifndef DYNARR
#define DYNARR
#include "DynamicArr.h"

DynamicArray::DynamicArray(){
	this->capacity = 0;
	this->num = 0;
	data = 0;
	Log = 0;
}

void DynamicArray::push_back(const char & v){
	if (this->num >= this->capacity)
	{
		char * ndata = new char[1<<Log];

		this->capacity =1<<Log;
		Log++;
		for (int i = 0; i < this->num; i++)
			ndata[i] = data[i];
		delete[] data;
		data = ndata;
	}
	data [this->num++] = v;
}

size_t DynamicArray::size() {
	return this->num;
}

char& DynamicArray::operator[](int index) {
	return data[index];
}

char* DynamicArray::getData(){
	push_back('\0');
	return data;
}

void DynamicArray::clear(){
	delete[] data;
	this->capacity = 0;
	this->num = 0;
	data = 0;
	Log = 0;
}

DynamicArray::~DynamicArray(){
	delete[] data;
	this->capacity = 0;
	this->num = 0;
	data = 0;
	Log = 0;
}

#endif