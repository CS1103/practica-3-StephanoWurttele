#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class matrix{
	public:
	int col,row;
	T elements;
	vector<vector<T>> matriz;
	matrix(int col1, int row1, T el):col(col1),row(row1),elements(el){
    		matriz.resize(row);
    		for (int i=0; i<matriz.size(); i++){
			matriz[i].resize(col, elements);
			cout<<"construyendo por i vez "<<matriz[i][0]<<endl;
	    	}
		cout<<endl;
	}
	matrix(int col1, int row1):col(col1),row(row1){
    		matriz.resize(row);
    		for (int i=0; i<matriz.size(); i++){
			matriz[i].resize(col,0);
	    	}
	}

	matrix():row(0),col(0){
    		matriz.resize(row);
    		for (int i=0; i<matriz.size(); i++){
			matriz[i].resize(col,0);
	    	}
	}
	void define(int col, int row,T value){
		matriz[row][col]=value;
	}


	matrix operator+(matrix<T> other){
		matrix temp(other.col,other.row);
		for (int i=0; i<matriz.size(); i++){
			for (int j=0; j<matriz[0].size(); j++){
				temp.matriz[i][j]=matriz[i][j]+other.matriz[i][j];
				cout<<"sumando "<<matriz[i][j]<<" con "<<other.matriz[i][j]<<" en "<< temp.matriz[i][j]<<"    ";
			}
			cout<<endl;
		}
		return temp;
	}
};

int main(){
	matrix<float> a(5,5,2.3);
	matrix<float> b(5,5,2.5);
	a.define(0,0,10);
	matrix<float> c(5,5);
	c=a+b;
	for (int i=0;i<c.row;i++){
		for (int j=0;j<c.col;j++){
			cout<<a.matriz[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	for (int i=0;i<c.row;i++){
		for (int j=0;j<c.col;j++){
			cout<<b.matriz[i][j]<<"  ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	for (int i=0;i<c.row;i++){
		for (int j=0;j<c.col;j++){
			cout<<c.matriz[i][j]<<"   ";
		}
		cout<<endl;
	}
	return 0;
}
