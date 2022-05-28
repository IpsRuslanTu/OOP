#include "stdafx.h"
#include "../TV/CRemoteControl.h"
#include "../TV/CTVSet.h"
#include <sstream>
#include <boost/optional.hpp>

using namespace std;
using boost::optional;
using boost::none;

// Зависимости RemoteControl-а вынесены в родительскую структуру,
// чтобы гарантировать их создание до конструирования самого remote-контрола
struct RemoteControlDependencies
{
	CTVSet tv;
	stringstream input;
	stringstream output;
};

struct RemoteControlFixture : RemoteControlDependencies
{
	CRemoteControl remoteControl;

	RemoteControlFixture()
		: remoteControl(tv, input, output)
	{
	}

	// Вспомогательная функция для проверки работы команды command
	// Она принимает ожидаемый номер канала expectedChannel и expectedOutput
	void VerifyCommandHandling(const string& command, const optional<int>& expectedChannel, const string& expectedOutput)
	{
		// Предварительно очищаем содержимое выходного потока
		output = stringstream();
		input = stringstream();
		BOOST_CHECK(input << command);
		BOOST_CHECK(remoteControl.HandleCommand());
		BOOST_CHECK_EQUAL(tv.IsTurnedOn(), expectedChannel.is_initialized());
		BOOST_CHECK_EQUAL(tv.GetChannel(), expectedChannel.get_value_or(0));
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}
};

BOOST_FIXTURE_TEST_SUITE(Remote_Control, RemoteControlFixture)

BOOST_AUTO_TEST_CASE(can_handle_TurnOn_command)
{
	VerifyCommandHandling("TurnOn", 1, "TV is turned on\n");
}

BOOST_AUTO_TEST_CASE(can_turn_off_tv_which_is_on)
{
	tv.TurnOn();
	VerifyCommandHandling("TurnOff", none, "TV is turned off\n");
}

// Проверка работы Info
BOOST_AUTO_TEST_CASE(can_print_tv_info)
{
	// Ожидаемое поведение команды Info, вызванной у выключенного телевизора
	VerifyCommandHandling("Info", none, "TV is turned off\n");

	// Проверяем поведение команды Info у включенного телевизора
	tv.TurnOn();
	tv.SelectChannel(42);
	VerifyCommandHandling("Info", 42, "TV is turned on\nChannel is: 42\n");
}

// Проверка работы SelectChannel
BOOST_AUTO_TEST_CASE(can_select_a_valid_channel_when_tv_which_is_on)
{
	tv.TurnOn();
	VerifyCommandHandling("SelectChannel 42", 42, "Channel 42 is selected.\n");
}

// Нельзя переключать каналы у выключенного телевизора
BOOST_AUTO_TEST_CASE(cant_select_channel_when_tv_is_turned_off)
{
	VerifyCommandHandling("SelectChannel 42", none, "This operation is possible when the TV is turned on.\n");
	VerifyCommandHandling("SelectChannel 100", none, "This operation is possible when the TV is turned on.\n");
}

// Нельзя переключиться на каналы вне диапазона [1, 99]
BOOST_AUTO_TEST_CASE(cant_select_an_invalid_channel_when_tv_is_on)
{
	tv.TurnOn();
	tv.SelectChannel(42);
	VerifyCommandHandling("SelectChannel 100", 42, "Invalid channel\n");
	VerifyCommandHandling("SelectChannel 0", 42, "Invalid channel\n");
}

BOOST_AUTO_TEST_CASE(can_select_previous_channel)
{
	tv.TurnOn();
	tv.SelectChannel(42);
	tv.SelectChannel(55);
	VerifyCommandHandling("SelectPreviousChannel", 42, "Your channel is 42\n");
	VerifyCommandHandling("SelectPreviousChannel", 55, "Your channel is 55\n");
	tv.TurnOff();
	tv.TurnOn();
	VerifyCommandHandling("SelectPreviousChannel", 42, "Your channel is 42\n");
	tv.TurnOff();
	VerifyCommandHandling("SelectPreviousChannel", none, "This operation is possible when the TV is turned on.\n");
}

BOOST_AUTO_TEST_SUITE_END()


struct RemoteControlByNameFixture : RemoteControlDependencies
{
	CRemoteControl remoteControl;

	RemoteControlByNameFixture()
		: remoteControl(tv, input, output)
	{
	}

	// Вспомогательная функция для проверки работы команды command
	// Она принимает ожидаемый номер канала expectedValue и expectedOutput
	void VerifyCommandHandling(const string& command, const optional<string>& expectedValue,
		const string& expectedOutput)
	{
		// Предварительно очищаем содержимое выходного потока
		output = stringstream();
		input = stringstream();
		BOOST_CHECK(input << command);
		BOOST_CHECK(remoteControl.HandleCommand());
		BOOST_CHECK_EQUAL(tv.IsTurnedOn(), expectedValue.is_initialized());
		BOOST_CHECK_EQUAL(tv.GetChannelName(1), expectedValue.get_value_or(0));
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}
};

BOOST_FIXTURE_TEST_SUITE(Remote_Control_With_Names, RemoteControlByNameFixture)

BOOST_AUTO_TEST_CASE(can_set_channel_name)
{
	tv.TurnOn();
	//VerifyCommandHandling("SetChannelName 5 Hello", "Hello", )
}

BOOST_AUTO_TEST_SUITE_END()