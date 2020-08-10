#include <iostream>
#define SER(N) (i+(N))%4 
int main() {
	double x[4],y[4],x5,y5;
	for (int i=0;i<4;i++)
		std::cin >> x[i] >> y[i];
	std::cin >> x5 >> y5;
	int pos[4];
	for (int i=0;i<4;i++){
		if (x[SER(0)]-x[SER(1)] == 0){ //if square
			if (x5 < x[SER(0)]) pos[i] = 1;//left
			if (x5 ==  x[SER(0)]) pos[i] = 2;//equal
			if (x5 > x[SER(0)]) pos[i] = 3;//right
		}else{
			double nY = y[SER(0)]+(x5-x[SER(0)])*(y[SER(0)]-y[SER(1)])/(x[SER(0)]-x[SER(1)]); //equation of a straight line
			if (y5 > nY) pos[i] = 1;//higher
			if (y5 == nY) pos[i] = 2;//equal
			if (y5 < nY) pos[i] = 3;//under
		}
		//std::cout<<pos[i]; 
	}
	std::cout<< std::endl;
	for (int i=0;i<4;i++){
		if ((pos[SER(0)]!=3)&&(pos[SER(1)]!=3)&&(pos[SER(2)]!=1)&&(pos[SER(3)]!=1)){
			std::cout << "Yes";
			return 0; 
		}
	}
	std::cout << "No";
}