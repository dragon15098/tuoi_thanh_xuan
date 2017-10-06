#include <iostream>
#include <conio.h>
#include <fstream> 
#include <cstdlib>
#include <ctime>
using namespace std;
int win(int map[][3]){
	for(int i =0 ;i <3;i++){
		if(map[i][0] == map[i][1] && map[i][1] == map[i][2] && map[i][0] != 0){
			if(map[i][0] == -1){
				return -1;
			}
			return 1;
		}
		if(map[0][i] == map[1][i] && map[2][i] == map[1][i]  && map[0][i] != 0){
			if(map[0][i] == -1){
				return -1;
			}
			return 1;
		}
	}
	if(map[0][0] == map[1][1] && map[1][1] == map[2][2] && map[1][1] != 0){
		if(map[1][1] == -1){
				return -1;
			}
			return 1;
	}
	if(map[0][2] == map[1][1] && map[1][1] == map[2][0] && map[1][1] != 0){
		if(map[1][1] == -1){
				return -1;
			}
			return 1;
	} 
	return 0;
}
void setup(int map[][3]){
	for (int i=0;i<3;i++){
		for (int j=0; j< 3;j++){
			map[i][j]= 0;
		}
	}
}
void inmap(int map[][3]){
	cout << "####################\n";
	for (int i =0; i < 3;i++){
		
		for (int j =0; j< 3;j++){
			if(map[i][j] == -1){
				if(j<2){
					cout << " X |";	
				}
				else{
					cout << " X ";
				}
			}
			else if (map[i][j]==1){
				if(j<2){
					cout << " O |";
				}
				else{
					cout << " O ";	
				}
				
			}
			else if (map[i][j]==0){
				if(j<2){
					cout << "   |";	
				}
				else{
					cout << "   ";
				}
			}
		}
		cout << "\n";
		if(i<2){
			cout << "---|---|---\n";		
		}
		
	}
}
void mode1(){
	int map[3][3];
	setup(map);
	inmap(map);
	int move = 0;
	ofstream FileDemo ("File Move.txt");
	while( win(map)==0 &&  move < 9){
		int x, y;
		cout << "Nhap toa do x, y muon danh: ";
		cin >> x >> y;
		while(map[x][y] != 0){
			cout << "Nuoc di da danh!!! Nhap lai: ";
			cin >> x >> y;
		}
		
		if(move%2==0){
			map[x][y]= -1;
    		FileDemo<< move << " " << x << " " << y << "\n";
		}
		else{
			map[x][y] = 1;
			FileDemo<< move << " " << x << " " << y << "\n";
		}
		move++;
		
		inmap(map);
	}
	if(win(map) == -1){
		cout << "Nguoi choi X thang!!!";
	}
	else if (win(map)==1){
		cout << "Nguoi choi O thang!!!";
	}
	else if (win(map)==0){
		cout << "Hai nguoi choi hoa nhau";
	}
	system("clr");
	FileDemo.close();
}
int sp_bot(int map[][3], int sp[8]){
	//kiem tra nuoc di thang thua
	for(int i =0; i<3; i++){
		for(int j=0;j<3;j++){
			sp[i] += map[i][j]; // tinh diem theo hang ngang
			sp[3+i] += map[j][i]; // tinh diem theo cot doc
		}
	}
	for (int i=0;i<3;i++){
		sp[6] += map[i][i]; // cheo 1 
		sp[7] += map[i][2-i]; // cheo 2
	}
	for(int i=0;i<8;i++){
		if(sp[i]==2 || sp[i]==-2){
			return i;
		}
	}
	// chiem cac nut dac biet
	if(map[1][1] == 0){
		return 8;
	}
	if(map[0][0] == 0 || map[2][2] || map[0][2] == 0 || map[2][0]==0){
		return 9;
	}
	// chiem cac nut con lai
	return 10;
}
void auto_bot(int map[][3]){
	int sp[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int next_move = sp_bot(map, sp);
	
	if(next_move <3){
		for (int i =0;i<3;i++){
			if(map[next_move][i] ==0){
				map[next_move][i] = 1;
			}
		}
	}
	if(3 <= next_move && next_move<6){
		for (int i =0;i<3;i++){
			if(map[i][next_move-3] ==0){
				map[i][next_move-3] = 1;
			}
		}
	}
	if(next_move == 6){
		for (int i =0;i<3;i++){
			if(map[i][i] ==0){
				map[i][i] = 1;
			}
		}
	}
	if(next_move == 7){
		for(int i = 0;i<3;i++){
			if(map[i][2-i]==0){
				map[i][2-i] = 1;
			}
		}
	}
	if(next_move == 8){
		map[1][1]=1;
	}
	if(next_move == 9){
		if(map[0][0]==0){
			map[0][0]=1;
		}
		else if(map[0][2]==0){
			map[0][2]=1;
		}
		else if(map[2][0]==0){
			map[2][0]=1;
		}
		else if(map[2][2]==0){
			map[2][2]=1;
		}
	}
	if(next_move == 10){
		srand(time(NULL));
		int a[4][2]={ {0,1}, {1,0}, {2,1}, {1,2} };
		int ran = rand()%4;
		while(map[a[ran][0]][a[ran][1]]!=0){
			
			ran = rand()%4;
		}
		map[a[ran][0]][a[ran][1]] =1;
	}
}
void mode2(){
	int map[3][3];
	setup(map);
	inmap(map);
	int move = 0;
	ofstream FileDemo ("File Move.txt");
	while( win(map)==0 &&  move < 9){
		int x, y;
		cout << "Nhap toa do x, y muon danh: ";
		cin >> x >> y;
		while(map[x][y] != 0){
			cout << "Nuoc di da danh!!! Nhap lai: ";
			cin >> x >> y;
		}	
		map[x][y]= -1;
		move++;
		FileDemo<< move << " " << x << " " << y << "\n";
		auto_bot(map); 
		move++;
		inmap(map);
	}
	if(win(map) == -1){
		cout << "Nguoi choi thang :((";
	}
	else if (win(map)==1){
		cout << "May Thang :))";
	}
	else{
		cout << "Hai nguoi choi hoa nhau :| ";
	}
	FileDemo.close();	
}
void control(){
	cout << "Chon che do choi:\n";
	cout << "1: 2 nguoi choi\n";
	cout << "2: choi voi may\n";
	int x;
	cin >> x;
	while(x!=1 && x!= 2){
		cout << "Nhap lai che do choi: \n";
		cin >> x;
	}
	if(x==1){
		int continues = 1;
		while(continues ==1){
			mode1();
			cout << "Choi nua khong??? \n" << "1: co\n2: khong\n";
			cin>>continues;
		}
	}
	if(x==2){
		int continues = 1;
		while(continues ==1){
			mode2();
			cout << "Choi nua khong??? \n" << "1: co\n, 2: khong\n";
			cin>>continues;
		}
	}
}
int main(){
	control();
	return 0;
}

