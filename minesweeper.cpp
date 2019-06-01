#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#define cls system("cls")
using namespace std;
int height=0,width=0,boom=0;
int inner[50][50];
int display();
int open(int x, int y);
bool lose=false;
char int2char(int inpu);
char inner2reversi(int x, int y);
int gameover(bool win);

int main(){
	cout<<"Input the width(<50):";
	cin>>width;
	cls;
	cout<<"Input the height(<50):";
	cin>>height;
	cout<<"Input the number of mines(<"<<height*width/2<<"):";
	cin>>boom;
	for (int i=0;i<width;i++){
		for (int j=0;j<height;j++){
			inner[i][j]=0;
		}
	}
	srand(time(NULL));
	while(boom!=0){
		int innerx,innery;
		innerx=rand()%width;
		innery=rand()%height;
		if (inner[innerx][innery]!=9){
			inner[innerx][innery]=9;
			boom--;
			for (int i=-1;i<=1;i++){
				for (int j=-1;j<=1;j++){
					if(inner[innerx+i][innery+j]!=9 && innerx+i>-1 && innerx+i<width && innery+j>-1 && innery+j<height) inner[innerx+i][innery+j]++;
				}
			}
		}
	}
	
	
	while(true){
		display();
		int x,y;
		cout<<"Input the x-coordinate:";
		cin>>x;
		cout<<"Input the y-coordinate:";
		cin>>y;
		if(inner[x][y]>=0 && inner[x][y]!=10){
			char enter;
			while(true){
				char enter;
				cout<<"Input the action(o=sweep the mines,p=mark)";
				cin>>enter;
				if(enter=='o'){
					if(inner[x][y]==9) {
						inner[x][y]=-9;
						gameover(false);
					}
					if(inner[x][y]>10) inner[x][y]=(inner[x][y]-1)/10;
					if(inner[x][y]==0) inner[x][y]=10;
					if(inner[x][y]>0) inner[x][y]=inner[x][y]*-1;
					open(x,y);
					break;
				}else if(enter=='p'){
					inner[x][y]=inner[x][y]*10+1;
					break;
				}else{
					cout<<"Ivalid Action\n";
				}
			}
		}else{
			cout<<"Invalid input\n";
		}
		bool check=false;
		for(int i=0;i<width;i++){
			for(int j=0;j<height;j++){
				if(inner[i][j]==9){
					check=true;
				}
			}
		}
		if (check==false) gameover(true);
	}
}

int display(){
	cls;
	cout<<"\\ ";
	for (int i=0;i<width;i++){
		cout<<" ";
		if(i<10) cout<<"0";
		cout<<i;
	}
	cout<<endl;
	for (int i=0;i<height;i++){
		if(i<10) cout<<"0";
		cout<<i;
		for (int j=0;j<width;j++){
			cout<<"  "<<inner2reversi(j,i);
		}
		cout<<"| "<<i<<endl;
	}
	for (int i=0;i<height+1;i++){
		cout<<"---";
	}
	cout<<endl;
	cout<<"/ ";
	for (int i=0;i<width;i++){
		cout<<" ";
		if(i<10) cout<<"0";
		cout<<i;
	}
	cout<<endl;
}

int open(int x, int y){ 
	for (int i=-1;i<=1;i++){
		for (int j=-1;j<=1;j++){
			if(inner[x+i][y+j]<9 && x+i>-1 && x+i<width && y+j>-1 && y+j<height) inner[x+i][y+j]=abs(inner[x+i][y+j])*-1;
		}
	}
	if(inner[x+1][y]==0 && x<height){
		inner[x+1][y]=10;
		open(x+1,y);
	}
	if(inner[x][y+1]==0 && y<width){
		inner[x][y+1]=10;
		open(x,y+1);
	}
	if(inner[x-1][y]==0 && x>0){
		inner[x-1][y]=10;
		open(x-1,y);
	}
	if(inner[x][y-1]==0 && y>0){
		inner[x][y-1]=10;
		open(x,y-1);
	}
}

char int2char(int inpu){
	char out;
	switch(inpu){
		case 1:
			out='1';
			break;
		case 2:
			out='2';
			break;
		case 3:
			out='3';
			break;
		case 4:
			out='4';
			break;
		case 5:
			out='5';
			break;
		case 6:
			out='6';
			break;
		case 7:
			out='7';
			break;
		case 8:
			out='8';
			break;
	}
	return out;
}

char inner2reversi(int x, int y){
	char out;
	switch(inner[x][y]){
		case 10:
			out=' ';
			break;
		case -9:
			out='B';
			break;
		default:
			if(inner[x][y]>10){
				out='P';
				break;
			}else if(inner[x][y]>=0){
				out='O';
				break;
			}else{
				out=int2char(inner[x][y]*-1);
				break;
			}
	}
	return out;
}
int gameover(bool win){
		display();
		if(win==true){
			cout<<"YOU WIN, Good Job\n";
		}else{
			cout<<"YOU LOSE\n";
		cout<<"Please close this program to restart...\n";
		}
	while(true){
		int test;
	}
}
