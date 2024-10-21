#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <atomic>
#include <random>

std::mutex output_mutex;
std::vector<std::string> thread_outputs;
std::atomic<int> completed_threads(0);

void clear_console()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void update_progress(const std::vector<std::string>& outputs)
{
    clear_console();
    for (const auto& output : outputs)
    {
        std::cout << output << std::endl;
    }
}

void progress_bar(int thread_num, int length, int total_threads, int rand_value)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i <= length; ++i)
    {
        std::stringstream ss;
        ss << "Thread " << std::setw(2) << thread_num << " [" << std::this_thread::get_id() << "]: [";

        int pos = 50 * i / length;
        for (int j = 0; j < 50; ++j)
        {
            if (j < pos) ss << "=";
            else if (j == pos) ss << ">";
            else ss << " ";
        }
        ss << "] " << std::setw(3) << i * 100 / length << "%";

        if (i == length)
        {
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            ss << " Completed in " << duration.count() << " ms";
        }

        {
            std::lock_guard<std::mutex> lock(output_mutex);
            thread_outputs[thread_num] = ss.str();
            update_progress(thread_outputs);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(rand_value));
    }

    if (++completed_threads == total_threads)
    {
        std::lock_guard<std::mutex> lock(output_mutex);
        update_progress(thread_outputs);
        std::cout << "\nAll threads completed." << std::endl;
    }
}

int main()
{
    int num_threads = 5;
    int calculation_length = 100;

    thread_outputs.resize(num_threads);

    std::vector<std::thread> threads;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 500);

    for (int i = 0; i < num_threads; ++i)
    {
        std::mt19937 gen(rd());
        int mean = dist(gen);

        threads.emplace_back(progress_bar, i, calculation_length, num_threads, mean);
    }
    for (auto& t : threads)
    {
        t.join();
    }
}