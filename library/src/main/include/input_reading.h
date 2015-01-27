#ifndef INPUT_READING_H_
#define INPUT_READING_H_

class InputReading {
    public:
        InputReading();
        float average();

    private:
        void evaluate();
        float left_;
        float right_;
        float average_;
};

#endif  // INPUT_READING_H_
