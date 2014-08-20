#ifndef DEMO_H
#define DEMO_H 

class Demo {
    public:
        virtual ~Demo() {};
        virtual void Initialize() = 0;
        virtual void Run() = 0;
};

#endif
