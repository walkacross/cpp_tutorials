// 8_6_strc_ref.cpp -- using structure reference
#include <iostream>
#include <string>

struct free_throws
{
    std::string name;
    int made;
    int attempts;
    float percent;
};

void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & source);

int main()
{
    free_throws one = {"aaaa",12,14};
    free_throws two = {"bbbb",10,16};
    free_throws three = {"cccc",7,9};
    free_throws four = {"dddd", 5, 9};
    free_throws five = {"eeee",6,14};
    free_throws team = {"ffff",0,0};
    // no initialization
    free_throws dup;

    set_pc(one);
    display(one);
    accumulate(team, one);
    display(team);

    //use return value as argument
    display(accumulate(team,two)); 
    accumulate(accumulate(team,three),four);
    display(team);
    
    // use return value in assignment
    dup = accumulate(team, five);

    std::cout << "displaying team:\n";
    display(team);
    std::cout << "displaying dup after assignment:\n";
    display(dup);
    set_pc(four);

    //ill-advised assignment
    accumulate(dup,five) = four;
    std::cout << "displaying dup after ill-advised assignment:\n";
    display(dup);
    return 0;
}

void display(const free_throws & ft)
{
    using std::cout;
    cout << "name: " << ft.name << "\n";
    cout << " made: " << ft.made < "\t";
    cout << "attemps: " << ft.attempts < "\t";
    cout << "percent: " << ft.percent << "\n";
}

void set_pc(free_throws & ft)
{
    if (ft.attempts != 0)
        ft.percent  = 100.0f * float(ft.made) / float(ft.attempts);
    else
        ft.percent = 0;
}

free_throws & accumulate(free_throws & target, const free_throws & source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);
    return target;
}
