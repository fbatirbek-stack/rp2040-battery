#include <Adafruit_TinyUSB.h>

// Rapor ID'leri
#define HID_PD_IPRODUCT           0x01
#define HID_PD_SERIAL             0x02
#define HID_PD_MANUFACTURER       0x03
#define HID_PD_RECHARGEABLE       0x06
#define HID_PD_PRESENTSTATUS      0x07
#define HID_PD_REMAINTIMELIMIT    0x08
#define HID_PD_MANUFACTUREDATE    0x09
#define HID_PD_CONFIGVOLTAGE      0x0A
#define HID_PD_VOLTAGE            0x0B
#define HID_PD_REMAININGCAPACITY  0x0C
#define HID_PD_RUNTIMETOEMPTY     0x0D
#define HID_PD_FULLCHRGECAPACITY  0x0E
#define HID_PD_WARNCAPACITYLIMIT  0x0F
#define HID_PD_CPCTYGRANULARITY1  0x10
#define HID_PD_REMNCAPACITYLIMIT  0x11
#define HID_PD_DELAYBE4SHUTDOWN   0x12
#define HID_PD_DELAYBE4REBOOT     0x13
#define HID_PD_AUDIBLEALARMCTRL   0x14
#define HID_PD_CAPACITYMODE       0x16
#define HID_PD_DESIGNCAPACITY     0x17
#define HID_PD_CPCTYGRANULARITY2  0x18
#define HID_PD_AVERAGETIME2FULL   0x1A
#define HID_PD_AVERAGETIME2EMPTY  0x1C
#define HID_PD_IDEVICECHEMISTRY   0x1F
#define HID_PD_IOEMINFORMATION    0x20

// String indeksleri
#define IMANUFACTURER   1
#define IPRODUCT        2
#define ISERIAL         3
#define IDEVICECHEMISTRY 2
#define IOEMVENDOR       1

static const uint8_t desc_hid_report[] = {
  0x05, 0x84, 0x09, 0x04, 0xA1, 0x01, 0x09, 0x24, 0xA1, 0x02,
  0x75, 0x08, 0x95, 0x01, 0x15, 0x00, 0x26, 0xFF, 0x00,
  0x85, HID_PD_IPRODUCT, 0x09, 0xFE, 0x79, IPRODUCT, 0xB1, 0x23,
  0x85, HID_PD_SERIAL, 0x09, 0xFF, 0x79, ISERIAL, 0xB1, 0x23,
  0x85, HID_PD_MANUFACTURER, 0x09, 0xFD, 0x79, IMANUFACTURER, 0xB1, 0x23,
  0x05, 0x85,
  0x85, HID_PD_RECHARGEABLE, 0x09, 0x8B, 0xB1, 0x23,
  0x85, HID_PD_IDEVICECHEMISTRY, 0x09, 0x89, 0x79, IDEVICECHEMISTRY, 0xB1, 0x23,
  0x85, HID_PD_IOEMINFORMATION, 0x09, 0x8F, 0x79, IOEMVENDOR, 0xB1, 0x23,
  0x85, HID_PD_CAPACITYMODE, 0x09, 0x2C, 0xB1, 0x23,
  0x85, HID_PD_CPCTYGRANULARITY1, 0x09, 0x8D, 0x26, 0x64, 0x00, 0xB1, 0x22,
  0x85, HID_PD_CPCTYGRANULARITY2, 0x09, 0x8E, 0xB1, 0x23,
  0x85, HID_PD_FULLCHRGECAPACITY, 0x09, 0x67, 0xB1, 0x83,
  0x85, HID_PD_DESIGNCAPACITY, 0x09, 0x83, 0xB1, 0x83,
  0x85, HID_PD_REMAININGCAPACITY, 0x09, 0x66, 0x81, 0xA3, 0x09, 0x66, 0xB1, 0xA3,
  0x85, HID_PD_WARNCAPACITYLIMIT, 0x09, 0x8C, 0xB1, 0xA2,
  0x85, HID_PD_REMNCAPACITYLIMIT, 0x09, 0x29, 0xB1, 0xA2,
  0x85, HID_PD_MANUFACTUREDATE, 0x09, 0x85, 0x75, 0x10,
  0x27, 0xFF, 0xFF, 0x00, 0x00, 0xB1, 0xA3,
  0x85, HID_PD_AVERAGETIME2FULL, 0x09, 0x6A, 0x27, 0xFF, 0xFF, 0x00, 0x00,
  0x66, 0x01, 0x10, 0x55, 0x00, 0xB1, 0xA3,
  0x85, HID_PD_AVERAGETIME2EMPTY, 0x09, 0x69, 0x81, 0xA3, 0x09, 0x69, 0xB1, 0xA3,
  0x85, HID_PD_RUNTIMETOEMPTY, 0x09, 0x68, 0x81, 0xA3, 0x09, 0x68, 0xB1, 0xA3,
  0x85, HID_PD_REMAINTIMELIMIT, 0x09, 0x2A, 0x75, 0x10,
  0x27, 0x64, 0x05, 0x00, 0x00, 0x16, 0x78, 0x00, 0x81, 0x22,
  0x09, 0x2A, 0xB1, 0xA2,
  0x05, 0x84,
  0x85, HID_PD_DELAYBE4SHUTDOWN, 0x09, 0x57, 0x16, 0x00, 0x80,
  0x27, 0xFF, 0x7F, 0x00, 0x00, 0xB1, 0xA2,
  0x85, HID_PD_DELAYBE4REBOOT, 0x09, 0x55, 0xB1, 0xA2,
  0x85, HID_PD_CONFIGVOLTAGE, 0x09, 0x40, 0x15, 0x00,
  0x27, 0xFF, 0xFF, 0x00, 0x00, 0x67, 0x21, 0xD1, 0xF0, 0x00, 0x55, 0x05, 0xB1, 0x23,
  0x85, HID_PD_VOLTAGE, 0x09, 0x30, 0x81, 0xA3, 0x09, 0x30, 0xB1, 0xA3,
  0x85, HID_PD_AUDIBLEALARMCTRL, 0x09, 0x5A, 0x75, 0x08, 0x15, 0x01, 0x25, 0x03,
  0x65, 0x00, 0x55, 0x00, 0x81, 0x22, 0x09, 0x5A, 0xB1, 0xA2,
  0x09, 0x02, 0xA1, 0x02,
  0x85, HID_PD_PRESENTSTATUS, 0x05, 0x85,
  0x09, 0x44, 0x75, 0x01, 0x15, 0x00, 0x25, 0x01, 0x81, 0xA3, 0x09, 0x44, 0xB1, 0xA3,
  0x09, 0x45, 0x81, 0xA3, 0x09, 0x45, 0xB1, 0xA3,
  0x09, 0xD0, 0x81, 0xA3, 0x09, 0xD0, 0xB1, 0xA3,
  0x09, 0xD1, 0x81, 0xA3, 0x09, 0xD1, 0xB1, 0xA3,
  0x09, 0x42, 0x81, 0xA3, 0x09, 0x42, 0xB1, 0xA3,
  0x09, 0x43, 0x81, 0xA2, 0x09, 0x43, 0xB1, 0xA2,
  0x09, 0x4B, 0x81, 0xA3, 0x09, 0x4B, 0xB1, 0xA3,
  0x09, 0xDB, 0x81, 0xA3, 0x09, 0xDB, 0xB1, 0xA3,
  0x09, 0x46, 0x81, 0xA3, 0x09, 0x46, 0xB1, 0xA3,
  0x09, 0x47, 0x81, 0xA3, 0x09, 0x47, 0xB1, 0xA3,
  0x05, 0x84,
  0x09, 0x68, 0x81, 0xA2, 0x09, 0x68, 0xB1, 0xA2,
  0x09, 0x69, 0x81, 0xA3, 0x09, 0x69, 0xB1, 0xA3,
  0x09, 0x73, 0x81, 0xA3, 0x09, 0x73, 0xB1, 0xA3,
  0x09, 0x65, 0x81, 0xA3, 0x09, 0x65, 0xB1, 0xA3,
  0x95, 0x02, 0x81, 0x01, 0xB1, 0x01,
  0xC0, 0xC0, 0xC0
};

Adafruit_USBD_HID usb_hid;

static uint8_t  storeData[33][2];
static uint8_t  storeLen[33];

static void setStore8(uint8_t id, uint8_t v) {
  storeData[id][0] = v; storeLen[id] = 1;
}
static void setStore16(uint8_t id, uint16_t v) {
  storeData[id][0] = v & 0xFF; storeData[id][1] = v >> 8; storeLen[id] = 2;
}

uint16_t get_report_cb(uint8_t report_id, hid_report_type_t report_type,
                       uint8_t* buffer, uint16_t reqlen) {
  (void) report_type;
  if (report_id > 32 || storeLen[report_id] == 0) return 0;
  uint16_t n = storeLen[report_id];
  if (n > reqlen) n = reqlen;
  memcpy(buffer, storeData[report_id], n);
  return n;
}

void set_report_cb(uint8_t report_id, hid_report_type_t report_type,
                   uint8_t const* buffer, uint16_t bufsize) {
  (void) report_type;
  if (report_id > 32 || bufsize == 0) return;
  uint16_t n = bufsize > 2 ? 2 : bufsize;
  memcpy(storeData[report_id], buffer, n);
  storeLen[report_id] = n;
}

void setup() {
  TinyUSBDevice.setID(0x2000, 0x0001);
  TinyUSBDevice.setManufacturerDescriptor("Powerful");
  TinyUSBDevice.setProductDescriptor("SLE-2000 2.000 VA Line");
  TinyUSBDevice.setSerialDescriptor("PW2024SLE001");

  usb_hid.setPollInterval(10);
  usb_hid.setReportDescriptor(desc_hid_report, sizeof(desc_hid_report));
  usb_hid.setReportCallback(get_report_cb, set_report_cb);
  usb_hid.begin();

  setStore8(HID_PD_IPRODUCT, IPRODUCT);
  setStore8(HID_PD_SERIAL, ISERIAL);
  setStore8(HID_PD_MANUFACTURER, IMANUFACTURER);
  setStore8(HID_PD_RECHARGEABLE, 1);
  setStore8(HID_PD_IDEVICECHEMISTRY, IDEVICECHEMISTRY);
  setStore8(HID_PD_IOEMINFORMATION, IOEMVENDOR);
  setStore8(HID_PD_CAPACITYMODE, 2);          
  setStore8(HID_PD_CPCTYGRANULARITY1, 1);
  setStore8(HID_PD_CPCTYGRANULARITY2, 1);
  setStore8(HID_PD_FULLCHRGECAPACITY, 100);
  setStore8(HID_PD_DESIGNCAPACITY, 100);
  setStore8(HID_PD_REMAININGCAPACITY, 100);   
  setStore8(HID_PD_WARNCAPACITYLIMIT, 20);
  setStore8(HID_PD_REMNCAPACITYLIMIT, 10);
  setStore16(HID_PD_MANUFACTUREDATE, (2024 - 1980) * 512 + 1 * 32 + 1);
  setStore16(HID_PD_AVERAGETIME2FULL, 0);
  setStore16(HID_PD_AVERAGETIME2EMPTY, 3600); 
  setStore16(HID_PD_RUNTIMETOEMPTY, 3600);
  setStore16(HID_PD_REMAINTIMELIMIT, 600);    
  setStore16(HID_PD_DELAYBE4SHUTDOWN, (uint16_t)-1);
  setStore16(HID_PD_DELAYBE4REBOOT, (uint16_t)-1);
  setStore16(HID_PD_CONFIGVOLTAGE, 2400);     
  setStore16(HID_PD_VOLTAGE, 2400);           
  setStore8(HID_PD_AUDIBLEALARMCTRL, 2);
  
  // Varsayılan: Fişe takılı ve Tam Dolu (AC + Batt + Full)
  setStore16(HID_PD_PRESENTSTATUS, 0x010C);
}

// Yaşam Döngüsü Değişkenleri
static int cycle_counter = 0;
static int ops_state = 0; // 0: Normal Şebeke, 1: Self-Test (Elektrik Kesintisi), 2: Şarj Oluyor

void loop() {
  if (TinyUSBDevice.mounted() && usb_hid.ready()) {
    cycle_counter++;
    uint16_t current_status = 0x010C; 
    uint8_t current_capacity = 100;
    uint16_t current_voltage = 2400;

    // Durum 0: Normal Şebeke Akışı
    if (ops_state == 0) {
      current_status = 0x010C; // AC (0x04) + Batt (0x08) + Full (0x100)
      current_capacity = 100;
      current_voltage = random(2395, 2405); // Hafif dalgalanma
      
      if (cycle_counter > 300) { // Yaklaşık 10 dakikada bir (300 x 2 sn)
        ops_state = 1; // Self-Test moduna geç
        cycle_counter = 0;
      }
    } 
    // Durum 1: AC Şebeke Kesintisi (Self-Test / Aküye Geçiş)
    else if (ops_state == 1) {
      current_status = 0x0028; // AC Yok! Sadece Batt (0x08) + Discharging (0x20)
      current_capacity = 99;
      current_voltage = random(2300, 2350); // Akü yüke bindiği için voltaj düşer
      
      if (cycle_counter > 5) { // 10 saniyelik test (5 x 2 sn)
        ops_state = 2; // Şebeke geldi, şarja geç
        cycle_counter = 0;
      }
    } 
    // Durum 2: Şebeke Geri Geldi (Şarj Oluyor)
    else if (ops_state == 2) {
      current_status = 0x001C; // AC (0x04) + Batt (0x08) + Charging (0x10)
      current_capacity = 99;
      current_voltage = random(2410, 2430); // Şarj olduğu için voltaj yükselir
      
      if (cycle_counter > 15) { // 30 saniye şarjda kalır (15 x 2 sn)
        ops_state = 0; // Batarya doldu, normale dön
        cycle_counter = 0;
      }
    }

    // Sisteme verileri kaydet
    setStore16(HID_PD_PRESENTSTATUS, current_status);
    setStore8(HID_PD_REMAININGCAPACITY, current_capacity);
    setStore16(HID_PD_VOLTAGE, current_voltage);

    // Windows'a anlık durumu bildir
    usb_hid.sendReport(HID_PD_PRESENTSTATUS, storeData[HID_PD_PRESENTSTATUS], 2);
    delay(20);
    usb_hid.sendReport(HID_PD_REMAININGCAPACITY, storeData[HID_PD_REMAININGCAPACITY], 1);
    delay(20);
    usb_hid.sendReport(HID_PD_VOLTAGE, storeData[HID_PD_VOLTAGE], 2);
  }
  delay(2000); // 2 saniyelik ana döngü
}
