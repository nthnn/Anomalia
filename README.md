# Anomalia - Arduino Encapsulated Event Library

The Anomalia library is an Arduino library designed to provide a flexible and efficient framework for handling anomaly events in your Arduino projects. It allows you to define events, specify conditions, and execute corresponding actions when those events occur. With Anomalia, you can easily monitor various system states, detect anomalies, and respond accordingly, enhancing the reliability and functionality of your Arduino applications. The library provides a powerful framework for handling events and anomalies in your Arduino projects. By defining events, specifying conditions, and executing actions, you can monitor system states and respond to anomalies effectively.

## Features

- Simple and intuitive API for defining events and actions.
- Flexible event condition and value retrieval functions.
- Pre-event and event functions for executing actions before and after an event.
- Efficient event checking mechanism.
- Lightweight and optimized for Arduino platforms.

## Installation

To use the Anomalia library, follow these steps:

1. Download the Anomalia library from the official Arduino library manager or the GitHub repository.
2. If downloaded from the GitHub repository, import the library into your Arduino IDE by navigating to `Sketch > Include Library > Add .ZIP Library` and selecting the downloaded Anomalia library file.
3. Once imported, you can include the library in your Arduino sketch by adding the following line at the top of your code:

    ```cpp
    #include <anomalia.h>
    ```

4. You are now ready to utilize the Anomalia library in your Arduino projects.

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

## License

Copyright 2023 - Nathanne Isip

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

```THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.```