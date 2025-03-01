# 基本原則

## 1.1 所有権の明確化
```cpp
// 1. 明示的な所有権移転
void* create_owned_resource() {
    return new Resource();  // 呼び出し側が所有権を持つ
}

// 2. 参照のみを返す
const Resource* get_resource_reference() {
    return &singleton_resource;  // 所有権の移転なし
}
```

## 1.2 リソース管理の責任
```cpp
// 1. 作成者が解放
void* creator_responsible() {
    void* ptr = create_resource();
    use_resource(ptr);
    delete_resource(ptr);  // 作成者が解放
    return nullptr;
}

// 2. 受け取り側が解放
void* receiver_responsible() {
    return create_resource();  // 受け取り側で解放が必要
}
```

## 1.3 所有権の原則

### 1. 単一所有者の原則
- リソースは常に1つの所有者を持つ
- 所有権の移転は明示的に行う
- 共有所有権は避ける
- 循環参照を防ぐ

### 2. 所有権の階層
- 親オブジェクトが子オブジェクトを所有
- 親の削除時に子も削除される
- 子の所有権変更は親を通じて行う
- 親子関係は明確に管理する

### 3. 一時的な借用
- 所有権を移転せずに一時的に使用
- 借用中は所有者が削除しない
- 借用期間を明確にする
- 借用中の状態変更に注意

## 1.4 リソース管理の原則

### 1. RAIIパターン
```cpp
class ScopedResource {
    void* ptr;
public:
    explicit ScopedResource(void* p) : ptr(p) {}
    ~ScopedResource() {
        if (ptr) cleanup(ptr);
    }
private:
    ScopedResource(const ScopedResource&) = delete;
    ScopedResource& operator=(const ScopedResource&) = delete;
};
```

### 2. スマートポインタの使用
```cpp
class ResourcePtr {
    void* ptr;
public:
    explicit ResourcePtr(void* p = nullptr) : ptr(p) {}
    ~ResourcePtr() { reset(); }
    
    void reset(void* p = nullptr) {
        if (ptr) cleanup(ptr);
        ptr = p;
    }
    
    void* release() {
        void* p = ptr;
        ptr = nullptr;
        return p;
    }
    
    void* get() const { return ptr; }
    
private:
    ResourcePtr(const ResourcePtr&) = delete;
    ResourcePtr& operator=(const ResourcePtr&) = delete;
};
```

## 1.5 メモリ管理のガイドライン

### 1. リソースの確保と解放
- 必ずcreate/deleteをペアで使用
- リソースリークを防ぐ
- エラー時の解放を確実に行う
- 解放順序を考慮する

### 2. 所有権の管理
- 所有権の移転を明確にする
- 共有を避ける
- 循環参照を防ぐ
- 親子関係を適切に管理する

### 3. エラー処理
- リソース確保失敗時の処理
- 部分的な確保/解放
- クリーンアップの確実な実行
- 例外安全性の確保

### 4. デバッグサポート
- メモリリークの検出
- 所有権の追跡
- リソース使用状況の監視
- エラーの早期発見
