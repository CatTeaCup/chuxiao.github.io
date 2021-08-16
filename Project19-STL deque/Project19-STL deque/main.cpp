#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

//deque�൱��һ��˫��vector���Ƕ��С�����Ҫ���ǿ���ͷ���ͷɾ��push_front��pop_front��push_back��pop_back��front��back��insert�������ĺ���
//deque����vector��һ�����������Կռ䣬deque��ͷ������ɾ���ٶȺܿ죬vector��Ҫ�ƶ����������Ԫ�أ�vector����Ԫ���ر�죬deque��һ��--
//deque��ʵ��ԭ���������ڲ���һ���п�������¼���еĻ�������ַ��ÿһ�λ��������ܱ�����Ԫ�أ�����deque���������Ŀռ䣬����ͨ���п�����¼�������ĵ�ַ��Ȼ�󻺳����ڴ洢Ԫ��
void printdeque(const deque<int>& d)  //����const�������޸�ֵ
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)  //����const�󣬵�������Ҫ��Ϊconst_iterator 
	{
		//*it = 10;  //����const�����޸�ֵ
		cout << *it << " ";
	}
	cout << endl;
}

//deque���캯��
void test01() 
{
	cout << "deque���캯����" << endl;
	//�޲ι���
	deque<int>d1;
	for (int i = 0; i < 10; i++) 
	{
		d1.push_front(i);
	}
	printdeque(d1);

	//
	deque<int>d2(d1.begin(),d1.end());
	printdeque(d2);

	//��������
	deque<int>d3(d2);

	//
	deque<int>d4(10, 100);
	printdeque(d4);
}

//deque��ֵ
void test02() 
{
	cout << "deque��ֵ��" << endl;
	deque<int>d1;
	for (int i = 0; i < 10; i++) 
	{
		d1.push_front(i);
	}

	//�ȺŸ�ֵ
	deque<int>d2;
	d2 = d1;
	printdeque(d2);

	//assign��ֵ
	deque<int>d3;
	d3.assign(d2.begin(), d2.end());
	printdeque(d3);

	deque<int>d4;
	d4.assign(10, 100);
	printdeque(d4);
}

//deque��С
void test03() 
{
	cout << "deque��С��" << endl;
	deque<int>d1;
	for (int i = 0; i < 10; i++) 
	{
		d1.push_back(i);
	}
	printdeque(d1);

	//û��capacity����Ϊ�������ռ�
	//empty��size
	if (!d1.empty()) 
	{
		cout << "d1��Ϊ��" << endl;
		cout << "d1�Ĵ�СΪ��" << d1.size() << endl;
	}

	//resize
	d1.resize(15);
	printdeque(d1);
	d1.resize(20, 100);  //ָ�����ֵ
	printdeque(d1);
}

//deque�Ĳ����ɾ��
void test04() 
{
	cout << "deque�Ĳ����ɾ����" << endl;
	deque<int>d1;
	//β��
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	//ͷ��
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	printdeque(d1);
	//βɾ
	d1.pop_back();
	//ͷɾ
	d1.pop_front();
	printdeque(d1);

	//insert
	d1.insert(d1.begin(), 2, 10000);  //������
	printdeque(d1);
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	d1.insert(d1.begin(), d2.begin(), d2.end());  //������
	printdeque(d1);

	//erase
	deque<int>::iterator it = d1.begin();
	it++;  //���õ�����λ��
	d1.erase(it, d1.end());
	printdeque(d1);
}

//deque�����ݴ�ȡ
void test05()
{
	cout << "deque�����ݴ�ȡ��" << endl;
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	//[]��ʽ��������
	for(int i = 0;i<d1.size();i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;
	//at()��ʽ��������
	for(int i = 0;i<d1.size();i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << endl;

	//back
	cout << d1.back() << endl;
	//front
	cout << d1.front() << endl;
}

//deque������
void test06()
{
	cout << "deque������" << endl;
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	//sort������deque��vectorҲ����ʹ��algorithm�е�sort����������
	sort(d1.begin(), d1.end());
	printdeque(d1);
}

int main() 
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();

	system("pause");
	return -1;
}