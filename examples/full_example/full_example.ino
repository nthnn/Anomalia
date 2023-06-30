#include <anomalia.h>

#define TEST_PIN 5

Anomalia anomalia;

bool test_condition() {
    return digitalRead(TEST_PIN) == HIGH;
}

void* test_value() {
    return TO_VALUE(digitalRead(TEST_PIN));
}

void test_pre_event(bool returned_value) {
    Serial.println("Value: " + String(returned_value));
}

void test_event(void* value) {
    Serial.println("Received value: " + String((int) value));
}

void setup() {
    Serial.begin(9600);
    pinMode(TEST_PIN, INPUT);

    anomalia.listen(test_condition, test_value, test_pre_event, test_event);
}

void loop() {
    anomalia.check();
}