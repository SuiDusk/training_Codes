import numpy as np

# 创建shape=(4,20,20,3)的Tensor：4张20*20的RGB图片，像素值[0,255]
img_np = np.random.randint(0, 256, size=(4,20,20,3), dtype=np.uint8)

# 多层循环遍历（对应shape的4个维度）
print("【遍历第1张图的前2行2列像素】")
for i in range(4):  # 只遍历第1张图（i=0）
    for j in range(20):  # 前2行（高）
        for p in range(20):  # 前2列（宽）
            for q in range(3):  # RGB3通道
                print(f"第{i+1}张图-({j},{p})像素-{['R','G','B'][q]}通道：{img_np[i,j,p,q]}")