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


