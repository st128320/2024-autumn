#include<iostream>

class ArrayList
{
private:
	int len;
	int* data;
	void init(int len = 10)
	{

		this->len = len;
		this->data = (int*)malloc(sizeof(int) * len);
	}
	bool indexValid(int index)
	{
		return 0 <= index < this->len;
	}
public:
	ArrayList(int len = 10)
	{
		this->init(len);
		for (int i = 0; i < this->len; ++i)
		{
			this->data[i] = 0;
		}
	}
	int get(int index)
	{
		if (indexValid(index))
		{
			return this->data[index];
		}
		return -1;
	}
	void set(int index, int value)
	{
		if (indexValid(index))
		{
			this->data[index] = value;
		}
	}
	void expand() 
	{
		int newLen = this->len + 1; 
		int* newData = (int*)malloc(sizeof(int) * newLen);
		if (newData == nullptr)
		{
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < this->len; ++i) 
		{
			newData[i] = this->data[i];
		}
		free(this->data); 
		this->data = newData;
		this->len = newLen;
	}
	ArrayList(ArrayList& list)
	{
		
		this->init(list.len);
		for (int i = 0; i < list.len; ++i)
		{
			this->set(i, list.get(i));
		}
	}
	~ArrayList()
	{
		free(this->data);

	}
	void randomize(int min = 10, int max = 99)
	{
		for (int i = 0; i < len; ++i)
		{
			this->data[i] = rand() % (max - min + 1) + min;
		}
	}
	void print()
	{
		for (int i = 0; i < this->len; ++i)
		{
			printf("%d ", this->data[i]);
		}
		printf("\n");
	}
	void pushBack(int element)
	{
		expand();
		data[len -1] = element;
	}
	void pushFront(int element)
	{
		{
			int newLen = this->len + 1;
			int* newData = (int*)malloc(sizeof(int) * newLen);
			for (int i = 0; i < this->len; ++i)
			{
				newData[i+1] = this->data[i];
			}
			free(this->data);
			newData[0] = element;
			this->data = newData;
			this->len = newLen;
		}
	}
	void insert(int index, int element)
	{
		int newLen = this->len + 1;
		int* newData = (int*)malloc(sizeof(int) * newLen);
		if (newData == nullptr)
		{
			exit(EXIT_FAILURE);
		}
		newData[index-1] = element;
		for (int i = index-1; i < this->len+1; ++i)
		{
			newData[i+1] = this->data[i];
		}
		for (int i = 0; i <index-1; ++i)
		{
			newData[i] = this->data[i];
		}
		this->data = newData;
		this->len = newLen;
	}
	int popBack()
	{
		int a = data[len];
		int newLen = this->len - 1;
		int* newData = (int*)malloc(sizeof(int) * newLen);
		if (newData == nullptr)
		{
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < len - 1; ++i)
		{
			newData[i] = this->data[i];
		}
		free(this->data);
		this->data = newData;
		this->len = newLen;
		return a;
	}
	int popFront()
	{
		int a = this->data[0];
		int newLen = this->len - 1;
		int* newData = (int*)malloc(sizeof(int) * newLen);
		if (newData == nullptr)
		{
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < len - 1; ++i)
		{
			newData[i] = this->data[i+1];
		}
		free(this->data);
		this->data = newData;
		this->len = newLen;
		return a;
	}
	int extract(int index)
	{
		int a = this->data[index-1];
		int newLen = this->len - 1;
		int* newData = (int*)malloc(sizeof(int) * newLen);
		if (newData == nullptr)
		{
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < index-1; ++i)
		{
			newData[i] = this->data[i];
		}
		for (int i = index-1; i < len - 1; ++i)
		{
			newData[i] = this->data[i + 1];
		}
		free(this->data);
		this->data = newData;
		this->len = newLen;
		return a;
	}
	void revers(int start, int end)
	{
		int c = start - 1;
		int k = end - 1;
		int e = 0;
		int l = 0;
		for (int i = 0; i <(c+k)/2+1; ++i)
		{
			e = data[c + i];
			data[c+i] = data[k-i];
			data[k - i] = e;
		}
	}
	int sum()
	{
		int k = 0;
		for (int i = 0; i < len; ++i)
		{
			k += data[i];
		}
		return k;
	}  
	int secondMax()
	{
		int c = 0;
		int mx = data[0];
		int mn = data[0];
		int g = 0;
		int k = 0;
		for (int i = 0; i <len; ++i)
		{
			if (data[i] >= mx)
			{
				mx = data[i];
				k = i;
	
			}
		}
		for (int i = 0; i < len; ++i)
		{
			if (data[i] <= mn)
			{
				mn = data[i];
				g = i;

			}
		}
		c = mx;
	    mx = data[g];
		for (int i = 0; i < len; ++i)
		{
			if (data[i] >= mx and data[i] != c)
			{
				mx = data[i];
			}
		}
		return mx;
	}
	int lastMinIndex()
	{
		int mx=data[0];
		int k=0;
		for (int i = 0; i < len; ++i)
		{
			if (data[i] >= mx)
			{
				mx = data[i];
				k = i+1;

			}
		}
		return k;
	}
	void shift(int k)
	{
		int s = ((k % len) + len) % len;
		int newLen = this->len;
		int* newData = (int*)malloc(sizeof(int) * newLen);
		if (newData == nullptr)
		{
			exit(EXIT_FAILURE);
		}
	    for (int i = 0; i < len; ++i)
		{
			newData[i] = data[(i -s+len) % len];
		}
		free(this->data);
		this->data = newData;
		this->len = newLen;
	}
	int countOdd()
	{
		int c = 0;
		for (int i = 0; i < len; ++i)
		{
			if (data[i] % 2 != 0)
			{
				++c;
			}
		}
		return c;
	}
	int sumEven()
	{
		int sum = 0;
		for (int i = 0; i < len; ++i)
		{
			if (data[i] % 2 == 0)
			{
				sum += data[i];
			}
		}
		return sum;
	}


};