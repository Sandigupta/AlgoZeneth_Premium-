// Function to perform the query operation
const int MAXN = 1000;
int Arr[MAXN][MAXN];
void processQuery(int U, int D, int L, int R, int X) {
    Arr[U][L] += X;
    Arr[U][R+1] -= X;
    Arr[D+1][L] -= X;
    Arr[D+1][R+1] += X;
}

// After that we will do 2D prefix sum as we do in previous section
