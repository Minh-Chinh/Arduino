#include "ICamera.hpp"
#include "FileCamera.cpp"      
#include "run_inference.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    // Khởi tạo giả lập camera từ thư mục test_frames
    FileCamera cam("test_frames");

    while (true) {
        Frame frame = cam.capture();
        if (!frame.buf) {
            std::cerr << "No frames found in test_frames!\n";
            return 1;
        }
        int result = run_inference(frame.buf, frame.len);
        std::cout << "Inference result: " << result << std::endl;
        // delay 100ms giữa 2 frame
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}
