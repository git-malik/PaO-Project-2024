#ifndef SAVEEXCEPTION_H
#define SAVEEXCEPTION_H

class SaveException : public std::exception {
public:
    SaveException(const std::string& message) : message(message) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
private:
    std::string message;
};

#endif // SAVEEXCEPTION_H