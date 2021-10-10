#include <iostream>
using namespace std;

int main(int argc,char *argv[]){
	int n;
	cin>>n;
	int city[50][50]={0};
	int sum=0;
	int row[50];
	int column[50];
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cin>>city[i][j];
		}
	}
	for (int i=0;i<n;i++){
		int max=city[i][0];
		for (int j=1;j<n;j++){
			if (city[i][j]>max){
				max=city[i][j];
			}
		}
		row[i]=max;
	}
	for (int i=0;i<n;i++){
		int max=city[0][i];
		for (int j=1;j<n;j++){
			if (city[j][i]>max){
				max=city[j][i];
			}
		}
		column[i]=max;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			int min=row[i]>=column[j]?column[j]:row[i];
			if (city[i][j]<min){
				sum+=min-city[i][j];
			}
		}
	}
	cout<<sum<<endl;
	
}