# インデントとフォーマット

## 4.1 インデント
- スペース4文字を使用
- タブ文字は使用しない
- 継続行は8スペース

例：
```cpp
void someFunction() {
    if (condition) {
        doSomething();
        doSomethingElse(
                parameter1,    // 継続行は8スペース
                parameter2);
    }
}
```

## 4.2 ブレース
```cpp
if (condition) {
    // 処理
} else {
    // 処理
}

while (condition) {
    // 処理
}

class ClassName {
public:
    // メンバ
private:
    // メンバ
};
```

## 4.3 スペース
```cpp
// 演算子の前後
a = b + c;
if (a < b) {
}

// カンマの後
function(a, b, c);

// ポインタ/参照の*と&
int* ptr;
int& ref;
```

## 4.4 行の長さと折り返し

### 基本ルール
- 1行の最大長は80文字
- 長い行は適切に折り返す
- 演算子の前で折り返す

### 関数宣言/定義
```cpp
ReturnType LongClassName::longFunctionName(
    Type1 parameter1,
    Type2 parameter2,
    Type3 parameter3
) {
    // 実装
}
```

### 条件文
```cpp
if (longCondition1 &&
    longCondition2 &&
    longCondition3) {
    // 処理
}
```

### 関数呼び出し
```cpp
someFunction(
    longArgument1,
    longArgument2,
    longArgument3
);
```

## 4.5 空行の使用

### 基本ルール
- 論理的なブロックの間に1行
- クラス定義の前後に2行
- ファイル末尾に1行

### 例
```cpp
#include <vector>
#include <string>

// 2行空ける
class MyClass {
public:
    MyClass();
    
    // メソッド間に1行
    void method1();
    
    void method2();
private:
    int m_value;
};

// 2行空ける
class AnotherClass {
    // ...
};
