#pragma once

#pragma warning (disable : 4251)

#include <iostream>
#include <vector>

template <typename T>
class List
{
public:
	List()
		: capacity(2)
	{
		data = new T[capacity];
		memset(data, 0, sizeof(T) * capacity);
	}

	List(List&& other) noexcept
		: data(other.data), size(other.size), capacity(other.capacity)
	{
		other.data = nullptr;
		other.size = 0;
		other.capacity = 0;
	}

	~List()
	{
		if (data != nullptr)
		{
			delete[] data;
		}
	}

	List<T>& operator=(List&& other) noexcept
	{
		if (this != &other)
		{
			if (data != nullptr)
			{
				delete[] data;
			}

			data = other.data;
			size = other.size;
			capacity = other.capacity;

			other.data = nullptr;
			other.size = 0;
			other.capacity = 0;
		}
		return *this;
	}

	List(const List& other)
		: capacity(other.capacity), size(other.size)
	{
		// 새로운 메모리 블록 할당
		data = new T[capacity];
		// 데이터 복사
		for (int ix = 0; ix < size; ++ix)
		{
			data[ix] = other.data[ix];
		}
	}

	List& operator=(const List& other)
	{
		if (this != &other)
		{
			if (data != nullptr)
			{
				delete[] data;
			}

			capacity = other.capacity;
			size = other.size;
			data = new T[capacity];

			for (int ix = 0; ix < size; ++ix)
			{
				data[ix] = other.data[ix];
			}
		}
		return *this;
	}

	void PushBack(const T& value)
	{
		if (size == capacity)
		{
			ReAllocate(capacity * 2);
		}

		data[size] = value;
		size++;
	}

	void PushBack(T&& value)
	{
		if (size == capacity)
		{
			ReAllocate(capacity * 2);
		}

		data[size] = std::move(value);
		size++;
	}

	void Clear()
	{
		size = 0;
	}

	void Erase(int index)
	{
		// 예외 처리.
		if (index < 0 || index >= size)
		{
			__debugbreak();
		}

		// 삭제한 데이터의 인덱스 다음 위치를 한칸 앞으로 모두 이동.
		for (int ix = index; ix < size - 1; ++ix)
		{
			data[ix] = std::move(data[ix + 1]);
		}

		// 삭제 후 크기 줄이기.
		--size;
	}

	int Size() const
	{
		return size;
	}

	int Capacity() const
	{
		return capacity;
	}

	const T& operator[](int index) const
	{
		if (index >= size)
		{
			__debugbreak();
		}

		return data[index];
	}

	T& operator[](int index)
	{
		if (index >= size)
		{
			__debugbreak();
		}

		return data[index];
	}

	T* begin() const
	{
		return data;
	}

	T* end() const
	{
		return data + size;
	}

private:
	void ReAllocate(int newCapacity)
	{
		T* newBlock = new T[newCapacity];

		if (newCapacity < size)
		{
			size = newCapacity;
		}

		for (int ix = 0; ix < size; ++ix)
		{
			newBlock[ix] = std::move(data[ix]);
		}

		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}

private:
	T* data = nullptr;
	int size = 0;
	int capacity = 0;
};