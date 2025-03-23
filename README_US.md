# Arduino_Air-Quality-Monitor
([中文](README.md) | English)

The Arduino based air quality monitoring system combines several sensors to measure various environmental factors.


##  Summary　（概要）
The Arduino Air Quality Monitor is a high-performance air quality monitoring device designed based on the Arduino Pro Mini microcontroller (MCU). It integrates multiple advanced sensing technologies to provide precise monitoring of environmental air quality.

The device is equipped with the SGP40 gas sensor module (for detecting TVOC and CO2 concentrations), AHT20 and SHT40 temperature and humidity sensors, which can accurately measure the temperature and humidity levels in the air. Moreover, the PMS9003M air particulate matter sensor measures concentrations of PM1.0, PM2.5, and PM10, enabling a comprehensive evaluation of airborne particulate pollutants.

For display, the system uses either a TFT color LCD screen or an OLED display panel, offering intuitive, real-time visual presentation of various air quality indicators, moving beyond traditional warning lights or monotonous numeric displays. This not only enables users to easily monitor environmental changes but also aids in the long-term collection and analysis of data, leading to effective air quality management and optimization, ultimately enhancing the air quality in living and working spaces.


##  Installation　（安裝）
Install Arduino software
- Arduino software downloads：https://www.arduino.cc/en/software
- 『Optional』 Taojingchi USART HMI software downloads：http://wiki2.tjc1688.com/download/usart_hmi.html


![image](https://github.com/user-attachments/assets/f3161a06-ddbb-4171-99bf-20f8f908ab94)![image](https://github.com/user-attachments/assets/b0710f04-fd93-45aa-9160-a2d1f29711fd)



##  Import data　（導入資料）
1. Download GitHub Data or Create a New Arduino Project:
   - You can either download the necessary files from GitHub or start a new Arduino project.

2. Include the Required Arduino Libraries:
   - To add extra functionality, move the required Arduino library files to your project. You can download these libraries from the "Library" folder on GitHub.
   - Alternatively, open the Arduino IDE, go to the 「Sketch」 menu, and select 「Include Library」→「Manage Libraries...」 to access and install the libraries.

3. Import the Libraries:
   - After importing the function libraries, select the project you wish to work on and integrate the necessary code.



##  Prepare Electronic Materials　（準備電子材料）
1. Arduino Pro Mini ATmage328 (5V/16M)
2. USB to UART Adapter (FTDI or CP2102)
3. 0.96' OLED Display 128×64 4Pin IIC I2C
4. 『Optional』TJC3224T128_011R_A01
5. PLANTOWER PMS9003M
6. AHT20
7. SHT40 (3.3~5V)
8. SGP30
9. Jumper Wires
![image](https://github.com/user-attachments/assets/32860887-41da-4aaa-b610-3b2edfed01f2)
![image](https://github.com/user-attachments/assets/11a21991-e7fd-4b30-83d2-aa7afde7e7ca)

##  Pin wiring　（引腳接線）

Here are two different wiring methods, designed for different panel types.

Please wire accordingly based on your project requirements.
The diagrams below illustrate the wiring for the OLED Display and TJC3224T128_011R_A01, respectively.

![image](https://github.com/user-attachments/assets/27b40138-775a-4e6f-b1ef-655c7a60583f)
- Please note that this design only supports a 5V voltage range. Therefore, it is recommended to set VCC to 5V by default to ensure proper operation.
- Arduino Pro Mini: A4 (SDA) ; A5 (SCL) ; D2 (PMS9003M_RXD) ; D3 (PMS9003M_TXD)
- AHT20: SDA (A4) ; SCL (A5)
- SHT40: SDA (A4) ; SCL (A5)
- SGP30: SDA (A4) ; SCL (A5)
- OLED Display: SDA (A4) ; SCL (A5)
- PMS9003M: RXD (D2) ; TXD (D3)

　　

![image](https://github.com/user-attachments/assets/c7ff4b5a-bc86-40f1-9ed6-1c33ea98351b)
- Please note that this design only supports a 5V voltage range. Therefore, it is recommended to set VCC to 5V by default to ensure proper operation.
- Arduino Pro Mini: A4 (SDA) ; A5 (SCL) ; D2 (PMS9003M_RXD) ; D3 (PMS9003M_TXD) ; D9 (TJC3224T128_RXD) ; D8 (TJC3224T128_TXD) 
- AHT20: SDA (A4) ; SCL (A5)
- SHT40: SDA (A4) ; SCL (A5)
- SGP30: SDA (A4) ; SCL (A5)
- PMS9003M: RXD (D2) ; TXD (D3)
- TJC3224T128: RXD (D9) ; TXD (D8)



##  Program Code　（程式代碼）
This project utilizes an online program database for management and display. To ensure the code runs properly, please install the following five libraries in advance: AHT20, Adafruit_SHT4x, SGP30, PMS, and U8g2.

Below is a demonstration of the library installation:

1. AHT20 Library
   - Purpose: AHT20 is used for I²C interface control, calibration, data reading, as well as temperature and humidity conversion and compensation. This enables accurate environmental data acquisition.
   - Installation Steps:
     - Open Arduino IDE and click "Tools" > "Manage Libraries...".
     - In the Library Manager search bar, enter "AHT20".
     - Find "AHT20" in the search results and click the "Install" button.
       ![image](https://github.com/user-attachments/assets/d8d2d553-a49e-482b-b60f-660d08b17fdf)


       
2. Adafruit_SHT4x Library
   - Purpose: Used for I²C interface control, data reading, and measurement accuracy settings of the SHT4x series temperature and humidity sensors, enabling precise environmental data acquisition.
   - Installation Steps:
     - Open Arduino IDE and click "Tools" > "Manage Libraries...".
     - In the Library Manager search bar, enter "SHT4x".
     - Find "Adafruit SHT4x Library" in the search results and click the "Install" button.
       ![image](https://github.com/user-attachments/assets/89dd46f8-98a6-449b-bea9-2ceed2bb680f)



3. SGP30 Library
   - Purpose: Drive the SGP30 sensor to read TVOC and eCO₂ data via I²C, perform baseline calibration and compensation to improve measurement accuracy.
   - Installation Steps:
     - Open Arduino IDE and click "Tools" > "Manage Libraries...".
     - In the Library Manager search bar, enter "SGP30".
     - Find "SGP30" in the search results and click the "Install" button.
    ![image](https://github.com/user-attachments/assets/5bd1e041-0a4a-40fb-bebe-660f46146bdb)


4. PMS Library
   - Purpose: Primarily used to drive the PMS (Plantower) series air quality sensors, which can measure and read the concentrations of PM1.0, PM2.5, and PM10 suspended particulate matter.
   - Installation Steps:
     - Open Arduino IDE and click "Tools" > "Manage Libraries...".
     - In the Library Manager search bar, enter "PMS".
     - Find "PMS Library" in the search results and click the "Install" button.
       ![image](https://github.com/user-attachments/assets/a11838c0-11a1-451e-848f-320e05f28e70)

     
    
5. U8g2 Library
   - Purpose: Used to drive OLED/LCD displays, supporting I²C and SPI communication, with the ability to display text, graphics, images, and more.
   - Installation Steps:
     - Open Arduino IDE and click "Tools" > "Manage Libraries...".
     - In the Library Manager search bar, enter "U8g2".
     - Find "U8g2" in the search results and click the "Install" button.
![image](https://github.com/user-attachments/assets/77dfd004-388f-4494-b862-28c7bc0570be)

After the installation is complete, you can go to the GitHub Arduino code folder and download the Aht20xSHT40xSgp30xPMSxU8G2xUSARTLCD code.
Once downloaded, you can import it into Arduino IDE or the appropriate development environment for compilation and uploading.

Download link：https://github.com/BoomerChiao/Arduino_Air-Quality-Monitor/tree/main/Code/Aht20xSHT40xSgp30xPMSxU8G2xUSARTLCD

.

.

P.S. Other Library Installation
   - Open Arduino IDE and click "Sketch" > "Include Library" > "Add .ZIP Library...".
   - Search for the downloaded .ZIP library and click the "Open" button.

##  USART HMI Code
After downloading and installing the installation package provided on the official website, you can open the application.
Next, select the USART HMI Code file "SGP_ARDUINO_.HMI" obtained from Git. After opening it, you can download the code to the purchased TJC3224T128_011R_A01 circuit board for flashing.

Download link：https://github.com/BoomerChiao/Arduino_Air-Quality-Monitor/tree/main/Code/USART%20HMI

1. After opening the "SGP_ARDUINO_.HMI" obtained from Git, simply click "下载".
![image](https://github.com/user-attachments/assets/82d4c529-5171-4741-a2a5-fa6b8e685ea8)
   

2. After clicking the "下载" button, the system will display the "串口下载" window. Then, click "连机并开始下载" to initiate the process.
![image](https://github.com/user-attachments/assets/33829e79-34ff-450c-8d9d-3e6059d6663a)
   

3. During the download process, the screen will display prompt messages such as "开始下载".
![image](https://github.com/user-attachments/assets/b45297b3-cfcf-47f2-a71b-aa637d75cb4b)
   - If it does not appear, please check if the USB connection is working properly. After re-plugging the USB port, reopen the "串口下载" window.


4. Please confirm if the USART HMI LCD is being updated.

![image](https://github.com/user-attachments/assets/78311e35-6c56-467b-8606-73c480535786)
   - If the screen displays the update progress, it means the download was successful.
   - If there is no update, please recheck the wiring and try again.


##  Arduino Pro or Pro Mini USB to UART Hookup Guide　（Arduino Pro、Pro Mini USB 燒入連接指南）
The Arduino Pro Mini and Arduino Pro are compact, low-power versions of the Arduino board. To program these boards or communicate with them via a computer, you'll need a USB-to-UART (Universal Asynchronous Receiver/Transmitter) adapter.

![image](https://github.com/user-attachments/assets/06e75a60-4666-4329-bbba-8ee2ec47657e)
Picture from：https://www.b4x.com/android/forum/threads/how-to-connect-an-arduino-pro-mini-to-a-pc-via-a-usb-to-serial-module.77010/
1. Steps to Connections
   - USB-to-UART Adapter VCC → Arduino Pro Mini VCC
     - USB-to-UART Adapter Pins Connect to Arduino Pro Mini VCC (make sure it matches the voltage of your Pro Mini)
   - USB-to-UART Adapter GND → Arduino Pro Mini GND
   - USB-to-UART Adapter TX → Arduino Pro Mini RX
   - USB-to-UART Adapter RX → Arduino Pro Mini TX
   - USB-to-UART Adapter DTR → Arduino Pro Mini DTR
2. Troubleshooting Tips
   - Check Connections： Ensure all wires are connected securely and to the correct pins.
   - Verify Voltage： Make sure the VCC connection matches the voltage requirements of your Pro Mini.
   - Auto-reset： If uploading code fails, try manually pressing the reset button on the Pro Mini just before uploading.

##  Advanced Design　（進階設計）
To simplify the electronics manufacturing process, PCB printing technology can be used to replace messy and difficult-to-manage wiring.

This not only significantly reduces the risk of incorrect connections but also enhances the stability and reliability of the product. Especially in compact devices, PCBs can effectively integrate intricate circuit layouts, reduce size, and improve production efficiency, making the product thinner and more powerful.

###  Circuit Design （電路設計）
![image](https://github.com/user-attachments/assets/fc58c8ef-e276-4195-9208-d72b3a10fb52)
- The small capacitor on the left-side MCU I/O pins suppresses low-frequency noise and improves signal stability.
- The pull-up resistors on the I²C interface ensure proper SCL and SDA operation, reducing the risk of signal floating and data errors.
- Connector USB1 is designed for USB Type-C charging input, with a 5.1kΩ pull-down resistor on the CC pin to identify the device as a Sink, enabling correct power supply from the Source.
- Connector U7 is compatible with the IP5306 charging management module for easy connection.


![image](https://github.com/user-attachments/assets/1ecd17ff-f9c4-4eb9-860a-081d3e06b4e9)

###  PCB layout （電路布局）

![image](https://github.com/user-attachments/assets/37251f03-d573-4346-a2e7-56e3a9b486cf)

###  PCB Prepare Electronic Materials　（PCB準備電子材料）
1. SMD MLCC 
   - C1、C2：N/A
   - C3、C4、C5、C6、C8：100nF-1206 or N/A
   - C9：10nF-0805 or N/A
   - C7：47uf-50v or  N/A
   - C10、C11、C12、C13、C14：22uF-1206
   - C15、C16：10uF-1206
   

2. SMD Resistors
   - R1：30kΩ-1206
   - R2：4.7kΩ-1206
   - R3、R4：5.1kΩ-1206
   - R5、R6：4.7kΩ-1206 or N/A
   - R7、R8：0~1.2kΩ-1206 or N/A
   - R9、R11：10kΩ-1206
   - R10:0.5Ω-1206
   - R12:2Ω-1206
   - F1：TLC-MSMD160/6 or 0Ω-1812

3. SMD Active component
   - D1：SMBJ6.0CA or N/A
   - U8：IP5306
   - U2：AMS1117-3.3
  
4. SMD LED
   - LED1、LED2、LED3、LED4：LED-1206 (XL-3216UGC)

5. SMD Inductor
   - L1：0650-1.0UH (CXP0650-1R0M-AG(1.0uh))
   - L2：1206-Ferrite Beads (CBW321609U800T)
   
6. DIP and SMD Connectors 
   - CN1：SMD P=1.25mm、1x8P、Surface Mount，Right Angle (YIYUAN YTC-A1251-08ABW)
   - U1、U2、U4、U5、U6：DIP 2.54mm Plugin 1x4P Female Headers (BX-PM2.54-1-4PY)
   - U7：DIP 2.54mm Plugin 1x6P Female Headers (BX-PM2.54-1-6PY)
   - U9：DIP 2.54mm Plugin 3P Straight 1x3P Pin Headers or 3P slide switch (BX-PZ2.54-1-3PZZ) or (3Pin Slide Switches-SPDT)
   - U10、U11：DIP 6x6x7mm With bracket Tactile Switches (ZX-QC66-7.0ZJ)
   - U11：N/A

7. Power Connector
   - USB：SMD TYPE-C 6Pin (KH-TYPE-C-6P-T)


###  3D casing （3D外殼）

![image](https://github.com/user-attachments/assets/2df0a756-9bfb-4d62-a3d2-f06f0fde024f)

![image](https://github.com/user-attachments/assets/24f6962f-13e3-4e89-b849-e94ffdba82e8)

⬆The enclosure shown in the image consists of the STL files for Enclosure_A, Enclosure_B, Enclosure_C, and Enclosure_Button.

.

![image](https://github.com/user-attachments/assets/5e6b1661-6399-4a89-9974-7d9b89bbcf68)

⬆The enclosure shown in the image consists of the STL files for Enclosure_Bracket_A, Enclosure_Bracket_B, and Enclosure_Bracket_C.

![image](https://github.com/user-attachments/assets/f5ed9a49-17f0-4481-8f44-68b133faf8a6)

The files consist of 7 pieces in total:
   - 4 main enclosure files: Enclosure_A, Enclosure_B, Enclosure_C, and Enclosure_Button.
   - 3 rear bracket files: Enclosure_Bracket_A, Enclosure_Bracket_B, and Enclosure_Bracket_C.
   
You can download the 3D files here：
https://github.com/BoomerChiao/Arduino_Air-Quality-Monitor/tree/main/Enclosure


