#ifndef INPUT_READING_H_
#define INPUT_READING_H_

class InputReading {
    private:
        float left_;
//        float right_;
//        float ratio_;
//        long int epoch_time_;
//        long int system_time_;


    public:
        InputReading() : left_(0) {}

        // Prints the current value to STDOUT.
        int Print() const;
};

#endif  // INPUT_READING_H_
