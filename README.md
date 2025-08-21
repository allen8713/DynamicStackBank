# Dynamic Stack & Simple Bank System in C++

這是一個小型 C++ 專案，展示兩個練習：

1. **動態模板堆疊（Dynamic Templated Stack）**  
   可自動擴充的堆疊類別，支援任意資料型別（例如 int、double）。

2. **簡單銀行帳號系統（Simple Bank Account System）**  
   簡單的銀行帳號管理程式，能讀取帳號資料與交易資料，處理存款/提款，並輸出帳號報表。  
   示範了 C++ 類別設計、檔案處理與資料結構應用。

---

## 專案結構

```text
DynamicStackBank/
├── include/
│   ├── Stack.h          # 動態模板堆疊類別定義
│   ├── account.h        # 帳號類別定義
│   └── bank.h           # 銀行類別定義
├── src/
│   ├── driver.cpp       # 測試堆疊功能
│   ├── main.cpp         # 執行銀行系統
│   ├── account.cpp      # 帳號類別實作
│   └── bank.cpp         # 銀行類別實作
├── Makefile             # 編譯專案
├── accounts.txt         # 範例帳號資料
└── transactions.txt     # 範例交易資料
```


---

## 功能特色

### 1. 動態模板堆疊（Stack）
- 可存放任意型別資料（int, double, string 等）。
- 當堆疊滿時，自動擴充容量。
- 常用操作：
  - `Push()`：加入元素
  - `Pop()`：彈出頂端元素
  - `Top()`：查看頂端元素
  - `IsStackEmpty()` / `IsStackFull()`：檢查堆疊狀態
  - `ClearStack()`：清空堆疊

### 2. 簡單銀行系統
- 讀取帳號資料檔案，建立帳號物件。
- 讀取交易檔案，依帳號處理存款/提款。
- 支援交易報表輸出，處理以下狀況：
  - 無效帳號
  - 餘額不足
- 使用 `unordered_map` 快速查找帳號。

---

## 編譯與執行

### 編譯專案
使用 Makefile：

進行編譯 make

測試Stack ./a.out

執行銀行系統 ./b.out



## 輸入輸出範例

範例輸入檔案

account.txt
```text
1111111111 Alice 5000.0
2222222222 Bob 3000.0
3333333333 Charlie 7000.0
4444444444 Diana 2500.0
5555555555 Edward 10000.0
```
transactions.txt
```text
#transactions.txt
1111111111 D 1000.0
2222222222 W 500.0
3333333333 W 8000.0
4444444444 D 750.0
5555555555 W 2000.0
6666666666 D 1000.0
```

D 表示存款（Deposit）

W 表示提款（Withdrawal）

第 6 筆交易的帳號 6666666666 不存在，會顯示錯誤訊息


範例程式輸出
```text
===== Account Listing =====
Account Number: 1111111111
Name: Alice
Balance: $5000.00
--------------------------
Account Number: 2222222222
Name: Bob
Balance: $3000.00
--------------------------
Account Number: 3333333333
Name: Charlie
Balance: $7000.00
--------------------------
Account Number: 4444444444
Name: Diana
Balance: $2500.00
--------------------------
Account Number: 5555555555
Name: Edward
Balance: $10000.00
--------------------------

===== Transaction Report =====
Account: 1111111111 Type: D Amount: 1000.00 New Balance: 6000.00
Account: 2222222222 Type: W Amount: 500.00 New Balance: 2500.00
Account: 3333333333 Type: W Amount: 8000.00 *** Insufficient funds ***
Account: 4444444444 Type: D Amount: 750.00 New Balance: 3250.00
Account: 5555555555 Type: W Amount: 2000.00 New Balance: 8000.00
Account: 6666666666 Type: D Amount: 1000.00 *** Invalid account number ***

===== Updated Account Listing =====
Account Number: 1111111111
Name: Alice
Balance: $6000.00
--------------------------
Account Number: 2222222222
Name: Bob
Balance: $2500.00
--------------------------
Account Number: 3333333333
Name: Charlie
Balance: $7000.00
--------------------------
Account Number: 4444444444
Name: Diana
Balance: $3250.00
--------------------------
Account Number: 5555555555
Name: Edward
Balance: $8000.00
--------------------------
```
