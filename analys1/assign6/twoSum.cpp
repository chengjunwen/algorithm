#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
//#include <ext/hash_map>
using namespace std;
//using namespace __gnu_cxx;

#define N 10000;
//struct nodeT{
//	int val;
//	nodeT * next;
//};

int main(){
	fstream f;
//	f.open("./test.txt");
	f.open("./algo1-programming_prob-2sum.txt");
	if(!f){
		cout<<"can't open the file !"<<endl;
		return 0;
	}
	map<long long,int> rec;
	map<long long,int>::iterator it1,it2;
	long long count=0;
	int j=0;
	while(!f.eof()){
		string line;
		getline(f,line);
		long long data;
		istringstream stream(line);
		stream>>data;
		if(rec.find(data)==rec.end())
			rec[data]=j++;
		
	}//while
	f.close();
	if(rec.find(-60012933873)!=rec.end()) cout<<"find it"<<endl;
	for(long long i=-10000;i<=10000;i++){
		for(it1=rec.begin();it1!=rec.end();it1++){
			long long b=i-it1->first;	
			it2=rec.find(b);
			if(it2!=rec.end()&&it2!=it1){
			//	cout<<i<<endl;
				count++;
				break;
			}
		}
	}
	cout<<count<<endl;
}
