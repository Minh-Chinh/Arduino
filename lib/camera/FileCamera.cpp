#include "ICamera.hpp"
#include <filesystem>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

namespace fs = std::filesystem;

class FileCamera : public ICamera {
    std::vector<fs::path> files;
    size_t idx = 0;
    // buffer tĩnh để giữ data sau khi trả về
    std::vector<uint8_t> buffer;

public:
    // Đường dẫn tới thư mục chứa ảnh (ví dụ "test_frames")
    explicit FileCamera(const std::string& folder) {
        for (auto &p : fs::directory_iterator(folder)) {
            if (p.path().extension() == ".jpg")
                files.push_back(p.path());
        }
        std::sort(files.begin(), files.end());
    }

    Frame capture() override {
        if (files.empty()) return {nullptr, 0};
        // đọc file hiện tại
        std::ifstream in(files[idx], std::ios::binary);
        buffer.assign(std::istreambuf_iterator<char>(in),
                      std::istreambuf_iterator<char>());
        Frame f{ buffer.data(), buffer.size() };
        idx = (idx + 1) % files.size();
        return f;
    }
};
