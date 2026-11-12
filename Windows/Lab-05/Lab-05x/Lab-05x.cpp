#include <iostream>
#include <windows.h>
#include <ctime>


using namespace std;


void PrintLine(char symbol = '-', int line_length = 100)
{
    cout << string(line_length, symbol) + '\n';
}


void GetPriorityValues(const DWORD& priority_class, const int& thread_priority, string& value_priority_class, string& value_thread_priority)
{
    switch (priority_class)
    {
        case IDLE_PRIORITY_CLASS:
        {
            value_priority_class = "IDLE_PRIORITY_CLASS";
            break;
        }
        case BELOW_NORMAL_PRIORITY_CLASS:
        {
            value_priority_class = "BELOW_NORMAL_PRIORITY_CLASS";
            break;
        }
        case NORMAL_PRIORITY_CLASS:
        {
            value_priority_class = "NORMAL_PRIORITY_CLASS";
            break;
        }
        case ABOVE_NORMAL_PRIORITY_CLASS:
        {
            value_priority_class = "ABOVE_NORMAL_PRIORITY_CLASS";
            break;
        }
        case HIGH_PRIORITY_CLASS:
        {
            value_priority_class = "HIGH_PRIORITY_CLASS";
            break;
        }
        case REALTIME_PRIORITY_CLASS:
        {
            value_priority_class = "REALTIME_PRIORITY_CLASS";
            break;
        }
        default:
        {
            value_priority_class = "Not known";
            break;
        }
    }

    switch (thread_priority)
    {
        case THREAD_PRIORITY_HIGHEST:
        {
            value_thread_priority = "THREAD_PRIORITY_HIGHEST";
            break;
        }
        case THREAD_PRIORITY_ABOVE_NORMAL:
        {
            value_thread_priority = "THREAD_PRIORITY_ABOVE_NORMAL";
            break;
        }
        case THREAD_PRIORITY_NORMAL:
        {
            value_thread_priority = "THREAD_PRIORITY_NORMAL";
            break;
        }
        case THREAD_PRIORITY_LOWEST:
        {
            value_thread_priority = "THREAD_PRIORITY_LOWEST";
            break;
        }
        case THREAD_PRIORITY_BELOW_NORMAL:
        {
            value_thread_priority = "THREAD_PRIORITY_BELOW_NORMAL";
            break;
        }
        default:
        {
            value_thread_priority = "Not known";
            break;
        }
    }

}


int main()
{
    clock_t start_time = clock();

    HANDLE h_process = GetCurrentProcess();
    HANDLE h_thread = GetCurrentThread();
    string value_priority_class, value_thread_priority;
    for (int i = 1; i <= 1000001; ++i)
    {
        if (i % 1000 == 0)
        {
            Sleep(200);

            int thread_priority = GetThreadPriority(h_thread);
            DWORD priority_class = GetPriorityClass(h_process);
            DWORD currentProcessor = GetCurrentProcessorNumber();

            GetPriorityValues(priority_class, thread_priority, value_priority_class, value_thread_priority);

            PrintLine();
            cout << "Iteration: " << i << '\n';
            cout << "PID: " << GetCurrentProcessId() << '\n';
            cout << "TID: " << GetCurrentThreadId() << '\n';
            cout << "Process priority class: " << value_priority_class << '\n';
            cout << "Thread priority (number): " << thread_priority << '\n';
            cout << "Thread priority (string): " << value_thread_priority << '\n';
            cout << "Current process CPU: " << currentProcessor << '\n';
            PrintLine();
        }
    }
    PrintLine('=');
    clock_t end_time = clock();
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Past time: " << time_spent << " seconds.\n";
    PrintLine('=');

    return 0;
}