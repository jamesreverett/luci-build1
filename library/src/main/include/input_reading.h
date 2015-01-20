#ifndef INPUT_READING_H_
#define INPUT_READING_H_

// TODO: which namespace??

const float kEyeRatioBarrier = 0.350000;

class InputReading {
    public:
        // TODO: re-evaluate constructors vs setters - force 3 arg constructor?
        InputReading();
        InputReading(float, float, long);

        float left_openness();
        void set_left_openness(float val);

        float right_openness();
        void set_right_openness(float val);

        long device_timestamp();
        void set_device_timestamp(long val);

        long epoch_time();
        void set_epoch_time(long val);

        float average_openness();
        int perclos();

        void PrintJSON() const;

    private:
        void EvaluateOpenness();

        float left_openness_;
        float right_openness_;
        float average_openness_;
        long device_timestamp_;
        long epoch_time_;
        int perclos_; // SHOULD this be boolean 0/1 - other values?
};

#endif  // INPUT_READING_H_
