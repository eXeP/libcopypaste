void printmat(vector<vector<i64>> A){
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[0].size(); j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
vector<vector<i64>> matmul(vector<vector<i64>> A, vector<vector<i64>> B){
    int n = A[0].size(), a = A.size(), b = B[0].size();
    vector<vector<i64>> C(a, vector<i64>(b, 0));
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            for(int k = 0; k < n; k++)
                C[i][j] = (C[i][j]+A[i][k]*B[k][j])%defmod;

        }
    }
    return C;
}
vector<vector<i64>> matpow(vector<vector<i64>> A, i64 n){
    vector<vector<i64>> R(A.size(), vector<i64>(A.size(), 0));
    for(int i = 0; i < A.size(); ++i)
    	R[i][i] = 1;
    while(n){
        if(n&1){
            R = matmul(R, A);
            n--;
        }
        A = matmul(A, A);
        n/=2;
    }
    return R;
}
