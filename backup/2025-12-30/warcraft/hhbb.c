// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m小虎[2;37;0m[2;37;0m", ({"xiaohu"}));        
        set("gender", "男性");                
        set("long", "$HIG$小虎[2;37;0m
它是輪哥的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "hhbb");
        set("owner_name", "輪哥");
        set_temp("owner", "hhbb");
        set_temp("owner_name", "輪哥");
        ::setup();
}
