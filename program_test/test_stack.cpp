#include "../Stack/Stack.h"

#include "../google_test/gtest.h"

TEST(TStack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> s(-5));
}

TEST(TStack, cant_pop)
{
	TStack<int> s(1);
	s.ClearStack();

	ASSERT_ANY_THROW(s.Pop());
}

TEST(TStack, cant_top)
{
	TStack<int> s(1);
	s.ClearStack();

	ASSERT_ANY_THROW(s.Top());
}

TEST(TStack, cant_push)
{
	TStack<int> s(1);
	s.PushElem(5);

	ASSERT_ANY_THROW(s.PushElem(6));
}

