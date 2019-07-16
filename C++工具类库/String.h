#pragma once
#include<iostream>

class String
{
private:

	char* data;

public:

	//************************************
	// Method:     String 
	// Description: 普通构造函数(由字符常量)
	//				语句【 String str = "123" 】是调用此构造函数
	// Parameter:  const char * src - 
	// Returns:     - 
	//************************************
	String(const char* src = NULL)
	{
		//复制src字符串的内容
		if (src == NULL)
		{
			this->data == NULL;
		}
		else
		{
			this->data = (char*)malloc(strlen(src) + 1);	//加一是为了终止符'\0'
			memset(this->data, 0x0, strlen(src) + 1);
			strcpy(this->data, src);
		}

	}

	//************************************
	// Method:     String 
	// Description: 拷贝构造函数
	//				拷贝构造函数是一种特殊的构造函数，函数的名称必须和类名称一致，它必须的一个参数是本类型的一个引用变量。
	//				拷贝构造函数的调用时机：
	//				1.当某函数的返回类型是该类对象。
	//				2.当对象需要通过另外一个对象进行初始化。例如语句【String str2 = str】的str2对象的通过str对象初始化
	// Parameter:  String & src - 
	// Returns:     - 
	//************************************
	String(const String& src)
	{
		if (this != &src)
		{
			//复制src字符串的内容
			if (src.data == NULL)
			{
				this->data == NULL;
			}
			else
			{
				this->data = (char*)malloc(strlen(src.data) + 1);	//加一是为了终止符'\0'
				memset(this->data, 0x0, strlen(src.data) + 1);
				strcpy(this->data, src.data);
			}
		}

	}

	//************************************
	// Method:     ~String 
	// Description: 析构函数
	//				当对象生命周期结束时调用(当函数return时，存于栈内的对象自动调用析构函数，存于堆中的对象(即new出来的)需要手动delete)
	// Returns:     -  
	//************************************
	~String()
	{
		free(this->data);
		data = NULL;
	}

	//************************************
	// Method:     operator= 
	// Description: 赋值运算符（由对象）
	//				语句【 str1 = str2 】是调用此运算符。注意：语句【 String str1 = str2 】并未使用运算符重载，而是调用了拷贝构造。
	// Parameter:  const String & right - 
	// Returns:    String - 
	//************************************
	String operator=(const String& right)
	{
		//释放
		free(this->data);
		this->data = NULL;
		//赋值
		this->data = (char*)malloc(strlen(right.data) + 1);
		memset(this->data, 0, strlen(right.data) + 1);
		strcpy(this->data, right.data);

		//先调用拷贝构造函数：将局部变量newStr的地址传入，将newStr的各成员数据拷贝到一个新的[临时对象]中
		//随后返回的是[临时对象]
		return *this;
		//本函数结束后调用[临时对象]的析构函数结束其生命周期
	}

	//************************************
	// Method:     operator= 
	// Description: 重载赋值运算符（由字符常量）
	//				语句【 str = "123" 】是调用此运算符
	// Parameter:  const char * right -
	// Returns:    String -
	//************************************
	String operator=(const char* right)
	{
		//释放原有字符串
		free(this->data);
		this->data = NULL;

		//重新赋值：拷贝src字符串的内容
		if (right == NULL)
		{
			data == NULL;
		}
		else
		{
			int len = strlen(right);
			char* temp = (char*)malloc(len + 1);	//加一是为了终止符'\0'
			data = temp;
			memset(data, 0x0, strlen(right) + 1);
			strcpy(data, right);
		}

		//先调用拷贝构造函数：将局部变量newStr的地址传入，将newStr的各成员数据拷贝到一个新的[临时对象]中
		//随后返回的是[临时对象]
		return *this;
		//本函数结束后调用[临时对象]的析构函数结束其生命周期
	}

	//************************************
	// Method:     operator+ 
	// Description: 重载运算符'+'：成员函数(由字符常量)
	//				语句【String newStr = str + "123"】将调用此运算符 operator + ("123")
	// Parameter:  const char * right - 
	// Returns:    String& - 
	//************************************
	String operator+(const char* right)
	{
		//创建新对象
		String newStr;
		newStr.data = (char*)malloc(strlen(this->data) + strlen(right) + 1);
		memset(newStr.data, 0x0, strlen(this->data) + strlen(right) + 1);

		//拼接
		strcat(newStr.data, this->data);
		strcat(newStr.data, right);

		//先调用拷贝构造函数：将局部变量newStr的地址传入，将newStr的各成员数据拷贝到一个新的[临时对象]中
		//随后调用newStr对象的析构函数结束其生命周期
		//最后返回的是[临时对象]
		return newStr;
	}


	//************************************
	// Method:     operator+ 
	// Description: 重载运算符'+'：成员函数(由对象)
	// Parameter:  const String & str - 
	// Returns:    String - 
	//************************************
	String operator+(const String& right)
	{
		String newString;

		//只要左右有一边为NULL空串，就不需要拼接
		if (right.data == NULL)
		{
			return *this;
		}
		else if (this->data == NULL)
		{
			newString = right;
		}
		else
		{
			//拼接
			newString.data = (char*)malloc(strlen(right.data) + strlen(this->data) + 1);
			memset(newString.data, 0, strlen(right.data) + strlen(this->data) + 1);
			strcat(newString.data, this->data);
			strcat(newString.data, right.data);
		}

		//先调用拷贝构造函数：将局部变量newStr的地址传入，将newStr的各成员数据拷贝到一个新的[临时对象]中
		//随后调用newStr对象的析构函数结束其生命周期
		//最后返回的是[临时对象]
		return newString;
	}



	//************************************
	// Method:     operator+ 
	// Description: 重载运算符'+'：友元函数
	//				当运算符重载为类的友元函数时，没有隐含的this指针，所有的操作数都必须通过函数的形参进行传递，函数的参数与操作数自左至右一一对应。 
	//				语句【String newStr = "123" + str】将调用此运算符 operator + ("123",str)
	// Parameter:  const char * left - 字符常量
	// Parameter:  const String & right - String对象
	// Returns:    friend char*
	//************************************
	friend String operator+(const char* left, String& right)
	{
		//申请新的堆内存
		String newStr;
		newStr.data = (char*)malloc(strlen(left) + strlen(right.data) + 1);
		memset(newStr.data, 0x0, strlen(left) + strlen(right.data) + 1);

		//拼接
		strcat(newStr.data, left);
		strcat(newStr.data, right.data);

		//先调用拷贝构造函数：将局部变量newStr的地址传入，将newStr的各成员数据拷贝到一个新的[临时对象]中
		//随后调用newStr对象的析构函数结束其生命周期
		//最后返回的是[临时对象]
		return newStr;
	}

	//************************************
	// Method:     ToPChar 
	// Description: String 转为 char*
	// Returns:    char* -  
	//************************************
	char* ToPChar()
	{
		//返回指针
		return this->data;
	}

	char* SubString(int beginIndex, int endIndex)
	{

	}

	//************************************
	// Method:     SubString 
	// Description: 截取字符串
	// Parameter:  int beginIndex - 起始索引，索引从0开始
	// Returns:    char* -  
	//************************************
	String SubString(int beginIndex)
	{
		//边界检查
		int strLen = strlen(this->data);
		if (beginIndex > strLen) { throw  "【exception】索引越界"; }

		//构造一个新的String 
		String newStr;
		newStr.data = (char*)malloc(strLen - beginIndex + 1);
		memset(newStr.data, 0x0, strLen - beginIndex + 1);

		//截取
		memcpy(newStr.data, this->data + beginIndex, strLen - beginIndex + 1);

		//先调用拷贝构造函数：将局部变量newStr的地址传入，将newStr的各成员数据拷贝到一个新的[临时对象]中
		//随后调用newStr对象的析构函数结束其生命周期
		//最后返回的是[临时对象]
		return newStr;
	}

	//************************************
	// Method:     ToUpper 
	// Description:转为大写字母str
	// Returns:    String - 
	//************************************
	String ToUpper()
	{
		String newStr = String(this->data);
		char* cursor = newStr.data;
		while (*cursor != 0)
		{
			if (*cursor >= 'a' && *cursor <= 'z')
			{
				*cursor -= 32;//根据ASCII码
			}
			cursor++;
		}
		return newStr;
	}

	//************************************
	// Method:     ToLower 
	// Description:转为小写字母str
	// Returns:    String - 
	//************************************
	String ToLower()
	{
		String newStr = String(this->data);
		char* cursor = newStr.data;
		while (*cursor != 0)
		{
			if (*cursor >= 'A' && *cursor <= 'Z')
			{
				*cursor += 32;//根据ASCII码
			}
			cursor++;
		}
		return newStr;
	}
};



