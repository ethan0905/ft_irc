#include "../inc/parsing.hpp"

parsing::parsing()
{
}

parsing::~parsing()
{
}

bool    parsing::valid_server_name(std::string server_name)
{
    size_t i = 0;
    if (server_name.size() > 63)
        return (false);
    for (; i < server_name.size(); i++)
    {
        if (server_name[i] == ' ' || server_name[i] == '\t' || server_name[i] == '\n' || server_name[i] == '\r' || server_name[i] == '\v' || server_name[i] == '\f')
            return (false);
    }
    return (true);
}

bool    parsing::valid_user_name(std::string user_name)
{
    size_t i = 0;
    size_t point = 0;
    if (user_name.size() > 16)
        return (false);
    if (user_name[i] == '.')
    {
        i++;
        point++;
    }
    for (; i < user_name.size(); i++)
    {
        if ((user_name[i] == ' ' && point == 0) || user_name[i] == '\t' || user_name[i] == '\n' || user_name[i] == '\r' || user_name[i] == '\v' || user_name[i] == '\f'
        || user_name[i] == '!' || user_name[i] == '@' || user_name[i] == '#' || user_name[i] == '$' || user_name[i] == ',' || user_name[i] == '.' || user_name[i] == '?')
            return (false);
    }
    return (true);
}

bool    parsing::valid_channel_name(std::string channel_name)
{
    if (channel_name.size() > 50 || (!is_local(channel_name) && !is_regular(channel_name)))
        return (false);
    for (size_t i = 0; i < channel_name.size(); i++)
    {
        if (channel_name[i] == ' ' || channel_name[i] == 7 || channel_name[i] == ',' || channel_name[i] == '\t')
            return (false);
    }
    return (true);
}

bool    parsing::is_local(std::string server_name)
{
    if (server_name.find('&') == std::string::npos)
        return (false);
    return (true);
}

bool    parsing::is_regular(std::string server_name)
{
    if (server_name.find('#') == std::string::npos)
        return (false);
    return (true);
}
