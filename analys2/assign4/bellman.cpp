#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int numVers, numEdges;
struct Edge{
	int tail;
	int head;
	int length;
}
int main(){
	ifstream fp;
	fp.open("data/graph1.txt", ios::in);
	if(!fp){
		cout<<"can't open file !"<<endl;
		return 0;
	}

	string line;
	vector<Edge> edges	

	getline(fp, line);
	istringstream stream(line);
	line>>numVers>>numEdges;
	while(fp.peek()!=EOF){
		Edge temp;
		getline(fp, line);
		istringstream stream(line);
		cout<<line<<endl;
		line>>temp.tail>>temp.head>>temp.length;
	}
	fp.close();
	cout<<edges.size()<<endl;
}
