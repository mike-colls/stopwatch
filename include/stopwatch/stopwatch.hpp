#pragma once
#include <chrono>

namespace sw
{
    class stopwatch
    {
    public:
        void start()
        {
            start_ = std::chrono::high_resolution_clock::now();
            started_ = true;
        }

        void stop()
        {
            end_ = std::chrono::high_resolution_clock::now();
            started_ = false;
        }

        void reset()
        {
            if( started_ )
                start_ = std::chrono::high_resolution_clock::now();
            else
                end_ = start_;
        }

        [[nodiscard]] std::chrono::milliseconds elapsed_milli_seconds() const
        {
            if( started_ )
            {
                std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
                return std::chrono::duration_cast<std::chrono::milliseconds>( now - start_ );
            }
            else
            {
                return std::chrono::duration_cast<std::chrono::milliseconds>( end_ - start_ );
            }
        }

        [[nodiscard]] bool started() const
        {
            return started_;
        }

    private:
        std::chrono::high_resolution_clock::time_point start_;
        std::chrono::high_resolution_clock::time_point end_;
        bool started_{ false };
    };
}
