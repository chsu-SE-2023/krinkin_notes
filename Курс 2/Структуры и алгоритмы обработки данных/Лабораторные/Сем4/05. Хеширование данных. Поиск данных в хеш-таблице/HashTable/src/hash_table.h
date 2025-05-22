#pragma once
#include <vector>

#define F_PRESITION 6

class MyHashTable {

private:
	std::vector<std::vector<float>> table;
	static int cls_count;
	static int a;
	static int c;

public:
	MyHashTable(int);
	void add(float, int (*)(float));
	int getClassLenght(int);
	int getColCount();
	int getFillPercent();
	int getLongestClass();
	static int hashA(float);
	static int hashB(float);
	static float round(float, int);
	int search(float, int (*)(float));
	void setA(int);
	void setC(int);
	void toTable(System::Data::DataTable^&);
};