#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

const char* ssid = "YU";
const char* password = "1qaz2wsx";
String main="<html>\
                    <head>\
                          <title>YUesp32demo</title>\
                    </head>\
                    <body bgcolor=\"#000000\" text = \"#FF3030\">\
                          <h1>Hello form YUesp32!</h1>\
                              <br>IP:192.168.137.196\</br>\
                              <br><a href=\"/inline\">SecondPage</a></br>\
                              <br><input type=\"button\" value=\"LED ON\" onclick=\"location.href='/H'\">\
                                  <input type=\"button\" value=\"LED OFF\" onclick=\"location.href='/L'\"></br>\
                      </body>\
               </html>";

WebServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);
  WiFi.begin(ssid, password);
  pinMode(2, OUTPUT);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address:");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("YUesp32"))
  {
    Serial.println("MDNS responder started");
  }
  server.on("/", handleRoot);
  server.on("/H", LEDON);
  server.on("/L", LEDOFF);
  server.begin();
}

void LEDON()
{
  digitalWrite(2, HIGH);
  server.send(200, "text/html",
              "<html>\
              <head>\
              <title>YUesp32demo</title>\
              </head><body text = \"#FF3030\">LED ON!\
              </body>\
              </html>");
}

void LEDOFF()
{
  digitalWrite(2, LOW);
  server.send(200, "text/html",main);
}

void handleRoot()
{
  //  server.send(200,"text/html",
  //  "<html><head><title>YUesp32demo</title></head><body><h1><font color=\"red\">Hello form YUesp32!</font></h1></body></html>");
  server.send(200, "text/html",
              "<html>\
                    <head>\
                          <title>YUesp32demo</title>\
                    </head>\
                    <body bgcolor=\"#000000\" text = \"#FF3030\">\
                          <h1>Hello form YUesp32!</h1>\
                              <br>IP:192.168.137.196\</br>\
                              <br><a href=\"/inline\">SecondPage</a></br>\
                              <br><input type=\"button\" value=\"LED ON\" onclick=\"location.href='/H'\">\
                                  <input type=\"button\" value=\"LED OFF\" onclick=\"location.href='/L'\"></br>\
                      </body>\
               </html>");

  //<a href=\"http://192.168.137.196/inline\">SecondPage</a>超連結
  //<button type="button">LED ON</button> html button語法
  //<br>換行</br>
  //<input type="button" value="第二頁" onclick="location.href='http://192.168.137.196/inline'">


  server.on("/inline", []() {//第二頁http://192.168.137.196/inline
    server.send(200, "text/plain", "this works as well");
  });
  //把式子宣告極簡化，不好閱讀
}

void loop() {
  server.handleClient();

}
