#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>

#define DIST 1

using namespace std;

int main(int argc, char* argv[]){
	string filename = "out58.bin";

	if(argc >= 2){
		filename = argv[1];
	}

	fstream s(filename.c_str(), s.binary | s.in);

//	cout << "s.in.tellg is: " << s.tellg() << endl;
//	cout << "s.gcount is: " << s.gcount() << endl;

	//exit(0);
	if(!s.is_open()){
		cerr << "fail to open " << filename << endl;
	}
	else{
		double d;
		int lineSize = 1;
		int lineIndex = 0;
		int readNum = 0;
		//while(!s.eof()){
		while(1){
			s.read(reinterpret_cast<char*>(&d), sizeof d);
			if(s.eof()) break;
		//	cout << d << endl;
			
			readNum++;
			if(d < 1.0){
				if(lineIndex < lineSize){
					cout << d << '\t';
					lineIndex++;
				}
				else{
					cout << endl;
					cout << d << '\t';
					lineIndex = 1;
					lineSize++;
				}
			}

			else{//d >= 1
				for(int i = 0; i < d / 1; i++){
					if(lineIndex < lineSize){
						cout << DIST << '\t';
						lineIndex++;
					}
					else{
						cout << endl;
						cout << DIST << '\t';
						lineIndex = 1;
						lineSize++;
					}
				}
			}
				
				
		}
		cerr << "the readNum is: " << readNum << endl;
	}
	

	s.close();

	return 0;
}

		

