#include <iostream>
#include <fstream>
using namespace std;
void Result(int map[][9]){
	for(int x=0;x<9;x++){
		for(int y=0;y<9;y++){
			cout << map[x][y] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
bool checkValid(int map[][9], int x, int y, int k){
	for( int i=0; i<9; i++){
		if(map[i][y] == k){
			return false;
		}
	}
	for(int j=0; j<9; j++){
		if(map[x][j] == k){
			return false;
		}
	}
	for(int i=(x/3)*3; i<(x/3+1)*3; i++){
		for(int j=(y/3)*3; j<(y/3+1)*3;j++){
			if(map[i][j] == k){
				return false;
			}
		}
	}
	return true;	
}
void Try(int map[][9], int x, int y){
	if(y==9){
		if(x==8){
			cout << "done: " << "\n";
			Result(map);
			return;
		}
		else{
			Try(map,x+1,0);
		}
	}
	else if(map[x][y] == 0){
		for(int k=1; k<=9; k++){
			if(checkValid(map, x, y, k)){
				map[x][y] = k;
				Try(map,x,y+1);
				map[x][y] =0;
			}
		}
	}
	else{
		Try(map, x, y+1);
	}
}
void Create(int map[][9]){
	fstream file;
	file.open("file.txt", ios::in);
	string s;
	int i=0;
	while(!file.eof()){
		getline(file,s);
		for(int j=0;j<9;j++){
			map[i][j] = s[j] - '0';
		}
		i++;
	}
	file.close();
	
}

int main(){
	//int map[][9]={{0,0,0,0,0,0,0,0,0} ,{0,0,0,0,0,0,0,0,0} ,{9,2,8,6,3,4,1,5,7} ,{2,7,5,3,9,6,4,1,8},{0,0,0,0,0,0,0,0,0} ,{3,4,1,8,5,7,2,6,9} ,{7,1,3,2,4,5,9,8,6},{5,9,6,1,8,3,7,2,4},{4,8,2,7,6,9,5,3,1}};
	//int map[][9]={{0,0,3,0,2,0,6,0,0} ,{9,0,0,3,0,5,0,0,1} ,{0,0,1,8,0,6,4,0,0} ,{0,0,8,1,0,2,9,0,0},{7,0,0,0,0,0,0,0,8} ,{0,0,6,7,0,8,2,0,0} ,{0,0,2,6,0,9,5,0,0},{8,0,0,2,0,3,0,0,9},{0,0,5,0,1,0,3,0,0}};
	cout << "start:" << "\n";
	int map[9][9];
	Create(map);
	Result(map);
	Try(map,0,0);	
}
