import numpy as np

# 1. 创建不同维度的Tensor（NumPy的ndarray即为实操中的Tensor）
scalar = np.array(5)  # 0维Tensor（标量）
vec = np.array([1, 2, 3])  # 1维Tensor（向量）
mat = np.array([[1, 2], [3, 4]])  # 2维Tensor（矩阵）
tensor_3d = np.array([[[1,2], [3,4]], [[5,6], [7,8]]])  # 3维Tensor

# 打印Tensor及基本信息
print("【0维Tensor（标量）】：", scalar, "，shape：", scalar.shape)
print("【1维Tensor（向量）】：", vec, "，shape：", vec.shape)
print("【2维Tensor（矩阵）】：\n", mat, "，shape：", mat.shape)
print("【3维Tensor】：\n", tensor_3d, "，shape：", tensor_3d.shape)

# 2. 体验“算子是基础计算单元”：用「加法算子」对Tensor做计算
add_op = lambda x, y: x + y  # 定义加法算子（lambda简化函数）

# 加法算子对不同Tensor的计算（同维度才能计算，体现算子的计算逻辑）
res1 = add_op(vec, [4,5,6])  # 1维Tensor相加
res2 = add_op(mat, [[5,6], [7,8]])  # 2维Tensor相加
print("\n【加法算子计算结果】")
print("1维Tensor相加：", res1)
print("2维Tensor相加：\n", res2)

#用减法/乘法定义新算子,对Tensor做计算
mul_op = lambda x,y:x*y
div_op = lambda x,y:x/y
matmul_op = lambda x,y:x@y

vec_res = mul_op (vec, 2)
print(f"向量乘以标量：{vec_res}，shape：{vec_res.shape}")

vec_dot = matmul_op(vec, np.array([4, 5, 6]))  # 注意：这里自动按一维数组做内积
print(f"向量点积（内积）：{vec_dot}")

mat_div = div_op(mat, np.array([1, 2]))  # 对应位置相除
print(f"矩阵对应元素除法：\n{mat_div}")

mat_mul_res = matmul_op(mat, np.array([[5, 6], [7, 8]]))
print(f"矩阵乘法（点积）：\n{mat_mul_res}")