#include<iostream>
#include<fstream>
#include<array>
#include<vector>
#include<algorithm>

struct student {
	std::string name, lastname;
	std::array<int,4> points;
	int total;
	friend std::istream& operator>>(std::istream& is, student& s);
	friend std::ostream& operator<<(std::ostream& os,const student& s);
};

std::istream& operator>>(std::istream& is, student& s) {
	return is >> s.name >> s.lastname >> s.points[0]>>s.points[1]>> s.points[2] >> s.points[3];
}
std::ostream& operator<<(std::ostream& os, const student& s) {
	return os<<s.name[0]<<". "<<s.lastname<<" "<< s.points[0] + s.points[1] + s.points[2] + s.points[3];
}
bool invalid(const student& s) {
	return s.points[0]<0 && s.points[1]<0 && + s.points[2]<0 && + s.points[3]<0;
}


int main(int argc, char* argv[]){
	
	std::fstream f("oop.txt");
	std::vector<student> v;
	std::istream_iterator<student> is(f), eof;
	std::copy(is, eof, back_inserter(v));
	v.erase(remove_if(begin(v), end(v), invalid), v.end());
	
	//std::sort(v.begin(), v.end(),)
	std::copy(begin(v), end(v), std::ostream_iterator<student>(std::cout, "\n"));

}