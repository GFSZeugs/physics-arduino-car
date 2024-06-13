enum Direction {
    FORWARD, BACKWARD
};

struct Engine {
    private:
        int pwmPin;
        int dirPin;
    
        int thrust;
        Direction dir;
        
    public:
        Engine(int, int);

        int getThrust();
        void setThrust(int);

        void kickstart(int);

        Direction getDirection();
        void setDirection(Direction);
};
