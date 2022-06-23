#define BOOST_TEST_MODULE Test_CMyStack
#include <boost/test/included/unit_test.hpp>
#include "../MyStack/CMyStack.h"
#include <stdexcept>

struct EmptyIntStackFixture
{
	CMyStack<int> stack;

	EmptyIntStackFixture()
		: stack()
	{}
};

BOOST_FIXTURE_TEST_SUITE(test_empty_int_cmystack, EmptyIntStackFixture)

BOOST_AUTO_TEST_CASE(method_isEmpty_return_true_when_stack_empty)
{
	BOOST_CHECK(stack.IsEmpty());
}

BOOST_AUTO_TEST_CASE(method_top_must_return_logic_error_when_stack_is_empty)
{
	BOOST_CHECK_THROW(stack.Top(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(method_pop_must_return_logic_error_when_stack_is_empty)
{
	BOOST_CHECK_THROW(stack.Pop(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(test_method_push_stack_has_passed_value_in_top)
{
	stack.Push(33);
	BOOST_CHECK_EQUAL(stack.Top(), 33);
	stack.Push(12);
	BOOST_CHECK_EQUAL(stack.Top(), 12);
}

BOOST_AUTO_TEST_CASE(method_clear_does_stack_empty)
{
	stack.Clear();
	BOOST_CHECK(stack.IsEmpty());
}

BOOST_AUTO_TEST_SUITE_END()


struct EmptyStackFixture
{
	CMyStack<int> stack;

	EmptyStackFixture()
		: stack()
	{}
};

struct EmptyStringStackFixture
{
	CMyStack<std::string> stack;

	EmptyStringStackFixture()
		: stack()
	{}
};

BOOST_FIXTURE_TEST_SUITE(test_empty_string_cmystack, EmptyStringStackFixture)

BOOST_AUTO_TEST_CASE(method_isEmpty_return_true_when_stack_empty)
{
	BOOST_CHECK(stack.IsEmpty());
}

BOOST_AUTO_TEST_CASE(test_push_and_pop_string)
{
	stack.Push("hello");
	BOOST_CHECK_EQUAL(stack.Top(), "hello");
	stack.Push("bye");
	BOOST_CHECK_EQUAL(stack.Top(), "bye");
	stack.Pop();
	BOOST_CHECK_EQUAL(stack.Top(), "hello");
	stack.Pop();
	BOOST_CHECK(stack.IsEmpty());
}

BOOST_AUTO_TEST_SUITE_END()


struct FullStringStackFixture
{
	CMyStack<std::string> stack;

	FullStringStackFixture()
		: stack()
	{}

	std::stringstream stream;
};

void PushTwoElementsInStack(CMyStack<std::string>& stack)
{
	stack.Push("hello");
	stack.Push("bye");
}

BOOST_FIXTURE_TEST_SUITE(test_full_string_cmystack, FullStringStackFixture)

BOOST_AUTO_TEST_CASE(test_copy_constructor)
{
	PushTwoElementsInStack(stack);
	BOOST_CHECK(!stack.IsEmpty());

	CMyStack<std::string> stack2(stack);

	BOOST_CHECK_EQUAL(stack.Top(), "bye");
	BOOST_CHECK_EQUAL(stack2.Top(), "bye");

	stack.Clear();

	BOOST_CHECK(stack.IsEmpty());
	BOOST_CHECK_EQUAL(stack2.Top(), "bye");
}

BOOST_AUTO_TEST_CASE(test_move_constructor)
{
	PushTwoElementsInStack(stack);
	BOOST_CHECK(!stack.IsEmpty());

	CMyStack<std::string> stack2 = std::move(stack);

	BOOST_CHECK(stack.IsEmpty());
	BOOST_CHECK(!stack2.IsEmpty());
	BOOST_CHECK_EQUAL(stack2.Top(), "bye");
}

BOOST_AUTO_TEST_SUITE_END()