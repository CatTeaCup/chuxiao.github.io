#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

//deque相当于一个双端vector，是队列。最重要的是可以头插和头删，push_front、pop_front、push_back、pop_back、front、back、insert都是它的函数
//deque不像vector是一段连续的线性空间，deque在头部插入删除速度很快，vector需要移动后面的所有元素；vector访问元素特别快，deque慢一点--
//deque的实现原理是在其内部有一个中控器来记录所有的缓冲区地址，每一段缓冲区都能保存多个元素，所以deque不是连续的空间，而是通过中控器记录缓冲区的地址，然后缓冲区内存储元素
void printdeque(const deque<int>& d)  //加了const，不能修改值
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)  //加了const后，迭代器需要变为const_iterator 
	{
		//*it = 10;  //加了const后不能修改值
		cout << *it << " ";
	}
	cout << endl;
}

//deque构造函数
void test01() 
{
	cout << "deque构造函数：" << endl;
	//无参构造
	deque<int>d1;
	for (int i = 0; i < 10; i++) 
	{
		d1.push_front(i);
	}
	printdeque(d1);

	//
	deque<int>d2(d1.begin(),d1.end());
	printdeque(d2);

	//拷贝构造
	deque<int>d3(d2);

	//
	deque<int>d4(10, 100);
	printdeque(d4);
}

//deque赋值
void test02() 
{
	cout << "deque赋值：" << endl;
	deque<int>d1;
	for (int i = 0; i < 10; i++) 
	{
		d1.push_front(i);
	}

	//等号赋值
	deque<int>d2;
	d2 = d1;
	printdeque(d2);

	//assign赋值
	deque<int>d3;
	d3.assign(d2.begin(), d2.end());
	printdeque(d3);

	deque<int>d4;
	d4.assign(10, 100);
	printdeque(d4);
}

//deque大小
void test03() 
{
	cout << "deque大小：" << endl;
	deque<int>d1;
	for (int i = 0; i < 10; i++) 
	{
		d1.push_back(i);
	}
	printdeque(d1);

	//没有capacity，因为不连续空间
	//empty、size
	if (!d1.empty()) 
	{
		cout << "d1不为空" << endl;
		cout << "d1的大小为：" << d1.size() << endl;
	}

	//resize
	d1.resize(15);
	printdeque(d1);
	d1.resize(20, 100);  //指定填充值
	printdeque(d1);
}

//deque的插入和删除
void test04() 
{
	cout << "deque的插入和删除：" << endl;
	deque<int>d1;
	//尾插
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	//头插
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	printdeque(d1);
	//尾删
	d1.pop_back();
	//头删
	d1.pop_front();
	printdeque(d1);

	//insert
	d1.insert(d1.begin(), 2, 10000);  //迭代器
	printdeque(d1);
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	d1.insert(d1.begin(), d2.begin(), d2.end());  //迭代器
	printdeque(d1);

	//erase
	deque<int>::iterator it = d1.begin();
	it++;  //设置迭代器位置
	d1.erase(it, d1.end());
	printdeque(d1);
}

//deque的数据存取
void test05()
{
	cout << "deque的数据存取：" << endl;
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	//[]方式访问数据
	for(int i = 0;i<d1.size();i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;
	//at()方式访问数据
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

//deque的排序
void test06()
{
	cout << "deque的排序：" << endl;
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	//sort：除了deque，vector也可以使用algorithm中的sort来进行排序
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