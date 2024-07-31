#include <functional>
#include <thread>
#include <chrono>

#pragma once
                             
class ThreadTimer {
private:
    std::thread th;
    bool running = false;

public:
    typedef std::chrono::milliseconds Interval;
    typedef std::function<void(void)> Timeout;

    void start(const Interval& interval, const Timeout& timeout) {
        if (!running){
            running = true;
            th = std::thread( [interval, timeout]{
                while (true) {
                    std::this_thread::sleep_for(interval);
                    timeout();
                }
            });            
        }
    }

    void stop() {
        if (running){
            running = false;
            th.detach(); 
        }
    }
};