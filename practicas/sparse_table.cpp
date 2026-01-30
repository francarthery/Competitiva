struct SparseTable{ //nlog(n) tiempo y memoria. Sirve para operaciones idempotentes.
    int N, K;
    vector<vector<int>> st;
    SparseTable(int n) : N(n), K(__lg(n) + 1) {
        st.assign(K, vector<int>(N));
    }
    void build(vector<int> &v){
        st[0] = v;
        forn(i, K - 1) for(int j = 0; j + (1 << (i + 1)) <= N; j++){
            st[i + 1][j] = max(st[i][j], st[i][j + (1 << i)]); 
        }
    }    
    int query(int l, int r) { // [l, r)
        int i = __lg(r - l);
        return max(st[i][l], st[i][r - (1 << i)]);
    };
};