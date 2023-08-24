// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
wifi::WiFiComponent *wifi_wificomponent;
mdns::MDNSComponent *mdns_mdnscomponent;
api::APIServer *api_apiserver;
using namespace api;
using namespace sensor;
using namespace i2c;
i2c::ArduinoI2CBus *i2_bus_id;
preferences::IntervalSyncer *preferences_intervalsyncer;
bmp085::BMP085Component *bmp085_bmp085component;
sensor::Sensor *sensor_sensor;
#define yield() esphome::yield()
#define millis() esphome::millis()
#define micros() esphome::micros()
#define delay(x) esphome::delay(x)
#define delayMicroseconds(x) esphome::delayMicroseconds(x)
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ========== AUTO GENERATED CODE BEGIN ===========
  // esphome:
  //   name: bmp085
  //   friendly_name: BMP085
  //   build_path: .esphome/build/bmp085
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   name_add_mac_suffix: false
  //   min_version: 2023.9.0
  App.pre_setup("bmp085", "BMP085", "", __DATE__ ", " __TIME__, false);
  // wifi:
  //   id: wifi_wificomponent
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: LIGHT
  //   fast_connect: false
  //   passive_scan: false
  //   enable_on_boot: true
  //   networks:
  //   - ssid: wifi_ssid
  //     password: wifi_password
  //     id: wifi_wifiap
  //     priority: 0.0
  //   use_address: bmp085.local
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("bmp085.local");
  {
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid("wifi_ssid");
  wifi_wifiap.set_password("wifi_password");
  wifi_wifiap.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap);
  }
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_LIGHT);
  wifi_wificomponent->set_fast_connect(false);
  wifi_wificomponent->set_passive_scan(false);
  wifi_wificomponent->set_enable_on_boot(true);
  wifi_wificomponent->set_component_source("wifi");
  App.register_component(wifi_wificomponent);
  // mdns:
  //   id: mdns_mdnscomponent
  //   disabled: false
  //   services: []
  mdns_mdnscomponent = new mdns::MDNSComponent();
  mdns_mdnscomponent->set_component_source("mdns");
  App.register_component(mdns_mdnscomponent);
  // api:
  //   id: api_apiserver
  //   port: 6053
  //   password: ''
  //   reboot_timeout: 15min
  api_apiserver = new api::APIServer();
  api_apiserver->set_component_source("api");
  App.register_component(api_apiserver);
  api_apiserver->set_port(6053);
  api_apiserver->set_password("");
  api_apiserver->set_reboot_timeout(900000);
  // sensor:
  // i2c:
  //   sda: 21
  //   scl: 22
  //   scan: true
  //   id: i2_bus_id
  //   frequency: 50000.0
  i2_bus_id = new i2c::ArduinoI2CBus();
  i2_bus_id->set_component_source("i2c");
  App.register_component(i2_bus_id);
  i2_bus_id->set_sda_pin(21);
  i2_bus_id->set_scl_pin(22);
  i2_bus_id->set_frequency(50000);
  i2_bus_id->set_scan(true);
  // esp32:
  //   board: esp32dev
  //   framework:
  //     version: 2.0.5
  //     source: ~3.20005.0
  //     platform_version: platformio/espressif32@5.4.0
  //     type: arduino
  //   variant: ESP32
  // preferences:
  //   id: preferences_intervalsyncer
  //   flash_write_interval: 60s
  preferences_intervalsyncer = new preferences::IntervalSyncer();
  preferences_intervalsyncer->set_write_interval(60000);
  preferences_intervalsyncer->set_component_source("preferences");
  App.register_component(preferences_intervalsyncer);
  // sensor.bmp085:
  //   platform: bmp085
  //   i2c_id: i2_bus_id
  //   address: 0x77
  //   update_interval: 60s
  //   temperature:
  //     name: Outside Temperature
  //     disabled_by_default: false
  //     id: sensor_sensor
  //     force_update: false
  //     unit_of_measurement: °C
  //     accuracy_decimals: 1
  //     device_class: temperature
  //     state_class: measurement
  //   id: bmp085_bmp085component
  bmp085_bmp085component = new bmp085::BMP085Component();
  bmp085_bmp085component->set_update_interval(60000);
  bmp085_bmp085component->set_component_source("bmp085.sensor");
  App.register_component(bmp085_bmp085component);
  bmp085_bmp085component->set_i2c_bus(i2_bus_id);
  bmp085_bmp085component->set_i2c_address(0x77);
  sensor_sensor = new sensor::Sensor();
  App.register_sensor(sensor_sensor);
  sensor_sensor->set_name("Outside Temperature");
  sensor_sensor->set_object_id("outside_temperature");
  sensor_sensor->set_disabled_by_default(false);
  sensor_sensor->set_device_class("temperature");
  sensor_sensor->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor->set_unit_of_measurement("\302\260C");
  sensor_sensor->set_accuracy_decimals(1);
  sensor_sensor->set_force_update(false);
  bmp085_bmp085component->set_temperature(sensor_sensor);
  // socket:
  //   implementation: bsd_sockets
  // network:
  //   enable_ipv6: false
  // =========== AUTO GENERATED CODE END ============
  App.setup();
}

void loop() {
  App.loop();
}
