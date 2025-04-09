class Pixel {

private:

    int x;
    int y;
    char* color;
    float mas;

public:
    Pixel();
    Pixel(int, int, char*, float);
    Pixel(const Pixel&);
    Pixel(int);
    Pixel(float);
    Pixel(char);
    Pixel(char*);

    operator int();
    operator float();
    operator char();
    operator char*();

    Pixel& operator+ (Pixel);
    Pixel& operator= (const Pixel&); 

    ~Pixel() {
       delete []color;
    }

    int get_x() const;
    int get_y() const;
    char* get_color() const;
    float get_mas() const;
    void set_x(int);
    void set_y(int);
    void set_color(char*);
    void set_mas(float);
    
    Pixel &copy(const Pixel&);
    Pixel summa(Pixel);
    Pixel* there_I_am() { 
        return this;
    }    
};