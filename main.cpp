#include <iostream> // 包含输入输出流库
#include <string>	// 包含标准字符串库
#include <cstring>	// 包含C风格字符串处理函数库，提供strlen、memcpy等函数

/**
 * 自定义String类：实现一个简单的字符串类，管理字符串内存
 * 展示C++类的基本概念：构造函数、析构函数、运算符重载、内存管理等
 */
class String
{
private:
	char *m_Buffer;		 // 字符缓冲区指针，指向存储字符串内容的堆内存
	unsigned int m_Size; // 字符串长度（不包含结尾的空字符'\0'）

public:
	/**
	 * 默认构造函数：创建一个空字符串
	 * 初始化列表将成员设为空值
	 * 函数体中创建只包含空字符的字符数组
	 */
	String()
		: m_Buffer(nullptr), m_Size(0)
	{
		m_Buffer = new char[1]; // 分配一个字符的空间
		m_Buffer[0] = '\0';		// 设置为空字符，代表空字符串
	}

	/**
	 * 参数构造函数：通过C风格字符串创建String对象
	 * @param string 指向C风格字符串的指针（以'\0'结尾的字符数组）
	 */
	String(const char *string)
	{
		m_Size = strlen(string);		  // 计算字符串长度（不含'\0'）
		m_Buffer = new char[m_Size + 1];  // 分配内存（+1是为了存储结尾的'\0'）
		memcpy(m_Buffer, string, m_Size); // 从源字符串复制字符到缓冲区
		m_Buffer[m_Size] = 0;			  // 添加字符串结束符，0等同于'\0'
	}

	/**
	 * 拷贝构造函数：通过另一个String对象创建新的String对象
	 * @param other 源String对象的常量引用
	 * 初始化列表直接复制字符串长度
	 */
	String(const String &other)
		: m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];			  // 分配新内存
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1); // 复制字符串内容（包含'\0'）
	}

	/**
	 * 析构函数：释放动态分配的内存
	 * 在对象生命周期结束时自动调用
	 */
	~String()
	{
		delete[] m_Buffer; // 释放字符缓冲区内存
	}

	/**
	 * 重载赋值运算符：将另一个String对象的内容复制到当前对象
	 * @param other 源String对象的常量引用
	 * @return 当前对象的引用，支持连续赋值操作
	 */
	String &operator=(const String &other)
	{
		if (this != &other) // 检查自赋值情况
		{
			delete[] m_Buffer;							  // 释放原有内存
			m_Size = other.m_Size;						  // 复制字符串长度
			m_Buffer = new char[m_Size + 1];			  // 分配新内存
			memcpy(m_Buffer, other.m_Buffer, m_Size + 1); // 复制字符串内容
		}
		return *this; // 返回当前对象的引用
	}

	/**
	 * 获取字符串长度
	 * @return 字符串中的字符数量（不包含结尾的'\0'）
	 */
	unsigned int GetLength() const { return m_Size; }

	/**
	 * 重载下标运算符：访问指定位置的字符（非常量版本）
	 * @param index 字符位置索引
	 * @return 对应位置字符的引用，允许修改
	 */
	char &operator[](unsigned int index)
	{
		return m_Buffer[index]; // 返回指定索引位置的字符引用
	}

	/**
	 * 重载下标运算符：访问指定位置的字符（常量版本）
	 * @param index 字符位置索引
	 * @return 对应位置字符的常量引用，不允许修改
	 */
	const char &operator[](unsigned int index) const
	{
		return m_Buffer[index]; // 返回指定索引位置的字符常量引用
	}

	/**
	 * 获取C风格字符串
	 * @return 指向内部字符缓冲区的常量指针
	 */
	const char *c_str() const
	{
		return m_Buffer; // 返回缓冲区指针，可用于C风格字符串函数
	}

	/**
	 * 声明输出流运算符<<为友元函数
	 * 允许该函数直接访问类的私有成员
	 */
	friend std::ostream &operator<<(std::ostream &stream, const String &string);
};

/**
 * 重载输出流运算符：允许使用cout直接输出String对象
 * @param stream 输出流对象的引用
 * @param string String对象的常量引用
 * @return 输出流对象的引用，支持连续输出操作
 */
std::ostream &operator<<(std::ostream &stream, const String &string)
{
	stream << string.m_Buffer; // 将字符串内容输出到流
	return stream;			   // 返回流对象，支持链式操作
}

/**
 * 主函数：演示String类的基本使用
 */
int main()
{
	// 使用参数构造函数创建字符串
	String s1 = "Hello"; // 隐式调用String(const char*)构造函数

	// 使用拷贝构造函数创建字符串
	String s2 = s1; // 等价于String s2(s1)

	// 输出字符串内容
	std::cout << "s1: " << s1 << std::endl;
	std::cout << "s2: " << s2 << std::endl;

	// 使用默认构造函数和赋值运算符
	String s3; // 创建空字符串
	s3 = s1;   // 调用赋值运算符
	std::cout << "s3: " << s3 << std::endl;

	return 0; // 程序正常结束
}
