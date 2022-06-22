#include "CStringStack.h"

CStringStack::CStringStack()
{
}

CStringStack::~CStringStack() = default;

void CStringStack::Push(const std::string& str)
{
	m_top = std::make_shared<Node>(str, m_top);
	++m_size;
}

unsigned CStringStack::Size()const
{
	return m_size;
}

void CStringStack::Pop()
{
	if (IsEmpty())
	{
		throw std::logic_error("Stack is empty");
	}
	m_top = m_top->next;
	--m_size;
}

bool CStringStack::IsEmpty()const
{
	return m_top == nullptr;
}

std::string CStringStack::Top()const
{
	if (IsEmpty())
	{
		throw std::logic_error("Stack is empty");
	}
	return m_top->str;
}

void CStringStack::Display(std::ostream& stream)
{
	if (IsEmpty())
	{
		throw std::logic_error("Stack is empty");
	}

	std::shared_ptr<Node> ptr = m_top;

	while (ptr != nullptr)
	{
		stream << ptr->str << std::endl;
		ptr = ptr->next;
	}
}

void CStringStack::Clear()
{
	while (m_top != nullptr)
	{
		m_top = m_top->next;
	}
	m_size = 0;
}