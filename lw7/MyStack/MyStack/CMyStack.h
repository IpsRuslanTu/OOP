#include "stdafx.h"
#pragma once

template<typename T>
class CMyStack
{
public:
	CMyStack() = default;
	~CMyStack() {};

	CMyStack(const CMyStack& other)
	{
		m_top = other.m_top;
		m_size = other.m_size;
	}

	CMyStack(CMyStack&& other) noexcept
		: m_top(nullptr)
		, m_size(0)
	{
		*this = std::move(other);
	}

	CMyStack& operator=(const CMyStack& other)
	{
		if (this != &other)
		{
			CMyStack temp(other);
			std::swap(m_top, temp.m_top);
			std::swap(m_size, temp.m_size);
		}
		return *this;
	}

	CMyStack& operator=(CMyStack&& other) noexcept
	{
		m_top = std::move(other.m_top);
		m_size = std::move(other.m_size);
		return *this;
	}

	void Push(T value)
	{
		Node node = { value, m_top };
		m_top = std::make_shared<Node>(node);
		++m_size;
	}

	void Pop()
	{
		if (IsEmpty())
		{
			throw std::logic_error("stack is empty");
		}

		m_top = m_top->next;
		--m_size;
	}

	T Top()
	{
		if (IsEmpty())
		{
			throw std::logic_error("stack is empty");
		}

		return m_top->value;
	}

	bool IsEmpty()
	{
		return m_top == nullptr;
	}

	void Clear()
	{
		while (m_top != nullptr)
		{
			m_top = m_top->next;
		}
		m_size = 0;
	}

private:
	struct Node
	{
		Node(T value, std::shared_ptr<Node> const& pointer)
			: value(value)
			, next(pointer)
		{
		}

		~Node()
		{
		}

		T value;
		std::shared_ptr<Node> next;
	};

	std::shared_ptr<Node> m_top = nullptr;
	unsigned m_size = 0;
};