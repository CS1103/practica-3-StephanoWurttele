#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>


using namespace std;
class Seccion{
	public:
	map<string,string> students;
	Seccion(){};
	void add(string name,string age){
		students.insert(pair<string,string>(name,age));
		auto it = students.find(name);
	}
	void borrar(string name){
		students.erase(name);
	}
	void list(string opcion){
		int a=0;
		if (opcion=="All"){
			cout<<"All"<<endl;
			for (auto i=students.begin();i!=students.end();++i){
				cout<<i->first<<" , "<<i->second;
				cout<<endl;
			}
		}
		else{
			auto it = students.find(opcion);
			if (it != students.end()){
				cout<<it->first<<" , "<<it->second<<endl;
			}
		}
	}
};

int main(){
	Seccion A;
	ifstream readfile;
	readfile.open("text.txt");
	string instruction;
	string temp;
	string value;
	string key;
	int x;
	int counter;
	while(getline(readfile,temp)){
		counter++;
	}
	readfile.close();
	readfile.open("text.txt");
	if(readfile.is_open()){
		while(x<counter){
			readfile>>instruction;
			if (instruction=="C"){
				readfile>>value;
				readfile>>key;
				A.add(value,key);
			}
			else{
				if(instruction=="L"){
					readfile>>value;
					A.list(value);
					cout<<endl;
				}
				else{
					readfile>>value;
					A.borrar(value);
				}
			}
			x++;
		}
	}
	return 0;
}
