#ifndef USERSESSION_H
#define USERSESSION_H
#include <QString>

class UserSession {
public:
    static UserSession& instance() {
        static UserSession instance; // Guaranteed to be destroyed
        return instance;
    }

    void setUsername(const QString &username) { this->username = username; }
    QString getUsername() const { return username; }

private:
    UserSession() {} // Constructor is private
    QString username;
};

#endif // USERSESSION_H
