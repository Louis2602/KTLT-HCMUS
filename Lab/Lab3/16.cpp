#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int** transposeMatrix(int** a, int length, int width) {
    for(int i=0; i<width; i++) {
        for(int j=0; j<length/2; j++) {
            int tmp = *(*(a+i)+j);
            *(*(a+i)+j) = *(*(a+i)+length-j-1);
            *(*(a+i)+length-j-1) = tmp;
        }
    }
    return a;
}

int main(){
    int length, width;
    cin >> width >> length;
    srand(time(0));
    // Khoi tao mang 2 chieu
    int **a;
    a = new int *[width];
    for (int i = 0; i < width; i++)
    {
        *(a + i) = new int[length];
        for (int j = 0; j < length; j++)
            *(*(a + i) + j) = rand() % 10;
    }
    cout << "Generated Matrix\n";
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
            cout << *(*(a + i) + j) << " ";
        cout << '\n';
    }
    int **ans;
    ans = transposeMatrix(a, length, width);
    cout << "After transpose:\n";
    for(int i=0; i<width; i++) {
        for(int j=0; j<length; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
