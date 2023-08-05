




void* myMemCpy(const void* src, void* des, const size_t len) {
    if (src == nullptr || des == nullptr) {
        return nullptr;
    }

    if (src < des) {
        for (size_t i = 0; i < len; i++) {
            *((char*)des + i) = *((char*)src + i);
        }
    } else {
        for (size_t i = len - 1; i >= 0; i--) {
            *((char*)des + i) = *((char*)src + i);
        }
    }
    return (void*)des;
}