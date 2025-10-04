//code ini dibuat secara manual oleh shello ardiansyah XI TJKT (github.com/AkazawaKazairo)
//script ini tidak diperjualbelikan dan siapa saja boleh menggunakan dan recode script ini
//laporkan kepada saya jika ada yang memperjualbelikan script ini! (wa: 08511732330)

// ganti template_id dan template_name sesuai dengan templatemu
#define BLYNK_TEMPLATE_ID "TMPL6YsmZ2kd-"
#define BLYNK_TEMPLATE_NAME "esp8266 relay"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Token dari device di Blynk Console (ganti sesuai tokenmu)
char auth[] = "kbBLFIIdh9zX9gXWgRWmf7J0AuRYMu7Z";

// WiFi yang akan digunakan untuk menjalankan project
char ssid[] = "Ardi Setengah Matang";
char pass[] = "1029384756";

// Pin relay
int relay1 = D1; // GPIO5
int relay2 = D2; // GPIO4

void setup()
{
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, HIGH); // Awal mati (karena aktif LOW)
  digitalWrite(relay2, HIGH);
  Blynk.begin(auth, ssid, pass);
}

// Relay 1 (V0)
BLYNK_WRITE(V0)
{
  int value = param.asInt(); // 0 = OFF, 1 = ON
  digitalWrite(relay1, value); // tambahkan tanda ! sebelum value jika relay terbalik
}

// Relay 2 (V1)
BLYNK_WRITE(V1)
{
  int value = param.asInt();
  digitalWrite(relay2, value); // tambahkan tanda ! sebelum value jika relay terbalik
}

void loop()
{
  Blynk.run();
}