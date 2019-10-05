#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>

#define DIST 1

using namespace std;

int main(int argc, char* argv[]){
	//string filename = "out58.bin";
	string nameFile = "xxm58Name.bin";
	string distFile = "xxm58Dist.bin";

	//fstream s(filename.c_str(), s.binary | s.in);
	fstream out1(nameFile.c_str(), out1.binary | out1.in);
	fstream out2(distFile.c_str(), out2.binary | out2.in);
	
	if(!out1.is_open()){
		cerr << "fail to open " << nameFile << endl;
		return 1;
	}
	if(!out2.is_open()){
		cerr << "fail to open " << distFile << endl;
		return 1;
	}

	double d;
	char * name = new char[20];

	int lineSize = 1;
	int lineIndex = 0;
	int readNum = 0;

	out1.read(reinterpret_cast<char*>(name), 20 * sizeof(char));
	for(int i = 0; i < 20; i++){
		if(name[i] < 32) break;//invalid ASCII
		cout << name[i];
	}

	//while(!s.eof()){
	while(1){
		out2.read(reinterpret_cast<char*>(&d), sizeof d);
		if(out2.eof()) break;
		
		readNum++;
		if(d < 1.0){
			if(lineIndex < lineSize){
				cout << '\t' << d;
				lineIndex++;
			}
			else{
				cout << endl;
				out1.read(reinterpret_cast<char*>(name), 20 * sizeof(char));
				for(int i = 0; i < 20; i++){
					if(name[i] < 32) break;//invalid ASCII
					cout << name[i];
				}
				cout << '\t' << d;
				lineIndex = 1;
				lineSize++;
			}
		}

		else{//d >= 1
			for(int j = 0; j < d / 1; j++){
				if(lineIndex < lineSize){
					//cout << DIST << '\t';
					cout << '\t' << DIST;
					lineIndex++;
				}
				else{
					cout << endl;
					out1.read(reinterpret_cast<char*>(name), 20 * sizeof(char));
					for(int i = 0; i < 20; i++){
						if(name[i] < 32) break;//invalid ASCII
						cout << name[i];
					}
					//cout << DIST << '\t';
					cout << '\t' << DIST;

					lineIndex = 1;
					lineSize++;
				}
			}
		} 
			
	}
	cerr << "the readNum is: " << readNum << endl;
	

	delete name;
	out1.close();
	out2.close();

	return 0;
}

		

