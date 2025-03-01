# コンパイル要件

## 4.1 コンパイラフラグ
```cmake
# 警告レベル
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

# 最適化
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
```

## 4.2 プラットフォーム固有の設定
```cmake
if(APPLE)
    set(CMAKE_MACOSX_RPATH ON)
elseif(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()
