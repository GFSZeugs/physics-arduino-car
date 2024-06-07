enum Direction {
    FORWARD, BACKWARD
};

struct Engine {
    private:
        int pwmPin;
        int dirPin;
    
        float thrust;
        Direction dir;
        
    public:
        Engine(int, int);

        float getThrust();
        void setThrust(float);

        Direction getDirection();
        void setDirection(Direction);
};
