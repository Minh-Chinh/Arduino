#pragma once
#include <cstddef>
#include <cstdint>

// Xử lý frame JPEG/RGB, trả về label hoặc score
int run_inference(const uint8_t* buf, size_t len);

