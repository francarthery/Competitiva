#include <bits/stdc++.h>
using namespace std;

static const double INF = 1e15;

// Variables globales para no pasarlas mil veces (o se pueden encapsular)
int M;
vector<double> pL, pR;      // pL[i] = prob. en cuadra -i, pR[i] = prob. en cuadra +i
vector<double> sumL, sumR;  // sumL[i] = sum de pL[k] para k >= i+1, sumR[j] = sum de pR[k] para k >= j+1

// dp[i][j][s]: -1 si no calculado, o la mínima distancia esperada
double dp[1001][1001][3];

double PnoVis(int i, int j) {
    // Prob. de que el auto siga sin aparecer tras visitar i a la izq. y j a la der.
    return sumL[i] + sumR[j]; 
}

// Distancia para moverse a la cuadra -(i+1)
double distLeft(int i, int j, int s) {
    if (s == 2) {
        // Estamos en 0 (solo sucede si i=0,j=0 al inicio)
        return i + 1; 
    } else if (s == 0) {
        // Estamos en -(i)
        return 1; 
    } else {
        // s == 1, estamos en +(j)
        // Distancia para ir de +j a -(i+1) = j (para volver a 0) + (i+1) (para llegar a -(i+1))
        return j + (i + 1);
    }
}

// Distancia para moverse a la cuadra +(j+1)
double distRight(int i, int j, int s) {
    if (s == 2) {
        // Estamos en 0
        return j + 1;
    } else if (s == 1) {
        // Estamos en +(j)
        return 1;
    } else {
        // s == 0, estamos en -(i)
        // Distancia = i (para volver a 0) + (j+1) (para llegar a +(j+1))
        return i + (j + 1);
    }
}

double solveDP(int i, int j, int s) {
    // Caso base: ya visitamos todo
    if (i == M && j == M) return 0.0;
    
    double &res = dp[i][j][s];
    if (res > -0.5) {
        // Significa que ya está calculado (inicializado en -1)
        return res;
    }

    double P = PnoVis(i, j);
    if (P < 1e-15) {
        // No queda nada por visitar con prob > 0
        // (Teóricamente no debería pasar si i<M o j<M, pero por seguridad)
        return res = 0.0;
    }

    // Opción ir a la izquierda (si i < M)
    double costLeftVal = INF;
    if (i < M) {
        double moveDist = distLeft(i, j, s);
        // Formula:
        //    costo = (moveDist * P) + [P - pL[i+1]] * dp(i+1, j, 0)
        costLeftVal = moveDist * P + (P - pL[i+1]) * solveDP(i+1, j, 0);
    }

    // Opción ir a la derecha (si j < M)
    double costRightVal = INF;
    if (j < M) {
        double moveDist = distRight(i, j, s);
        costRightVal = moveDist * P + (P - pR[j+1]) * solveDP(i, j+1, 1);
    }

    res = min(costLeftVal, costRightVal);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef fran
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> M;
    pL.resize(M+1); 
    pR.resize(M+1);

    // Leemos 2M probabilidades en orden:
    // primero las M del lado oeste (-M..-1), luego las M del lado este (+1..+M).
    for (int i = M; i >= 1; i--) {
        // pL[M] es la prob. de la cuadra -M, pL[1] la de -1
        cin >> pL[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> pR[i];
    }

    // Precomputamos sumL[i] = pL[i+1] + ... + pL[M]
    // para saber cuánto falta visitar a partir de i ya visitados.
    sumL.resize(M+1); 
    sumR.resize(M+1);
    sumL[M] = 0.0;
    for (int i = M-1; i >= 0; i--) {
        sumL[i] = sumL[i+1] + pL[i+1];
    }
    sumR[M] = 0.0;
    for (int j = M-1; j >= 0; j--) {
        sumR[j] = sumR[j+1] + pR[j+1];
    }

    // Inicializamos DP con -1
    for(int i=0; i<=M; i++){
        for(int j=0; j<=M; j++){
            for(int s=0; s<3; s++){
                dp[i][j][s] = -1.0;
            }
        }
    }

    double ans = solveDP(0, 0, 2);

    cout << fixed << setprecision(6) << ans << "\n";
    return 0;
}
