#pragma once
#include <vector>
#include <string>

#define F_PRESITION 6
#define MODE_INT "int"
#define MODE_SUM "sum"

class MyHashTable {

private:
	std::vector<std::vector<float>> table;
	static int cls_count;
	static int a;
	static int c;

public:
	MyHashTable(int);
	void add(float, int (*)(float, std::string), std::string);
	int getClassLenght(int);
	int getColCount();
	float getFillPercent();
	int getLongestClass();
	static int hashA(float, std::string);
	static int hashB(float, std::string);
	static float round(float, int);
	int search(float, int (*)(float, std::string), std::string);
	void setA(int);
	void setC(int);
	void toTable(System::Data::DataTable^&);
};