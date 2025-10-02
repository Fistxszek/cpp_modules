#include "Contact.hpp"

std::string Contact::getFirstName() const { return m_FirstName; }
void Contact::setFirstName(const std::string& val) { m_FirstName = val; }

std::string Contact::getLastName() const { return m_LastName; }
void Contact::setLastName(const std::string& val) { m_LastName = val; }

std::string Contact::getNickname() const { return m_Nickname; }
void Contact::setNickname(const std::string& val) { m_Nickname = val; }

std::string Contact::getNumber() const { return m_Number; }
void Contact::setNumber(const std::string& val) { m_Number = val; }

std::string Contact::getSecret() const { return m_Secret; }
void Contact::setSecret(const std::string& val) { m_Secret = val; }

void Contact::clearContact()
{
    m_FirstName.clear();
    m_LastName.clear();
    m_Nickname.clear();
    m_Number.clear();
    m_Secret.clear();
}
