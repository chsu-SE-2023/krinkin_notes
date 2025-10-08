import turtle
import math

try:
    corners = int(input("Введите число углов в фигуре: "))
except ValueError:
    print("Вы ввели не число")
    exit()

# Перенос окна поверх других
turtle.getcanvas().winfo_toplevel().attributes('-topmost', True)

from easter_egg import play_animation
if corners < 0: play_animation()

if corners < 3:
    print("Число углов в фигуре не может быть меньше 3-х!")
    exit()

radius = 200
edge = (math.pi * radius**2) / (corners/2 * radius)
angle = 180-((corners - 2) * 180)/corners

turtle.speed("fast")

# Перемещение черепахи в начальную точку
# для того чтобы фигура была нарисована 
# ровно по центру окна
turtle.up()
turtle.left(90)
turtle.forward(radius)
turtle.right(90)
turtle.right(angle/2)
turtle.down()

for _ in range(corners):
    turtle.forward(edge)
    turtle.right(angle)

turtle.done()