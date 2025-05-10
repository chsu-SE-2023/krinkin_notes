import bpy, math

COLL_NAME = 'Jenga'
ROW_COUNT = 12
ROW_SIZE = 3

def coll_remove(name):
    """
    Функция, удаляющая заданную коллекцию с её объектами
    :param coll_name: Имя удаляемой коллекции
    """
    try:
        j_coll = bpy.data.collections.get(name)
        for obj in j_coll.objects: # Удаление объектов в коллекции
            bpy.data.objects.remove(obj, do_unlink=True)
        bpy.data.collections.remove(j_coll)
    except:
        print("Collection does not exist")

def create_row(coll_name, index, size):
    """
    Функция создающая один ряд башни в коллекции
    :param coll_name: Имя коллекции для башни
    :param index: Номер ряда в башне
    :param size: Кол-во балок в ряду
    """
    src = bpy.data.objects['Plank']
    src.scale[0] = size*2
    z_axis = 2 * index
    if index % 2 == 0:
        for i in range(size//2, -size//2, -1):
            c = src.copy(); c.location = (0, 4*i, z_axis)
            bpy.data.collections[coll_name].objects.link(c)
    else:
        for i in range(size//2, -size//2, -1):
            c = src.copy(); c.location = (4*i, 0, z_axis)
            c.rotation_euler[2] = math.radians(90)
            bpy.data.collections[coll_name].objects.link(c)

def main():
    coll_remove(COLL_NAME)
    j_coll = bpy.data.collections.new(COLL_NAME)
    bpy.context.scene.collection.children.link(j_coll)
    for i in range(ROW_COUNT):
        create_row(COLL_NAME, i, ROW_SIZE)

if __name__ == "__main__":
    main()