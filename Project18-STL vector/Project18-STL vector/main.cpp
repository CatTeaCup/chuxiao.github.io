#include<iostream>
#include<vector>
using namespace std;
//vector�����飬��C++�Դ������������ǣ���ͨ�����Ǿ�̬�ռ䣬��vector���Զ�̬��չ
//vector��push_back��pop_back��front��back��ָ���v.begin()\v.end()\v.rbegin()\v.rend()�ȵ�����

void printvector(vector<int>& v)   //���ý��գ�����
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)   //vector�ĵ�����ʹ��
	{
		cout << *it << " ";  //it��this���ƣ���������ָ��
	}
	cout << endl;
}

//vector����
void test01() 
{
	cout << "vector���죺" << endl;
	//Ĭ�Ϲ��� �޲ι���
	vector<int>v1;
	for (int i = 0; i < 10; i++) 
	{
		v1.push_back(i);
	}
	printvector(v1);

	//ͨ�����䷽ʽ���й���
	vector<int>v2(v1.begin(), v1.end());  //�����ڿ�������
	printvector(v2);

	//n��elem��ʽ����
	vector<int>v3(10, 100);  //10��100
	printvector(v3);

	//��������
	vector<int>v4(v3);
	printvector(v4);
}

//vector��ֵ
void test02() 
{
	cout << "vector��ֵ��" << endl;
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	//��ֵ  operator= �Ⱥ����������
	vector<int>v2;
	v2 = v1;
	printvector(v2);

	//assign
	vector<int>v3;
	v3.assign(v2.begin(), v2.end());
	printvector(v3);

	//n��elem��ʽ
	vector<int>v4;  //����
	v4.assign(10, 100);  //��ֵ
	printvector(v4);
}

//vector�������ʹ�С
void test03() 
{
	cout << "vector�������ʹ�С��" << endl;
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	//�ա���������С
	if (v1.empty()) 
	{
		cout << "v1Ϊ��" << endl;
	}
	else 
	{
		cout << "v1��Ϊ��" << endl;
		cout << "v1������Ϊ��" << v1.capacity() << endl;
		cout << "v1�Ĵ�СΪ��" << v1.size() << endl;
	}

	//���¸���v1�Ĵ�С
	v1.resize(15);  //Ĭ�����ֵ
	printvector(v1);
	v1.resize(20, 100);  //ָ�����ֵ
	printvector(v1);
	v1.resize(10);
	printvector(v1);
}

//�����ɾ��
void test04() 
{
	cout << "vector�Ĳ����ɾ����" << endl;
	//β��
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printvector(v1);

	//βɾ
	v1.pop_back();
	printvector(v1);

	//����
	v1.insert(v1.begin(), 100);  //ͨ��v1.begin()+1�������м����ĳһԪ��
	printvector(v1);
	v1.insert(v1.begin(), 2, 1000);
	printvector(v1);

	//ɾ��
	v1.erase(v1.begin());
	printvector(v1);
	v1.erase(v1.begin(), v1.end());  //==v1.clear();
	printvector(v1);
}

//vector�����ݴ�ȡ
void test05() 
{
	cout << "vector�����ݴ�ȡ��" << endl;
	vector<int>v1;
	for (int i = 0; i < 10; i++) 
	{
		v1.push_back(i);
	}

	//at����operator��[]
	for (int i = 0; i < v1.size(); i++) 
	{
		cout << v1[i] << " ";
		cout << v1.at(i) << " ";
	}
	cout << endl;

	//front()��back()
	cout << "vector�ĵ�һ��Ԫ��Ϊ��" << v1.front() << endl;
	cout << "vector�����һ��Ԫ��Ϊ��" << v1.back() << endl;
}

//vector�Ļ���
void test06() 
{
	cout << "vector�����ݻ�����" << endl;
	vector<int>v1, v2;
	for (int i = 0; i < 10; i++) 
	{
		v1.push_back(i);
	}
	for (int i = 0; i < 5; i++) 
	{
		v2.push_back(i);
	}
	printvector(v1);
	printvector(v2);

	//swap����Ԫ��
	//v1.swap(v1[9], v1[0]);  //���ܽ���Ԫ�أ�д���ˣ���Ӧ����v1.swap
	swap(v1.front(), v1.back());
	printvector(v1);

	//swap����vector
	v1.swap(v2);  //v1��v2����
	printvector(v1);
	printvector(v2);

	//ʵ����;��swap���ÿ���ʵ���ڴ�����
	vector<int>v3;
	for (int i = 0; i < 10000; i++) 
	{
		v3.push_back(i);
	}
	cout << v3.capacity() << endl;  //capacity����size��Ϊ12000����
	cout << v3.size() << endl;  //sizeΪ10000

	v3.resize(3);
	cout << v3.capacity() << endl;  //capacity����
	cout << v3.size() << endl;  //size��Ϊ��3���˷��ڴ�

	vector<int>(v3).swap(v3);  //ʹ��swap���������ڴ棺vector<int>(v3)�Ǵ���һ����v3��size��ͬ����������Ȼ�����������.swap(v3)��v3��������v3�ڴ�����
	cout << v3.capacity() << endl;
	cout << v3.size() << endl;
}

//vector��Ԥ���ռ�
void test07()
{
	cout << "vector��Ԥ���ռ䣺" << endl;
	vector<int>v1;
	//�������
	v1.reserve(10000); //ע�͵�����ٿ���~

	//���Ȳ鿴����10000�����ݣ���Ҫ���¿��ٶ��ٴ��ڴ棬vector���ڴ���������
	int* p = NULL;  //��Ȼv1��vector���͵ģ�����v1[0]��int���͵�
	int num = 0;
	for (int i = 0; i < 10000; i++) 
	{
		v1.push_back(i);
		if (p != &v1[0])   //���ָ��p������v1[0]�ĵ�ַ--˵��v1Ϊ�����ɸ�������ݣ��Զ������������ڴ棬Ҳ����&v1[0]����
		{
			p = &v1[0];
			num++;
		}
	}
	cout << "���ٿռ����Ϊ��" << num << endl;

	//����reserveԤ���ռ䣨��ǰ�棩
}

int main() 
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();

	system("pause");
	return -1;
}