import numpy as np

# 1. 创建模拟图片：N=1, H=3, W=3, C=3（对应教程中的RGB图片举例）
# 初始为NHWC格式（TensorFlow默认）：shape=(1,3,3,3)
img_nhwc = np.array([
    [
        [[255,0,0], [255,255,0], [0,255,0]],
        [[0,255,255], [0,0,255], [255,0,255]],
        [[128,128,128], [0,0,0], [255,255,255]]
    ]
], dtype=np.uint8)
print("【NHWC格式】shape =", img_nhwc.shape)
print("NHWC遍历（低维到高维：N→H→W→C）：\n", img_nhwc.flatten()[:12])  # 展平看前12个元素

# 2. NHWC转换为NCHW格式（Caffe/PyTorch默认）：用transpose重排维度
# transpose(0,3,1,2)：将维度顺序从(N,H,W,C)改为(N,C,H,W)
img_nchw = img_nhwc.transpose(0, 3, 1, 2)
print("\n【NCHW格式】shape =", img_nchw.shape)
print("NCHW遍历（低维到高维：N→C→H→W）：\n", img_nchw.flatten()[:12])  # 展平看前12个元素

# 3. 格式还原：NCHW→NHWC
img_nhwc_back = img_nchw.transpose(0, 2, 3, 1)
print("\n【NCHW转回NHWC】是否与原数据一致：", np.array_equal(img_nhwc, img_nhwc_back))