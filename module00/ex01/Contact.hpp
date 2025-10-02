#pragma once

#include <string>
#include <iomanip>

class Contact
{
public:
    std::string getFirstName() const;
    void setFirstName(const std::string& val);

    std::string getLastName() const;
    void setLastName(const std::string& val);

    std::string getNickname() const;
    void setNickname(const std::string& val);

    std::string getNumber() const;
    void setNumber(const std::string& val);

    std::string getSecret() const;
    void setSecret(const std::string& val);

    void clearContact();

private:
    std::string m_FirstName;
    std::string m_LastName;
    std::string m_Nickname;
    std::string m_Number;
    std::string m_Secret;
};
