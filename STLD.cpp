#include <iostream>
#include <deque>
#include <vector>
using namespace std;


deque<int> function(deque<int> temp, int n){
	int contador=0;
	int posicion;
	deque<int>::iterator it;
	deque<int> ordenado;
	int size=(temp.size()/n);
	vector<deque<int>> deques;
	if (size%2==0){
		deques.resize(size);
	}
	else{
		deques.resize(size+1);
	}
	cout<<"Deque size is "<<deques.size()<<endl;
	for (it=temp.begin(); it!=temp.end();++it){
		posicion=contador/n;
		deques[posicion].push_front(*it);
		contador+=1;
		cout << '\t' << *it;
	}
	cout<<endl;
	
	int min=999;
	for (int i=0;i<deques.size();++i){
		min=9999;
		for(auto j=deques[i].begin();j!=deques[i].end();++j){
			cout<<"evaluating "<<*j<<endl;
			if(*j<min){
				min=*j;
				cout<<min<<endl;
			}
		}
		ordenado.push_front(min);
	}
	return ordenado;
}
int main(){
	deque<int> prueba;
	prueba.push_back(10);
	prueba.push_back(20);
	prueba.push_back(30);
	prueba.push_back(40);
	prueba.push_back(50);
	prueba.push_back(60);
	prueba.push_back(70);
//	prueba.push_back(80);
	deque<int> x= function(prueba,2);
	cout<<"About to print ordered deque"<<endl<<endl;
	for (auto it=x.begin();it!=x.end();++it){
		cout<< '\t' << *it;
	}
	return 0;
}

