#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>
using namespace std;
struct square{
	int x;
	int y;
};
int last_dot(int map[], int m, int n){
	for(int y =0;y<m;y++){
		for(int x =0;x<n;x++){
			if(map[y*n+x]==2){
				return 1;
			}
		}
	}
	return 0;
}
void in_map(int map[], int m, int n){
	for(int y =0;y<m;y++){
		for(int x =0; x < n; x++){
			if(map[y*n+x]==1){
				cout << "#";
			}
			if(map[y*n+x]==0){
				cout << " ";
			}
			if(map[y*n+x]==2){
				cout << "*";
			}
			if(map[y*n+x]==3){
				cout << "P";
			}
		}
		cout << "\n";
	}
}
square find_next_dot(int map[], int y, int x, int m, int n){
	int max_i = 1;
	int max_j = 1;	
	int number = 1;
	square re;
	while(last_dot(map,m,n)){
		for(int i = -number; i<max_i+number;i++){
			for(int j = -number ; j<max_j+number;j++){
				if(i!=0 || j!=0){
					int tmp_y = y+i;
					int tmp_x = x+j;
					if(map[tmp_y*n +tmp_x] == 2 && (tmp_x >=0 && tmp_x <n) && (tmp_y >= 0 && tmp_y <m)){
						re.x = tmp_x;
						re.y = tmp_y;
						return re;
					}
				}
				
			}
		}		
		number++;
	}
	re.x = -1;
	re.y = -1;
	return re;
}
void setting_state(int state[], int count, int valuable){
	for (int i=0;i<count;i++){
		state[i]=valuable;
	}
}
void setting_Canmove(int map[], square Canmove[], int m, int n){
	int dem=0;
	for(int y=0 ; y < m;y++){
		for(int x=0; x < n ;x++){
			if(map[y*n+x] == 2 || map[y*n+x] == 0 || map[y*n+x] == 3){
				square a1;
				a1.x = x;
				a1.y = y;
				Canmove[dem] = a1;
				dem++;
			}
		}	
	}
}
int check_square(square Canmove[], int x, int y, int count){
	for(int i =0;i<count;i++){
		if(Canmove[i].x == x && Canmove[i].y == y){
			return i;
		}
	}
	return -1;
}
void setup_find_next_dot(int count, square Canmove[], int Canmove_sp[][4]){
	int arr[][2] = {{0,-1}, {0,1}, {1,0}, {-1,0}};
	for(int i =0;i<count;i++){
		for(int j =0; j<4;j++){
			int tmp_x = Canmove[i].x + arr[j][1];
			int tmp_y = Canmove[i].y + arr[j][0];
			Canmove_sp[i][j] = check_square(Canmove, tmp_x,tmp_y, count);
		}
	}
}
void control(int count, square Canmove[], int Canmove_sp[][4], int state[], int *pacman, int dot, int map[], int m, int n, int *move, ofstream &PHistory){
	vector<int> stack;
	stack.push_back(*pacman);
	int dem =0;
	while(dot != stack[stack.size()-1]){
		int last = stack[stack.size()-1];
		int c = 0;
		for(int i=0;i<4;i++){
			if(Canmove_sp[last][i] != -1 && state[Canmove_sp[last][i]] == 0){
				stack.push_back(Canmove_sp[last][i]);
				state[Canmove_sp[last][i]] = 1;
				c = 1;
				break;
			}
		}
		if(c==0){
			stack.pop_back();
		}
		
 	}


	for(int i =1; i< stack.size();i++){
		map[Canmove[*pacman].y * n +Canmove[*pacman].x] = 0;
		cout << *move << ",(" << Canmove[*pacman].x << "," << Canmove[*pacman].y << ")->(";
		*pacman = stack[i]; 
		cout << Canmove[*pacman].x << "," << Canmove[*pacman].y;
		if(map[Canmove[*pacman].y * n +Canmove[*pacman].x] == 2){
			cout << "),YES\n";
		}
		else{
			cout << "),NO\n";
		}
		map[Canmove[*pacman].y * n +Canmove[*pacman].x] = 3;
		PHistory << Canmove[*pacman].x << " " << Canmove[*pacman].y << "\n";
		*move+=1;
		in_map(map, m,n);
	}
	setting_state(state, count, 0);
	
}
void setup_map(int map[], int m, int n){
	int count =0;
	int move = 0;
	int pacman;
	for(int y=0 ; y < m ;y++){
		for(int x=0; x < n ;x++){
			if(map[y*n+x] == 2 || map[y*n+x] == 0 || map[y*n+x] == 3){
				count += 1; 
			}
			if(map[y*n+x] == 3){
				pacman = count -1  ;
			}
		}
	}
	square Canmove[count];
	setting_Canmove(map, Canmove, m, n);
	
	int state[count];
	setting_state(state, count, 0);
	
	
	int Canmove_sp[count][4];
	setup_find_next_dot(count, Canmove, Canmove_sp);
	
	square next_dot = find_next_dot(map, Canmove[pacman].y, Canmove[pacman].x , m, n);
	int int_next_dot = check_square(Canmove, next_dot.x, next_dot.y,count);
	
	ofstream PHistory("PHistory.txt");
	while(true){
		square next_dot = find_next_dot(map, Canmove[pacman].y, Canmove[pacman].x, m, n);
		if(next_dot.x == -1 && next_dot.y == -1){
			break;
		}
		int int_next_dot = check_square(Canmove, next_dot.x, next_dot.y,count);
		in_map(map,m,n);
		control(count, Canmove, Canmove_sp, state, &pacman, int_next_dot, map, m, n, &move, PHistory);
	}
	PHistory.close();
}
void get_size_map(int *m, int *n){
	fstream file_map ;
	file_map.open("pacman.txt", ios::in);
	string size_map;
	getline(file_map, size_map);
	char tmp_m[9], tmp_n[9];
	int i;
	for(i =0;i< size_map.size();i++){
		if(size_map[i] != ' '){
			tmp_m[i] = size_map[i];
		}
		else{
			break;
		}
	}
	i++;
	for(int j=0;i<size_map.size();j++, i++){
		tmp_n[j] = size_map[i];
 	}
	*m = atoi(tmp_m);
	*n = atoi(tmp_n);
	file_map.close();
}
void create_map(int map[], int m, int n){
	fstream file_map ;
	file_map.open("pacman.txt", ios::in);
	string s;
	getline(file_map, s);
	int index_map =0;
	while(!file_map.eof()){
		getline(file_map, s);
		for(int i = 0; i < s.size();i++, index_map++){
			if(s[i] == '#'){
				map[index_map] = 1;
			}
			else if(s[i] == '.'){
				map[index_map] = 2;
			}
			else if(s[i] == 'P'){
				map[index_map] = 3;
			}
			else{
				map[index_map] = 0;
			}
		}
	}
}
int main(){
	int m;
	int n;
	get_size_map( &m, &n);
	int map[n*m];
	create_map(map,m,n);
	setup_map(map,m,n);
}
