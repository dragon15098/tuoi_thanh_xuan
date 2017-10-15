#include <iostream>
#include <time.h>
#include <windows.h>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;
void print_map(int map[][4]){
	system("cls");
	int size = 6;
	for(int x=0;x<4;x++){
		for(int y=0;y<4;y++){
			if(map[x][y]==-1){
				if(y<3){
					for(int i=0 ;i<size;i++){
						cout << " ";
					}
					cout << "|";
				}
				else{
					for(int i=0 ;i<size;i++){
						cout << " ";
					}
				}
			}
			else{
				if(y<3){
					char s[size];
					itoa(map[x][y],s,10);
					int len=0;
					for(int p=0;p<size;p++){
						if(s[p]!='\0'){
							len++;
						}
						else{
							break;
						}
					}
					if(len%2==0){
						for(int i =0;i<(size-len)/2;i++){
							cout << " ";
						}
						cout << map[x][y];
						for(int i =0;i<(size-len)/2;i++){
							cout << " ";
						}
						cout << "|";
					}
					else{
						for(int i =0;i<(size-len)/2+1;i++){
							cout << " ";
						}
						cout << map[x][y];
						for(int i =0;i<((size-len)/2);i++){
							cout << " ";
						}
						cout << "|";
					}
				}
				else{	
					char s[size];
					itoa(map[x][y],s,10);
					int len=0;
					for(int p=0;p<size;p++){
						if(s[p]!='\0'){
							len++;
						}
						else{
							break;
						}
					}
					if(len%2==0){
						for(int i =0;i<(size-len)/2;i++){
							cout << " ";
						}
						cout << map[x][y];
						for(int i =0;i<(size-len)/2;i++){
							cout << " ";
						}
					}
					else{
						for(int i =0;i<(size-len)/2+1;i++){
							cout << " ";
						}
						cout << map[x][y];
						for(int i =0;i<((size-len)/2);i++){
							cout << " ";
						}
					}
				}
			}
		}
		cout << "\n";
	}
}
void up(int map[][4]){
	for(int j =0; j <4;j++){
		int move=0;
		for(int i=0;i<4;i++){
			if(map[i][j]==-1){
				move++;
			}
			if(map[i][j]!=-1 && move != 0){
				map[i-move][j] = map[i][j];
				map[i][j]=-1;
			}
		}
	}
	for (int j=0; j<4;j++){
		int move = 0;
		for(int i=0;i<3;i++){
			if(map[i][j]==map[i+1][j]){
				if(map[i][j] != -1){
					map[i-move][j] = map[i][j]*2;
					if(move != 0){
						map[i][j] = -1;
						map[i+1][j] = -1;
					} 
					else{
						map[i+1][j] = -1;
					}
					move++;
				}
			}
			else{
				if(i>=1){
					if(map[i-1][j] == -1){
						map[i-1][j] = map[i][j];
						map[i][j] = -1;
					}
				}	
			}
		}		
	}
	for(int j= 0;j<4;j++){
		if(map[3][j]!=-1 && map[2][j]==-1){
			map[2][j]=map[3][j];
			map[3][j]=-1;
		}
	}
}
void down(int map[][4]){
	for(int j=3;j>=0;j--){
		int move=0;
		for(int i=3;i>=0;i--){
			if(map[i][j]==-1){
				move++;
			}
			if(map[i][j]!=-1 && move != 0){
				map[i+move][j] = map[i][j];
				map[i][j]=-1;
			}
		}
	}
	for(int j=0; j<4;j++){
		int move = 0;
		for(int i=3;i>0;i--){
			if(map[i][j]==map[i-1][j]){
				if(map[i][j] != -1){
					map[i+move][j] = map[i][j]*2;
					if(move != 0){
						map[i][j] = -1;
						map[i-1][j] = -1;
					} 
					else{
						map[i-1][j] = -1;
					}
					move++;
				}
			}
			else{
				if(i<3){
					if(map[i+1][j] == -1){
						map[i+1][j] = map[i][j];
						map[i][j] = -1;
					}		
				}
			}
		}		
	}
	for(int j=0;j<4;j++){
		if(map[0][j]!=-1 && map[1][j]==-1){
			map[1][j]=map[0][j];
			map[0][j]=-1;
		}
	}
}
void left(int map[][4]){
	for(int i=0; i<4;i++){
		int move=0;
		for(int j=0;j<4;j++){
			if(map[i][j]==-1){
				move++;
			}
			if(map[i][j]!=-1 && move != 0){
				map[i][j-move] = map[i][j];
				map[i][j]=-1;
			}
		}
	}
	for (int i=0; i<4;i++){
		int move = 0;
		for(int j=0;j<3;j++){
			if(map[i][j]==map[i][j+1]){
				if(map[i][j] != -1){
					map[i][j-move] = map[i][j]*2;
					if(move != 0){
						map[i][j] = -1;
						map[i][j+1] = -1;
					} 
					else{
						map[i][j+1] = -1;
					}
					move++;
				}
			}
			else{
				if(j>0){
					if(map[i][j-1] == -1){
						map[i][j-1] = map[i][j];
						map[i][j] = -1;
					}	
				}
			}
		}		
	}
	for(int i=0;i<4;i++){
		if(map[i][3]!=-1 && map[i][2]==-1){
			map[i][2] = map[i][3];
			map[i][3] = -1;
		}
	}
}
void right(int map[][4]){
	for(int i=0; i<4;i++){
		int move=0;
		for(int j=3;j>=0;j--){
			if(map[i][j]==-1){
				move++;
			}
			if(map[i][j]!=-1 && move != 0){
				map[i][j+move] = map[i][j];
				map[i][j]=-1;
			}
		}
	}
	for (int i=0; i<4;i++){
		int move = 0;
		for(int j=3;j>0;j--){
			if(map[i][j]==map[i][j-1]){
				if(map[i][j] != -1){
					map[i][j+move] = map[i][j]*2;
					if(move != 0){
						map[i][j] = -1;
						map[i][j-1] = -1;
					}
					else{
						map[i][j-1] = -1;
					}
					move++;
				}
			}
			else{
				if(j<3){
					if(map[i][j+1] == -1){
						map[i][j+1] = map[i][j];
						map[i][j] = -1;
					}		
				}
			}
		}		
	}
	for(int i=0;i<4;i++){
		if(map[i][0]!=-1 && map[i][1]==-1){
			map[i][1] = map[i][0];
			map[i][0] = -1;
		}
	}
}
void random(int map[][4]){
	int rand_x, rand_y;
	srand (time(NULL));
  	do{
  		rand_x = rand() % 4;
		rand_y = rand() % 4;
	}while(map[rand_x][rand_y]!=-1);
	int pr = rand() %100;
	if(pr<90){
		map[rand_x][rand_y] = 2;
	}
	else{
		map[rand_x][rand_y] = 4;
	}
}
int max_map(int map[][4]){
	int max=0;
	for(int x=0;x<4;x++){
		for(int y=0;y<4;y++){
			if(max<map[x][y]){
				max = map[x][y];
			}
		}
	}
	return max;
}
int mode(int map[][4], int old_map[][4]){
	int num =0;
	for(int x=0;x<4;x++){
		for(int y=0;y<4;y++){
			if(old_map[x][y] != map[x][y]){
				return 1;
			}
			if(old_map[x][y]!=-1){
				num++;
			}
		}
	}
	if(num==16){
		return 0;	
	}
	return 2;
}
bool full(int map[][4]){
	for(int i=1;i<17;i++){
		int need_check=2*pow(2,i);
		bool have= false;
		for(int y=0;y<4 && !have;y++){
			for(int x=0;x<4;x++){
				if(map[x][y] == need_check){
					have = true;
					break;
				}
			}
		}
		if(!have){
			return false;
		}
	}
	return true;
}
void read_map(int map[][4]){
	fstream file("file.txt");
	if(!file){
		file.close();
		ofstream file("file.txt");
		for(int i=0;i<16;i++){
			file << -1 << " ";
		}
		file.close();
	}
	else{
		for(int i=0;i<16;i++){
			file >> map[i/4][i%4]; 
		}
	}
	for(int i=0;i<16;i++){
		file >> map[i/4][i%4];
	}
	file.close();
}
void new_game(){
	fstream file("file.txt");
	if(!file){
		file.close();
		ofstream file("file.txt");
		for(int i=0;i<16;i++){
			file << -1 << " ";
		}
		file.close();
	}
	else{
		file.clear();
		for (int i=0;i<16;i++){
			file << -1 << " ";
		}
		file.close();
	}
}
void save_game(int map[][4]){
	ofstream file("file.txt");
	file.clear();
	for(int x=0;x<4;x++){
		for(int y=0;y<4;y++){
			file << map[x][y] << " ";
		}
	}
	file.close();
}
void control_game(int map[][4]){	
	int input;
	while(true){
		cout << "nhap huong di: ";
		cin >> input;
		while(input!=2 && input!=4 && input!=8 && input!=6){
			cout << "khong hop le. Nhap lai:";
			cin >> input;
		}
		int old_map[4][4];
		for(int x=0;x<4;x++){
			for(int y=0;y<4;y++){
				old_map[x][y] = map[x][y];
			}
		}	
		switch(input){
			case 8:
				up(map);
				break;
			case 2:
				down(map);
				break;
			case 4:
				left(map);
				break;
			case 6:
				right(map);
				break;
		}
		if(mode(map, old_map) == 1){
			random(map);		
		}
		else if(mode(map, old_map) == 0){
			if(full(map)){
				cout << "WOW!!!";
				break;
			}
			else{
				cout << "Not done. Max number: " << max_map(map);
				break;
			}
		}
		save_game(map);
		print_map(map);
	}
}
void mode_game(){
	int map[4][4];
	int in;
	cout << "1.Choi moi\n";
	cout << "2.Choi tiep\n";
	cout << "3.Thoat\n";
	cout << "Chon chuc nang: ";
	cin >> in;
	while(in!=1 && in!=2 && in!=3){
		cout << "Chon sai chuc nang. Nhap lai: ";
		cin >> in;
	}
	switch(in){
		case 1:
			new_game();
			read_map(map);
			print_map(map);
			control_game(map);
			break;
		case 2:		
			read_map(map);
			print_map(map);
			control_game(map);
			break;
		case 3:
			return;
	}
}
int main(){
	//int map[][4] = {{4,8,16,32}, {64,128,256,512}, {1024,2048,4096,8192}, {16384,32768,65536,131072}};
	//print_map(map);
	//control_game(map);
	//read_map(map);
	mode_game();
}
