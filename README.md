# Arduino_Air-Quality-Monitor
The Arduino based air quality monitoring system combines several sensors to measure various environmental factors.

##  Summary　（概要）
The Arduino Air Quality Monitor is a high-performance air quality monitoring device designed based on the Arduino Pro Mini microcontroller (MCU). It integrates multiple advanced sensing technologies to provide precise monitoring of environmental air quality.

The device is equipped with the SGP40 gas sensor module (for detecting TVOC and CO2 concentrations), AHT20 and SHT40 temperature and humidity sensors, which can accurately measure the temperature and humidity levels in the air. Moreover, the PMS9003M air particulate matter sensor measures concentrations of PM1.0, PM2.5, and PM10, enabling a comprehensive evaluation of airborne particulate pollutants.

For display, the system uses either a TFT color LCD screen or an OLED display panel, offering intuitive, real-time visual presentation of various air quality indicators, moving beyond traditional warning lights or monotonous numeric displays. This not only enables users to easily monitor environmental changes but also aids in the long-term collection and analysis of data, leading to effective air quality management and optimization, ultimately enhancing the air quality in living and working spaces.



###  中文
Arduino Air Quality Monitor 是一款高效能的空氣品質監測器，基於 Arduino Pro Mini 微控制器（MCU）設計，集成多種先進感測技術以實現對環境空氣品質的精確監測。

該設備搭載了 SGP40 氣體感測模組（用於檢測 TVOC 和 CO2 等氣體濃度）、AHT20 和 SHT40 溫濕感測器，能夠準確測量空氣中的溫度與濕度參數，並且配備 PMS9003M 空氣懸浮顆粒傳感器，用於測量 PM1.0、PM2.5 和 PM10 顆粒物濃度，全面評估空氣中的有害物質。

顯示方面，選用 TFT 彩色液晶顯示螢幕或 OLED 顯示面板，提供直觀的可視化顯示，並能即時呈現各項空氣品質指標，突破傳統的警示燈號或單調數字顯示方式。這不僅讓用戶能夠輕鬆監控環境變化，還有助於進行長期數據的收集與分析，從而實現有效的空氣質量管理和優化，進一步提升生活和工作空間的空氣品質。


##  Installation　（安裝）
Install Arduino software
- Arduino software downloads：https://www.arduino.cc/en/software
- 『Optional』 Taojingchi USART HMI software downloads：http://wiki2.tjc1688.com/download/usart_hmi.html

									
###  中文
安裝 Arduino 軟體
- Arduino 軟體下載：https://www.arduino.cc/en/software
- (非必要) 淘晶馳 USART HMI 軟體下載：http://wiki2.tjc1688.com/download/usart_hmi.html

![image](https://github.com/user-attachments/assets/f3161a06-ddbb-4171-99bf-20f8f908ab94)![image](https://github.com/user-attachments/assets/b0710f04-fd93-45aa-9160-a2d1f29711fd)



##  Import data　（導入資料）
1. Download GitHub Data or Create a New Arduino Project:
   - You can either download the necessary files from GitHub or start a new Arduino project.

2. Include the Required Arduino Libraries:
   - To add extra functionality, move the required Arduino library files to your project. You can download these libraries from the "Library" folder on GitHub.
   - Alternatively, open the Arduino IDE, go to the 「Sketch」 menu, and select 「Include Library」→「Manage Libraries...」 to access and install the libraries.

3. Import the Libraries:
   - After importing the function libraries, select the project you wish to work on and integrate the necessary code.


###  中文
1. 下載 GitHub 資料或創建新 Arduino 專案：
   - 你可以從本網的 GitHub 下載所需的資料，或是自行創建一個新的 Arduino 專案。
    
2. 導入必要的程式函數庫：
   - 將必要的函數庫文件從 GitHub 的“Library”資料夾中下載並安裝至指定位置。
   - 你也可以在 Arduino IDE 中選擇「草稿碼」→「匯入程式庫」→「管理程式庫...」，然後下載所需的程式函數庫。

3. 完成函數庫導入後：
   - 選擇你要製作的專案並直接開啟即可開始使用。


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

以下提供兩種不同的引腳接線方式，主要針對不同的面板類型。

請依據你的成品需求進行接線。下圖分別展示 OLED Display 與 TJC3224T128_011R_A01 的接線方式。

![image](https://github.com/user-attachments/assets/27b40138-775a-4e6f-b1ef-655c7a60583f)
- 請注意，該設計僅持支援 5V 電壓範圍。因此，建議將 VCC 預設為 5V 電源以確保正常運作。
- Arduino Pro Mini: A4 (SDA) ; A5 (SCL) ; D2 (PMS9003M_RXD) ; D3 (PMS9003M_TXD)
- AHT20: SDA (A4) ; SCL (A5)
- SHT40: SDA (A4) ; SCL (A5)
- SGP30: SDA (A4) ; SCL (A5)
- OLED Display: SDA (A4) ; SCL (A5)
- PMS9003M: RXD (D2) ; TXD (D3)

　　

![image](https://github.com/user-attachments/assets/c7ff4b5a-bc86-40f1-9ed6-1c33ea98351b)
- 請注意，該設計僅持支援 5V 電壓範圍。因此，建議將 VCC 預設為 5V 電源以確保正常運作。
- Arduino Pro Mini: A4 (SDA) ; A5 (SCL) ; D2 (PMS9003M_RXD) ; D3 (PMS9003M_TXD) ; D9 (TJC3224T128_RXD) ; D8 (TJC3224T128_TXD) 
- AHT20: SDA (A4) ; SCL (A5)
- SHT40: SDA (A4) ; SCL (A5)
- SGP30: SDA (A4) ; SCL (A5)
- PMS9003M: RXD (D2) ; TXD (D3)
- TJC3224T128: RXD (D9) ; TXD (D8)



##  Program Code　（程式代碼）
本次專題採用了網上提供程式數據庫進行管理和顯示，為了確保代碼能夠正常運行，請事先安裝五項程式庫分別為AHT20、Adafruit_SHT4x、SGP30、PMS、U8g2


以下程式庫安裝示範：

1. AHT20 Library
   - 用途：AHT20 用於 I²C 介面驅動、校準與數據讀取，以及溫濕度轉換與補償 等功能，使能夠讀取準確的環境數據。
   - 安裝方式如下
     - 打開 Arduino IDE 點擊「工具」 > 「管理庫...」。
     - 在程式庫管理器的搜索框中輸入 "AHT20"。
     - 在搜尋結果中找到 "AHT20" 點擊 「安裝」 按鈕。
       ![image](https://github.com/user-attachments/assets/d8d2d553-a49e-482b-b60f-660d08b17fdf)


       
2. Adafruit_SHT4x Library
   - 用途：用於 SHT4x 系列溫濕度感測器的 I²C 介面驅動、數據讀取、測量精度設定 等功能，使能夠讀取精確的環境溫濕度數據。
   - 安裝方式如下
     - 打開 Arduino IDE 點擊「工具」 > 「管理庫...」。
     - 在程式庫管理器的搜索框中輸入 "SHT4x"。
     - 在搜尋結果中找到 "Adafruit SHT4x Library" 點擊 「安裝」 按鈕。
       ![image](https://github.com/user-attachments/assets/89dd46f8-98a6-449b-bea9-2ceed2bb680f)



3. SGP30 Library
   - 用途：驅動 SGP30 感測器，透過 I²C 讀取 TVOC 和 eCO₂ 數據，執行基線校準與補償，提高測量準確度。
   - 安裝方式如下
     - 打開 Arduino IDE 點擊「工具」 > 「管理庫...」。
     - 在程式庫管理器的搜索框中輸入 "SGP30"。
     - 在搜尋結果中找到 "SGP30" 點擊 「安裝」 按鈕。
    ![image](https://github.com/user-attachments/assets/5bd1e041-0a4a-40fb-bebe-660f46146bdb)


4. PMS Library
   - 用途：主要用於驅動 PMS (Plantower) 系列空氣品質感測器，可測量讀取 PM1.0、PM2.5 和 PM10 懸浮微粒濃度。
   - 安裝方式如下
     - 打開 Arduino IDE 點擊「工具」 > 「管理庫...」。
     - 在程式庫管理器的搜索框中輸入 "PMS"。
     - 在搜尋結果中找到 "PMS Library" 點擊 「安裝」 按鈕。
       ![image](https://github.com/user-attachments/assets/a11838c0-11a1-451e-848f-320e05f28e70)

     
    
5. U8g2 Library
   - 用途：用於驅動 OLED/LCD 顯示器，支援 I²C、SPI 通訊，可顯示文字、圖形、圖片 等功能。
   - 安裝方式如下
     - 打開 Arduino IDE 點擊「工具」 > 「管理庫...」。
     - 在程式庫管理器的搜索框中輸入 "U8g2"。
     - 在搜尋結果中找到 "U8g2" 點擊 「安裝」 按鈕。
![image](https://github.com/user-attachments/assets/77dfd004-388f-4494-b862-28c7bc0570be)

安裝完成後，可前往 GitHub 的 Arduino code 資料夾，並下載 Aht20xSHT40xSgp30xPMSxU8G2xUSARTLCD 程式碼。
下載後，可將其匯入 Arduino IDE 或相應的開發環境，進行編譯與燒錄。

您可以從以下鏈接下載代碼：https://github.com/BoomerChiao/Arduino_Air-Quality-Monitor/tree/main/Code/Aht20xSHT40xSgp30xPMSxU8G2xUSARTLCD

.

.

P.S. 其他安裝Library
   - 打開 Arduino IDE 點擊「sketch」 > 「程式庫」 > 「加入.Zip程式庫...」。
   - 搜尋 已下載Zip程式庫 ，點擊 「開啟」 按鈕。
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
為了簡化電子製作過程，可採用PCB印刷技術，以取代雜亂且難以管理的線路。

這不僅能顯著降低錯誤連接的風險，還能提升產品的穩定性與可靠性，特別是在 小型化 設備中，PCB能有效整合精細的電路佈局，減少體積並提升生產效率，使產品更加輕薄且具備更高的性能表現。

###  Circuit Design （電路設計）
![image](https://github.com/user-attachments/assets/fc58c8ef-e276-4195-9208-d72b3a10fb52)
- 左側 MCU 電路的 I/O 口小電容可以用來 抑制低頻噪聲 ，並提高訊號穩定性。
- 而 I²C 通訊接口上的 上拉電阻 則確保 SCL 和 SDA 能夠正常運作，防止訊號浮空，降低誤觸發與數據錯誤的風險，進一步提升通訊可靠性，避免異常狀況發生。
- 右側 Connector USB1 主要設計 USB Type-C 充電輸入，CC（Configuration Channel）腳位加 5.1kΩ 下拉電阻其主要作為，識別設備為 Sink（受電設備），使 Source（供電設備）正確提供電力，確保正確的電流供應，根據 Source 端的電壓判斷最大可用電流，且支援 C to C 連接線的正確識別，即使使用 USB-C 充電器與 USB-C 線材，也能讓 Source 正確認定此設備為受電設備並進行供電。
- 而 Connector U7 插座對應匿名 IP5306，主要是為了兼容市面上常見的 IP5306 充電管理模組，方便直接連接使用。


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

⬆上圖所示的外殼分別為 Enclosure_A、Enclosure_B、Enclosure_C 和 Enclosure_Button 的 STL 檔案

.

![image](https://github.com/user-attachments/assets/5e6b1661-6399-4a89-9974-7d9b89bbcf68)

⬆上圖所示的外殼分別為 Enclosure_Bracket_A、Enclosure_Bracket_B 和 Enclosure_Bracket_C 的 STL 檔案

![image](https://github.com/user-attachments/assets/f5ed9a49-17f0-4481-8f44-68b133faf8a6)

檔案共 7 個，主要外殼檔案包含 Enclosure_A、Enclosure_B、Enclosure_C、Enclosure_Button 共 4 個，以及後支架 Enclosure_Bracket_A、Enclosure_Bracket_B、Enclosure_Bracket_C 共 3 個。

你可以在這裡獲得3D檔案下載：
https://github.com/BoomerChiao/Arduino_Air-Quality-Monitor/tree/main/Enclosure


