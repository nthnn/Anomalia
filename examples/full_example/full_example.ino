/*
*   Anomalia Full Example    *
*   By: Nathanne Isip        *
*/
#include <anomalia.h>

// Definition of the digital pin for this test
#define TEST_PIN 5

// Create Anomalia instance
Anomalia anomalia;

// Condition function for testing
bool test_condition() {
    // Read value of the test pin and return
    return digitalRead(TEST_PIN);
}

// Value function for testing
void* test_value() {
    // Using TO_VALUE macro is recommended for values to be returned by the function
    return TO_VALUE(digitalRead(TEST_PIN));
}

// Pre-event function for testing.
void test_pre_event(bool returned_value) {
    Serial.println("Value: " + String(returned_value));
}

// Event function for testing.
void test_event(void* value) {
    Serial.println("Received value: " + String((int) value));
}

void setup() {
    Serial.begin(9600);
    pinMode(TEST_PIN, INPUT); // Initialize test pin

    // Add anomaly listener
    anomalia.listen(test_condition, test_value, test_pre_event, test_event);
}

void loop() {
    // Run anomaly checks on actual loop
    anomalia.check();

    // Using delays and running tasks are not recommended
    delay(1000);    
}