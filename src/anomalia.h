#ifndef ANOMALIA_H
#define ANOMALIA_H

#include <Arduino.h>
#include <List.hpp>

#define TO_VALUE(x) ((void*) x)

struct _AnomaliaEvt {
    bool (*condition)();
    void* (*value)();

    void (*pre_event)(bool returned_value);
    void (*event)(void* value);
};

typedef struct _AnomaliaEvt AnomaliaEvent;

class Anomalia {
    public:
    void clear();
    void check();

    void listen(AnomaliaEvent event);
    void listen(
        bool (*condition)(),
        void* (*value)(),
        void (*pre_event)(bool returned_value),
        void (*event)(void* value));

    private:
    List<AnomaliaEvent> events;
};

#endif