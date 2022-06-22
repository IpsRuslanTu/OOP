#include "stdafx.h"
#include "../StringStack/CStringStack.h"

struct CStringEmptyStackFixture
{
	CStringEmptyStackFixture()
		: ss()
	{
	}
	CStringStack ss;
};

BOOST_FIXTURE_TEST_SUITE(Test_empty_stack, CStringEmptyStackFixture)

BOOST_AUTO_TEST_CASE(test_new_empty_stack_result_isEmpty_must_be_true)
{
	BOOST_CHECK(ss.IsEmpty());
}

BOOST_AUTO_TEST_CASE(test_new_empty_stack_size_must_be_0)
{
	BOOST_CHECK_EQUAL(ss.Size(), 0);
}

BOOST_AUTO_TEST_CASE(empty_stack_hasnt_top_throw_exception)
{
	BOOST_CHECK_THROW(ss.Top(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(empty_stack_pop_method_throw_exception)
{
	BOOST_CHECK_THROW(ss.Pop(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(empty_stack_display_method_throw_exception)
{
	BOOST_CHECK_THROW(ss.Display(std::cout), std::logic_error);
}

BOOST_AUTO_TEST_CASE(push_string_in_empty_stack_top_must_return_this_string)
{
	ss.Push("hello");
	BOOST_CHECK_EQUAL(ss.Top(), "hello");
}

BOOST_AUTO_TEST_CASE(push_string_in_empty_stack_size_must_be_1)
{
	ss.Push("hello");
	BOOST_CHECK_EQUAL(ss.Size(), 1);
}

BOOST_AUTO_TEST_CASE(push_string_in_empty_stack_display_print_message_in_stream)
{
	std::stringstream stream;
	ss.Push("hello");
	ss.Display(stream);
	BOOST_CHECK_EQUAL(stream.str(), "hello\n");
}

BOOST_AUTO_TEST_CASE(push_string_in_empty_stack_isEmpty_must_return_false)
{
	ss.Push("hello");
	BOOST_CHECK(!ss.IsEmpty());
}

BOOST_AUTO_TEST_CASE(pop_string_from_1value_stack__stack_must_be_empty)
{
	ss.Push("hello");
	BOOST_CHECK(!ss.IsEmpty());
	ss.Pop();
	BOOST_CHECK(ss.IsEmpty());
}

BOOST_AUTO_TEST_SUITE_END()


struct CStringNewStackFixture
{
	CStringNewStackFixture()
		: ss()
	{
	}
	CStringStack ss;

	std::stringstream stream;
};

void PushTwoElementsInStack(CStringStack& stack)
{
	stack.Push("hello");
	stack.Push("bye");
}

BOOST_FIXTURE_TEST_SUITE(Test_2_elements_stack, CStringNewStackFixture)

BOOST_AUTO_TEST_CASE(size_of_stack_with_2_elemens_must_be_2)
{
	PushTwoElementsInStack(ss);
	BOOST_CHECK_EQUAL(ss.Size(), 2);
}

BOOST_AUTO_TEST_CASE(pop_2_strings_stack_must_be_empty)
{
	PushTwoElementsInStack(ss);
	BOOST_CHECK_EQUAL(ss.Top(), "bye");
	ss.Pop();
	BOOST_CHECK_EQUAL(ss.Size(), 1);
	BOOST_CHECK_EQUAL(ss.Top(), "hello");
	ss.Pop();
	BOOST_CHECK_EQUAL(ss.Size(), 0);
	BOOST_CHECK(ss.IsEmpty());
}

BOOST_AUTO_TEST_CASE(display_stack)
{
	BOOST_CHECK_THROW(ss.Display(stream), std::logic_error);
	PushTwoElementsInStack(ss);
	ss.Display(stream);
	BOOST_CHECK_EQUAL(stream.str(), "bye\nhello\n");
}

BOOST_AUTO_TEST_CASE(after_clear_stack_stack_must_be_empty)
{
	PushTwoElementsInStack(ss);
	BOOST_CHECK_EQUAL(ss.Size(), 2);
	BOOST_CHECK(!ss.IsEmpty());
	ss.Clear();
	BOOST_CHECK(ss.IsEmpty());
	BOOST_CHECK_EQUAL(ss.Size(), 0);
}

BOOST_AUTO_TEST_CASE(test_copy_constructor)
{
	PushTwoElementsInStack(ss);
	BOOST_CHECK(!ss.IsEmpty());

	CStringStack ss2(ss);
	ss2.Display(stream);

	BOOST_CHECK_EQUAL(ss2.Size(), 2);
	BOOST_CHECK_EQUAL(stream.str(), "bye\nhello\n");

	ss.Clear();

	BOOST_CHECK(ss.IsEmpty());
	BOOST_CHECK_EQUAL(ss.Size(), 0);

	std::stringstream stream2;
	ss2.Display(stream2);

	BOOST_CHECK_EQUAL(stream2.str(), "bye\nhello\n");
}

BOOST_AUTO_TEST_CASE(test_move_constructor)
{
	PushTwoElementsInStack(ss);
	BOOST_CHECK(!ss.IsEmpty());

	CStringStack ss2 = std::move(ss);
	ss2.Display(stream);

	BOOST_CHECK(ss.IsEmpty());
	BOOST_CHECK(!ss2.IsEmpty());
	BOOST_CHECK_EQUAL(stream.str(), "bye\nhello\n");
}

BOOST_AUTO_TEST_SUITE_END()