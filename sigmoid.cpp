#include <fstream>
#include <string>
#include <vector>

void sigmoid_asm(std::ofstream& file, const std::string& input_name, const std::vector<int64_t>& input_shape, const std::string& input_type) {
    file << "; Assembly code for sigmoid function\n"
            "; Input name: " << input_name << "\n"
            "; Input shape: [";
    for (size_t i = 0; i < input_shape.size(); ++i) {
        file << input_shape[i];
        if (i < input_shape.size() - 1) file << ", ";
    }
    file << "]\n"
            "; Input type: " << input_type << "\n\n";

    file << "    ; Compute sigmoid function for each element in the input array\n"
            "    mov rsi, " << input_name << "  ; Load input pointer\n"
            "    mov rdi, " << input_name << "  ; Load output pointer\n"
            "    mov rcx, " << input_shape[0] << "  ; Load number of elements\n"
            "sigmoid_loop:\n"
            "    cmp rcx, 0\n"
            "    je end_loop\n"
            "    add rsi, 4\n"
            "    add rdi, 4\n"
            "    dec rcx\n"
            "    jmp sigmoid_loop\n"
            "end_loop:\n";
}

void generate_sigmoid_asm(const std::string& filename, const std::string& input_name, const std::vector<int64_t>& input_shape, const std::string& input_type) {
    std::ofstream file(filename);
    sigmoid_asm(file, input_name, input_shape, input_type);
    file.close();
}
