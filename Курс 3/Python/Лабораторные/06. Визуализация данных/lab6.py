from argparse import ArgumentParser
import matplotlib.pyplot as plt
import numpy as np

def build_map(filename):
    with open(filename, "rb") as file:
        header = file.readline().decode().strip().split("|")
        header_size = int(file.readline())

        xlen = int(header[0]) # размер карты по ширине
        ylen = int(header[1]) # размер карты по длине
        stepx = float(header[2].replace(',', '.')) # масштаб карты по ширине
        stepy = float(header[3].replace(',', '.')) # масштаб карты по длине
        startx = int(header[4]) # начало данных на карте по ширине
        starty = int(header[5]) # начало данных на карте по длине
        lastx = int(header[6]) # конец данных на карте по ширине
        lasty = int(header[7]) # конец данных на карте по длине
        width = int(header[8]) # количество точек по ширине
        height = int(header[9]) # количество точек по длине
        level = float(header[10].replace(',', '.')) # базовый уровень

        file.seek(header_size)
        data = (np.frombuffer(file.read(), dtype=np.float32)-level)/10
        plot_data = np.array(data.reshape((height,width)))

        px = 1/plt.rcParams['figure.dpi']
        extent = [0, (lastx-startx)*stepx, 0, (lasty-starty)*stepy]
        fig, ax = plt.subplots(figsize=(xlen*px, ylen*px))
        im = ax.imshow(plot_data, cmap='hot', extent=extent, aspect='auto')
        
        ax.contour(plot_data, colors='black', linewidths=0.5, levels=30, extent=extent)
        fig.colorbar(im, ax=ax)

        plt.show()

if __name__ == "__main__":

    parser = ArgumentParser(
                prog='lab6',
                description='Shows heatmap for binary file'
            )
    parser.add_argument('filename')
    args = parser.parse_args()
    
    build_map(args.filename)