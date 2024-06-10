cdef extern from "sigmoid.cpp":
    void generate_sigmoid_asm(string filename, string input_name, vector[int64_t] input_shape, string input_type)

def generate_sigmoid(string filename, string input_name, list input_shape, string input_type):
    generate_sigmoid_asm(filename, input_name, input_shape, input_type)
