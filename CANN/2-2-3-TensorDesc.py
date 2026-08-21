import numpy as np

# 定义函数：提取Tensor的元信息，模拟CANN的TensorDesc
def get_tensor_desc(tensor, name):
    """
    模拟TensorDesc，返回Tensor的核心描述信息
    :param tensor: 输入的Tensor（np.ndarray）
    :param name: Tensor的唯一名称（name属性）
    :return: 字典形式的TensorDesc
    """
    tensor_desc = {
        "name": name,  # 唯一标识
        "shape": tensor.shape,  # 形状
        "dtype": tensor.dtype,  # 数据类型
        "format": "ND" if len(tensor.shape)>=1 else "SCALAR"  # 排布格式，简化为ND/标量
    }
    return tensor_desc

# 创建模拟图片的4D Tensor：shape=(4,20,20,3)（4张20*20的RGB图片）
img_tensor = np.random.rand(4,20,20,3).astype(np.bool_)  # dtype指定为float32
# 提取TensorDesc元信息
img_desc = get_tensor_desc(img_tensor, "rgb_image_tensor")

# 打印TensorDesc，对应上方表格
print("【张量描述符（TensorDesc）】")
for k, v in img_desc.items():
    print(f"{k}：{v}")
# 打印Tensor的实际数据（前2个像素）
print("\n【Tensor实际数据（前2个像素）】：\n", img_tensor[0,0,0:2,:])