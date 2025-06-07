#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;

class LogProcessor {
public:
    static int info;
    static int debug;
    static int error;

    LogProcessor *nextLogProcessor;

    LogProcessor(LogProcessor *recivedProcessor)
    {
        nextLogProcessor = recivedProcessor;
    }

    virtual void logger(int logLevel, string message) {
        if (nextLogProcessor != NULL) {
            nextLogProcessor->logger(logLevel, message);
        }
    }
};


class InfoLogProcessor : public LogProcessor {
public:
    InfoLogProcessor(LogProcessor *recivedProcessor):LogProcessor(recivedProcessor)
    {

    }
    void logger(int logLevel, string message) {
        if(logLevel == info) {
            cout<<"INFO: "<<message<<"\n";
        } else{

            LogProcessor::logger(logLevel, message);
        }
    }
};

class DebugLogProcessor : public LogProcessor {
public:
    DebugLogProcessor(LogProcessor *recivedProcessor):LogProcessor(recivedProcessor)
    {

    }
    void logger(int logLevel, string message) {
        if(logLevel == debug) {
            cout<<"Debug: "<<message<<"\n";
        } else{

            LogProcessor::logger(logLevel, message);
        }
    }
};

class ErrorLogProcessor : public LogProcessor {
public:
    ErrorLogProcessor(LogProcessor *recivedProcessor):LogProcessor(recivedProcessor)
    {

    }
    void logger(int logLevel, string message) {
        if(logLevel == error) {
            cout<<"Error: "<<message<<"\n";
        } else{

            LogProcessor::logger(logLevel, message);
        }
    }
};

int LogProcessor::info = 1;
int LogProcessor::debug = 2;
int LogProcessor::error = 3;

int main()
{
    LogProcessor *log=new InfoLogProcessor(new DebugLogProcessor(new ErrorLogProcessor(NULL)));
    log->logger(3,"its an Error");
    log->logger(2,"its an Debug");
    log->logger(1,"its an Info");
    return 0;
}