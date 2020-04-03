// Assignments.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

// Method 1
int MaxSubSeqSum1(int n, int a[])
// Simple iteration, T(n)=O(N^3)
{
	int MaxSum = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int TempSum = 0;
			for (int k = i; k <= j; ++k) {
				TempSum += a[k];
			}

			if (TempSum > MaxSum)
				MaxSum = TempSum;
		}
	}
	return MaxSum;
}

// Method 2
int MaxSubSeqSum2(int n, int a[])
// T(n)=O(N^2)
{
	int MaxSum = 0;
	for (int i = 0; i < n; ++i) {
		int TempSum = 0;
		for (int j = i; j < n; ++j) {
			TempSum += a[j];
			
			if (TempSum > MaxSum)
				MaxSum = TempSum;
		}
	}
	return MaxSum;
}

// Method 3
int Max3(int A, int B, int C) {
	return (A > B) ? ((A > C) ? A : C) : ((B > C) ? B : C);
}

int DivideAndConquer(int a[], int left, int right) {
	if (left == right) {
		if (a[left] > 0)
			return a[left];
		return 0;
	}

	int center = (left + right) / 2;
	int MaxLeftSum = DivideAndConquer(a, left, center);
	int MaxRightSum = DivideAndConquer(a, center + 1, right);

	int MaxLeftBorderSum = 0;
	int LeftBorderSum = 0;
	for (int i = center; i >= left; i--) {
		LeftBorderSum += a[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}

	int MaxRightBorderSum = 0;
	int RightBorderSum = 0;
	for (int i = center + 1; i <= right; i++) {
		RightBorderSum += a[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubSeqSum3(int n, int a[])
// T(n)=O(N*log(N))
{
	return DivideAndConquer(a, 0, n - 1);
}

// Method 4
int MaxSubSeqSum4(int n, int a[])
// T(n)=O(N)
{
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for (int i = 0; i < n; i++) {
		ThisSum += a[i];
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
		}
		else if (ThisSum < 0) {
			ThisSum = 0;
		}
	}
	return MaxSum;
}

int main()
{
	int n = 8;
	int a[8] = { 1, -2, 3, 4, 6, 2, -4, 5};

	std::cout << MaxSubSeqSum1(n, a) << std::endl;
	std::cout << MaxSubSeqSum2(n, a) << std::endl;
	std::cout << MaxSubSeqSum3(n, a) << std::endl;
	std::cout << MaxSubSeqSum4(n, a) << std::endl;

	return 0;
}