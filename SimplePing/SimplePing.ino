#include <EtherCard.h>


static byte mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 }; 
/* Mac address that should be unique in network */

byte Ethernet::buffer[700];
static uint32_t timer;

const char website[] PROGMEM = "www.google.com";
/* website to connect */

/* called when the client request is complete */
static void my_callback (byte status, word off, word len) {
  Serial.println(">>>");
  Ethernet::buffer[off+300] = 0;
  Serial.print((const char*) Ethernet::buffer + off);
  Serial.println("...");
}

void setup () {
  Serial.begin(57600);
  Serial.println(F("\n[web browser]"));

  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0) 
    Serial.println(F("Ethernet connection error"));
  if (!ether.dhcpSetup())
    Serial.println(F("DHCP error"));

  ether.printIp("IP:  ", ether.myip);
  ether.printIp("GW:  ", ether.gwip);  
  ether.printIp("DNS: ", ether.dnsip);  

  if (!ether.dnsLookup(website))
    Serial.println("DNS failed");
    
  ether.printIp("SRV: ", ether.hisip);
}

void loop () {
  ether.packetLoop(ether.packetReceive());
  
  if (millis() > timer) {
    timer = millis() + 5000;
    Serial.println();
    Serial.print("Connecting...");
    ether.browseUrl(PSTR(""), "", website, my_callback);
  }
}
