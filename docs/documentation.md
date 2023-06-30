# Anomalia Library Documentation

## Introduction

The Anomalia library is an Arduino library designed to provide a flexible and efficient framework for handling anomaly events in your Arduino projects. It allows you to define events, specify conditions, and execute corresponding actions when those events occur. With Anomalia, you can easily monitor various system states, detect anomalies, and respond accordingly, enhancing the reliability and functionality of your Arduino applications.

## Installation

To use the Anomalia library, follow these steps:

1. Download the Anomalia library from the official Arduino library manager or the GitHub repository.
2. Import the library into your Arduino IDE by navigating to `Sketch > Include Library > Add .ZIP Library` and selecting the downloaded Anomalia library file.
3. Once imported, you can include the library in your Arduino sketch by adding the following line at the top of your code:

    ```cpp
    #include <Anomalia.h>
    ```

4. You are now ready to utilize the Anomalia library in your Arduino projects.

## Class Reference

### `Anomalia`

The Anomalia class is the main class of the Anomalia library. It provides methods to define events, set conditions, and execute actions when events occur.

#### Public Methods

```void clear()```

Clears all registered events from the event list. This method removes all events previously defined using the listen() method.

```void check()```

Checks all defined events and executes the corresponding actions if their associated conditions are met.

```void listen(AnomaliaEvent event)```

Adds a pre-defined AnomaliaEvent structure to the event list. This structure encapsulates the condition, value, pre-event, and event functions associated with an event. The library will call the functions in the structure when the event condition is satisfied.

```void listen(bool (*condition)(), void* (*value)(), void (*pre_event)(bool returned_value), void (*event)(void* value))```

Creates and adds a new event to the event list. This method allows you to define the event's condition, value, pre-event, and event functions directly without using the AnomaliaEvent structure.

### ```AnomaliaEvent```

The AnomaliaEvent structure represents an individual event and contains the necessary functions to define the event's behavior.

#### Structure Members

```bool (*condition)()```

A function pointer that points to a user-defined condition function. This function determines if the event's condition is satisfied. It should return true when the condition is met and false otherwise.

```void* (*value)()```

A function pointer that points to a user-defined value function. This function retrieves the value associated with the event. It should return a void pointer (void*) that represents the value. See ```TO_VALUE(x)```.

```void (*pre_event)(bool returned_value)```

A function pointer that points to a user-defined pre-event function. This function is executed before the event's main action. It takes a boolean parameter returned_value, which indicates the result of the event's condition function.

```void (*event)(void* value)```

A function pointer that points to a user-defined event function. This function is executed when the event's condition is satisfied. It takes a void pointer (void*) parameter that represents the event's value.

## Usage

To use the Anomalia library, follow these steps:

Define an instance of the Anomalia class:

```cpp
Anomalia anomaly;
```

Define your event conditions, values, pre-events, and events using one of the provided methods, such as ```listen()```:

```cpp
anomaly.listen(myCondition, myValue, myPreEvent, myEvent);
```

Implement the corresponding functions for each event:

```cpp
bool myCondition() {
    // Your condition implementation
}

void* myValue() {
    // Your value retrieval implementation
    return TO_VALUE(anyValue);
}

void myPreEvent(bool returned_value) {
    // Your pre-event implementation
}

void myEvent(void* value) {
    // Your event implementation
}
```

In your main loop or at appropriate intervals, call the check() method to check for events and execute their associated actions:

```cpp
void loop() {
    // Other code
    
    anomaly.check();
    
    // Other code
}
```

## Examples

To help you get started, here's a simple example demonstrating the usage of the Anomalia library:

```cpp
#include <Anomalia.h>

// Define an instance of the Anomalia class
Anomalia anomaly;

// Event condition function
bool myCondition() {
    // Implement your condition logic here
}

// Event value function
void* myValue() {
    // Implement your value retrieval logic here
}

// Pre-event function
void myPreEvent(bool returned_value) {
    // Implement your pre-event logic here
}

// Event function
void myEvent(void* value) {
    // Implement your event logic here
}

void setup() {
    // Register the event with its associated functions
    anomaly.listen(myCondition, myValue, myPreEvent, myEvent);
}

void loop() {
    // Check for events and execute actions
    anomaly.check();
}
```

The Anomalia library provides a powerful framework for handling events and anomalies in your Arduino projects. By defining events, specifying conditions, and executing actions, you can monitor system states and respond to anomalies effectively. Refer to the documentation and examples to explore the library's capabilities and integrate it into your own projects.