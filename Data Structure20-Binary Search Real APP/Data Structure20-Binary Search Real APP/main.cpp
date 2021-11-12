#include<iostream>
using namespace std;

//1.koko���㽶
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
	int left = 1;  //������һ���һ��������������С�ٶȣ�������СΪ1�����Ϊmax(piles)
	int right = 0;
	for (int i = 0; i < length; i++)
	{
		if (right < piles[i])
		{
			int right = piles[i];
		}
	}  //right == max(piles[])
	int max = right;

	while (left <= right) //[left,right]����ʱ������ʹ��left=right+1��������������left��<=right������<
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

	if (left > max) //���leftԽ�硣����������С�ٶȣ�����Ϊ����߽磬����Ϊ�ж�leftԽ��
	{
		return -1;
	}
	return left;
}

//2.������������
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
			sum = weights[i];  //�������˵����������������ˣ�sumӦΪ�����������
		}
		else if (sum == mid)  //�������˵����������������ã�sumӦΪ�µĿ�ʼ��0
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
	int left = max;  //������Ҫ�����䴬��С������������������С��������Ϊmax(weights)�������������Ϊsum(weights)
	int right = sum;  //��Ϊ[left,right]

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