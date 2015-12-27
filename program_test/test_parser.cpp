#include "../Calc/Parser.h"
#include "../google_test/gtest.h"

TEST(TParser, division_by_zero)
{
	TParser t("2/0");
	t.InfToPost();

	ASSERT_ANY_THROW(t.calcPost());
}