# Arduino_Air-Quality-Monitor
(中文 | [English](README_US.md))

![image](https://github.com/user-attachments/assets/69f7d60f-dce7-4d65-ac8b-84a9e41473f2)

The Arduino based air quality monitoring system combines several sensors to measure various environmental factors.

基於 Arduino 的空氣品質監測系統結合多種感測器來測量各種環境因素。

##  Summary　（概要）
Arduino Air Quality Monitor 是一款高效能的空氣品質監測器，基於 Arduino Pro Mini 微控制器（MCU）設計，集成多種先進感測技術以實現對環境空氣品質的精確監測。

該設備搭載了 SGP40 氣體感測模組（用於檢測 TVOC 和 CO2 等氣體濃度）、AHT20 和 SHT40 溫濕感測器，能夠準確測量空氣中的溫度與濕度參數，並且配備 PMS9003M 空氣懸浮顆粒傳感器，用於測量 PM1.0、PM2.5 和 PM10 顆粒物濃度，全面評估空氣中的有害物質。

顯示方面，選用 TFT 彩色液晶顯示螢幕或 OLED 顯示面板，提供直觀的可視化顯示，並能即時呈現各項空氣品質指標，突破傳統的警示燈號或單調數字顯示方式。這不僅讓用戶能夠輕鬆監控環境變化，還有助於進行長期數據的收集與分析，從而實現有效的空氣質量管理和優化，進一步提升生活和工作空間的空氣品質。


##  Installation　（安裝）
安裝 Arduino 軟體
- Arduino 軟體下載：https://www.arduino.cc/en/software
- (非必要) 淘晶馳 USART HMI 軟體下載：http://wiki2.tjc1688.com/download/usart_hmi.html

![image](https://github.com/user-attachments/assets/f3161a06-ddbb-4171-99bf-20f8f908ab94)![image](https://github.com/user-attachments/assets/b0710f04-fd93-45aa-9160-a2d1f29711fd)



##  Import data　（導入資料）
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

您可以從這裡下載代碼：https://github.com/BoomerChiao/Arduino_Air-Quality-Monitor/tree/main/Code/Aht20xSHT40xSgp30xPMSxU8G2xUSARTLCD

.

.

P.S. 其他安裝Library
   - 打開 Arduino IDE 點擊「sketch」 > 「程式庫」 > 「加入.Zip程式庫...」。
   - 搜尋 已下載Zip程式庫 ，點擊 「開啟」 按鈕。

##  USART HMI Code
依據官網提供的安裝包下載並安裝後，即可開啟應用程式。
接著，選擇從 Git 取得的 USART HMI Code 程式檔案「SGP_ARDUINO_.HMI」，開啟後即可將程式碼下載至購買的 TJC3224T128_011R_A01 電路板上進行燒錄。

您可以從這裡下載代碼：https://github.com/BoomerChiao/Arduino_Air-Quality-Monitor/tree/main/Code/USART%20HMI

1. 開啟 Git 取得的「SGP_ARDUINO_.HMI」後，直接點擊「下載」。
![image](https://github.com/user-attachments/assets/82d4c529-5171-4741-a2a5-fa6b8e685ea8)
   

2. 「下載」按鈕點擊完成後，系統會跳出「串口下載」視窗。接著，點擊 「連機並開始下載」 以啟動程序。
![image](https://github.com/user-attachments/assets/33829e79-34ff-450c-8d9d-3e6059d6663a)
   

3. 下載過程中，畫面會顯示「開始下載」等提示訊息。
![image](https://github.com/user-attachments/assets/b45297b3-cfcf-47f2-a71b-aa637d75cb4b)
   - 若未顯示，請檢查 USB 連接是否正常，重新插拔 USB 端口後，再次開啟「串口下載」視窗。


4. 確認 USART HMI LCD 是否正在更新。

![image](https://github.com/user-attachments/assets/78311e35-6c56-467b-8606-73c480535786)
   - 若畫面顯示更新進度，表示下載成功。
   - 若無更新，請重新檢查線路並重試。


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


##  UI、UX　（使用者介面）
![image](https://github.com/user-attachments/assets/8b8f1606-1367-4109-b8cf-43c25be71b0b)

本專題支援 LCD 與 OLED 兩種顯示使用者介面，分別針對不同使用者應用情境設計，以提供簡便且高效率的使用體驗。
以下將分別簡述說明兩種使用者介面上，各功能區塊的用途與操作方式。

1. 上圖左側畫面為 LCD 介面功能說明
   - Setting Button（設定按鈕）：點擊進入基本設定頁面。
   - Battery Power（電池電量顯示）：顯示目前電池電壓（尚未精準校正）。
   - TH Sensor Display（溫濕度顯示）：顯示目前溫度與濕度數值，點擊後可進入後台查看感測數據與簡易圖表。
   - Gas Level Display（氣體濃度顯示）：顯示空氣中氣體濃度，點擊後可查看詳細數據與簡易圖表。
   - PM2.5 Display（懸浮粒子顯示）：顯示空氣中不同粒徑懸浮顆粒數據，點擊後可查看詳細圖表與變化趨勢。

2. 上圖右側畫面為 OLED 介面功能說明
   - Battery（電池電量顯示）：顯示目前電池電壓（尚未精準校正）。
   - TH Sensor Display（溫濕度顯示）：顯示目前感測到的溫度與濕度數值。
   - Gas Level Display（氣體濃度顯示）：顯示氣體感測器目前偵測到的各項濃度值。
   - PM2.5 Display（懸浮粒子顯示）：顯示空氣中懸浮微粒（PM2.5）濃度。
   - TVOC Detection+（TVOC 強化模式）：畫面若出現「＊」符號，表示已開啟 TVOC 強化模式，將溫濕度一併納入判斷；若無則為預設模式。

‼️P.S 針對TVOC強化模式的啟動或關閉條件設定，請將 D7 腳位進行接地3秒後，鬆開 D7 腳位，即可觸發TVOC強化模式的啟動或關閉條件。


   

##  Advanced Design　（進階設計）
為了簡化電子製作過程，可採用PCB印刷技術，以取代雜亂且難以管理的線路。

這不僅能顯著降低錯誤連接的風險，還能提升產品的穩定性與可靠性，特別是在 小型化 設備中，PCB能有效整合精細的電路佈局，減少體積並提升生產效率，使產品更加輕薄且具備更高的性能表現。

您可於此下載 Gerber 檔案，並上傳至 JLCPCB 進行 PCB 訂製

Gerber：https://github.com/BoomerChiao/Arduino_Air-Quality-Monitor/tree/main/PCB

JLCPCB：https://jlcpcb.com/

您也可在此下載原理圖及 PCB 檔案，以進行後續編輯。

oshwlab：https://oshwlab.com/chiaochieh/sgp30xshtxarduino_pro_202412

###  Circuit Design （電路設計）
![image](https://github.com/user-attachments/assets/fc58c8ef-e276-4195-9208-d72b3a10fb52)
- 左側 MCU 電路的 I/O 口小電容可以用來 抑制低頻噪聲 ，並提高訊號穩定性。
- 而 I²C 通訊接口上的 上拉電阻 則確保 SCL 和 SDA 能夠正常運作，防止訊號浮空，降低誤觸發與數據錯誤的風險，進一步提升通訊可靠性，避免異常狀況發生。
- 右側 Connector USB1 主要設計 USB Type-C 充電輸入，CC（Configuration Channel）腳位加 5.1kΩ 下拉電阻其主要作為，識別設備為 Sink（受電設備），使 Source（供電設備）正確提供電力，確保正確的電流供應，根據 Source 端的電壓判斷最大可用電流，且支援 C to C 連接線的正確識別，即使使用 USB-C 充電器與 USB-C 線材，也能讓 Source 正確認定此設備為受電設備並進行供電。
- 而 Connector U7 插座對應匿名 IP5306，主要是為了兼容市面上常見的 IP5306 充電管理模組，方便直接連接使用。


![image](https://github.com/user-attachments/assets/1ecd17ff-f9c4-4eb9-860a-081d3e06b4e9)
- Power management 採用IP5306進行電源管理，該晶片具備升壓功能及電池電源多重管理，能顯著減少周圍零件的需求，並有效縮小電源模組的體積。
- Voltage Monitoring 電壓檢測電路的設計原理基於電阻分壓方式，透過分壓器將輸入電壓壓縮至控制器可讀取的範圍內，從而實現對電壓的有效監控。
- U10 按鈕設計主要用於觸發D7腳位接地，從而啟動或完成特定的功能應用。
- 其餘的PMS1、SGP、AHT_A、SHT、OLED、LCD皆為配套模組插座，用於連接相應的感測器和顯示模組。



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

您可於此下載 Gerber 檔案，並上傳至 JLCPCB 進行 PCB 訂製

Gerber：https://github.com/BoomerChiao/Arduino_Air-Quality-Monitor/tree/main/PCB

JLCPCB：https://jlcpcb.com/

您也可在此下載原理圖及 PCB 檔案，以進行後續編輯。

oshwlab：https://oshwlab.com/chiaochieh/sgp30xshtxarduino_pro_202412

##  3D casing （3D外殼）

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

thingiverse：https://www.thingiverse.com/thing:7043581

.

![image](https://github.com/user-attachments/assets/8879a8de-7cc1-4cff-87aa-36759aa87ef3)

![image](https://github.com/user-attachments/assets/b51de486-60c0-4d4c-8341-284f2b9ce705)

⬆上圖所示的外殼分別為 Enclosure_Button、Mini_Enclosure_A、Mini_Enclosure_B 和 Mini_Enclosure_C 的 STL 檔案

你可以在這裡獲得3D檔案下載：
https://github.com/BoomerChiao/Arduino_Air-Quality-Monitor/tree/main/Enclosure/Mini

thingiverse：https://www.thingiverse.com/thing:7043588

###  3D printed enclosure assembly　（3D外殼組裝）

####  Enclosure assembly　（3D正常版外殼組裝）

![image](https://github.com/user-attachments/assets/6c63d872-016a-49de-8c26-6b4c482282a0)

⬆請先準備 M3 螺絲、螺帽 M3 和 M3 單頭細牙銅柱，請參考如下數量
1. M3x5 螺絲 *1
2. M3 螺帽 *4
3. M3 六角單頭細牙銅柱 20mm *6
4. M3 六角單頭細牙銅柱 15mm *1

![image](https://github.com/user-attachments/assets/8bd56318-b7f5-4049-ab0c-64f3792df0c6)
![image](https://github.com/user-attachments/assets/c4cca5df-b334-4a62-bfa5-6155b0309f1e)

⬆完成圖示如上

.

####  Mini_Enclosure assembly　（3D精簡版外殼組裝）

![image](https://github.com/user-attachments/assets/4e3dcea7-b592-4257-8bc1-3ef0a068b271)

⬆請先準備 M3 螺絲、螺帽 M3、 M3 六角雙母細牙銅柱 和 單頭細牙銅柱，請參考如下數量
1. M3x5 或 M3x6 螺絲 *8
2. M3 螺帽 *3
3. M3 六角雙母細牙銅柱 10mm *3
4. M3 六角雙母細牙銅柱 20mm *2
5. M3 六角單頭細牙銅柱 8mm *1
6. M3 六角單頭細牙銅柱 10mm *2
7. M3 六角單頭細牙銅柱 15mm *1
   
![image](https://github.com/user-attachments/assets/5894995f-57d5-493b-8049-4273da685398)
![image](https://github.com/user-attachments/assets/9e38243e-be3b-4a15-a976-95b1555b496a)

⬆完成圖示如上

##  Product Showcase　（成品展示）

![image](https://github.com/user-attachments/assets/6a883f15-1ecb-4908-9c0a-05175804008b)
![image](https://github.com/user-attachments/assets/904a964c-7119-44af-b323-e664a1141164)

⬆👈左圖展示的是具備充電模組與濾波耦合電路的完整設計；👉右圖則為省略相關模組的簡化版本。

![image](https://github.com/user-attachments/assets/5c8f7808-2f43-4eff-99d6-fee495146004)

⬆此圖為 OLED 版本顯示模組 正面成品圖

![image](https://github.com/user-attachments/assets/5eaa7efd-2a6c-4770-8743-99e70a7bb08c)

⬆此圖為簡化版本顯示模組 背面成品圖

![image](https://github.com/user-attachments/assets/5a68ae87-86f9-433b-bbef-bddeb34cdcd6)

⬆此圖為 LCD 版本顯示模組 正面成品圖

![image](https://github.com/user-attachments/assets/2f4eb75a-cea9-4dfc-bbc0-eb8f537b134e)

⬆此圖為具備充電模組與電池布局的 側面存放圖

![image](https://github.com/user-attachments/assets/8b935066-21eb-410f-84de-88974288892b)

⬆此圖為完整版本顯示模組 背面成品圖

![image](https://github.com/user-attachments/assets/7d4dc535-557b-4cf1-894e-1d212dd3b8aa)
![image](https://github.com/user-attachments/assets/7113d09d-ceb9-442e-9b3b-eb3564d1f434)
![image](https://github.com/user-attachments/assets/2ff7a65e-b1ea-4c8b-acb3-04dad43ce9c6)

![image](https://github.com/user-attachments/assets/53d21167-3ad1-43e4-b54e-c9889fcea658)
![image](https://github.com/user-attachments/assets/f19f7f66-de2c-46d4-9b2c-179af0edd5cd)
![image](https://github.com/user-attachments/assets/3c4e63df-e414-4d0f-823a-d1dca9738c04)




## ISSUE （已知問題）
Q1. 溫度偏高。
   - SGP30 內建加熱裝置會產生熱量，影響溫度準確性；同時 IP5306 充電狀況下 IC 的熱堆積效應加劇。為確保準確性，需在通風良好的環境下使用。

     ![image](https://github.com/user-attachments/assets/dd189a38-2a05-4fba-a7a4-9c7010ccddca)

Q2. TVOC偏高。
   - SGP30 傳感器需要空氣流動來確保測量環境中的有機氣體準確性，而缺乏空氣流動會影響氣體擴散，導致不準確的讀數。因此，維持良好的空氣流動對提升測量準確性至關重要。

Q3. 電池電壓飄移。
   - 已經進行過優化，目前此功能提供的是大致數值觀察。

Q4. 後續是否提供更新？
   - 目前計劃針對 LCD 介面及 PMS9003M 的省電模式進行軟體更新，並正在評估其可行性。



##  References　（參考資料）
1. https://www.arduino.cc/en/software
2. http://wiki2.tjc1688.com/download/usart_hmi.html
3. https://www.b4x.com/android/forum/threads/how-to-connect-an-arduino-pro-mini-to-a-pc-via-a-usb-to-serial-module.77010/
4. https://learn.adafruit.com/adafruit-aht20/arduino
5. https://www.icshop.com.tw/products/368030501785
6. https://wiki.dfrobot.com/SHT40_Humidity_and_Temperature_Sensor_SKU_SEN0428
7. https://how2electronics.com/interfacing-sgp30-co2-tvoc-sensor-with-arduino/
8. https://easyeda.com/editor
9. https://jlcpcb.com/
10. https://oshwlab.com/
