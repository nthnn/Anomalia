#include "anomalia.h"

void Anomalia::clear() {
    this->events.clear();
}

void Anomalia::check() {
    for(int i = 0; i < this->events.getSize(); i++) {
        AnomaliaEvent* event = this->events.getPointer(i);
        bool condition_value = event->condition();

        event->pre_event(condition_value);
        if(condition_value)
            event->event(event->value());
    }
}

void Anomalia::listen(bool (*condition)(), void* (*value)(), void (*pre_event)(bool returned_value), void (*event)(void* value)) {
    this->events.add((AnomaliaEvent) {
        .condition = condition,
        .value = value,
        .pre_event = pre_event,
        .event = event
    });
}

void Anomalia::listen(AnomaliaEvent event) {
    this->events.add(event);
}
