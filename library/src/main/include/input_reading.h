#ifndef INPUT_READING_H_
#define INPUT_READING_H_

// TODO: which namespace??

class InputReading {
    public:
        InputReading();
        InputReading(float, float, long);

        float average_openness();

        float left_openness();
        void set_left_openness(float val);

        float right_openness();
        void set_right_openness(float val);

        long device_timestamp();
        void set_device_timestamp(long val);

        long epoch_time();
        void set_epoch_time(long val);

        void Print() const;

    private:
        void UpdateAverageOpenness();

        float left_openness_;
        float right_openness_;
        float average_openness_;
        long device_timestamp_;
        long epoch_time_;
};

#endif  // INPUT_READING_H_
