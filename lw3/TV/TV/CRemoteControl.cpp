#include "CRemoteControl.h"
#include "CTVSet.h"
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

CRemoteControl::CRemoteControl(CTVSet& tv, std::istream& input, std::ostream& output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
	, m_actionMap({ { "TurnOn", [this](istream& strm) {
						 return TurnOn(strm);
					 } },
		{ "TurnOff", bind(&CRemoteControl::TurnOff, this, std::placeholders::_1) }, 
		{ "Info", bind(&CRemoteControl::Info, this, _1) }, 
		{ "SelectChannel", bind(&CRemoteControl::SelectChannel, this, _1) }, 
		{ "SelectPreviousChannel", bind(&CRemoteControl::SelectPreviousChannel, this, _1) }, 
		{ "SetChannelName", bind(&CRemoteControl::SetChannelName, this, _1) },
		{ "GetChannelName", bind(&CRemoteControl::GetChannelName, this, _1) }, 
		{ "GetChannelByName", bind(&CRemoteControl::GetChannelByName, this, _1) },
		{ "DeleteChannelName", bind(&CRemoteControl::DeleteChannelName, this, _1) }
	})
{
}

bool CRemoteControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CRemoteControl::TurnOn(std::istream& /*args*/)
{
	m_tv.TurnOn();
	m_output << "TV is turned on" << endl;
	return true;
}

bool CRemoteControl::TurnOff(std::istream& /*args*/)
{
	m_tv.TurnOff();
	m_output << "TV is turned off" << endl;
	return true;
}

bool CRemoteControl::Info(std::istream& /*args*/)
{
	if (m_tv.IsTurnedOn())
	{
		m_output << "TV is turned on\nChannel is: " + to_string(m_tv.GetChannel()) + "\n";

		for (const auto& elem : m_tv.GetNamedChannels())
		{
			m_output << elem.first << " - " << elem.second << endl;
		}
	}
	else
	{
		m_output << "TV is turned off" << endl;
	}

	return true;
}

bool CRemoteControl::SelectChannel(std::istream& args)
{
	if (!m_tv.IsTurnedOn())
	{
		PrintWarning();
		return true;
	}

	int channel;
	args >> channel;

	if (args.fail())
	{
		args.clear();
		std::string str;
		args >> str;
		m_tv.SelectChannel(str);
	}
	else
	{
		if (!isInRange(channel))
		{
			return true;
		}
		m_tv.SelectChannel(channel);
	}

	m_output << "Channel " << m_tv.GetChannel() << " is selected." << endl;

	return true;
}

bool CRemoteControl::SelectPreviousChannel(std::istream&)
{
	if (m_tv.IsTurnedOn())
	{
		m_tv.SelectPreviousChannel();
		m_output << "Your channel is " + to_string(m_tv.GetChannel()) << endl;
	}
	else PrintWarning();

	return true;
}

bool CRemoteControl::SetChannelName(std::istream& args)
{
	if (m_tv.IsTurnedOn())
	{
		int channel;
		args >> channel;

		std::string name;
		std::getline(args, name);

		std::string trimName = TrimString(name);

		if (!trimName.empty())
		{
			m_tv.SetChannelName(channel, trimName);
			m_output << to_string(channel) + " added name " << trimName; 
		}
		else
		{
			m_output << "The channel name cannot consist only of spaces" << endl;
		}
	}
	else PrintWarning();

	return true;
}

bool CRemoteControl::GetChannelName(std::istream& args)
{
	if (m_tv.IsTurnedOn())
	{
		int channel;
		args >> channel;

		m_output << m_tv.GetChannelName(channel) << endl;
	}
	else PrintWarning();

	return true;
}

bool CRemoteControl::GetChannelByName(std::istream& args)
{
	if (m_tv.IsTurnedOn())
	{
		std::string name;
		std::getline(args, name);

		std::string trimName = TrimString(name);

		int channel = m_tv.GetChannelByName(trimName);
		if (channel == 0)
		{
			m_output << "No matches found" << endl;
		}
		else
		{
			m_output << channel << endl;
		}	
	}
	else PrintWarning();

	return true;
}

bool CRemoteControl::DeleteChannelName(std::istream& args)
{
	if (m_tv.IsTurnedOn())
	{
		std::string name;
		std::getline(args, name);
		std::string trimName = TrimString(name);

		int channel = m_tv.DeleteChannelName(trimName);
		if (channel != 0)
		{
			m_output << "Channel " << channel << " is deleted." << endl;
		}
		else
		{
			m_output << "No channel with name: " << name << endl;
		}
	}
	else PrintWarning();

	return true;
}

std::string CRemoteControl::TrimString(std::string str)
{
	std::string newStr = str;
	newStr.erase(
		std::unique_copy(newStr.begin(), newStr.end(), newStr.begin(),
			[](char c1, char c2) { return c1 == ' ' && c2 == ' '; }),
		newStr.end());

	if (newStr[0] == ' ')
	{
		newStr.erase(0, 1);
	}

	if (newStr.length() > 0)
	{
		if (newStr[newStr.length() - 1] == ' ')
		{
			newStr.erase(newStr.length() - 1, 1);
		}
	}
	
	return newStr;
}

void CRemoteControl::PrintWarning()
{
	m_output << "This operation is possible when the TV is turned on." << endl;
}

bool CRemoteControl::isInRange(int channel)
{
	if (channel >= 1 && channel <= 99)
	{
		return true;
	}
	else
	{
		m_output << "Invalid channel" << endl;
		return false;
	}
}