#include <iostream>
#include <string>
using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

// Return the length of LCS for X[0...m-1] and Y[0...n-1]
int lcs(string &X, string &Y, int m, int n)
{
	if (m == 0 || n == 0)
		return 0;
	if (X[m - 1] == Y[n - 1])
		return lcs(X, Y, m - 1, n - 1) + 1;
	else
		return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
}

int main()
{
	string X = "ABCBDAB";
	string Y = "BDCABA";

	cout << "The length of LCS is " << lcs(X, Y, X.length(), Y.length());
	cout << endl;

	getchar();
	return 0;
}