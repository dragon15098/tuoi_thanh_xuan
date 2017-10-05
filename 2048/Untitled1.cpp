#include <iostream>
using namespace std;
void print_map(int map[][4]){
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
					cout << map[i][j] << "|";				
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
	/*	cout << "j= " << j << "\n";
		print_map(map);
		cout << "\n";
	*/
	for (int j=0; j<4;j++){
		int move = 0;
		for(int i=0;i<3;i++){
			if(map[i][j] == map[i+1][j] && map[i][j]!=-1){
				map[i][j] *=2;
				map[i+1][j]=-1;
				move++;
			}
			for(int k = i;k<4;k++){
				if(move!=0){
					map[k-move][j] = map[k][j];
					map[k][j] =1;
				}
			}
		}
	}
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
			print_map(map);
			break;
	/*	case 4:
			left();
			break;
		case 6:
			right();
			break;
		case 2:
			down();
			break;*/
	}	
}
int main(){
	int map[][4] = {{-1,-1,-1,-1}, {-1,-1,-1,2}, {-1,-1,-1,2}, {-1,-1,-1,2}};
	print_map(map);
	control_game(map);
}
