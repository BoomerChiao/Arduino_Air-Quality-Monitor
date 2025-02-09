#include <Wire.h>
#include <AHT20.h>
#include <Adafruit_SHT4x.h>
#include <SGP30.h>
#include <SoftwareSerial.h> 
#include <PMS.h>
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#define imgWidth 128
#define imgHeight 64
SoftwareSerial Serial1(2, 3); // Arduino Pin2 is set to RX, Pin3 is set to TX
SoftwareSerial TJC(8,9);


PMS pms(Serial1);
PMS::DATA data;
SGP30 SGP;
Adafruit_SHT4x sht4 = Adafruit_SHT4x();
AHT20 aht20;
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); //Arduino搭配SSD1306(0.96" OLED)用這行

float TT,HH,AHT_T,AHT_H,SHT_T,SHT_H,H2,ETH;
int pm1,pm2,pm3,HT_SW,HT_adjustment_C;
unsigned short int TVOCa,ECO2a;//USART HMI
signed short int TTT,TTA,TTS,HHH,HHA,HHS,HH2,EETH;//USART HMI
unsigned short int TVOC,ECO2;
//char ;
bool HT_adjustment_A=false,HT_adjustment_B=false;

int val1,val3,val4;
float val2;


void setup()
{
  Serial.begin(9600);
  TJC.begin(9600);
  Serial1.begin(9600);
  

  pinMode( 7, INPUT_PULLUP );  //SWitch on/off
  while (!Serial){
    delay(10);
  }
  Wire.begin(); //Join I2C bus
  //Serial.println(F("Humidity AHT20 examples"));
  //Check if the AHT20 will acknowledge
  HT_line();
  

  if (! SGP.begin()){
    Serial.println(F("SGP Sensor not found :("));
    while (1);
  }
  SGP.GenericReset();
  u8g2.begin();
  u8g2.clearBuffer();
  }

void loop()
{
  //SGP.measure(true); //  returns false if no measurement is made 
  //HT_adjustment();
  if (pms.read(data))
  {
    HT_adjustment();//load debug..
    Serial.print(F("Temperature sensor abnormal code："));
    Serial.println(HT_SW);
    switch (HT_SW) {
      case 1:
      SHT40();
      TT = SHT_T; HH = SHT_H;
      break;

      case 2:
      AHT20();
      TT = AHT_T; HH = AHT_H;
      break;

      case 3:
      break;

      default:
      AHT20();
      SHT40();
      TT = (AHT_T+SHT_T)/2; HH = (AHT_H+SHT_H)/2;
      break;
      }
  
    HT_adjustment_txt();
    SGP30();
    PMS();
    HT_A();
    powerBT();
    USART_HMI();

    //HT_line();
  //delay(1000);
  

  }
}


void HT_line(void){

  HT_SW = 0;
  if (! aht20.begin())
  {
    Serial.println(F("AHT20 not detected. Please check wiring. Freezing."));
    HT_SW = HT_SW+1;
   // while (1);
    delay(100);
  }
  
  
  if (! sht4.begin()) {
    Serial.println(F("Couldn't find SHT4x"));
    HT_SW = HT_SW+2;
    //while (1) 
    delay(100);
  }
}


void AHT20(void)
{
  AHT_T = aht20.getTemperature();
  AHT_H = aht20.getHumidity();
  //If a new measurement is available
  //if (aht20.isConnected() == true)
  {
    //Get the new temperature and humidity value
    //float temperature = aht20.getTemperature();
    //float humidity = aht20.getHumidity();
    //Print the results
    Serial.print(F("AHT_Temperature: "));
    Serial.print(AHT_T, 2);
    Serial.print(F(" C\t"));
    Serial.print(F("Humidity: "));
    Serial.print(AHT_H, 2);
    Serial.print(F("% RH"));
    Serial.println();
  }
}

void SHT40(void){
  sensors_event_t humidity, temp;
  sht4.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  SHT_T=temp.temperature; 
  SHT_H=humidity.relative_humidity;
  Serial.print(F("SHT_Temperature: ")); Serial.print(temp.temperature); Serial.println(F(" degrees C"));
  Serial.print(F("SHT_Humidity: ")); Serial.print(humidity.relative_humidity); Serial.println(F("% rH"));
  /*Serial.print("Read duration (ms): ");
  Serial.println(timestamp);*/
}

void SGP30(void){
  SGP.measure(true);      //  returns false if no measurement is made 
  TVOC=SGP.getTVOC();   ECO2=SGP.getCO2();    H2=SGP.getH2();   ETH=SGP.getEthanol();
  if(SGP.getH2_raw() > 13119){ //0.5 the following situations is not appropriate 以下不適配
    H2=0; 
  }
  if(SGP.getEthanol_raw() > 18471){ //0.5the following situations is not appropriate 以下不適配
    ETH=0;
  }

  Serial.print(F("TVOC (ppb): "));
  Serial.print(TVOC);
  Serial.print(F("\t eCO2 (ppm): "));
  Serial.println(ECO2);
  Serial.print(F("H2 (ppm): "));
  Serial.print(H2);
  Serial.print(F("\t ETH (ppm):"));
  Serial.println(ETH);
  //Serial.println();
}

void PMS(void){
  pm1=data.PM_AE_UG_1_0;
  pm2=data.PM_AE_UG_2_5;
  pm3=data.PM_AE_UG_10_0;
  Serial.print(F("PM 1.0 (ug/m3): "));
  Serial.println(pm1);
  Serial.print(F("PM 2.5 (ug/m3): "));
  Serial.println(pm2);
  Serial.print(F("PM 10.0 (ug/m3): "));
  Serial.println(pm3);
  Serial.println();
}

void HT_A(void){
  //u8g2.setFont(u8g2_font_UnnamedDOSFontIV_tr); //Set font 設定字型
  u8g2.firstPage();
  do {
    u8g2.setDrawColor(1);
    u8g2.setFont(u8g2_font_streamline_weather_t);//Set font 設定字型
    u8g2.drawGlyph(
      5, 23, 0x36);

    u8g2.setDrawColor(0);
    switch (HT_SW) {
      case 1:
      u8g2.drawBox(18,4,5,6); //1
      break;

      case 2:
      u8g2.drawBox(18,4,5,10);
      u8g2.setDrawColor(1);
      u8g2.drawBox(18,8,4,2);
      break;

      case 3:
      u8g2.drawBox(18,4,5,10);
      break;

      default:
      u8g2.drawBox(18,4,5,3); //2
      break;
      }
    //u8g2.drawBox(18,4,5,3); //2
    //u8g2.drawBox(18,4,5,6); //1
    //u8g2.drawBox(18,4,5,10); //0
    //u8g2.setDrawColor(1);
    //u8g2.drawBox(18,8,4,2); //

    u8g2.setDrawColor(1);
    u8g2.setFont(u8g2_font_luBIS18_tr);//Set font 設定字型
    u8g2.setCursor(26,19);
    u8g2.print(":");
    u8g2.print(TT,1);
    u8g2.print("*C");

    u8g2.setFont(u8g2_font_open_iconic_thing_2x_t); //Set font 設定字型
    u8g2.drawGlyph(5, 40, 0x48);
    u8g2.setFont(u8g2_font_luBIS18_tr);//Set font 設定字型
    u8g2.setCursor(26,40);
    u8g2.print(":");
    u8g2.print(HH,1);
    u8g2.print(" %");


    u8g2.setFont(u8g2_font_squeezed_b6_tr); //Set font 設定字型
    u8g2.setCursor(0,48);
    u8g2.print("TVOC : ");
    u8g2.print(TVOC);
    u8g2.setCursor(70,48);
    u8g2.print("ppb");
    if (HT_adjustment_A == true){
      u8g2.setCursor(122,51);
      u8g2.print("*");
    }
    
    u8g2.setCursor(0,56);
    u8g2.print("eCO2 : ");
    u8g2.print(ECO2);
    u8g2.setCursor(70,56);
    u8g2.print("ppm");

    u8g2.setCursor(0,64);
    u8g2.print("PM2.5: ");
    u8g2.print(pm2);
    //u8g2.setCursor(70,64);

    
    u8g2.setCursor(70,64);
    u8g2.print("BAT: ");
    //u8g2.print(val2);
    val3=(val2-3)*93;
    if(val3<0){
      val3=0;
    }
    else if(val3>=100)
    {
      val3=100;
    }

    u8g2.print(val3);
    u8g2.print(" %");

  } while ( u8g2.nextPage() );
}

void HT_adjustment(void){
  if (digitalRead( 7 ) == false){
    HT_adjustment_C=HT_adjustment_C+1;
    if (HT_adjustment_C >3){
    if (HT_adjustment_A ==true){
      SGP.GenericReset();
      HT_adjustment_A =false;
      HT_adjustment_C=0;
      //Serial.print(F("HT adjustment off !!!"));
    }
  else if(HT_adjustment_A ==false){
    SGP.GenericReset();
    HT_adjustment_A =true;
    HT_adjustment_C=0;
  }}}
  else{HT_adjustment_C=0;}
  
}


void HT_adjustment_txt(void){
  if (HT_adjustment_A == true)
  {
    //Serial.println(HT_adjustment_A);
    //HT_adjustment_A ==true;
    Serial.print(F("HT adjustment on :"));
    Serial.println(SGP.setRelHumidity(TT, HH), HEX);
  }
  else
  {
    //Serial.println(HT_adjustment_A);
    Serial.println(F("HT adjustment off !!!"));

  } }

void USART_HMI(void){

  TTT=TT*100;
  char strTT[20];
  sprintf(strTT, "TempT.val=%d", TTT);
  TJC.print(strTT);
  //TJC.write("TempT.val=%d", TTT);
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);

  TTA=AHT_T*100;
  char strTTA[20];
  sprintf(strTTA, "TempA.val=%d", TTA);
  TJC.print(strTTA);
  //TJC.write("TempT.val=%d", TTT);
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);

  TTS=SHT_T*100;
  char strTTS[20];
  sprintf(strTTS, "TempS.val=%d", TTS);
  TJC.print(strTTS);
  //TJC.write("TempT.val=%d", TTT);
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);


  HHH=HH*100;
  char strHH[20];
  sprintf(strHH, "HumiT.val=%d", HHH);
  TJC.print(strHH);
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);

  HHA=AHT_H*100;
  char strHHA[20];
  sprintf(strHHA, "HumiA.val=%d", HHA);
  TJC.print(strHHA);
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);

  HHS=SHT_H*100;
  char strHHS[20];
  sprintf(strHHS, "HumiS.val=%d", HHS);
  TJC.print(strHHS);
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);


  TVOCa=TVOC;
  if (TVOCa>=30000){
    TVOCa=30000;
  }
  char strTVOC[20];
  sprintf(strTVOC, "TVOC.val=%d", TVOCa);
  TJC.print(strTVOC);
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);

  ECO2a=ECO2;
  if (ECO2a>=30000){
    ECO2a=30000;
  }
  char strECO2[20];
  sprintf(strECO2, "CO2.val=%d",ECO2a);
  //sprintf(strECO2, "n2.val=%d", ECO2);
  TJC.print(strECO2);
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);

  HH2=H2*10;
  char strH2[20];
  sprintf(strH2, "H2.val=%d", HH2);
  TJC.print(strH2);
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);

  EETH=ETH*10;
  char strETH[20];
  sprintf(strETH, "ETH.val=%d", EETH);
  TJC.print(strETH);
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);


  char strpm2[20];
  sprintf(strpm2, "PM25.val=%d", pm2);
  TJC.print(strpm2);
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);

  char strpm1[20];
  sprintf(strpm1, "PM10.val=%d", pm1);
  TJC.print(strpm1);
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);

  char strpm3[20];
  sprintf(strpm3, "PM100.val=%d", pm3);
  TJC.print(strpm3);
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);

  char strBAT[20];
  val4=val1/2.8;
  sprintf(strBAT, "BAT.val=%d", val4);
  TJC.print(strBAT);
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);

  char strHTADJ[20];
  sprintf(strHTADJ, "HTADJ.val=%d", HT_adjustment_A);
  TJC.print(strHTADJ);
  TJC.write(0xff);
  TJC.write(0xff);
  TJC.write(0xff);
}


void powerBT(void)
{
float temp;
      val1=analogRead(A0);
      temp=val1/2.8;
      val2=(temp/10);

      Serial.print(F("Voltage value："));
      Serial.print(val1);
      Serial.print(F("    "));
      Serial.println(val2);
      /*Serial.print(F("    "));
      Serial.println(val3);
      Serial.println(HT_adjustment_A);
      Serial.println(HT_adjustment_B);
      Serial.println(HT_adjustment_C);*/
}
