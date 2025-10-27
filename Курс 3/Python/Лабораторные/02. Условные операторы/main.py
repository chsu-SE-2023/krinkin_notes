import turtle
import math

# Код лабораторной
def main():

    try:
        corners = int(input("Введите число углов в фигуре: "))
    except ValueError:
        print("Вы ввели не число")
        exit()

    # Перенос окна поверх других
    turtle.getcanvas().winfo_toplevel().attributes('-topmost', True)

    if corners < 0:
        play_animation()

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
# Конец кода лабораторной












# Код для рисования некоторой анимации при помощи черепахи

from abc import abstractmethod
from io import BufferedReader, BytesIO
import urllib.request
import pathlib
import struct
import typing
import time

FILE_VERSIONS = (1, 2)

class VectorContour:

    _color: int
    _points: list

    def __init__(self, color: int, points: list):

        self._color = color
        self._points = points

    @property
    def color(self) -> int:
        return self._color

    def __getitem__(self, index: typing.Union[typing.SupportsIndex, typing.Tuple[int]]) -> \
            typing.Union[list, int]:
        return self._points[index]

    def __len__(self) -> int:
        return len(self._points)

    def __iter__(self) -> typing.Iterator[list]:
        return (point for point in self._points)

class VectorFrame:

    _contours: typing.List[VectorContour]

    def __init__(self, contours: typing.List[VectorContour] = []):
        self._contours = contours

    def __getitem__(self, index: typing.Union[typing.SupportsIndex, typing.Tuple[int]]) -> \
            typing.Union[VectorContour, list, int]:

        if type(index) == tuple:
            return self._contours[index[0]][index[1:]]
        return self._contours[index]

    def __len__(self) -> int:
        return len(self._contours)

    def __iter__(self) -> typing.Iterator[VectorContour]:
        return (contour for contour in self._contours)

class VectorVideo:

    _frames: typing.List[VectorFrame]
    _framerate: float
    _dimensions: typing.Tuple[int, int]

    def __init__(self, framerate: float, dimensions: typing.Tuple[int, int],
            frames: typing.List[VectorFrame] = []):

        self._frames = frames
        self._framerate = framerate
        self._dimensions = dimensions

    @property
    def framerate(self) -> float:
        return self._framerate

    @property
    def dimensions(self) -> typing.Tuple[int, int]:
        return self._dimensions

    @property
    def frame_count(self) -> int:
        return len(self)

    def __len__(self) -> int:
        return len(self._frames)

    def __getitem__(self, index: typing.Union[typing.SupportsIndex, typing.Tuple[int]]) -> \
            typing.Union[VectorFrame, VectorContour, list, int]:

        if type(index) == tuple:
            return self._frames[index[0]][index[1:]]
        return self._frames[index]

    def __setitem__(self, index: typing.SupportsIndex, value: VectorFrame):
        self._frames[index] = value

    def insert(self, index: typing.SupportsIndex, value: VectorFrame):
        self._frames.insert(index, value)

    def append(self, value: VectorFrame):
        self._frames.append(value)

    def __iter__(self) -> typing.Iterator[VectorFrame]:
        return (frame for frame in self._frames)

class VectorVideoDecoder:
    """
    A base class for handling decoding of vectorized video

    Properties
    ----------
    dimensions : (int, int)
        The width/height of the original video
    framerate : float
        The framerate of the original video
    total_frames : int
        The total number of encoded frames
    current_frame : int
        The next frame to be decoded
    """

    _framerate: float
    _dimensions: typing.Tuple[int, int]
    _total_frames: int
    _frame: int
    _vector_video: VectorVideo

    def __init__(self):
        self._framerate = None
        self._dimensions = None
        self._total_frames = None
        self._frame = 0

    @abstractmethod
    def seek(self, frame_offset: int, whence: int):
        pass

    @abstractmethod
    def read(self) -> VectorFrame:
        pass

    @property
    def dimensions(self) -> typing.Tuple[int, int]:
        return self._dimensions

    @property
    def framerate(self) -> float:
        return self._framerate

    @property
    def total_frames(self) -> int:
        return self._total_frames

    @property
    def current_frame(self) -> int:
        return self._frame

    @property
    def video(self) -> VectorVideo:
        return self._vector_video

class VectorVideoFileDecoder(VectorVideoDecoder):
    """
    A class handling decoding of vectorized videos from files

    ...

    Attributes
    ----------
    vector_file_path : pathlib.Path
        The path to the vector file
    """

    _file_path: pathlib.Path
    _file_object: BufferedReader
    _file_size: int
    _header_size: int

    def __init__(self, vector_file_path: pathlib.Path):

        super().__init__()
        self._file_path = vector_file_path
        self._file_object = None

    def _get_headers(self, remote=False):
        if self._file_object:
            file_version, = self._get_data("<I")

            if file_version not in FILE_VERSIONS:
                raise TypeError(f"Invalid file format. Wanted '{FILE_VERSIONS}' " \
                        f"but got '{file_version}'.")

            self._header_size = struct.calcsize("<IfII")
            if not remote:
                self._file_size = self._file_path.stat().st_size
            self._framerate, width, height = self._get_data("<fII")
            self._dimensions = (width, height)
            self._total_frames = self._count_frames()
            self._vector_video = VectorVideo(self._framerate, self._dimensions)

    def download_file(self, chunk_size=8192):
        url = "https://github.com/chsu-SE-2023/krinkin_notes/raw/refs/heads/main/%D0%9A%D1%83%D1%80%D1%81%203/Python/%D0%9B%D0%B0%D0%B1%D0%BE%D1%80%D0%B0%D1%82%D0%BE%D1%80%D0%BD%D1%8B%D0%B5/%D0%9B2%20%D0%A3%D1%81%D0%BB%D0%BE%D0%B2%D0%BD%D1%8B%D0%B5%20%D0%BE%D0%BF%D0%B5%D1%80%D0%B0%D1%82%D0%BE%D1%80%D1%8B/vector"
        remote = BytesIO()
        with urllib.request.urlopen(url) as response:
            while True:
                chunk = response.read(chunk_size)
                if not chunk: break
                remote.write(chunk)
        remote.seek(0)
        self._file_size = remote.getbuffer().nbytes
        self._file_object = remote

    def open(self):
        """
        Open the vector file for reading
        """
        try:
            self._file_object = self._file_path.open("rb")
            self._get_headers()
        except FileNotFoundError:
            self.download_file()
            self._get_headers(remote=True)

    def close(self):
        """
        Close the vector file
        """
        if self._file_object:
            self._file_object.close()
            self._file_object = None

    def __enter__(self):
        self.open()
        return self

    def __exit__(self, type, value, traceback):
        self.close()

    def read(self) -> VectorFrame:
        """
        Read the next frame and return it in the form of nested lists

        :return: The decoded vectorized frame

        List Structure
        --------------
        List of Contours:
            Contour (tuple[int, list]):
                Color (int)
                List of Points:
                    Point (tuple[float, float])
        """
        if self._frame < len(self._vector_video):
            frame = self._vector_video[self._frame]
        else:
            frame_size, num_contours = self._get_data("<II")
            contours = []
            for contour_num in range(num_contours):
                color, num_points = self._get_data("<BI")
                data = self._file_object.read(struct.calcsize(f"<{num_points*2}i"))
                points = struct.unpack(f'<{len(data)//4}i', data)
                points = [points[i:i+2] for i in range(0, len(points), 2)]
                contour = VectorContour(color, points)
                contours.append(contour)

            frame = VectorFrame(contours)
            self._vector_video.insert(self._frame, frame)

        self._frame += 1

        return frame

    def read_all(self) -> VectorVideo:
        while self._frame < self._total_frames:
            self.read()

        return self._vector_video

    def seek(self, frame_offset: int, whence: int = 0):
        """
        Seeks to specific frame in video
        
        :param int frame_offset: The frame to seek to.
        :param int whence: Optional, default 0, which means absolute positioning.
            1 is seek relative to current pointer. 2 is seek relative to end of video.
        """
        if whence == 0:
            relative_offset = frame_offset - self._frame
            frame_num = frame_offset
        elif whence == 1:
            relative_offset = frame_offset
            frame_num = self._frame + relative_offset
        elif whence == 2:
            relative_offset = self._total_frames - frame_offset
            frame_num = self._frame + relative_offset
        else:
            raise ValueError(f"invalid whence ({whence}, should be 0, 1 or 2)")

        # Seek to beginning if frame is before current frame
        if relative_offset < 0:
            self._file_object.seek(self._header_size)
            relative_offset = frame_num

        for i in range(relative_offset):
            frame_size, = self._get_data("<I")
            self._file_object.seek(frame_size, 1)

        self._frame = frame_num

    def read_specific(self, frame_num: int) -> \
            typing.List[typing.Tuple[int, typing.List[typing.Tuple[float, float]]]]:
        """
        Read a specific frame within the vector file without moving the pointer.
        See the read method
        
        :param int frame_num: The frame number to read
        :return: The decoded vectorized frame
        """

        # Find current position to return to
        previous_byte = self._file_object.tell()
        previous_frame = self._frame

        # Seek and read frame
        self.seek(frame_num)
        frame_data = self.read()

        # Return to last position
        self._file_object.seek(previous_byte)
        self._frame = previous_frame

        return frame_data

    def _get_data(self, format: str) -> typing.Tuple:
        size = struct.calcsize(format)
        data = self._file_object.read(size)
        if len(data) == size:
            return struct.unpack(format, data)
        return ()

    def _count_frames(self) -> int:
        last_pos = self._file_object.tell()
        self._file_object.seek(self._header_size)
        pos = self._header_size
        frame_size = 0
        num_frames = 0
        while pos + frame_size < self._file_size:
            frame_size, = self._get_data("<I")
            pos += 4
            self._file_object.seek(frame_size, 1)
            num_frames += 1
            pos += frame_size

        self._file_object.seek(last_pos)

        return num_frames

def play_animation():

    # Extract arguments
    vector_path = pathlib.Path("vector")
    start_frame = 0
    offset_tolerance = 0

    if not vector_path.exists():
        print("\n###### Девушки молятся... ######")

    # Setup vector decoder
    decoder = VectorVideoFileDecoder(vector_path)
    decoder.open()

    end_frame = decoder.total_frames

    # Setup turtle
    tortoise = turtle.Turtle()
    tortoise.speed(10)
    tortoise.hideturtle()
    turtle.bgcolor("black")
    screen = tortoise.getscreen()
    screen.tracer(0,0)

    # Create variables for video statistics
    max_frame_time = 0
    frames_dropped = 0
    total_time = 0

    # Play original video next to turtle
    start_time = time.time() - start_frame / decoder.framerate

    decoder.seek(start_frame)

    frame_count_digits = int(math.log10(end_frame) + 1)

    while decoder.current_frame < end_frame:

        try:
            # Get time before frame is drawn
            frame_start_time = time.time()

            # Clear the screen and draw new frame
            tortoise.clear()
            draw_path(tortoise, decoder, 1)

            # Get timing for frame compared to video and update statistics
            end_time = time.time()
            current_time = end_time - start_time
            target_time = decoder.current_frame / decoder.framerate
            time_offset = current_time - target_time
            frame_render_time = end_time - frame_start_time
            total_time += frame_render_time
            max_frame_time = max(max_frame_time, frame_render_time)

            # Determine whether to skip frames or delay frame
            skip_frames = 0
            if time_offset > offset_tolerance:
                skip_frames = int(time_offset * decoder.framerate) + 1
                decoder.seek(skip_frames, 1)
            elif time_offset < -offset_tolerance:
                time.sleep(-time_offset - offset_tolerance)

            # Update screen after time is re-synchronized
            screen.update()

            if skip_frames != 0:
                frames_dropped += skip_frames

        except KeyboardInterrupt:
            break

    # Close the screen when finished
    screen.bye()

    decoder.close()

def draw_path(tortoise: turtle.Turtle, decoder: VectorVideoDecoder,
        scale: float=1.0):

    contours = decoder.read()

    num_points = 0

    contours_drawn = 0

    # Draw every curve in the path
    for contour in contours:

        num_points += len(contour)

        # Make sure there is actually a contour
        if len(contour) > 0:

            # Gray line and fill based on contour
            tortoise.color("gray", "black" if contour.color == 1 else "white")

            contours_drawn += 1

            # Go to initial postion without drawing
            tortoise.up()
            move_turtle(tortoise, contour[0], decoder.dimensions, scale)
            tortoise.begin_fill()
            tortoise.down()

            # Draw remaining points
            for point in contour:
                move_turtle(tortoise, point, decoder.dimensions, scale)
            
            # Close loop by drawing back to initial position
            move_turtle(tortoise, contour[0], decoder.dimensions, scale)
            tortoise.end_fill()

def move_turtle(tortoise: turtle.Turtle, point: typing.Tuple[float, float],
        frame_dimensions: typing.Tuple[int, int], scale_factor: float=1.0):

    tortoise.goto((point[0] - frame_dimensions[0]/2) * scale_factor,
            (frame_dimensions[1]/2 - point[1]) * scale_factor)

if __name__ == '__main__':
    main()