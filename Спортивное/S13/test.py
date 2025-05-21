import numpy as np
from scipy.stats import norm

# данные групп
mean_a = 4.162601626
std_a = 0.843237163
n_a = 123
mean_b = 3.311827957
std_b = 0.465750788
n_b = 93

# вычисляем Z-статистику без прямого использования формулы
pooled_std = np.sqrt(((n_a - 1) * std_a ** 2 + (n_b - 1) * std_b ** 2) / (n_a + n_b - 2))
se = pooled_std * np.sqrt(1 / n_a + 1 / n_b)
Z = (mean_a - mean_b) / se

# вычисляем p-значение
p_value = 2 * (1 - norm.cdf(abs(Z)))

print(f"Z-статистика: {Z}")
print(f"p-значение: {p_value}")