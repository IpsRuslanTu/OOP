#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include "../HTMLEncode/functions.h"

SCENARIO("Test function HTMLEncode when no symbols for encoding")
{
	WHEN("input string is empty")
	{
		THEN("output string is empty")
		{
			REQUIRE(HTMLEncode("").empty());
		}
	}
	WHEN("input string no symbols for encoding")
	{
		THEN("output string is no changes")
		{
			REQUIRE(HTMLEncode("s3Uism") == "s3Uism");
		}
	}
}

SCENARIO("Test function HTMLEncode when input string with only 1 encoding symbol")
{
	WHEN("input string has only symbol \" ")
	{
		THEN("output string is &quot;")
		{
			REQUIRE(HTMLEncode("\"") == "&quot;");
		}
	}
	WHEN("input string has only symbol \' ")
	{
		THEN("output string is &apos;")
		{
			REQUIRE(HTMLEncode("\'") == "&apos;");
		}
	}
	WHEN("input string has only symbol '<'")
	{
		THEN("output string is &lt;")
		{
			REQUIRE(HTMLEncode("<") == "&lt;");
		}
	}
	WHEN("input string has only symbol '>'")
	{
		THEN("output string is &gt;")
		{
			REQUIRE(HTMLEncode(">") == "&gt;");
		}
	}
	WHEN("input string has only symbol '&'")
	{
		THEN("output string is &amp;")
		{
			REQUIRE(HTMLEncode("&") == "&amp;");
		}
	}
}

SCENARIO("Test function HTMLEncode with mixed string")
{
	REQUIRE(HTMLEncode("Cat <says> \"Meow\". M&M's") == 
		"Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s");
}