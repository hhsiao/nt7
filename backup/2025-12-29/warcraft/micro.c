// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m混沌[2;37;0m[2;37;0m", ({"little"}));        
        set("gender", "男性");                
        set("long", "長毛四足，如犬，有腹無五臟。牴觸善人，憑依惡人![2;37;0m
它是小不點的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "micro");
        set("owner_name", "小不點");
        set_temp("owner", "micro");
        set_temp("owner_name", "小不點");
        ::setup();
}
