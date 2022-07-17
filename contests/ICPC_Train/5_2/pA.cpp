#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>
using namespace std;

const double eps = 1e-4;

int GaussianElim(vector<vector<double>> A, vector<double> b, vector<double> &x) {
  int N = A.size(), M = A[0].size();
  x = vector<double>(M);
  vector<int> where = vector<int>(M, -1);
  //vector<vector<int>> nullspace = vector<vector<int>>();
  for(int row = 0, col = 0; col < M && row < N; col++) {
    int s = row;
    for(int i = row; i < N; i++) if(abs(A[i][col]) > abs(A[s][col])) s = i;
    if(abs(A[s][col]) < eps) continue;
    where[col] = row;
    for(int i = 0; i < M; i++) swap(A[s][i], A[row][i]);
    swap(b[s], b[row]);
    for(int i = 0; i < N; i++) if(i != row) {
      double f = A[i][col] / A[row][col];
      for(int j = 0; j < M; j++) {
        A[i][j] -= A[row][j] * f;
      }
      b[i] -= b[row] * f;
    }
    row++;
  }
  for(int i = 0; i < M; i++) if(where[i] != -1) {
    x[i] = b[where[i]] / A[where[i]][i];
  }
  for(int i = 0; i < N; i++) {
    double s = 0;
    for(int j = 0; j < M; j++) s += A[i][j] * x[j];
    if(abs(s - b[i]) > eps) {
      fill(x.begin(), x.end(), -1);
      return 0;
    }
  }
  return 1;
}

const int maxN = 100;

int N, K, adj[maxN][maxN], rowsum[maxN];
vector<vector<double>> A;
vector<double> b, x;
vector<int> goodrows;
int main() {
  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    rowsum[i] = 0;
    for(int j = 0; j < N; j++) {
      cin >> adj[i][j];
      rowsum[i] += adj[i][j];
    }
    if(rowsum[i] > 0) goodrows.push_back(i);
  }
  if(!goodrows.size()) {
    cout << 0 << endl;
    return 0;
  }
  x.resize(N);
  vector<double> row = vector<double>(N);
  for(int i = 0; i < (int)goodrows.size() - 1; i++) {
    for(int j = 0; j < N; j++) {
      row[j] = adj[goodrows[i]][j] - adj[goodrows[i + 1]][j];
    }
    A.push_back(row);
    b.push_back(0);
  }
  fill(row.begin(), row.end(), 0);
  for(int x : goodrows) row[x] = 1;
  A.push_back(row);
  b.push_back(K);
  
  GaussianElim(A, b, x);
  /*
  for(int i = 0; i < A.size(); i++) {
    for(int j = 0; j < N; j++) {
      cout << A[i][j] << " ";
    }
    cout << b[i] << endl;
  }
  */
  double ans = 0;
  for(int i = 0; i < N; i++) for(int j = i + 1; j < N; j++) {
    ans += adj[i][j] * x[i] * x[j];
  }
  cout << fixed << setprecision(15) << ans << endl;
}