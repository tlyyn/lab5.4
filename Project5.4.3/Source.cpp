#include <iostream> 
#include <cmath> 
using namespace std;

double D0(const int N)

{
	double D = 1;
	for (int K = N; K <= 25; K++)
		D *= (sqrt(1 + N/K));

	return D;
}
double D1(const int N, const int K)
{
	if (K > 25)
		return 1;
	else
		return sqrt(1 + N / K) * D1(N, K+1);

}
double D2(const int N, const int K)
{
	if (K < N)
		return 1;
	else
		return sqrt(1 + N / K) * D2(N, K - 1);
}
double D3(const int N, const int K, double t)
{
	t = t * sqrt(1 + N / K);
	if (K >= 25)
		return t;
	else

		return D3(N, K + 1, t);
}
double D4(const int N, const int K, double t)
{
	t = t * sqrt(1 + N / K);
	if (K <= 25)
		return t;
	else
		return D4(N, K - 1, t);

}
int main()
{

	int K, N;
	cout << "N = "; cin >> N;
	K = N;

	cout << "(iter) D0 = " << D0(N) << endl;
	cout << "(rec up ++) D1 = " << D1(K, N) << endl;
	cout << "(rec up --) D2 = " << D2(K, N) << endl;
	cout << "(rec down ++) D3 = " << D3(K, N, 1.) << endl;
	cout << "(rec down --) D4 = " << D4(K, N, 1.) << endl;
	return 1;
}