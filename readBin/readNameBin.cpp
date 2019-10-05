#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){
	string fileName = "xxm58Name.bin";

	fstream s(fileName.c_str(), s.binary | s.in);

	if(!s.is_open()){
		cerr << "fail to open " << fileName << endl;
		return 1;
	}

	else{
		char * name = new char[20];
		
		int nameNum = 0;
		//test the pointer moving regulation.
		//s.read(reinterpret_cast<char*>(name), 19 * sizeof(char));
		while(1){
			s.read(reinterpret_cast<char*>(name), 20 * sizeof(char));
			if(s.eof())	break;

		//addbyxxm: answer wrong: duplicate the tail one.
		//while(!s.eof()){
		//	s.read(reinterpret_cast<char*>(name), 20 * sizeof(char));
		//	//if(s.eof())	break;

			for(int i = 0; i < 20; i++){
				if(name[i] < 32) break;
				cout << name[i];
			}
			cout << endl;

			nameNum++;

		}
		cerr << "nameNum is: " << nameNum << endl;
	}
	
	return 0;
}
