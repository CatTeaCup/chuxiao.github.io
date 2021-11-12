#include<iostream>
using namespace std;

//1.koko吃香蕉
bool can_finsh(int mid, int* piles, int length, int H) 
{
	int sums = 0;
	for (int i = 0; i < length; i++) 
	{
		int sum = piles[i] / mid + ((piles[i] % mid) > 0 ? 1 : 0);
		sums = sums + sum;
	}
	if (sums <= H) 
	{
		return true;
	}
	return false;
}

int minEatingSpeed(int* piles, int length, int H)
{
	int left = 1;  //最少能一天吃一根。此问题求最小速度，所以最小为1，最大为max(piles)
	int right = 0;
	for (int i = 0; i < length; i++)
	{
		if (right < piles[i])
		{
			int right = piles[i];
		}
	}  //right == max(piles[])
	int max = right;

	while (left <= right) //[left,right]区间时，必须使得left=right+1才能跳出，所以left是<=right而不是<
	{
		int mid = left + (right - left)/2;
		if(can_finsh(mid,piles,length,H))
		{
			right = mid - 1;
		}
		else 
		{
			left = mid + 1;
		}
	}

	if (left > max) //如果left越界。我们是找最小速度，所以为找左边界，所以为判断left越界
	{
		return -1;
	}
	return left;
}

//2.包裹运输问题
bool can_finish2(int mid, int* weights,int length,int D) 
{
	int sum = 0;
	int day = 0;
	for (int i = 0; i < length; i++) 
	{
		sum = sum + weights[i];
		if (sum > mid) 
		{
			day++;
			sum = weights[i];  //如果超过说明最后加入的重量超了，sum应为最后加入的重量
		}
		else if (sum == mid)  //如果等于说明最后加入的重量正好，sum应为新的开始：0
		{
			day++;
			sum = 0;
		}
	}
	return day <= D;
}

int shipWithinDays(int* weights, int length, int D)
{
	int max = 0;
	int sum = 0;
	for (int i = 0; i < length; i++) 
	{
		if (max < weights[i]) 
		{
			max = weights[i];
		}
		sum = sum + weights[i];
	}
	int left = max;  //此问题要求运输船最小的运输能力。所以最小运输能力为max(weights)，最大运输能力为sum(weights)
	int right = sum;  //此为[left,right]

	while (left <= right) 
	{
		int mid = left + (right - left);
		if (can_finish2(mid, weights, length, D)) 
		{
			right = mid - 1;
		}
		else 
		{
			left = mid + 1;
		}
	}

	if (left > sum) 
	{
		return -1;
	}
	return left;
}