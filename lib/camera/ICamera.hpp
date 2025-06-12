#pragma once
#include <cstddef>
#include <cstdint>

// Một frame JPEG hoặc RAW bất kỳ
struct Frame {
    const uint8_t* buf;
    size_t len;
};

class ICamera {
public:
    virtual ~ICamera() = default;
    // Đọc khung hình mới, trả về Frame.buf len
    virtual Frame capture() = 0;
};
