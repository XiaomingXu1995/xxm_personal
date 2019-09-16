#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

vector < vector<int> > rowFArray, volFArray, blockFArray; 
vector < int > indexArray;
vector <int> resultArray;



void printFArray(vector < vector<int> > FArray){
	int i, j;
	for(i = 0; i < FArray.size(); i++){
		for(j = 0; j < FArray[i].size(); j++){
			cout << FArray[i][j] << " "; 
		}
		cout << endl;
	}
}

void initResultArray(){
	for(int i = 0; i < 81; i++){
		resultArray.push_back(0); 
	}
}

void initFArray(){
    int i, j, k, l;
    for(i = 0; i < 9; i++){
        vector<int> tmpArray;
        //for(l = 0; l < 9; l++){
        //    tmpArray.push_back(-1);
        //}
        rowFArray.push_back(tmpArray);
        volFArray.push_back(tmpArray);
        blockFArray.push_back(tmpArray);
    }
}
                    
    

bool findIn(vector<int> arr, int num){
    int i = 0;
    while(i < arr.size()){
        if(num == arr[i])
            return true;
        i++;
    }
    return false;
}
void updateFArray(int row, int vol, int num)
{
    int index, block;
    index = row * 9 + vol;
    //get blockId
    if(index / 27 == 0){
        if(index % 9 < 3){
            block = 0;
        }
        else if(index % 9 < 6){
            block = 1;
        }
        else{
            block = 2;
        }
    }
    else if (index / 27 == 1){
        if(index % 9 < 3){
            block = 3;
        }
        else if(index % 9 < 6){
            block = 4;
        }
        else{
            block = 5;
        }
    }
    else{
        if(index % 9 < 3){
            block = 6;
        }
        else if(index % 9 < 6){
            block = 7;
        }
        else{
            block = 8;
        }
    }
    rowFArray[row].push_back(num);
    volFArray[vol].push_back(num);
    blockFArray[block].push_back(num);
    
    
}

bool valid(int index, int num)
{
    int row, vol, block;
    row = index / 9;
    vol = index % 9;
    if(index / 27 == 0){
        if(index % 9 < 3){
            block = 0;
        }
        else if(index % 9 < 6){
            block = 1;
        }
        else{
            block = 2;
        }
    }
    else if (index / 27 == 1){
        if(index % 9 < 3){
            block = 3;
        }
        else if(index % 9 < 6){
            block = 4;
        }
        else{
            block = 5;
        }
    }
    else{
        if(index % 9 < 3){
            block = 6;
        }
        else if(index % 9 < 6){
            block = 7;
        }
        else{
            block = 8;
        }
    }
    //cerr << "row is: " << row << endl;
    //cerr << "vol is: " << vol << endl;
    //cerr << "block is: " << block << endl;
    if(!findIn(rowFArray[row], num) && !findIn(volFArray[vol], num) && !findIn(blockFArray[block], num)){
        return true;
    }
    else{
        return false;
    }
    
}

bool solveSudo(vector<int> &resArray, vector < vector<int> > &rowfArray, vector < vector<int> > &volfArray, vector < vector<int> > &blockfArray, int curIndex, int totalIter)
{
    //bool done = false;
    //int curIndex = 0;
    int row, vol, block;
    if(!findIn(indexArray, curIndex))
    {
        //get row vol block;
{
        row = curIndex / 9;
        vol = curIndex % 9;
        if(curIndex / 27 == 0){
            if(curIndex % 9 < 3){
                block = 0;
            }
            else if(curIndex % 9 < 6){
                block = 1;
            }
            else{
                block = 2;
            }
        }
        else if (curIndex / 27 == 1){
            if(curIndex % 9 < 3){
                block = 3;
            }
            else if(curIndex % 9 < 6){
                block = 4;
            }
            else{
                block = 5;
            }
        }
        else{
            if(curIndex % 9 < 3){
                block = 6;
            }
            else if(curIndex % 9 < 6){
                block = 7;
            }
            else{
                block = 8;
            }
        }
}

		//if(totalIter == 1 || curIndex == 80)
		if(totalIter == 1 || curIndex == 80)
		{
        	for(int i = 1; i <= 9; i++){
        	    if(valid(curIndex, i)){
        	            rowfArray[row].push_back(i);
        	            volfArray[vol].push_back(i);
        	            blockfArray[block].push_back(i);
						resArray[curIndex] = i;
        	            return true;
        	        }
			}
			return false;
		}
		else
		{
			for(int i = 1; i <= 9; i++){
				if(valid(curIndex, i)){
					rowfArray[row].push_back(i);
					volfArray[vol].push_back(i);
					blockfArray[block].push_back(i);
					if(solveSudo(resArray, rowfArray, volfArray, blockfArray, curIndex+1, totalIter-1))
					{
						resArray[curIndex] = i;
						return true;
					}
					else
					{
						rowfArray[row].pop_back();
						volfArray[vol].pop_back();
						blockfArray[block].pop_back();
					}
				}
			}
			return false;
		}
	}

	else //findIn(indexArray, curIndex)
	{
		return solveSudo(resArray, rowfArray, volfArray, blockfArray, curIndex+1, totalIter);
	}
}
		

int main(int argc, char* argv[]){
    initFArray();
	initResultArray();
    int filledNum = 27;
    //int inputArray[filledNum][3] = { {0, 0, 9},
    int inputArray[][3] = 
                                   { {0, 0, 9},
                                     {0, 4, 2},
                                     {0, 6, 4},
                                     {0, 8, 1},
                                     {1, 2, 5},
                                     {1, 4, 9},
                                     {1, 7, 2},
                                     {2, 1, 4},
                                     {2, 3, 1},
                                     {2, 7, 9},
                                     {2, 8, 7},
                                     {3, 0, 5},
                                     {3, 5, 1},
                                     {4, 8, 2},
                                     {5, 0, 4},
                                     {5, 3, 5},
                                     {5, 4, 7},
                                     {5, 6, 3},
                                     {5, 8, 9},
                                     {6, 1, 5},
                                     {6, 2, 3},
                                     {6, 5, 2},
                                     {6, 6, 1},
                                     {6, 7, 8},
                                     {8, 2, 2},
                                     {8, 3, 8},
                                     {8, 8, 3}};

    for(int i = 0; i < filledNum; i++){
        updateFArray(inputArray[i][0], inputArray[i][1],inputArray[i][2]);
        int tmpIndex = inputArray[i][0] * 9 + inputArray[i][1];
        indexArray.push_back(tmpIndex);
		resultArray[tmpIndex] = inputArray[i][2];
    }

//	for(int i = 0; i < indexArray.size(); i++){
//		cout << indexArray[i] << endl;
//	}

	//cout << "start to print resultArray!" << endl;
	//for(int i = 0; i < resultArray.size(); i++){
	//	cout << resultArray[i] << endl;
	//}

	cout << "start to print rowFArray!" << endl;
	printFArray(rowFArray);
	cout << "start to print volFArray!" << endl;
	printFArray(volFArray);
	cout << "start to print blockFArray!" << endl;
	printFArray(blockFArray);

	cout << "start the sloveSudo!" << endl;
	bool result = solveSudo(resultArray, rowFArray, volFArray, blockFArray, 0, 81-27);
	cout << "end the solveSudo!" << endl;
	if(result){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				cout << resultArray[i * 9 + j] << " " ;
			}
			cout << endl;
		}
	}
	else
	{
		cout << "the answer is wrong!" << endl;
	}
        

    //updateFArray(1,2,1);
    //indexArray.push_back(
    //updateFArray(1,3,2);
    //updateFArray(2,3,3);
    
  //  if(valid(0,3))
  //      cout << "the 0,0 is 1 is true;" << endl;
  //  else 
  //      cout << "the 0,0 is 1 is false;" << endl;

  //  if(valid(8,1))
  //      cout << "the 0,8 is 1 is true;" << endl;
  //  else 
  //      cout << "the 0,8 is 1 is false;" << endl;

    


    return 0;
}

    























