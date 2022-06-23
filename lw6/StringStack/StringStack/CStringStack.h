#include "stdafx.h"
#pragma once

class CStringStack
{
public:
	CStringStack();
	~CStringStack();

	CStringStack& operator=(const CStringStack& other)
	{
		if (this != &other)
		{
			CStringStack temp(other);
			std::swap(m_top, temp.m_top);
			std::swap(m_size, temp.m_size);
		}
		return *this;
	}

	CStringStack& operator=(CStringStack&& other) noexcept
	{
		m_top = std::move(other.m_top);
		m_size = std::move(other.m_size);
		return *this;
	}

	CStringStack(const CStringStack& other)
	{
		m_top = other.m_top;
		m_size = other.m_size;
	}

	CStringStack(CStringStack&& other) noexcept
		: m_top(nullptr)
		, m_size(0)
	{
		*this = std::move(other);
	}

	void Push(const std::string &str);
	void Pop();
	bool IsEmpty()const;
	std::string Top()const;
	void Display(std::ostream& stream);
	void Clear();
	unsigned Size()const;

private:
	struct Node
	{
		std::string str;
		std::shared_ptr<Node> next;

		Node(std::string value, std::shared_ptr<Node> const& pointer)
			: str(value)
			, next(pointer)
		{
		}
	};
	std::shared_ptr<Node> m_top;
	unsigned m_size = 0;
};
