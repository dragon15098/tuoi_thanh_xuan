#include <iostream>
using namespace std;
void print_map(int map[][4]){
	cout << "-------\n";
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			/*if(map[i][j]==-1){
				if(j<3){
					cout << " " << "|";
				}
				else{
					cout << " ";
				}
			}
			else{*/
				if(j<3){
					if(map[i][j] != -1){
						cout << " "<< map[i][j] << "|";	
					}
					else{
						cout << map[i][j] << "|";
					}	
				}
				else{
					cout << map[i][j];
				}
		//	}
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
	print_map(map);
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
	print_map(map);
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
	print_map(map);
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
	print_map(map);	
}
void control_game(int map[][4]){
	int input;
	cout << "nhap huong di: ";
	cin >> input;
	while(input!=2 && input!=4 && input!=8 && input!=6){
		cout << "khong hop le. Nhap lai:";
		cin >> input;
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
	
}
int main(){
	int map[][4] = {{-1,-1,2,2}, {-1,2,4,2}, {2,2,2,4}, {-1,2,2,-1}};
	print_map(map);
	while(true){
		control_game(map);
	}
	
}
