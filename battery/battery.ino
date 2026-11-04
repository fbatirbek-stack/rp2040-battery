#include <Adafruit_TinyUSB.h>

// Windows Battery / Power Device HID Report Descriptor
uint8_t const desc_hid_report[] = {
  0x05, 0x85,       // Usage Page (Power Device)
  0x09, 0x01,       // Usage (Smart Battery)
  0xA1, 0x01,       // Collection (Application)
    0x09, 0x42,       //   Usage (Charging)
    0x15, 0x00,       //   Logical Minimum (0)
    0x25, 0x01,       //   Logical Maximum (1)
    0x75, 0x01,       //   Report Size (1)
    0x95, 0x01,       //   Report Count (1)
    0x81, 0x02,       //   Input (Data, Var, Abs)
    0x09, 0x33,       //   Usage (Present)
    0x81, 0x02,       //   Input (Data, Var, Abs)
    0x09, 0x66,       //   Usage (Percent Full)
    0x15, 0x00,       //   Logical Minimum (0)
    0x26, 0x64, 0x00, //   Logical Maximum (100)
    0x75, 0x08,       //   Report Size (8)
    0x95, 0x01,       //   Report Count (1)
    0x81, 0x02,       //   Input (Data, Var, Abs)
  0xC0              // End Collection
};

Adafruit_USBD_HID usb_hid;

void setup() {
  usb_hid.setPollInterval(2);
  usb_hid.setReportDescriptor(desc_hid_report, sizeof(desc_hid_report));
  usb_hid.begin();

  while (!TinyUSBDevice.mounted()) {
    delay(1);
  }
}

void loop() {
  if (usb_hid.ready()) {
    // Rapor verisi: [Şarj: 1, Mevcut: 1, Yüzde: 100]
    uint8_t report[3] = { 1, 1, 100 };
    usb_hid.sendReport(0, report, sizeof(report));
  }
  delay(5000);
}
