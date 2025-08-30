#include <bits/stdc++.h>
using namespace std;

class Logger {
public:
    void printLog() {
        cout<<"Hi I m logger\n";
    }
};


class SingletonLogger {
public:
    static Logger* logger;

    static Logger* getInstance() {
        if(logger == NULL)
            logger = new Logger();

        return logger;
    }
};

Logger* SingletonLogger::logger = NULL;
int main()
{
    Logger* logger = SingletonLogger::getInstance();
    logger->printLog();

    Logger* logger_2 = SingletonLogger::getInstance();
    logger_2->printLog();
    return 0;
}