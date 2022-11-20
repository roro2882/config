#include <iostream>
#include <cmath>
int main(){
	int width=10;
	int height=10;
	int racetrack[width][height];
	for(int i=0; i<width;i++)
		for(int j=0;j<height;j++)
			racetrack[i][j]=0;
	char c;
	int i=0;
	int j=0;
	while(std::cin >> c){
		if(c=='o'){
			racetrack[i][j++]=0;
			std::cout << "0";
		}else if(c=='x'){
			racetrack[i][j++]=1;
			std::cout << "1";
		}
		if(j%(width)==0){
			i+=1;
			j=0;
			std::cout << std::endl;
		}
	}
	const int startx=9, starty = 3;
	int x = startx, y = starty;
	int speedx=0, speedy = 0;
	const int maxspeedx = 5, maxspeedy = 5;
	double val[width][height][maxspeedx][maxspeedy][3][3];
	std::cout<<"hello"<<std::endl;
	for(int i=0; i<width;i++)
		for(int j=0;j<height;j++)
			for(int sx=0;sx<maxspeedx;sx++)
				for(int sy=0;sy<maxspeedy;sy++)
				for(int ax=0;ax<3;ax++)
				for(int ay=0;ay<3;ay++)
					val[i][j][sx][sy][ax][ay]=0;
	int epi = 0;
	int randactions = 60;
	double gamma = 1;
	double alpha = 0.01;
	int n = 1;
	int storedR[n+1];
	int storedA[n+1][2];
	int storedS[n+1][4];
	int tt = 0;
	while(epi++<2){
	std::cout << "episode " << epi << std::endl;
	int t = 0;
	int T = 1000000000;
	int action[2] = {0,0};
	storedA[t%(n+1)][0]=action[0];
	storedA[t%(n+1)][1]=action[1];
	while(1){
		if(t<T){
			std::cout<<x<<","<<y<<std::endl;
			x-=speedx;
			y+=speedy;
			int reward = -1;
			if(x<0 || y>height || racetrack[x][y]==0){
				speedx=0;
				speedy=0;
				x=startx;
				y=starty;
				std::cout << "accident" << std::endl;
			}
			speedx += action[0];
			if(speedx<0)speedx=0;
			if(speedx>maxspeedx)speedx=maxspeedx;
			speedy += action[1];
			if(speedy<0)speedy=0;
			if(speedy>maxspeedy)speedy=maxspeedy;
			storedR[(t+1)%(n+1)]=reward;
			storedS[(t+1)%(n+1)][0]=x;
			storedS[(t+1)%(n+1)][1] = y;
			storedS[(t+1)%(n+1)][2] = speedx;
			storedS[(t+1)%(n+1)][3] = speedy;
			if(y==99){
				T=t+1;	
			}else{
				int axm=0,aym=0;
				int vmax=-1000000000;
				for(int ax=0;ax<3;ax++)
					for(int ay=0;ay<3;ay++){
						if(val[x][y][speedx][speedy][ax][ay]>vmax){
							axm = ax;
							aym = ay;
							vmax = val[x][y][speedx][speedy][ax][ay];
						}else if(tt%randactions==ax*3+ay){
							axm = ax;
							aym = ay;
							break;
						}
					}
				action[0] = axm-1;
				action[1] = aym-1;
				storedA[(t+1)%(n+1)][0]=action[0];
				storedA[(t+1)%(n+1)][1]=action[1];
			}
		}
		int tau = t-n+1;
		if(tau>=0){
			double G = 0;
			//discounting enleveeeeee (gamma**n)
			for(int i=tau+1;i<=tau+n && i<=T;i++)G+=storedR[i%(n+1)];
			//discounting enleveeeeee (gamma**n)
			if(tau+n<T)G+=val[x][y][speedx][speedy][storedA[(tau+n)%(n+1)][0]][storedA[(tau+n)%(n+1)][1]];
			val[storedS[tau%(n+1)][0]][storedS[tau%(n+1)][1]][storedS[tau%(n+1)][2]][storedS[tau%(n+1)][3]][storedA[(tau+n)%(n+1)][0]][storedA[(tau+n)%(n+1)][1]] =
				val[storedS[tau%(n+1)][0]][storedS[tau%(n+1)][1]][storedS[tau%(n+1)][2]][storedS[tau%(n+1)][3]][storedA[(tau+n)%(n+1)][0]][storedA[(tau+n)%(n+1)][1]] +
				alpha*(G-val[storedS[tau%(n+1)][0]][storedS[tau%(n+1)][1]][storedS[tau%(n+1)][2]][storedS[tau%(n+1)][3]][storedA[(tau+n)%(n+1)][0]][storedA[(tau+n)%(n+1)][1]]);
		}
		t+=1;
		tt+=1;
		if(tau = T-1)break;
	}
	}
	return 0;
}
void printtable(int *tablep, int width, int height){
	string result = "";
	for( int x = 0; x<width; x++){
		for( int y=0; y<height; y++){
		std::cout<<*tablep;
		++tablep;
		}
		std::cout<<"\n";
	}
}
