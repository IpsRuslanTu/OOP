#include "stdafx.h"
#include "/OOP/lw3/TV/TV/CTVSet.h"

/*
Телевизор
	изначально выключен
*/

struct TVSetFixture
{
	CTVSet tv;
};
// Телевизор 
BOOST_FIXTURE_TEST_SUITE(TVSet, TVSetFixture)
// изначально выключен
BOOST_AUTO_TEST_CASE(is_turned_off_by_default)
{
	BOOST_CHECK(!tv.IsTurnedOn());
}
// не может переключать канал в выключенном состоянии
BOOST_AUTO_TEST_CASE(cant_select_channel_when_turned_off)
{
	BOOST_CHECK(!tv.SelectChannel(87));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
}

// может быть включен
BOOST_AUTO_TEST_CASE(can_be_turned_on)
{
	tv.TurnOn();
	BOOST_CHECK(tv.IsTurnedOn());
}
// изначально отображает 0 канал
BOOST_AUTO_TEST_CASE(displays_channel_0_by_default)
{
	BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
}

struct when_turned_on_ : TVSetFixture
{
	when_turned_on_()
	{
		tv.TurnOn();
	}
};
// после включения
BOOST_FIXTURE_TEST_SUITE(when_turned_on, when_turned_on_)
// отображает канал 1
BOOST_AUTO_TEST_CASE(displays_channel_one)
{
	BOOST_CHECK_EQUAL(tv.GetChannel(), 1);
}
// можно выключить
BOOST_AUTO_TEST_CASE(can_be_turned_off)
{
	tv.TurnOff();
	BOOST_CHECK(!tv.IsTurnedOn());
}
// позволяет выбрать канал от 1 до 99
BOOST_AUTO_TEST_CASE(can_select_channel_from_1_to_99)
{
	BOOST_CHECK(tv.SelectChannel(1));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 1);

	BOOST_CHECK(tv.SelectChannel(99));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 99);

	// Выбираем канал между 1 и 99
	BOOST_CHECK(tv.SelectChannel(42));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 42);

	// При попытке выбрать канал за пределами [1; 99] 
	// телевизор не должен менять свой канал
	BOOST_CHECK(!tv.SelectChannel(0));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 42);

	BOOST_CHECK(!tv.SelectChannel(100));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 42);
}
BOOST_AUTO_TEST_SUITE_END()

struct after_subsequent_turning_on_ : when_turned_on_
{
	after_subsequent_turning_on_()
	{
		tv.SelectChannel(33);
		tv.TurnOff();
		tv.TurnOn();
	}
};

// после повторного включения
BOOST_FIXTURE_TEST_SUITE(after_subsequent_turning_on, after_subsequent_turning_on_)
// восстанавливает последний выбранный канал
BOOST_AUTO_TEST_CASE(restores_last_selected_channel)
{
	BOOST_CHECK_EQUAL(tv.GetChannel(), 33);
}
BOOST_AUTO_TEST_SUITE_END()

struct switching_to_previous_channel_ : when_turned_on_
{
	switching_to_previous_channel_()
	{
		tv.TurnOn();
		tv.SelectChannel(5);
		tv.SelectChannel(81);
	}
};

// проверка функции, выполняющей переключение телевизора на предыдущий канал, 
BOOST_FIXTURE_TEST_SUITE(switching_to_previous_channel, switching_to_previous_channel_)
// на котором телевизор находился ранее
BOOST_AUTO_TEST_CASE(switch_previous_channel)
{
	BOOST_CHECK_EQUAL(tv.GetChannel(), 81);
	tv.SelectPreviousChannel();
	BOOST_CHECK_EQUAL(tv.GetChannel(), 5);
	tv.SelectPreviousChannel();
	BOOST_CHECK_EQUAL(tv.GetChannel(), 81);
}
BOOST_AUTO_TEST_SUITE_END()


struct opportunities_work_channel_name_ : when_turned_on_
{
	opportunities_work_channel_name_()
	{
		tv.TurnOn();
		// Задали каналу имя
		tv.SetChannelName(10, "Good Morning");
	}
};

// возможность работы с именем канала 
BOOST_FIXTURE_TEST_SUITE(opportunities_work_channel_name, opportunities_work_channel_name_)

BOOST_AUTO_TEST_CASE(get_channel_by_name)
{
	// Получение номера канала по имени
	BOOST_CHECK_EQUAL(tv.GetChannelByName("Good Morning"), 10);
	// Получение 0 если канала с введенным именем нет
	BOOST_CHECK_EQUAL(tv.GetChannelByName("Goorning"), 0);
}
BOOST_AUTO_TEST_CASE(get_channel_name)
{
	// Получение имя канала по номеру
	BOOST_CHECK_EQUAL(tv.GetChannelName(10), "Good Morning");
	// Получение пустую строку если номеру не присвоено имя
	BOOST_CHECK(tv.GetChannelName(50).empty());
}
BOOST_AUTO_TEST_CASE(delete_channel_name)
{
	// Получение номера удаленного канала по его номеру
	BOOST_CHECK_EQUAL(tv.DeleteChannelName("Hello"), 0);
	BOOST_CHECK_EQUAL(tv.DeleteChannelName("Good Morning"), 10);
}
BOOST_AUTO_TEST_CASE(select_channel_by_name)
{
	// Переключение канала по его имени
	tv.SelectChannel(33);
	tv.SelectChannel("Good Morning");
	BOOST_CHECK_EQUAL(tv.GetChannel(), 10);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()