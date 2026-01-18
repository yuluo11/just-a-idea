#ifndef T_14
#define T_14

#include<string>
#include<iostream>
class Screen;

class Window_mgr
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	inline void clear(ScreenIndex);

private:
	std::vector<Screen> screens;
};
class Screen
{
    friend void Window_mgr::clear(ScreenIndex);
    public:
    typedef std::string::size_type pos;
    Screen()=default;
    Screen(pos ht,pos wd,char c):height(ht),width(wd),
    contents(ht*wd,c){}
    char get()const
    {return contents[cursor];}
    inline char get(pos ht,pos wd) const;
    Screen &move(pos r,pos c);
    Screen &set(char);
    Screen &set(pos ,pos,char);
    const Screen &display(std::ostream&os)const{do_display(os);return *this;}
    Screen &display(std::ostream&os){do_display(os);return *this;}
    private:
    void do_display(std::ostream &os)const
    {
        os<<contents;
    }
    private:
    pos cursor=0;
    pos height=0,width=0;
    std::string contents;
};

inline
void Window_mgr::clear(ScreenIndex i)
{
	Screen& s = screens[i];
	s.contents = std::string(s.height*s.width,' ');
}

inline 
Screen &Screen::move(pos r,pos c)
{
    pos row=r*width;
    cursor=row+c;
    return *this;
}

char Screen::get(pos r,pos c) const
{
    pos row=r*width;
    return contents[row+c];
}   

inline
Screen &Screen::set(char c)
{
    contents[cursor]=c;
    return *this;
}

Screen &Screen::set(pos row,pos col,char ch)
{
    contents[row*width+col]=ch;
    return *this;
}
#endif