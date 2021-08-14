#include<iostream>
#include<vector>
using namespace std;
//vector是数组，和C++自带数组的区别就是：普通数组是静态空间，而vector可以动态扩展
//vector有push_back、pop_back、front、back等指令，有v.begin()\v.end()\v.rbegin()\v.rend()等迭代器

void printvector(vector<int>& v)   //引用接收！！！
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)   //vector的迭代器使用
	{
		cout << *it << " ";  //it和this类似，迭代器是指针
	}
	cout << endl;
}

//vector构造
void test01() 
{
	cout << "vector构造：" << endl;
	//默认构造 无参构造
	vector<int>v1;
	for (int i = 0; i < 10; i++) 
	{
		v1.push_back(i);
	}
	printvector(v1);

	//通过区间方式进行构造
	vector<int>v2(v1.begin(), v1.end());  //类似于拷贝构造
	printvector(v2);

	//n个elem方式构造
	vector<int>v3(10, 100);  //10个100
	printvector(v3);

	//拷贝构造
	vector<int>v4(v3);
	printvector(v4);
}

//vector赋值
void test02() 
{
	cout << "vector赋值：" << endl;
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	//赋值  operator= 等号运算符重载
	vector<int>v2;
	v2 = v1;
	printvector(v2);

	//assign
	vector<int>v3;
	v3.assign(v2.begin(), v2.end());
	printvector(v3);

	//n个elem方式
	vector<int>v4;  //构造
	v4.assign(10, 100);  //赋值
	printvector(v4);
}

//vector的容量和大小
void test03() 
{
	cout << "vector的容量和大小：" << endl;
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	//空、容量、大小
	if (v1.empty()) 
	{
		cout << "v1为空" << endl;
	}
	else 
	{
		cout << "v1不为空" << endl;
		cout << "v1的容量为：" << v1.capacity() << endl;
		cout << "v1的大小为：" << v1.size() << endl;
	}

	//重新更改v1的大小
	v1.resize(15);  //默认填充值
	printvector(v1);
	v1.resize(20, 100);  //指定填充值
	printvector(v1);
	v1.resize(10);
	printvector(v1);
}

//插入和删除
void test04() 
{
	cout << "vector的插入和删除：" << endl;
	//尾插
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printvector(v1);

	//尾删
	v1.pop_back();
	printvector(v1);

	//插入
	v1.insert(v1.begin(), 100);  //通过v1.begin()+1可以在中间插入某一元素
	printvector(v1);
	v1.insert(v1.begin(), 2, 1000);
	printvector(v1);

	//删除
	v1.erase(v1.begin());
	printvector(v1);
	v1.erase(v1.begin(), v1.end());  //==v1.clear();
	printvector(v1);
}

//vector的数据存取
void test05() 
{
	cout << "vector的数据存取：" << endl;
	vector<int>v1;
	for (int i = 0; i < 10; i++) 
	{
		v1.push_back(i);
	}

	//at或者operator即[]
	for (int i = 0; i < v1.size(); i++) 
	{
		cout << v1[i] << " ";
		cout << v1.at(i) << " ";
	}
	cout << endl;

	//front()与back()
	cout << "vector的第一个元素为：" << v1.front() << endl;
	cout << "vector的最后一个元素为：" << v1.back() << endl;
}

//vector的互换
void test06() 
{
	cout << "vector的数据互换：" << endl;
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

	//swap交换元素
	//v1.swap(v1[9], v1[0]);  //不能交换元素，写错了，不应该是v1.swap
	swap(v1.front(), v1.back());
	printvector(v1);

	//swap交换vector
	v1.swap(v2);  //v1与v2互换
	printvector(v1);
	printvector(v2);

	//实际用途：swap巧用可以实现内存收缩
	vector<int>v3;
	for (int i = 0; i < 10000; i++) 
	{
		v3.push_back(i);
	}
	cout << v3.capacity() << endl;  //capacity大于size，为12000左右
	cout << v3.size() << endl;  //size为10000

	v3.resize(3);
	cout << v3.capacity() << endl;  //capacity不变
	cout << v3.size() << endl;  //size变为了3，浪费内存

	vector<int>(v3).swap(v3);  //使用swap巧妙收缩内存：vector<int>(v3)是创建一个和v3的size相同的匿名对象，然后该匿名对象.swap(v3)与v3互换，将v3内存收缩
	cout << v3.capacity() << endl;
	cout << v3.size() << endl;
}

//vector的预留空间
void test07()
{
	cout << "vector的预留空间：" << endl;
	vector<int>v1;
	//看最后面
	v1.reserve(10000); //注释掉这句再看看~

	//首先查看插入10000个数据，需要重新开辟多少次内存，vector的内存是连续的
	int* p = NULL;  //虽然v1是vector类型的，但是v1[0]是int类型的
	int num = 0;
	for (int i = 0; i < 10000; i++) 
	{
		v1.push_back(i);
		if (p != &v1[0])   //如果指针p不等于v1[0]的地址--说明v1为了容纳更多的数据，自动更换连续的内存，也就是&v1[0]变了
		{
			p = &v1[0];
			num++;
		}
	}
	cout << "开辟空间次数为：" << num << endl;

	//利用reserve预留空间（放前面）
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