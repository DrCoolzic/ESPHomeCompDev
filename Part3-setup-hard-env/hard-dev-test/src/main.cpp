#include <Arduino.h>
#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif

class Time {
 public:
  Time() : time_{0} {}
  Time(int time) : time_{time} {}
  auto time() -> int & { return time_; }
  auto time() const -> const int & { return time_; }

 private:
  int time_;
};

class Clock : Time {
 public:
  Clock() : Time(), tick_{1000} {}
  Clock(int tick) : Time(), tick_{tick} {}
  Clock(int tick, int time) : Time(tick), tick_{tick} {}
  auto tick() & -> int & { return tick_; }
  auto operator()() const -> const int & { return time(); }
  auto operator++(int) -> void { time() = time() + tick_; }

 private:
  int tick_;
};

char str[50];
Clock clk{500};
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  int t = clk.tick();
  clk.tick() = 500;
}
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(clk.tick());
  clk++;
  digitalWrite(LED_BUILTIN, LOW);
  delay(clk.tick());
  clk++;
  sprintf(str, "Current time %.2f second%c", clk() / 1000.0, clk() < 2000 ? ' ' : 's');
  Serial.println(str);
}
