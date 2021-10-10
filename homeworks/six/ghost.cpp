#include <iostream>
using namespace std;

bool isInArray(int n, int* array, int len) {
    for (int i = 0; i < len; i++) {
        if (array[i] == n) {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    int array[10000][2] = { 0 };
    int result[10000][2] ;
    int cache[10000] = { 0 };
    int index = 0;
    bool ismerge = false;
    for (int i = 0; i < n; i++) {
        cin >> array[i][0] >> array[i][1];
    }
    for (int i = 0; i < 10000; i++) {
        result[i][0] = -1;
        result[i][1] = -1;
    }
    for (int i=1;i<n;i++){
    	int k=array[i][0];
    	int l=array[i][1];
    	int j=i-1;
    	while (j>=0&&array[j][0]>k){
    		array[j+1][0]=array[j][0];
    		array[j+1][1]=array[j][1];
    		j--;
		}
		array[j+1][0]=k;
		array[j+1][1]=l;
	}
    for (int i = 0; i < n; i++) {
        ismerge = false;
        for (int j = i + 1; j < n; j++) {
            if (isInArray(i, cache, index)) {
                ismerge = true;
                break;
            }
            if (array[i][0] >= array[j][0] && array[i][1] <= array[j][1]) {
                array[i][0] = array[j][0];
                array[i][1] = array[j][1];
                cache[index++] = j;
            }
            else if (array[i][0]<array[j][0] && array[i][1]>array[j][1]) {
                cache[index++] = j;
            }
            else if (array[i][0] <= array[j][0] && array[i][1] >= array[j][0] && array[i][1] <= array[j][1]) {
                array[i][0] = array[i][0];
                array[i][1] = array[j][1];
                cache[index++] = j;
            }
            else if (array[i][0] >= array[j][0] && array[i][0] <= array[j][1] && array[i][1] >= array[j][1]) {
                array[i][0] = array[j][0];
                array[i][1] = array[i][1];
                cache[index++] = j;
            }
        }
        if (i + 1 == n && isInArray(i, cache, index)) {
            ismerge = true;
        }
        if (result[i][0] == -1 && result[i][1] == -1&&ismerge==false) {
            result[i][0] = array[i][0];
            result[i][1] = array[i][1];
        }
        
    } 
    
    for (int i = 0; i < n; i++) {
        if (result[i][0] != -1) {
            cout << result[i][0] << " " << result[i][1] << endl;
        }
    }
}