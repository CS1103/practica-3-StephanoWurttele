#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Seccion{
	public:
	map<string,string> students;
	Seccion(){};
	void add(string name,string age){
		students.insert(pair<string,string>(name,age));
	}
	void borrar(string name,string age){
		students.erase(name);
	}
};

int main(){
	Seccion A;
	string s="C";
	string s1="Jacinto";
	string s2="10";

	if(s=="C"){
		A.add(s1,s2);
	}
	return 0;
}
