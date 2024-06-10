import numpy as np
import onnxruntime as rt
from onnxruntime.datasets import get_example
from sigmoid import generate_sigmoid_asm

sigmoid_model = get_example('sigmoid.onnx')
sess = rt.InferenceSession(sigmoid_model, providers=rt.get_available_providers())

input_name = sess.get_inputs()[0].name
input_shape = sess.get_inputs()[0].shape
input_type = sess.get_inputs()[0].type
print("Input name:", input_name)
print("Input shape:", input_shape)
print("Input type:", input_type)

generate_sigmoid_asm("sigmoid.asm", input_name, input_shape, input_type)

