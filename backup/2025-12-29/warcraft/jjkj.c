// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("蛇年[2;37;0m[2;37;0m", ({"jjyy"}));        
        set("gender", "男性");                
        set("long", "天下英豪出我輩，江湖一入催人老[2;37;0m
它是極品卡的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jjkj");
        set("owner_name", "極品卡");
        set_temp("owner", "jjkj");
        set_temp("owner_name", "極品卡");
        ::setup();
}
