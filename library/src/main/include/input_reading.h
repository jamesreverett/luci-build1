#ifndef INPUT_READING_H_
#define INPUT_READING_H_

// TODO: which namespace??

class InputReading {
    public:
        InputReading() : left_openness_(0), right_openness_(0) {}
        // TODO: constructor with openness values

        float average_openness();

        float left_openness();
        void set_left_openness(float val);

        float right_openness();
        void set_right_openness(float val);

        long epoch_time();
        void set_epoch_time(long val);

        long system_time();
        void set_system_time(long val);

        void Print() const;

    private:
        void UpdateAverageOpenness();

        float left_openness_;
        float right_openness_;
        float average_openness_;
        long int epoch_time_;
        long int system_time_;
};

#endif  // INPUT_READING_H_
