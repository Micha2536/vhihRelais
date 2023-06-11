

String PARAM_SSID = "inputSsid";
String PARAM_PASSWORT = "inputPasswort";
String PARAM_reset = "reset";
String PARAM_relay1 = "relay1";
String PARAM_relay2 = "relay2";
String PARAM_relay3 = "relay3";
String PARAM_relay4 = "relay4";

#define index_html_version 180102

// HTML web page to handle input fields
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>ESP vhih Konfiguration</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <script>
    function submitMessage() {
      //alert("Wert gespeichert");
      setTimeout(function(){ document.location.reload(false); }, 500);   
    }
  </script>
 </head>
 <body>
  <center>
   <h1>** ESP vhih WLAN Konfiguration **</h1>
  <form action="/get" target="hidden-form">
    Eingabe SSID (Aktuelle SSID %inputSsid%): <input type="text" name="inputSsid">
    <input type="submit" value="Speichern" onclick="submitMessage()">
  </form><br>
  <form action="/get" target="hidden-form">
    Eingabe WLAN Passwort: <input type="text" name="inputPasswort">
    <input type="submit" value="Speichern" onclick="submitMessage()">
  </form><br>
  <form method="/get" >
  <button type="submit" value="true" name="reset" onclick="submitMessage()">Neustart</button>
 </form><br>
 <form  action="/get">
    <input  type="hidden" name="relay1" value=true /><input style="color:%relay1%" type="submit" value="Relay1 ON/OFF">
</form><form  action="/get">
    <input  type="hidden" name="relay2" value=true /><input style="color:%relay2%" type="submit" value="Relay2 ON/OFF">
</form><form  action="/get">
    <input  type="hidden" name="relay3" value=true /><input style="color:%relay3%" type="submit" value="Relay3 ON/OFF">
</form><form  action="/get">
    <input  type="hidden" name="relay4" value=true /><input style="color:%relay4%" type="submit" value="Relay4 ON/OFF">
</form>
</body></html>)rawliteral";

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}
